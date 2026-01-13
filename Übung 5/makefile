# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================


CLEANUP = rm -f
MKDIR = mkdir -p
TARGET_EXTENSION=.out

C_COMPILER=gcc
UNITY_ROOT=test/Unity

TARGET_BASE1=TESTList
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=$(UNITY_ROOT)/unity.c list.c  test/TestList.c  test/test_runners/TestList_Runner.c
INC_DIRS=-I. -I$(UNITY_ROOT)
SYMBOLS = -DUNITY_OUTPUT_COLOR

all: clean default

default: $(SRC_FILES1)
	$(C_COMPILER) -Wall $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	- ./$(TARGET1)

clean:
	$(CLEANUP) $(TARGET1)

ci: CFLAGS += -Werror
ci: default
