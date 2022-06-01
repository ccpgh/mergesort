//
// sort.h
//

#ifndef _SORT_H
#define _SORT_H

#include <iostream>
#include <sstream>
#include <deque>
#include <cassert>

#include "common.h"

namespace cc {

class Sort {

public:
  static inline std::string dump(const char **buffer, size_t size) {
    std::ostringstream os;
    os << "length: " << size << " {";

    for (size_t i(0); i < size; i++) {
      os << i;

      //os << " [";

      os << " \"" << display(buffer[i]) << "\"";

      if (cc::Logger < cc::LogDebug > ::isLevelOn()) {
        os << "(" << (static_cast<void*>(&buffer[i])) << "/"
            << (static_cast<const void*>(buffer[i])) << ")";
      }

      //os << "]";

      os << " ";
    }

    os << "}";
    return os.str();
  }

  enum OVERFLOW_TYPE {
    OVERFLOW_TYPE_NONE, OVERFLOW_TYPE_LHS
  };

  static OVERFLOW_TYPE overflow(const std::deque<const char*> &overflow_lhs,
      const std::deque<const char*> &overflow_rhs) {

    if (!overflow_lhs.empty()) {
      LOGGER_TRACE("case: lhs overflow");
      return OVERFLOW_TYPE_LHS;
    }

    LOGGER_TRACE("case: no overflow");
    return OVERFLOW_TYPE_NONE;
  }

  static void sort(const char **buffer, size_t size, size_t depth,
      const char *desc) {
    LOGGER_TRACE("called sort desc: ", desc, " depth: ", depth, " size: ",
        size);

    if (size <= 1) {
      LOGGER_DEBUG("sorting 1 element");
      return;
    }

    if (size == 2) {
      LOGGER_DEBUG("sorting 2 elements");

      if (strcmp(buffer[0], buffer[1]) > 0) {
        const char *placeholder = buffer[0];
        buffer[0] = buffer[1];
        buffer[1] = placeholder;
      }
      return;
    }

    size_t pivot(size / 2);

    // lhs
    const char **lhs_start(buffer);
    const size_t lhs_size(pivot);

    // rhs
    const char **rhs_start(buffer + pivot);
    const size_t rhs_size(size - pivot);

    // sort
    LOGGER_TRACE("calling sort lhs: length: ", lhs_size);
    sort(lhs_start, lhs_size, depth + 1, "left");

    LOGGER_TRACE("calling sort rhs: length: ", rhs_size);
    sort(rhs_start, rhs_size, depth + 1, "right");

    // dump
    LOGGER_TRACE("lhs: ", cc::Sort::dump(lhs_start, lhs_size));
    LOGGER_TRACE("rhs: ", cc::Sort::dump(rhs_start, rhs_size));

    merge(lhs_start, lhs_size, rhs_start, rhs_size, depth);

    LOGGER_TRACE("merged:", cc::Sort::dump(buffer, size));
  }

  static inline void merge(const char **lhs_start, size_t lhs_size,
      const char **rhs_start, size_t rhs_size, size_t depth) {

    LOGGER_DEBUG("merge depth: ", depth);

    std::deque<const char*> lhs_overflow;
    std::deque<const char*> rhs_overflow;

    auto lhs_source(lhs_start);
    auto lhs_limit(lhs_start + lhs_size);
    auto rhs_source(rhs_start);
    auto rhs_limit(rhs_start + rhs_size);
    auto target(lhs_start);

    for (size_t index(0); index < (lhs_size + rhs_size); index++, target++) {

      LOGGER_DEBUG("lhs depth: ", depth, " lhs_overflow size ",
          lhs_overflow.size(), " loop: ", index, " lhs_source: ",
          static_cast<const void*>(lhs_source), " rhs_source: ",
          static_cast<const void*>(rhs_source), " ",
          cc::Sort::dump(lhs_start, lhs_size));

      LOGGER_DEBUG("rhs depth: ", depth, " rhs_overflow size ",
          rhs_overflow.size(), " loop: ", index, " lhs_source: ",
          static_cast<const void*>(lhs_source), " rhs_source: ",
          static_cast<const void*>(rhs_source), " ",
          cc::Sort::dump(rhs_start, rhs_size));

      switch (overflow(lhs_overflow, rhs_overflow)) {

      case OVERFLOW_TYPE_LHS: {
        LOGGER_DEBUG("case OVERFLOW_TYPE_LHS depth: ", depth);
        mergeOverflowLHS(lhs_overflow, (lhs_source < lhs_limit), lhs_source,
            lhs_size, (rhs_source < rhs_limit), rhs_source, rhs_size, target,
            depth, index, (index < lhs_size ? lhs_overflow : rhs_overflow));
      }
        break;

      case OVERFLOW_TYPE_NONE: {
        LOGGER_DEBUG("case OVERFLOW_TYPE_NONE depth: ", depth);
        mergeOverflowNone((lhs_source < lhs_limit), lhs_source, lhs_size,
            (rhs_source < rhs_limit), rhs_source, rhs_size, target, depth,
            index, (index < lhs_size ? lhs_overflow : rhs_overflow));
      }
        break;

      }
    }
  }

  static inline void mergeOverflowLHS(std::deque<const char*> &source_overflow,
      bool lhs_comparator, const char **&lhs_source, size_t lhs_size,
      bool rhs_comparator, const char **&rhs_source, size_t rhs_size,
      const char **&target, size_t depth, size_t index,
      std::deque<const char*> &overflow) {

    if (rhs_comparator) {
      LOGGER_DEBUG("comparing lhs-overflow|rhs \"", source_overflow.front(),
          "\" (", (static_cast<const void*>(source_overflow.front())),
          ") to \"", *rhs_source, "\" (",
          (static_cast<const void*>(*rhs_source)), ") \"");

      if (strcmp(source_overflow.front(), *rhs_source) > 0) {
        LOGGER_DEBUG("source rhs");
        write(rhs_source, target, index, overflow);
        rhs_source++;
        if (index < lhs_size) {
          lhs_source++;
        }
        LOGGER_DEBUG("advanced source pointer to rhs_source: ",
            static_cast<void*>(rhs_source));
      } else {
        LOGGER_DEBUG("source source_overflow");
        write(source_overflow, target, index, overflow);
        LOGGER_DEBUG("pop_front source_overflow");
        source_overflow.pop_front();
        if (index < lhs_size) {
          lhs_source++;
        }
      }
    } else {

      LOGGER_DEBUG("source source_overflow");
      write(source_overflow, target, index, overflow);
      LOGGER_DEBUG("pop_front source_overflow");
      source_overflow.pop_front();
      if (index < lhs_size) {
        lhs_source++;
      }
    }
  }

  static inline void mergeOverflowNone(bool lhs_comparator,
      const char **&lhs_source, size_t lhs_size, bool rhs_comparator,
      const char **&rhs_source, size_t rhs_size, const char **&target,
      size_t depth, size_t index, std::deque<const char*> &overflow) {

    if (lhs_comparator && rhs_comparator) {

      LOGGER_DEBUG("comparing lhs|rhs \"", *lhs_source, "\" (",
          (static_cast<const void*>(*lhs_source)), ") to \"", *rhs_source,
          "\" (", (static_cast<const void*>(*rhs_source)), ") \"");

      if (strcmp(*lhs_source, *rhs_source) > 0) {
        LOGGER_DEBUG("source rhs");
        write(rhs_source, target, index, overflow);
        lhs_source++;
        rhs_source++;
        LOGGER_DEBUG("advanced source pointer to lhs_source: ",
            static_cast<void*>(lhs_source), " rhs_source: ",
            static_cast<void*>(rhs_source));
      } else {
        LOGGER_DEBUG("source lhs");
        write(lhs_source, target, index, overflow);
        lhs_source++;
        LOGGER_DEBUG("advanced source pointer to lhs_source: ",
            static_cast<void*>(lhs_source), " rhs_source: ",
            static_cast<void*>(rhs_source));
      }
    } else if (lhs_comparator) {
      LOGGER_ERROR("source lhs ONLY");
      lhs_source++;
      LOGGER_DEBUG("advanced source pointer to lhs_source: ",
          static_cast<void*>(lhs_source), " rhs_source: ",
          static_cast<void*>(rhs_source));
    } else if (rhs_comparator) {
      LOGGER_DEBUG("source rhs ONLY");
      rhs_source++;
      LOGGER_DEBUG("advanced source pointer to lhs_source: ",
          static_cast<void*>(lhs_source), " rhs_source: ",
          static_cast<void*>(rhs_source));
    } else {
      assert(
          0
              && "should NEVER get here - loops should be exhansusted at the same point lhs_comparator/lhs_comparator hit false");
    }
  }

  static inline void write(std::deque<const char*> &source,
      const char **&target, size_t index, std::deque<const char*> &overflow) {
    if (source.front() != *target) {
      if (*target) {
        LOGGER_DEBUG("overflowing target before write \"", display(*target),
            "\"");
        overflow.push_back(*target);
      }
      LOGGER_DEBUG("set index ", index, " to \"", source.front(), "\"");
      *target = source.front();
    } else {
      LOGGER_DEBUG("skip index ", index, " as slready set to \"",
          display(*target), "\"");
    }
  }

  static inline void write(const char **&source, const char **&target,
      size_t index, std::deque<const char*> &overflow) {
    if (*source != *target) {
      if (*target) {
        LOGGER_DEBUG("overflowing target before write \"", display(*target),
            "\"");
        overflow.push_back(*target);
      }
      LOGGER_DEBUG("set index ", index, " to \"", display(*source), "\"");
      *target = *source;
      LOGGER_DEBUG("set source (", static_cast<void*>(source), ") to NULL");
      *source = static_cast<char*>(0);
    } else {
      LOGGER_DEBUG("skip index ", index, " as slready set to \"",
          display(*target), "\"");
    }
  }

  static inline const char* display(const char *value) {
    if (!value) {
      return "NULL";
    }

    return value;
  }

private:
  Sort() = delete;

};

} // ns cc

#endif /* _SORT_H */

