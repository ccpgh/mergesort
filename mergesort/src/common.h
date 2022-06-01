//
// common.h
//

#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>

#include <chrono>

namespace cc {

class Common {

public:

  static inline std::string ltrim(const std::string &original) {
    std::string copy(original);

    copy.erase(copy.begin(), std::find_if(copy.begin(), copy.end(), [](char c) {
      return !std::isspace(c);
    }));

    return copy;
  }

  static inline std::string rtrim(const std::string &original) {
    std::string copy(original);

    copy.erase(std::find_if(copy.rbegin(), copy.rend(), [](char c) {
      return !std::isspace(c);
    }).base(), copy.end());

    return copy;
  }

  static inline std::string trim(const std::string &s) {
    return ltrim(rtrim(s));
  }

  static inline std::string lowercase(const std::string &original) {
    std::string copy(original);

    std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

    return copy;
  }

  static inline void lowercase(std::string &original) {
    std::transform(original.begin(), original.end(), original.begin(),
        ::tolower);
  }

  static inline bool isEnvValue(const std::string &name,
      const std::string &value) {
    return envValue(name) == value;
  }

  static inline std::string envValue(const std::string &name) {
    char *value { std::getenv(name.c_str()) };

    if (value == nullptr || strlen(value) == 0) {
      return "";
    }
    return lowercase(trim(value));
  }

  inline static std::string ts() {
    auto ts { std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now()) };

    std::ostringstream os;
    os << std::put_time(std::localtime(&ts), "%H:%M:%S"); // "%Y%m%d %H:%M:%S"

    return os.str();
  }

  inline static long long ts_EPOCH_MS() {
    static const auto epoch(std::chrono::system_clock::from_time_t(0));

    return std::chrono::duration_cast < std::chrono::milliseconds
        > (std::chrono::system_clock::now() - epoch).count();
  }

  inline static long long ts_EPOCH_US() {
    static const auto epoch(std::chrono::system_clock::from_time_t(0));

    return std::chrono::duration_cast < std::chrono::microseconds
        > (std::chrono::system_clock::now() - epoch).count();
  }

  inline static time_t time_t_SECONDS() {
    return std::time(NULL);
  }

  static constexpr char path_separator { '/' }; // NYI

  static constexpr const char* str_end(const char *s) {
    return *s ? str_end(s + 1) : s;
  }

  static constexpr bool str_slant(const char *s) {
    return *s == path_separator ? true : (*s ? str_slant(s + 1) : false);
  }

  static constexpr const char* r_slant(const char *s) {
    return *s == path_separator ? (s + 1) : r_slant(s - 1);
  }

  static constexpr const char* basename(const char *s) {
    return str_slant(s) ? r_slant(str_end(s)) : s;
  }

  static void load(const char **ss, size_t size) {

    if (!size) {
      return;
    }

    if (size > 1000) {
      size = 1000;
      ;
    }

    *(ss++) = "worry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "letters";
    if (!(--size)) {
      return;
    }

    *(ss++) = "print";
    if (!(--size)) {
      return;
    }

    *(ss++) = "distinct";
    if (!(--size)) {
      return;
    }

    *(ss++) = "scare";
    if (!(--size)) {
      return;
    }

    *(ss++) = "political";
    if (!(--size)) {
      return;
    }

    *(ss++) = "obey";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dynamic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wander";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pause";
    if (!(--size)) {
      return;
    }

    *(ss++) = "repulsive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stage";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sound";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pick";
    if (!(--size)) {
      return;
    }

    *(ss++) = "detailed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "apathetic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "discovery";
    if (!(--size)) {
      return;
    }

    *(ss++) = "apparatus";
    if (!(--size)) {
      return;
    }

    *(ss++) = "grade";
    if (!(--size)) {
      return;
    }

    *(ss++) = "freezing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "comparison";
    if (!(--size)) {
      return;
    }

    *(ss++) = "glorious";
    if (!(--size)) {
      return;
    }

    *(ss++) = "table";
    if (!(--size)) {
      return;
    }

    *(ss++) = "beneficial";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trucks";
    if (!(--size)) {
      return;
    }

    *(ss++) = "territory";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pot";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "incredible";
    if (!(--size)) {
      return;
    }

    *(ss++) = "excellent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "count";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shiny";
    if (!(--size)) {
      return;
    }

    *(ss++) = "savory";
    if (!(--size)) {
      return;
    }

    *(ss++) = "daffy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "songs";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wave";
    if (!(--size)) {
      return;
    }

    *(ss++) = "zebra";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unaccountable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lopsided";
    if (!(--size)) {
      return;
    }

    *(ss++) = "relation";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trust";
    if (!(--size)) {
      return;
    }

    *(ss++) = "explain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "quartz";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hands";
    if (!(--size)) {
      return;
    }

    *(ss++) = "idiotic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "increase";
    if (!(--size)) {
      return;
    }

    *(ss++) = "honey";
    if (!(--size)) {
      return;
    }

    *(ss++) = "label";
    if (!(--size)) {
      return;
    }

    *(ss++) = "zippy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shut";
    if (!(--size)) {
      return;
    }

    *(ss++) = "delicate";
    if (!(--size)) {
      return;
    }

    *(ss++) = "plain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "seed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ask";
    if (!(--size)) {
      return;
    }

    *(ss++) = "show";
    if (!(--size)) {
      return;
    }

    *(ss++) = "crime";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ruin";
    if (!(--size)) {
      return;
    }

    *(ss++) = "annoy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "volcano";
    if (!(--size)) {
      return;
    }

    *(ss++) = "relax";
    if (!(--size)) {
      return;
    }

    *(ss++) = "large";
    if (!(--size)) {
      return;
    }

    *(ss++) = "crack";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hook";
    if (!(--size)) {
      return;
    }

    *(ss++) = "test";
    if (!(--size)) {
      return;
    }

    *(ss++) = "owe";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shade";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "didactic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "brush";
    if (!(--size)) {
      return;
    }

    *(ss++) = "toothsome";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "blue";
    if (!(--size)) {
      return;
    }

    *(ss++) = "damaged";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hug";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wasteful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "polite";
    if (!(--size)) {
      return;
    }

    *(ss++) = "panoramic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ugly";
    if (!(--size)) {
      return;
    }

    *(ss++) = "match";
    if (!(--size)) {
      return;
    }

    *(ss++) = "repeat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "acoustics";
    if (!(--size)) {
      return;
    }

    *(ss++) = "messy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "business";
    if (!(--size)) {
      return;
    }

    *(ss++) = "circle";
    if (!(--size)) {
      return;
    }

    *(ss++) = "practise";
    if (!(--size)) {
      return;
    }

    *(ss++) = "program";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fearless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fancy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "proud";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bird";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ratty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "nutritious";
    if (!(--size)) {
      return;
    }

    *(ss++) = "automatic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "daughter";
    if (!(--size)) {
      return;
    }

    *(ss++) = "north";
    if (!(--size)) {
      return;
    }

    *(ss++) = "phone";
    if (!(--size)) {
      return;
    }

    *(ss++) = "expect";
    if (!(--size)) {
      return;
    }

    *(ss++) = "son";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flashy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "end";
    if (!(--size)) {
      return;
    }

    *(ss++) = "offer";
    if (!(--size)) {
      return;
    }

    *(ss++) = "brawny";
    if (!(--size)) {
      return;
    }

    *(ss++) = "round";
    if (!(--size)) {
      return;
    }

    *(ss++) = "popcorn";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "perpetual";
    if (!(--size)) {
      return;
    }

    *(ss++) = "visitor";
    if (!(--size)) {
      return;
    }

    *(ss++) = "madly";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ear";
    if (!(--size)) {
      return;
    }

    *(ss++) = "memory";
    if (!(--size)) {
      return;
    }

    *(ss++) = "plug";
    if (!(--size)) {
      return;
    }

    *(ss++) = "remarkable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dispensable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "well-made";
    if (!(--size)) {
      return;
    }

    *(ss++) = "present";
    if (!(--size)) {
      return;
    }

    *(ss++) = "aberrant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "produce";
    if (!(--size)) {
      return;
    }

    *(ss++) = "kitty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "berry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "employ";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bruise";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fade";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cautious";
    if (!(--size)) {
      return;
    }

    *(ss++) = "longing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "allow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "many";
    if (!(--size)) {
      return;
    }

    *(ss++) = "songs";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cut";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rabid";
    if (!(--size)) {
      return;
    }

    *(ss++) = "picayune";
    if (!(--size)) {
      return;
    }

    *(ss++) = "things";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "comb";
    if (!(--size)) {
      return;
    }

    *(ss++) = "yellow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "correct";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frightening";
    if (!(--size)) {
      return;
    }

    *(ss++) = "float";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hand";
    if (!(--size)) {
      return;
    }

    *(ss++) = "innocent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "handy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "suggest";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rural";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fascinated";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unpack";
    if (!(--size)) {
      return;
    }

    *(ss++) = "queen";
    if (!(--size)) {
      return;
    }

    *(ss++) = "alcoholic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "open";
    if (!(--size)) {
      return;
    }

    *(ss++) = "resonant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "groan";
    if (!(--size)) {
      return;
    }

    *(ss++) = "soap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "yellow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fancy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "light";
    if (!(--size)) {
      return;
    }

    *(ss++) = "vast";
    if (!(--size)) {
      return;
    }

    *(ss++) = "charge";
    if (!(--size)) {
      return;
    }

    *(ss++) = "kittens";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pull";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wakeful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "part";
    if (!(--size)) {
      return;
    }

    *(ss++) = "silent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "mellow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "quiet";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wonderful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "chilly";
    if (!(--size)) {
      return;
    }

    *(ss++) = "warlike";
    if (!(--size)) {
      return;
    }

    *(ss++) = "crow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "plastic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trousers";
    if (!(--size)) {
      return;
    }

    *(ss++) = "nippy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "vast";
    if (!(--size)) {
      return;
    }

    *(ss++) = "strange";
    if (!(--size)) {
      return;
    }

    *(ss++) = "obtain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wail";
    if (!(--size)) {
      return;
    }

    *(ss++) = "offbeat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "clever";
    if (!(--size)) {
      return;
    }

    *(ss++) = "calendar";
    if (!(--size)) {
      return;
    }

    *(ss++) = "magical";
    if (!(--size)) {
      return;
    }

    *(ss++) = "neck";
    if (!(--size)) {
      return;
    }

    *(ss++) = "act";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dog";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lace";
    if (!(--size)) {
      return;
    }

    *(ss++) = "help";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shallow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "animated";
    if (!(--size)) {
      return;
    }

    *(ss++) = "knotty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "amazing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "governor";
    if (!(--size)) {
      return;
    }

    *(ss++) = "army";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fade";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cows";
    if (!(--size)) {
      return;
    }

    *(ss++) = "interest";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unbiased";
    if (!(--size)) {
      return;
    }

    *(ss++) = "like";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sore";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fog";
    if (!(--size)) {
      return;
    }

    *(ss++) = "laugh";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fax";
    if (!(--size)) {
      return;
    }

    *(ss++) = "kittens";
    if (!(--size)) {
      return;
    }

    *(ss++) = "drawer";
    if (!(--size)) {
      return;
    }

    *(ss++) = "chicken";
    if (!(--size)) {
      return;
    }

    *(ss++) = "nimble";
    if (!(--size)) {
      return;
    }

    *(ss++) = "push";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rescue";
    if (!(--size)) {
      return;
    }

    *(ss++) = "invite";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dirty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "graceful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "thing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ubiquitous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "skirt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "canvas";
    if (!(--size)) {
      return;
    }

    *(ss++) = "uppity";
    if (!(--size)) {
      return;
    }

    *(ss++) = "alert";
    if (!(--size)) {
      return;
    }

    *(ss++) = "handy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "steel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pets";
    if (!(--size)) {
      return;
    }

    *(ss++) = "gaze";
    if (!(--size)) {
      return;
    }

    *(ss++) = "subdued";
    if (!(--size)) {
      return;
    }

    *(ss++) = "weather";
    if (!(--size)) {
      return;
    }

    *(ss++) = "petite";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sink";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stitch";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stingy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "soap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bomb";
    if (!(--size)) {
      return;
    }

    *(ss++) = "materialistic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "clever";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hypnotic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "thought";
    if (!(--size)) {
      return;
    }

    *(ss++) = "story";
    if (!(--size)) {
      return;
    }

    *(ss++) = "year";
    if (!(--size)) {
      return;
    }

    *(ss++) = "jelly";
    if (!(--size)) {
      return;
    }

    *(ss++) = "questionable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "imperfect";
    if (!(--size)) {
      return;
    }

    *(ss++) = "suit";
    if (!(--size)) {
      return;
    }

    *(ss++) = "knit";
    if (!(--size)) {
      return;
    }

    *(ss++) = "attack";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lunch";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unequaled";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pipe";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sister";
    if (!(--size)) {
      return;
    }

    *(ss++) = "available";
    if (!(--size)) {
      return;
    }

    *(ss++) = "turn";
    if (!(--size)) {
      return;
    }

    *(ss++) = "mountainous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "nutty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "borrow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "level";
    if (!(--size)) {
      return;
    }

    *(ss++) = "well-off";
    if (!(--size)) {
      return;
    }

    *(ss++) = "blind";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pray";
    if (!(--size)) {
      return;
    }

    *(ss++) = "disagree";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wise";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shrug";
    if (!(--size)) {
      return;
    }

    *(ss++) = "head";
    if (!(--size)) {
      return;
    }

    *(ss++) = "babies";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fearless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "basketball";
    if (!(--size)) {
      return;
    }

    *(ss++) = "utopian";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unique";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bucket";
    if (!(--size)) {
      return;
    }

    *(ss++) = "remember";
    if (!(--size)) {
      return;
    }

    *(ss++) = "debt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ray";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wide-eyed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tongue";
    if (!(--size)) {
      return;
    }

    *(ss++) = "habitual";
    if (!(--size)) {
      return;
    }

    *(ss++) = "splendid";
    if (!(--size)) {
      return;
    }

    *(ss++) = "numberless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "recess";
    if (!(--size)) {
      return;
    }

    *(ss++) = "deserted";
    if (!(--size)) {
      return;
    }

    *(ss++) = "diligent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "achiever";
    if (!(--size)) {
      return;
    }

    *(ss++) = "marble";
    if (!(--size)) {
      return;
    }

    *(ss++) = "quack";
    if (!(--size)) {
      return;
    }

    *(ss++) = "name";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sack";
    if (!(--size)) {
      return;
    }

    *(ss++) = "abnormal";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tangible";
    if (!(--size)) {
      return;
    }

    *(ss++) = "guide";
    if (!(--size)) {
      return;
    }

    *(ss++) = "last";
    if (!(--size)) {
      return;
    }

    *(ss++) = "welcome";
    if (!(--size)) {
      return;
    }

    *(ss++) = "berserk";
    if (!(--size)) {
      return;
    }

    *(ss++) = "purple";
    if (!(--size)) {
      return;
    }

    *(ss++) = "numerous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "play";
    if (!(--size)) {
      return;
    }

    *(ss++) = "look";
    if (!(--size)) {
      return;
    }

    *(ss++) = "uneven";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trip";
    if (!(--size)) {
      return;
    }

    *(ss++) = "economic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "enchanted";
    if (!(--size)) {
      return;
    }

    *(ss++) = "discovery";
    if (!(--size)) {
      return;
    }

    *(ss++) = "harbor";
    if (!(--size)) {
      return;
    }

    *(ss++) = "direful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "adventurous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shave";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trade";
    if (!(--size)) {
      return;
    }

    *(ss++) = "imminent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "clammy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "calendar";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bump";
    if (!(--size)) {
      return;
    }

    *(ss++) = "melt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "uninterested";
    if (!(--size)) {
      return;
    }

    *(ss++) = "laughable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unfasten";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tightfisted";
    if (!(--size)) {
      return;
    }

    *(ss++) = "education";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dear";
    if (!(--size)) {
      return;
    }

    *(ss++) = "launch";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bedroom";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sky";
    if (!(--size)) {
      return;
    }

    *(ss++) = "vessel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "spiteful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "adamant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "berserk";
    if (!(--size)) {
      return;
    }

    *(ss++) = "quartz";
    if (!(--size)) {
      return;
    }

    *(ss++) = "moan";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tacky";
    if (!(--size)) {
      return;
    }

    *(ss++) = "better";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "grass";
    if (!(--size)) {
      return;
    }

    *(ss++) = "appear";
    if (!(--size)) {
      return;
    }

    *(ss++) = "extend";
    if (!(--size)) {
      return;
    }

    *(ss++) = "noisy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "used";
    if (!(--size)) {
      return;
    }

    *(ss++) = "deer";
    if (!(--size)) {
      return;
    }

    *(ss++) = "jolly";
    if (!(--size)) {
      return;
    }

    *(ss++) = "whistle";
    if (!(--size)) {
      return;
    }

    *(ss++) = "judge";
    if (!(--size)) {
      return;
    }

    *(ss++) = "guarantee";
    if (!(--size)) {
      return;
    }

    *(ss++) = "march";
    if (!(--size)) {
      return;
    }

    *(ss++) = "living";
    if (!(--size)) {
      return;
    }

    *(ss++) = "position";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tomatoes";
    if (!(--size)) {
      return;
    }

    *(ss++) = "spiteful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cute";
    if (!(--size)) {
      return;
    }

    *(ss++) = "feeble";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trip";
    if (!(--size)) {
      return;
    }

    *(ss++) = "country";
    if (!(--size)) {
      return;
    }

    *(ss++) = "kitty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "replace";
    if (!(--size)) {
      return;
    }

    *(ss++) = "size";
    if (!(--size)) {
      return;
    }

    *(ss++) = "boorish";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tame";
    if (!(--size)) {
      return;
    }

    *(ss++) = "talented";
    if (!(--size)) {
      return;
    }

    *(ss++) = "labored";
    if (!(--size)) {
      return;
    }

    *(ss++) = "drown";
    if (!(--size)) {
      return;
    }

    *(ss++) = "birthday";
    if (!(--size)) {
      return;
    }

    *(ss++) = "reduce";
    if (!(--size)) {
      return;
    }

    *(ss++) = "annoy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "arrogant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "joke";
    if (!(--size)) {
      return;
    }

    *(ss++) = "distinct";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pray";
    if (!(--size)) {
      return;
    }

    *(ss++) = "attempt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "arrest";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bedroom";
    if (!(--size)) {
      return;
    }

    *(ss++) = "roll";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lacking";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bruise";
    if (!(--size)) {
      return;
    }

    *(ss++) = "amusement";
    if (!(--size)) {
      return;
    }

    *(ss++) = "glib";
    if (!(--size)) {
      return;
    }

    *(ss++) = "play";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cannon";
    if (!(--size)) {
      return;
    }

    *(ss++) = "early";
    if (!(--size)) {
      return;
    }

    *(ss++) = "better";
    if (!(--size)) {
      return;
    }

    *(ss++) = "peaceful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "carry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "abortive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cobweb";
    if (!(--size)) {
      return;
    }

    *(ss++) = "homely";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ajar";
    if (!(--size)) {
      return;
    }

    *(ss++) = "evasive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "striped";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trashy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stay";
    if (!(--size)) {
      return;
    }

    *(ss++) = "education";
    if (!(--size)) {
      return;
    }

    *(ss++) = "call";
    if (!(--size)) {
      return;
    }

    *(ss++) = "possible";
    if (!(--size)) {
      return;
    }

    *(ss++) = "passenger";
    if (!(--size)) {
      return;
    }

    *(ss++) = "jail";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fish";
    if (!(--size)) {
      return;
    }

    *(ss++) = "beds";
    if (!(--size)) {
      return;
    }

    *(ss++) = "windy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "condemned";
    if (!(--size)) {
      return;
    }

    *(ss++) = "interrupt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "jam";
    if (!(--size)) {
      return;
    }

    *(ss++) = "mindless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "water";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wistful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "warn";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hollow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stage";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fool";
    if (!(--size)) {
      return;
    }

    *(ss++) = "church";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sound";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tall";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sand";
    if (!(--size)) {
      return;
    }

    *(ss++) = "filthy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bathe";
    if (!(--size)) {
      return;
    }

    *(ss++) = "staking";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ground";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rebel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "likeable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "silk";
    if (!(--size)) {
      return;
    }

    *(ss++) = "voiceless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "soap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bomb";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lazy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "brainy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "development";
    if (!(--size)) {
      return;
    }

    *(ss++) = "worry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "deafening";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pathetic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "clammy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "delight";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cover";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shape";
    if (!(--size)) {
      return;
    }

    *(ss++) = "practise";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stage";
    if (!(--size)) {
      return;
    }

    *(ss++) = "colour";
    if (!(--size)) {
      return;
    }

    *(ss++) = "steep";
    if (!(--size)) {
      return;
    }

    *(ss++) = "charming";
    if (!(--size)) {
      return;
    }

    *(ss++) = "help";
    if (!(--size)) {
      return;
    }

    *(ss++) = "guarantee";
    if (!(--size)) {
      return;
    }

    *(ss++) = "boorish";
    if (!(--size)) {
      return;
    }

    *(ss++) = "quince";
    if (!(--size)) {
      return;
    }

    *(ss++) = "zoo";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hobbies";
    if (!(--size)) {
      return;
    }

    *(ss++) = "witty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "imperfect";
    if (!(--size)) {
      return;
    }

    *(ss++) = "curtain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "thankful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "well-groomed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "route";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tumble";
    if (!(--size)) {
      return;
    }

    *(ss++) = "square";
    if (!(--size)) {
      return;
    }

    *(ss++) = "right";
    if (!(--size)) {
      return;
    }

    *(ss++) = "feeling";
    if (!(--size)) {
      return;
    }

    *(ss++) = "roll";
    if (!(--size)) {
      return;
    }

    *(ss++) = "yummy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sniff";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sidewalk";
    if (!(--size)) {
      return;
    }

    *(ss++) = "program";
    if (!(--size)) {
      return;
    }

    *(ss++) = "avoid";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bored";
    if (!(--size)) {
      return;
    }

    *(ss++) = "square";
    if (!(--size)) {
      return;
    }

    *(ss++) = "instruct";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stamp";
    if (!(--size)) {
      return;
    }

    *(ss++) = "easy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "big";
    if (!(--size)) {
      return;
    }

    *(ss++) = "chase";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pie";
    if (!(--size)) {
      return;
    }

    *(ss++) = "piquant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flesh";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trade";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pleasant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "harass";
    if (!(--size)) {
      return;
    }

    *(ss++) = "skip";
    if (!(--size)) {
      return;
    }

    *(ss++) = "play";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hole";
    if (!(--size)) {
      return;
    }

    *(ss++) = "naive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "thirsty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rest";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tasteless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "exultant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "attract";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sock";
    if (!(--size)) {
      return;
    }

    *(ss++) = "multiply";
    if (!(--size)) {
      return;
    }

    *(ss++) = "attack";
    if (!(--size)) {
      return;
    }

    *(ss++) = "apathetic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "half";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pricey";
    if (!(--size)) {
      return;
    }

    *(ss++) = "witty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "science";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pest";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stretch";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shut";
    if (!(--size)) {
      return;
    }

    *(ss++) = "parched";
    if (!(--size)) {
      return;
    }

    *(ss++) = "slim";
    if (!(--size)) {
      return;
    }

    *(ss++) = "record";
    if (!(--size)) {
      return;
    }

    *(ss++) = "mountain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "thumb";
    if (!(--size)) {
      return;
    }

    *(ss++) = "even";
    if (!(--size)) {
      return;
    }

    *(ss++) = "momentous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "present";
    if (!(--size)) {
      return;
    }

    *(ss++) = "desk";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tired";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shake";
    if (!(--size)) {
      return;
    }

    *(ss++) = "free";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sand";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bedroom";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fragile";
    if (!(--size)) {
      return;
    }

    *(ss++) = "income";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sharp";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bubble";
    if (!(--size)) {
      return;
    }

    *(ss++) = "list";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hellish";
    if (!(--size)) {
      return;
    }

    *(ss++) = "gratis";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shirt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tooth";
    if (!(--size)) {
      return;
    }

    *(ss++) = "glossy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "invincible";
    if (!(--size)) {
      return;
    }

    *(ss++) = "branch";
    if (!(--size)) {
      return;
    }

    *(ss++) = "elderly";
    if (!(--size)) {
      return;
    }

    *(ss++) = "soap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "blot";
    if (!(--size)) {
      return;
    }

    *(ss++) = "boiling";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ritzy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "abundant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "upset";
    if (!(--size)) {
      return;
    }

    *(ss++) = "axiomatic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hissing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lopsided";
    if (!(--size)) {
      return;
    }

    *(ss++) = "repair";
    if (!(--size)) {
      return;
    }

    *(ss++) = "squeak";
    if (!(--size)) {
      return;
    }

    *(ss++) = "zephyr";
    if (!(--size)) {
      return;
    }

    *(ss++) = "supreme";
    if (!(--size)) {
      return;
    }

    *(ss++) = "listen";
    if (!(--size)) {
      return;
    }

    *(ss++) = "decisive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "excellent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "committee";
    if (!(--size)) {
      return;
    }

    *(ss++) = "helpful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "weary";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stick";
    if (!(--size)) {
      return;
    }

    *(ss++) = "defective";
    if (!(--size)) {
      return;
    }

    *(ss++) = "roof";
    if (!(--size)) {
      return;
    }

    *(ss++) = "humorous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "badge";
    if (!(--size)) {
      return;
    }

    *(ss++) = "angle";
    if (!(--size)) {
      return;
    }

    *(ss++) = "far-flung";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frightened";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unite";
    if (!(--size)) {
      return;
    }

    *(ss++) = "probable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "load";
    if (!(--size)) {
      return;
    }

    *(ss++) = "continue";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hideous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "scent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "abaft";
    if (!(--size)) {
      return;
    }

    *(ss++) = "post";
    if (!(--size)) {
      return;
    }

    *(ss++) = "aberrant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "phobic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "jump";
    if (!(--size)) {
      return;
    }

    *(ss++) = "standing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rebel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "birthday";
    if (!(--size)) {
      return;
    }

    *(ss++) = "request";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ossified";
    if (!(--size)) {
      return;
    }

    *(ss++) = "smash";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stir";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trick";
    if (!(--size)) {
      return;
    }

    *(ss++) = "miscreant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "spooky";
    if (!(--size)) {
      return;
    }

    *(ss++) = "instruct";
    if (!(--size)) {
      return;
    }

    *(ss++) = "smile";
    if (!(--size)) {
      return;
    }

    *(ss++) = "better";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sound";
    if (!(--size)) {
      return;
    }

    *(ss++) = "impartial";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dreary";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rebel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "channel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "beam";
    if (!(--size)) {
      return;
    }

    *(ss++) = "male";
    if (!(--size)) {
      return;
    }

    *(ss++) = "preach";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bit";
    if (!(--size)) {
      return;
    }

    *(ss++) = "white";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "nail";
    if (!(--size)) {
      return;
    }

    *(ss++) = "measure";
    if (!(--size)) {
      return;
    }

    *(ss++) = "influence";
    if (!(--size)) {
      return;
    }

    *(ss++) = "decay";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trust";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wacky";
    if (!(--size)) {
      return;
    }

    *(ss++) = "momentous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "number";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hover";
    if (!(--size)) {
      return;
    }

    *(ss++) = "beds";
    if (!(--size)) {
      return;
    }

    *(ss++) = "skirt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "aggressive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "grateful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rustic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "animated";
    if (!(--size)) {
      return;
    }

    *(ss++) = "milk";
    if (!(--size)) {
      return;
    }

    *(ss++) = "daughter";
    if (!(--size)) {
      return;
    }

    *(ss++) = "productive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "food";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frequent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fearless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "light";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cruel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "church";
    if (!(--size)) {
      return;
    }

    *(ss++) = "handy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "redundant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "decay";
    if (!(--size)) {
      return;
    }

    *(ss++) = "object";
    if (!(--size)) {
      return;
    }

    *(ss++) = "reign";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ball";
    if (!(--size)) {
      return;
    }

    *(ss++) = "basin";
    if (!(--size)) {
      return;
    }

    *(ss++) = "war";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ubiquitous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "summer";
    if (!(--size)) {
      return;
    }

    *(ss++) = "exclusive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "oatmeal";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "puffy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "mature";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cute";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shock";
    if (!(--size)) {
      return;
    }

    *(ss++) = "illegal";
    if (!(--size)) {
      return;
    }

    *(ss++) = "apathetic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tested";
    if (!(--size)) {
      return;
    }

    *(ss++) = "weight";
    if (!(--size)) {
      return;
    }

    *(ss++) = "kick";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ritzy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stranger";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bleach";
    if (!(--size)) {
      return;
    }

    *(ss++) = "possible";
    if (!(--size)) {
      return;
    }

    *(ss++) = "quill";
    if (!(--size)) {
      return;
    }

    *(ss++) = "statement";
    if (!(--size)) {
      return;
    }

    *(ss++) = "file";
    if (!(--size)) {
      return;
    }

    *(ss++) = "chubby";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cut";
    if (!(--size)) {
      return;
    }

    *(ss++) = "passenger";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ritzy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "normal";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trucks";
    if (!(--size)) {
      return;
    }

    *(ss++) = "curtain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "glue";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flash";
    if (!(--size)) {
      return;
    }

    *(ss++) = "delightful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "utter";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hill";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fumbling";
    if (!(--size)) {
      return;
    }

    *(ss++) = "gamy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pull";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frightened";
    if (!(--size)) {
      return;
    }

    *(ss++) = "peace";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trip";
    if (!(--size)) {
      return;
    }

    *(ss++) = "troubled";
    if (!(--size)) {
      return;
    }

    *(ss++) = "vein";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frightening";
    if (!(--size)) {
      return;
    }

    *(ss++) = "prevent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "secret";
    if (!(--size)) {
      return;
    }

    *(ss++) = "smile";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bells";
    if (!(--size)) {
      return;
    }

    *(ss++) = "yummy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "colorful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "quickest";
    if (!(--size)) {
      return;
    }

    *(ss++) = "two";
    if (!(--size)) {
      return;
    }

    *(ss++) = "offer";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tenuous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "acid";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "coal";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fuzzy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "descriptive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "invincible";
    if (!(--size)) {
      return;
    }

    *(ss++) = "butter";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frequent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flowers";
    if (!(--size)) {
      return;
    }

    *(ss++) = "grin";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frail";
    if (!(--size)) {
      return;
    }

    *(ss++) = "halting";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sticks";
    if (!(--size)) {
      return;
    }

    *(ss++) = "giant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "knock";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stare";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tangible";
    if (!(--size)) {
      return;
    }

    *(ss++) = "absorbing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "infamous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hill";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pump";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wheel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "disagreeable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "weary";
    if (!(--size)) {
      return;
    }

    *(ss++) = "agree";
    if (!(--size)) {
      return;
    }

    *(ss++) = "grouchy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "heat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "faulty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lunchroom";
    if (!(--size)) {
      return;
    }

    *(ss++) = "juice";
    if (!(--size)) {
      return;
    }

    *(ss++) = "knit";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "glue";
    if (!(--size)) {
      return;
    }

    *(ss++) = "disapprove";
    if (!(--size)) {
      return;
    }

    *(ss++) = "toy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "post";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "supply";
    if (!(--size)) {
      return;
    }

    *(ss++) = "vague";
    if (!(--size)) {
      return;
    }

    *(ss++) = "mate";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cloistered";
    if (!(--size)) {
      return;
    }

    *(ss++) = "raise";
    if (!(--size)) {
      return;
    }

    *(ss++) = "jolly";
    if (!(--size)) {
      return;
    }

    *(ss++) = "substantial";
    if (!(--size)) {
      return;
    }

    *(ss++) = "steer";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sloppy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rub";
    if (!(--size)) {
      return;
    }

    *(ss++) = "laughable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hurt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "jail";
    if (!(--size)) {
      return;
    }

    *(ss++) = "toes";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cemetery";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rural";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sand";
    if (!(--size)) {
      return;
    }

    *(ss++) = "badge";
    if (!(--size)) {
      return;
    }

    *(ss++) = "scrawny";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pest";
    if (!(--size)) {
      return;
    }

    *(ss++) = "squirrel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "waves";
    if (!(--size)) {
      return;
    }

    *(ss++) = "giraffe";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tendency";
    if (!(--size)) {
      return;
    }

    *(ss++) = "luxuriant";
    if (!(--size)) {
      return;
    }

    *(ss++) = "paltry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tumble";
    if (!(--size)) {
      return;
    }

    *(ss++) = "taste";
    if (!(--size)) {
      return;
    }

    *(ss++) = "highfalutin";
    if (!(--size)) {
      return;
    }

    *(ss++) = "song";
    if (!(--size)) {
      return;
    }

    *(ss++) = "concerned";
    if (!(--size)) {
      return;
    }

    *(ss++) = "appliance";
    if (!(--size)) {
      return;
    }

    *(ss++) = "women";
    if (!(--size)) {
      return;
    }

    *(ss++) = "abhorrent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "disappear";
    if (!(--size)) {
      return;
    }

    *(ss++) = "penitent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "scattered";
    if (!(--size)) {
      return;
    }

    *(ss++) = "force";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stocking";
    if (!(--size)) {
      return;
    }

    *(ss++) = "threatening";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cattle";
    if (!(--size)) {
      return;
    }

    *(ss++) = "past";
    if (!(--size)) {
      return;
    }

    *(ss++) = "disappear";
    if (!(--size)) {
      return;
    }

    *(ss++) = "allow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "innocent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "superb";
    if (!(--size)) {
      return;
    }

    *(ss++) = "clear";
    if (!(--size)) {
      return;
    }

    *(ss++) = "obnoxious";
    if (!(--size)) {
      return;
    }

    *(ss++) = "school";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lunchroom";
    if (!(--size)) {
      return;
    }

    *(ss++) = "slimy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "school";
    if (!(--size)) {
      return;
    }

    *(ss++) = "towering";
    if (!(--size)) {
      return;
    }

    *(ss++) = "light";
    if (!(--size)) {
      return;
    }

    *(ss++) = "skirt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "chicken";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lovely";
    if (!(--size)) {
      return;
    }

    *(ss++) = "produce";
    if (!(--size)) {
      return;
    }

    *(ss++) = "twig";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stimulating";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fixed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wicked";
    if (!(--size)) {
      return;
    }

    *(ss++) = "aftermath";
    if (!(--size)) {
      return;
    }

    *(ss++) = "brown";
    if (!(--size)) {
      return;
    }

    *(ss++) = "typical";
    if (!(--size)) {
      return;
    }

    *(ss++) = "abiding";
    if (!(--size)) {
      return;
    }

    *(ss++) = "utopian";
    if (!(--size)) {
      return;
    }

    *(ss++) = "robin";
    if (!(--size)) {
      return;
    }

    *(ss++) = "silly";
    if (!(--size)) {
      return;
    }

    *(ss++) = "drop";
    if (!(--size)) {
      return;
    }

    *(ss++) = "boil";
    if (!(--size)) {
      return;
    }

    *(ss++) = "noisy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "visitor";
    if (!(--size)) {
      return;
    }

    *(ss++) = "clip";
    if (!(--size)) {
      return;
    }

    *(ss++) = "zany";
    if (!(--size)) {
      return;
    }

    *(ss++) = "scream";
    if (!(--size)) {
      return;
    }

    *(ss++) = "regret";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bridge";
    if (!(--size)) {
      return;
    }

    *(ss++) = "development";
    if (!(--size)) {
      return;
    }

    *(ss++) = "donkey";
    if (!(--size)) {
      return;
    }

    *(ss++) = "horse";
    if (!(--size)) {
      return;
    }

    *(ss++) = "deserted";
    if (!(--size)) {
      return;
    }

    *(ss++) = "telling";
    if (!(--size)) {
      return;
    }

    *(ss++) = "support";
    if (!(--size)) {
      return;
    }

    *(ss++) = "kneel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hope";
    if (!(--size)) {
      return;
    }

    *(ss++) = "thoughtless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "knot";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trashy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fog";
    if (!(--size)) {
      return;
    }

    *(ss++) = "snakes";
    if (!(--size)) {
      return;
    }

    *(ss++) = "repulsive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "elite";
    if (!(--size)) {
      return;
    }

    *(ss++) = "elfin";
    if (!(--size)) {
      return;
    }

    *(ss++) = "warm";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unite";
    if (!(--size)) {
      return;
    }

    *(ss++) = "caption";
    if (!(--size)) {
      return;
    }

    *(ss++) = "repulsive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "groan";
    if (!(--size)) {
      return;
    }

    *(ss++) = "secret";
    if (!(--size)) {
      return;
    }

    *(ss++) = "vigorous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "car";
    if (!(--size)) {
      return;
    }

    *(ss++) = "outgoing";
    if (!(--size)) {
      return;
    }

    *(ss++) = "silent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "detailed";
    if (!(--size)) {
      return;
    }

    *(ss++) = "destroy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "glistening";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hobbies";
    if (!(--size)) {
      return;
    }

    *(ss++) = "itch";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wandering";
    if (!(--size)) {
      return;
    }

    *(ss++) = "creepy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "roof";
    if (!(--size)) {
      return;
    }

    *(ss++) = "loud";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "descriptive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "whispering";
    if (!(--size)) {
      return;
    }

    *(ss++) = "coordinated";
    if (!(--size)) {
      return;
    }

    *(ss++) = "violent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "truculent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "note";
    if (!(--size)) {
      return;
    }

    *(ss++) = "harbor";
    if (!(--size)) {
      return;
    }

    *(ss++) = "machine";
    if (!(--size)) {
      return;
    }

    *(ss++) = "lonely";
    if (!(--size)) {
      return;
    }

    *(ss++) = "replace";
    if (!(--size)) {
      return;
    }

    *(ss++) = "evasive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dream";
    if (!(--size)) {
      return;
    }

    *(ss++) = "gamy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "elite";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ruin";
    if (!(--size)) {
      return;
    }

    *(ss++) = "coach";
    if (!(--size)) {
      return;
    }

    *(ss++) = "selective";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hurried";
    if (!(--size)) {
      return;
    }

    *(ss++) = "attract";
    if (!(--size)) {
      return;
    }

    *(ss++) = "kiss";
    if (!(--size)) {
      return;
    }

    *(ss++) = "scarecrow";
    if (!(--size)) {
      return;
    }

    *(ss++) = "count";
    if (!(--size)) {
      return;
    }

    *(ss++) = "describe";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pull";
    if (!(--size)) {
      return;
    }

    *(ss++) = "gullible";
    if (!(--size)) {
      return;
    }

    *(ss++) = "gaping";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trade";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dazzling";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tug";
    if (!(--size)) {
      return;
    }

    *(ss++) = "order";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wanting";
    if (!(--size)) {
      return;
    }

    *(ss++) = "weigh";
    if (!(--size)) {
      return;
    }

    *(ss++) = "real";
    if (!(--size)) {
      return;
    }

    *(ss++) = "harm";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "arrive";
    if (!(--size)) {
      return;
    }

    *(ss++) = "arrange";
    if (!(--size)) {
      return;
    }

    *(ss++) = "excite";
    if (!(--size)) {
      return;
    }

    *(ss++) = "list";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pocket";
    if (!(--size)) {
      return;
    }

    *(ss++) = "detect";
    if (!(--size)) {
      return;
    }

    *(ss++) = "long-term";
    if (!(--size)) {
      return;
    }

    *(ss++) = "whimsical";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rabbits";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sneeze";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fruit";
    if (!(--size)) {
      return;
    }

    *(ss++) = "previous";
    if (!(--size)) {
      return;
    }

    *(ss++) = "screeching";
    if (!(--size)) {
      return;
    }

    *(ss++) = "meat";
    if (!(--size)) {
      return;
    }

    *(ss++) = "day";
    if (!(--size)) {
      return;
    }

    *(ss++) = "selective";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "agreement";
    if (!(--size)) {
      return;
    }

    *(ss++) = "produce";
    if (!(--size)) {
      return;
    }

    *(ss++) = "harbor";
    if (!(--size)) {
      return;
    }

    *(ss++) = "carpenter";
    if (!(--size)) {
      return;
    }

    *(ss++) = "winter";
    if (!(--size)) {
      return;
    }

    *(ss++) = "aspiring";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cagey";
    if (!(--size)) {
      return;
    }

    *(ss++) = "develop";
    if (!(--size)) {
      return;
    }

    *(ss++) = "mate";
    if (!(--size)) {
      return;
    }

    *(ss++) = "miniature";
    if (!(--size)) {
      return;
    }

    *(ss++) = "messy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "giraffe";
    if (!(--size)) {
      return;
    }

    *(ss++) = "important";
    if (!(--size)) {
      return;
    }

    *(ss++) = "view";
    if (!(--size)) {
      return;
    }

    *(ss++) = "friends";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ethereal";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trap";
    if (!(--size)) {
      return;
    }

    *(ss++) = "nasty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cheerful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rebel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ghost";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frame";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bag";
    if (!(--size)) {
      return;
    }

    *(ss++) = "nutritious";
    if (!(--size)) {
      return;
    }

    *(ss++) = "harm";
    if (!(--size)) {
      return;
    }

    *(ss++) = "introduce";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rail";
    if (!(--size)) {
      return;
    }

    *(ss++) = "violet";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unfasten";
    if (!(--size)) {
      return;
    }

    *(ss++) = "spill";
    if (!(--size)) {
      return;
    }

    *(ss++) = "manage";
    if (!(--size)) {
      return;
    }

    *(ss++) = "telling";
    if (!(--size)) {
      return;
    }

    *(ss++) = "upset";
    if (!(--size)) {
      return;
    }

    *(ss++) = "quince";
    if (!(--size)) {
      return;
    }

    *(ss++) = "birth";
    if (!(--size)) {
      return;
    }

    *(ss++) = "aloof";
    if (!(--size)) {
      return;
    }

    *(ss++) = "push";
    if (!(--size)) {
      return;
    }

    *(ss++) = "frame";
    if (!(--size)) {
      return;
    }

    *(ss++) = "taste";
    if (!(--size)) {
      return;
    }

    *(ss++) = "corn";
    if (!(--size)) {
      return;
    }

    *(ss++) = "thoughtful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flaky";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flower";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fence";
    if (!(--size)) {
      return;
    }

    *(ss++) = "airport";
    if (!(--size)) {
      return;
    }

    *(ss++) = "join";
    if (!(--size)) {
      return;
    }

    *(ss++) = "coil";
    if (!(--size)) {
      return;
    }

    *(ss++) = "amount";
    if (!(--size)) {
      return;
    }

    *(ss++) = "friction";
    if (!(--size)) {
      return;
    }

    *(ss++) = "imported";
    if (!(--size)) {
      return;
    }

    *(ss++) = "religion";
    if (!(--size)) {
      return;
    }

    *(ss++) = "window";
    if (!(--size)) {
      return;
    }

    *(ss++) = "scene";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tawdry";
    if (!(--size)) {
      return;
    }

    *(ss++) = "command";
    if (!(--size)) {
      return;
    }

    *(ss++) = "point";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pricey";
    if (!(--size)) {
      return;
    }

    *(ss++) = "disapprove";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sloppy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "military";
    if (!(--size)) {
      return;
    }

    *(ss++) = "intelligent";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hulking";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cause";
    if (!(--size)) {
      return;
    }

    *(ss++) = "park";
    if (!(--size)) {
      return;
    }

    *(ss++) = "economic";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tour";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dislike";
    if (!(--size)) {
      return;
    }

    *(ss++) = "friction";
    if (!(--size)) {
      return;
    }

    *(ss++) = "flawless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "cute";
    if (!(--size)) {
      return;
    }

    *(ss++) = "decision";
    if (!(--size)) {
      return;
    }

    *(ss++) = "next";
    if (!(--size)) {
      return;
    }

    *(ss++) = "attach";
    if (!(--size)) {
      return;
    }

    *(ss++) = "vegetable";
    if (!(--size)) {
      return;
    }

    *(ss++) = "hurt";
    if (!(--size)) {
      return;
    }

    *(ss++) = "scintillating";
    if (!(--size)) {
      return;
    }

    *(ss++) = "bath";
    if (!(--size)) {
      return;
    }

    *(ss++) = "straight";
    if (!(--size)) {
      return;
    }

    *(ss++) = "sleepy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "experience";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trail";
    if (!(--size)) {
      return;
    }

    *(ss++) = "punish";
    if (!(--size)) {
      return;
    }

    *(ss++) = "books";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rush";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dare";
    if (!(--size)) {
      return;
    }

    *(ss++) = "grain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "grandmother";
    if (!(--size)) {
      return;
    }

    *(ss++) = "destroy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "end";
    if (!(--size)) {
      return;
    }

    *(ss++) = "giraffe";
    if (!(--size)) {
      return;
    }

    *(ss++) = "grain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "territory";
    if (!(--size)) {
      return;
    }

    *(ss++) = "shop";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trip";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unit";
    if (!(--size)) {
      return;
    }

    *(ss++) = "income";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stain";
    if (!(--size)) {
      return;
    }

    *(ss++) = "ocean";
    if (!(--size)) {
      return;
    }

    *(ss++) = "trace";
    if (!(--size)) {
      return;
    }

    *(ss++) = "salty";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dead";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stare";
    if (!(--size)) {
      return;
    }

    *(ss++) = "country";
    if (!(--size)) {
      return;
    }

    *(ss++) = "rate";
    if (!(--size)) {
      return;
    }

    *(ss++) = "toad";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tease";
    if (!(--size)) {
      return;
    }

    *(ss++) = "stir";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fax";
    if (!(--size)) {
      return;
    }

    *(ss++) = "superb";
    if (!(--size)) {
      return;
    }

    *(ss++) = "run";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wistful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "utopian";
    if (!(--size)) {
      return;
    }

    *(ss++) = "pretend";
    if (!(--size)) {
      return;
    }

    *(ss++) = "vase";
    if (!(--size)) {
      return;
    }

    *(ss++) = "committee";
    if (!(--size)) {
      return;
    }

    *(ss++) = "float";
    if (!(--size)) {
      return;
    }

    *(ss++) = "dress";
    if (!(--size)) {
      return;
    }

    *(ss++) = "alert";
    if (!(--size)) {
      return;
    }

    *(ss++) = "wasteful";
    if (!(--size)) {
      return;
    }

    *(ss++) = "snobbish";
    if (!(--size)) {
      return;
    }

    *(ss++) = "spiders";
    if (!(--size)) {
      return;
    }

    *(ss++) = "unwieldy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "auspicious";
    if (!(--size)) {
      return;
    }

    *(ss++) = "brief";
    if (!(--size)) {
      return;
    }

    *(ss++) = "kneel";
    if (!(--size)) {
      return;
    }

    *(ss++) = "calm";
    if (!(--size)) {
      return;
    }

    *(ss++) = "healthy";
    if (!(--size)) {
      return;
    }

    *(ss++) = "fetch";
    if (!(--size)) {
      return;
    }

    *(ss++) = "tame";
    if (!(--size)) {
      return;
    }

    *(ss++) = "gabby";
    if (!(--size)) {
      return;
    }

    *(ss++) = "horse";
    if (!(--size)) {
      return;
    }

    *(ss++) = "insidious";
    if (!(--size)) {
      return;
    }

    *(ss++) = "slave";
    if (!(--size)) {
      return;
    }

    *(ss++) = "humor";
    if (!(--size)) {
      return;
    }

    *(ss++) = "overwrought";
    if (!(--size)) {
      return;
    }

    *(ss++) = "increase";
    if (!(--size)) {
      return;
    }

    *(ss++) = "mist";
    if (!(--size)) {
      return;
    }

    *(ss++) = "motionless";
    if (!(--size)) {
      return;
    }

    *(ss++) = "army";
    if (!(--size)) {
      return;
    }

    *(ss++) = "charge";
    if (!(--size)) {
      return;
    }

    *(ss++) = "contain";
    if (!(--size)) {
      return;
    }
  }

private:
  Common() = delete;

};

} // ns cc

#endif /* _COMMON_H */
