# VEXcode mkenv.mk 2019_06_06_01

# macros to help with windows paths that include spaces
sp :=
sp +=
qs = $(subst ?,$(sp),$1)
sq = $(subst $(sp),?,$1)

# default platform and build location
PLATFORM  = vexv5
BUILD     = build

# version for clang headers
ifneq ("$(origin HEADERS)", "command line")
HEADERS = 8.0.0
endif

# Project name passed from app
ifeq ("$(origin P)", "command line")
PROJECT   = $(P)
else
PROJECT   = $(notdir $(call sq,$(abspath ${CURDIR})))
endif

# Toolchain path passed from app
ifeq ("$(origin T)", "command line")
TOOLCHAIN = $(T)
endif
ifndef TOOLCHAIN
TOOLCHAIN = ${HOME}/sdk
endif

# Verbose flag passed from app
ifeq ("$(origin V)", "command line")
BUILD_VERBOSE=$(V)
endif

# allow verbose to be set by makefile if not set by app
ifndef BUILD_VERBOSE
ifndef VERBOSE
BUILD_VERBOSE = 0
else
BUILD_VERBOSE = $(VERBOSE)
endif
endif

# use verbose flag
ifeq ($(BUILD_VERBOSE),0)
Q = @
else
Q =
endif

# compile and link tools
CC      = clang
CXX     = clang
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size
LINK    = arm-none-eabi-ld
ARCH    = arm-none-eabi-ar
ECHO    = @echo
DEFINES = -DVexV5

# platform specific macros
ifeq ($(OS),Windows_NT)
$(info windows build for platform $(PLATFORM))
SHELL = cmd.exe
MKDIR = md "$(@D)" 2> nul || :
RMDIR = rmdir /S /Q
CLEAN = $(RMDIR) $(BUILD) 2> nul || :
else
$(info unix build for platform $(PLATFORM))
MKDIR = mkdir -p "$(@D)" 2> /dev/null || :
RMDIR = rm -rf
CLEAN = $(RMDIR) $(BUILD) 2> /dev/null || :
endif

# toolchain include and lib locations
TOOL_INC  = -I"$(TOOLCHAIN)/$(PLATFORM)/clang/$(HEADERS)/include" -I"$(TOOLCHAIN)/$(PLATFORM)/gcc/include"  -I"$(TOOLCHAIN)/$(PLATFORM)/gcc/include/c++/4.9.3"  -I"$(TOOLCHAIN)/$(PLATFORM)/gcc/include/c++/4.9.3/arm-none-eabi/armv7-ar/thumb"
TOOL_LIB  = -L"$(TOOLCHAIN)/$(PLATFORM)/gcc/libs"

# compiler flags
CFLAGS_CL = -target thumbv7-none-eabi -fshort-enums -Wno-unknown-attributes -U__INT32_TYPE__ -U__UINT32_TYPE__ -D__INT32_TYPE__=long -D__UINT32_TYPE__='unsigned long' 
CFLAGS_V7 = -march=armv7-a -mfpu=neon -mfloat-abi=softfp
CFLAGS    = ${CFLAGS_CL} ${CFLAGS_V7} -Os -Wall -Werror=return-type -ansi -std=gnu99 $(DEFINES)
CXX_FLAGS = ${CFLAGS_CL} ${CFLAGS_V7} -Os -Wall -Werror=return-type -fno-rtti -fno-threadsafe-statics -fno-exceptions  -std=gnu++11 -ffunction-sections -fdata-sections $(DEFINES)

# linker flags
LNK_FLAGS = -nostdlib -T "$(TOOLCHAIN)/$(PLATFORM)/lscript.ld" -R "$(TOOLCHAIN)/$(PLATFORM)/stdlib_0.lib" -Map="$(BUILD)/$(PROJECT).map" --gc-section -L"$(TOOLCHAIN)/$(PLATFORM)" ${TOOL_LIB}

# future statuc library
PROJECTLIB = lib$(PROJECT)
ARCH_FLAGS = rcs

# libraries
LIBS =  --start-group -lv5rt -lstdc++ -lc -lm -lgcc --end-group

# include file paths
INC += $(addprefix -I, ${INC_F})
INC += -I"$(TOOLCHAIN)/$(PLATFORM)/include"
INC += ${TOOL_INC}
