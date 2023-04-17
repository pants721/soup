print-%  : ; @echo $* = $($*)

UNAME_S = $(shell uname -s)

CC = clang++

INCFLAGS = -iquotesrc
INCFLAGS += -Ilib/any/include/boost

CCFLAGS  = -std=c++20 -O2 -g -Wall -Wextra -Wpedantic -Wno-c99-extensions
CCFLAGS += -Wno-unused-parameter
CCFLAGS += $(INCFLAGS)

LDFLAGS = -lm
LDFLAGS += $(INCFLAGS)

SRC  = $(shell find src -name "*.cpp")
OBJ  = $(SRC:.cpp=.o)
BIN = bin

LDFLAGS += -lstdc++

.PHONY: all clean

all: dirs libs build 

dirs:
	mkdir -p ./$(BIN)

libs:
	cd lib/any/ && cmake .

run: build
	$(BIN)/game

build: dirs $(OBJ)
	$(CC) -o $(BIN)/game $(filter %.o,$^) $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CCFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)
