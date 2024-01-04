include libs/systemc_installed/build-unix/Makefile.config

PROJECT := cpu-simulator
SRCS    := $(wildcard /modules/*/*.cpp)
OBJS    := $(SRCS:.cpp=.o)

include libs/systemc_installed/build-unix/Makefile.rules
