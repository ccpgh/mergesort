#
# Makefile mergesort
# 

all: prepare build

MAKEFILE_PATH = $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR  = $(dir $(MAKEFILE_PATH))

BUILD_ROOT = ..

BUILD_DIR   = $(PWD)
SRC_DIR     = $(BUILD_ROOT)/src
BIN_DIR     = $(BUILD_ROOT)/bin
OBJ_DIR     = $(BUILD_ROOT)/obj
TARGET_NAME = mergesort
TARGET_EXE  = $(BIN_DIR)/$(TARGET_NAME)
SUBDIRS     = $(shell find $(SRC_DIR) -type d | sort -r)
BUILDDIRS   = $(BIN_DIR)
SRC_FILES   = $(shell find $(SRC_DIR) -name *.cpp)
OBJ_FILES   = $(SRC_FILES:%.cpp=%.o)
INCL_DIRS   = $(addprefix -I, $(SUBDIRS))

CCC	    = g++

INCLUDES    = -I. $(INCL_DIRS) 
 
# NOTE: levels are -std=c++11 -std=c++14 -std=c++17 -std=c++2a
CPPFLAGS    = -Wall -g -std=c++11

.cpp.o:
	$(CCC) -c $(CPPFLAGS) $< $(INCLUDES) -o $@

$(TARGET_EXE):  $(OBJ_FILES) 
	$(CCC) $(CPPFLAGS) -o $(TARGET_EXE) $(OBJ_FILES) 

prepare:
	@for builddir in $(BUILDDIRS); do if [ ! -d "$$builddir" ]; then \mkdir "$$builddir" ; echo making "$$builddir" ; fi; done
	@for builddir in $(BUILDDIRS); do if [ ! -d "$$builddir" ]; then \echo "could not create/read dir $$builddir"; exit 1; fi; done

build: $(TARGET_EXE)

clean:
	\rm -fr $(OBJ_FILES) $(TARGET_EXE)

depend:
	makedepend -DSUDOKUSOLVER_MAKEDEPENDS -Y $(INCLUDES) -- $(CPPFLAGS) -- $(SRC_FILES) 

.PHONEY: all
.PHONEY: prepare
.PHONEY: build
.PHONEY: clean
.PHONEY: depend

