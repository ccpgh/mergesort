//
//  main.cpp
//

#include <iostream>
#include <vector>
#include <sstream>

#include "log.h"
#include "common.h"
#include "sort.h"

// README: 
// c++ code for merge in place for mergesort for client to collect
// see src/sort/merge function
// remove all logging and other classes
// use export CC_LOGLEVEL=trace|debug|info|warn|error to adjust output
//

int main(int argc, const char *argv[]) {

  LOGGER_INFO("starting");

  const size_t size(1000);

  const char *ss[size];

  cc::Common::load(ss, size);

  LOGGER_INFO("loaded");

  if (cc::Logger < cc::LogInfo > ::isLevelOn()) {
    LOGGER_INFO("start: ", cc::Sort::dump(ss, size));
  }

  cc::Sort::sort(ss, size, 0, "all");

  LOGGER_INFO("sorted");

  if (cc::Logger < cc::LogInfo > ::isLevelOn()) {
    LOGGER_INFO("end: ", cc::Sort::dump(ss, size));
  }

  LOGGER_INFO("fini.");

  return 0;
}

