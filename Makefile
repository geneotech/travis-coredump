

all: build

build:
	$(CXX) -o test might_crash.cpp -std=gnu++1z -g -O0 -DDEBUG

clean:
	rm -rf ./test
	rm -rf ./test.dSYM