#Pass in this flag -- not sure how -std=c++11 --needed for stoi in InputReader
CC=g++
CXXFLAGS=-c -Wall -std=c++11

all: test

test: launcher.o InputReader.o Map.o  bitmap_image.o
	$(CC) launcher.o InputReader.o Map.o  bitmap_image.o -o test

launcher.o: launcher.cpp
	$(CC) $(CXXFLAGS) launcher.cpp

InputReader.o: InputReader.cpp
	$(CC) $(CXXFLAGS) InputReader.cpp

Map.o: Map.cpp
	$(CC) $(CXXFLAGS)  Map.cpp

#StringSplitter.o: StringSplitter.cpp
#	$(CC) $(CXXFLAGS) StringSplitter.cpp

bitmap_image.o: bitmap/bitmap_image.cpp
	$(CC) $(CXXFLAGS) bitmap/bitmap_image.cpp
