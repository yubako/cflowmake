#
#cpputestで作ったテストがそのまま使えるように同じmakefileを使用。
#
#Set this to @ to keep the makefile quiet
BUILD_BASE=/home/user/cflowcase/

#---- Outputs ----#
COMPONENT_NAME = TestName
#Set this to @ to keep the makefile quiet
SILENCE = @
#SILENCE =

#--- Inputs ----#
PROJECT_HOME_DIR = .
ifeq "$(CPPUTEST_HOME)" ""
    CPPUTEST_HOME = /home/user/cutest/
endif

# プロダクトソース置き場。相対パスの場合は親ディレクトリ以上を
# 指定しないこと(.oが変なところにできる...)
#SRC_DIRS = $(BUILD_BASE)/src

# to pick specific files (rather than directories) use this:
SRC_FILES =

TEST_SRC_DIRS = .\
    testcases/*

MOCKS_SRC_DIRS = \
    mocks \

INCLUDE_DIRS =\
  .\
  $(BUILD_BASE)/src/include \
  $(BUILD_BASE)/src/parse/include \
  $(BUILD_BASE)/test/include/* \
  $(BUILD_BASE)/test/mocks     \
  $(CPPUTEST_HOME)/include/ \
  mocks

#CPPUTEST_CXXFLAGS
#CPPUTEST_CPPFLAGS
#CPPUTEST_CFLAGS
CPPUTEST_LDFLAGS = -L$(BUILD_BASE)/src/lib/ -lcyl -ll
CPPUTEST_WARNINGFLAGS = -Wall -Werror -Wswitch-default
CPPUTEST_WARNINGFLAGS += -Wconversion -Wswitch-enum
CPPUTEST_USE_GCOV = Y

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

