#Pass in this flag -- not sure how -std=c++11 --needed for stoi in InputReader
CC=g++
CXXFLAGS=-c -Wall -std=c++11

all: test

test: InputReader.o Map.o StringSplitter.o bitmap_image.o
	$(CC) InputReader.o Map.o StringSplitter.o bitmap_image.o -o test

InputReader.o: InputReader.cpp
	$(CC) $(CXXFLAGS) InputReader.cpp

Map.o: Map.cpp
	$(CC) $(CXXFLAGS)  Map.cpp

StringSplitter.o: StringSplitter.cpp
	$(CC) $(CXXFLAGS) StringSplitter.cpp

bitmap_image.o: bitmap/bitmap_image.cpp
	$(CC) $(CXXFLAGS) bitmap/bitmap_image.cpp
