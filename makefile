CC = g++ -c -std=c++11

all: test evaluate

evaluate: evaluate.o
	g++ evaluate.o -o evaluate

evaluate.o: evaluate.cpp
	$(CC) evaluate.cpp

test: test.o
	g++ test.o -o test

test.o: test.cpp
	$(CC) test.cpp

clean:
	rm test.o
	rm evaluate.o
