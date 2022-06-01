//
// log.h
//

#ifndef _LOG_H
#define _LOG_H

#include <iostream>
#include <sstream>
#include <atomic>

#include "common.h"

namespace cc {

namespace logger {
namespace id {
extern std::atomic<unsigned long long> counter;

const std::string& threadId();
} // ns id
} // ns logger

class LogError;
class LogWarn;
class LogInfo;
class LogDebug;
class LogTrace;

template<typename T>
class LoggerProxy;

class Logging {
public:
  static inline std::string getEndl() {
    std::ostringstream os;
    os << std::endl;
    return os.str();
  }

public:
  static constexpr const char *_LOGLEVEL { "CC_LOGLEVEL" };
  static constexpr const char *_LOGLEVEL_TRACE { "trace" };
  static constexpr const char *_LOGLEVEL_DEBUG { "debug" };
  static constexpr const char *_LOGLEVEL_INFO { "info" };
  static constexpr const char *_LOGLEVEL_WARN { "warn" };
  static constexpr const char *_LOGLEVEL_ERROR { "error" };

protected:
  std::string ts() const;
};

template<typename T>
class Logger: public Logging {

private:
  Logger() :
      _id(cc::logger::id::counter.fetch_add(1)) {
  }

  friend class LoggerProxy<T> ;

public:
  virtual ~Logger() {
    this->flush();
  }

  Logger(const Logger &logger) :
      _id(cc::logger::id::counter.fetch_add(1)) {
    this->_os << logger._os.str();
  }

  template<typename U>
  Logger<T>& operator<<(const U &u) {
    static bool isLevel(Logger<T>::isLevelOn());

    if (isLevel) {
      this->_os << u;
    }

    return (*this);
  }

  Logger<T>& operator<<(Logger<T>& (*fp)(Logger<T> &logger)) {
    return fp(*this);
  }

  void flush() {
    if (this->_os.str().length() > 0) {
      std::ostringstream os;

      os << this->ts() << " [" << cc::logger::id::threadId() << "|"
          << this->getPrefix() << "] " << this->_os.str();

      std::cout << os.str();

      this->clear();
    }
  }

  void clear() {
    this->_os.clear();
    this->_os.str("");
  }

  static bool isLevelOn();

  static bool isNoLevelOn();

  static std::string getTimestamp();

  const char* getPrefix() const;

private:
  Logger& operator=(const Logger&) = delete;

private:
  std::ostringstream _os;

  const long long _id;
};

template<typename T>
class LoggerProxy {

public:
  LoggerProxy() {
  }

  virtual ~LoggerProxy() {
    std::cout.flush();
  }

  template<typename U>
  Logger<T> operator<<(const U &data) {
    Logger<T> logger;

    logger << data;

    return logger;
  }

private:
  LoggerProxy(const LoggerProxy&) = delete;
  LoggerProxy& operator=(const LoggerProxy&) = delete;
};

extern LoggerProxy<LogError> error;
extern LoggerProxy<LogWarn> warn;
extern LoggerProxy<LogInfo> info;
extern LoggerProxy<LogDebug> debug;
extern LoggerProxy<LogTrace> trace;

template<typename T>
Logger<T>& endl(Logger<T> &logger) {
  static const std::string newline(Logging::getEndl());
  logger << newline;
  return logger;
}

class LogError;
class LogWarn;
class LogInfo;
class LogDebug;
class LogTrace;

//

inline std::ostringstream& operator<<(std::ostringstream &os,
    const std::ostringstream &s) {
  os << s.str();
  return os;
}

template<typename T>
void log(std::ostringstream &os, const T &t) {
  os << t;
}

template<typename T, typename ... Args>
void log(std::ostringstream &os, const T &t, const Args &... args) {
  os << t;
  cc::log<Args...>(os, args...);
}

template<typename T, typename ... Args>
void log(cc::LoggerProxy<T> &logger, const char *file, uint32_t lineno,
    const char *function, const Args &... args) {
  std::ostringstream os;

  os << file << ":" << lineno << "(" << function << ") ";

  cc::log<Args...>(os, args...);

  logger << os.str() << cc::endl;
}

#define LOGGER_TRACE(...) {                                                \
if (cc::Logger<cc::LogTrace>::isLevelOn())                                 \
{                                                                          \
constexpr const char* basename(cc::Common::basename(__FILE__));            \
cc::log<cc::LogTrace>                                                      \
(cc::trace, basename,                                                      \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_DEBUG(...) {                                                \
if (cc::Logger<cc::LogDebug>::isLevelOn())                                 \
{                                                                          \
constexpr const char* basename(cc::Common::basename(__FILE__));            \
cc::log<cc::LogDebug>                                                      \
(cc::debug, basename,                                                      \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_INFO(...) {                                                 \
if (cc::Logger<cc::LogInfo>::isLevelOn())                                  \
{                                                                          \
constexpr const char* basename(cc::Common::basename(__FILE__));            \
cc::log<cc::LogInfo>                                                       \
(cc::info, basename,                                                       \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_WARN(...) {                                                 \
if (cc::Logger<cc::LogWarn>::isLevelOn())                                  \
{                                                                          \
constexpr const char* basename(cc::Common::basename(__FILE__));            \
cc::log<cc::LogWarn>                                                       \
(cc::warn, basename,                                                       \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_ERROR(...) {                                                \
if (cc::Logger<cc::LogError>::isLevelOn())                                 \
{                                                                          \
constexpr const char* basename(cc::Common::basename(__FILE__));            \
cc::log<cc::LogError>                                                      \
(cc::error, basename,                                                      \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

} // ns cc

#endif /* _LOG_H */
