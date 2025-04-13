CC=g++
FLAGS=-Wall -Wextra
LINKS=-lraylib
OUT=./main.out
GAME_FILES=game/*.cc

TEST_OUT=tests/test.out
TEST_LINKS=-lgtest
TEST_DEFS=-Dgtest_disable_pthreads=OFF
TEST_FILES=tests/test.cc tests/**/*.cc

all:
	$(CC) $(FLAGS) -o $(OUT) main.cc $(GAME_FILES) $(LINKS)

run: all
	$(OUT)

test:
	$(CC) $(FLAGS) -o $(TEST_OUT) $(TEST_FILES) $(GAME_FILES) $(LINKS) $(TEST_LINKS) $(TEST_DEFS)

test-run: test
	$(TEST_OUT)
