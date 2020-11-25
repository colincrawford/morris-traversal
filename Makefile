CC=g++
CC_FLAGS=-std=c++17 -Wall -I.

build: bin/simple_example bin/tests

test: bin/tests
	./bin/tests

bin/simple_example: examples/simple_example.cpp src
	$(CC) $(CC_FLAGS) examples/simple_example.cpp -o bin/simple_example

bin/tests: tests/tests.cpp src
	$(CC) $(CC_FLAGS) tests/tests.cpp -o bin/tests

src: src/sample_node.h src/morris_traversal.h
