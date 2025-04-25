CC=g++
FLAGS=-Wall -Wextra
LINKS=-lraylib
OUT=./main.out
GAME_FILES=$(shell find game -type f -iregex ".*\.cc")

TARGET=build/core.so
OBJS=$(GAME_FILES:.cc=.o)

TEST_OUT=build/test.out
TEST_LINKS=-lgtest
TEST_DEFS=-Dgtest_disable_pthreads=OFF
TEST_FILES=$(shell find tests -type f -iregex ".*\.cc")

all: make-build-dir $(TARGET)
	$(CC) $(FLAGS) -o main.out main.cc $(TARGET) $(LINKS)
	#$(CC) $(FLAGS) -c build/$(OUT) $(GAME_FILES) $(LINKS)

make-build-dir:
	mkdir -p build

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(shell find build -type f -iregex ".*\.o") -shared

%.o: %.cc
	$(CC) $(FLAGS) -fPIC -c $< -o build/$(shell basename $@)

run: all
	$(OUT)

test: all
	$(CC) $(FLAGS) -o $(TEST_OUT) $(TEST_FILES) $(TARGET) $(LINKS) $(TEST_LINKS) $(TEST_DEFS)

test-run: test
	$(TEST_OUT)
