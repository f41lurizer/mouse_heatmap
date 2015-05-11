#uncomment this line and comment g++ to compile for windows
#CC=x86_64-w64-mingw32-g++
CC=g++
CXXFLAGS=-c -Wall -std=c++11

all: test

test: launcher.o Resolution.o InputReader.o Map.o  bitmap_image.o
	$(CC) launcher.o Resolution.o InputReader.o Map.o  bitmap_image.o -o test

launcher.o: launcher.cpp
	$(CC) $(CXXFLAGS) launcher.cpp

InputReader.o: InputReader.cpp
	$(CC) $(CXXFLAGS) InputReader.cpp

Map.o: Map.cpp
	$(CC) $(CXXFLAGS)  Map.cpp

Resolution.o: Resolution.cpp
	$(CC) $(CXXFLAGS) Resolution.cpp

#StringSplitter.o: StringSplitter.cpp
#	$(CC) $(CXXFLAGS) StringSplitter.cpp

bitmap_image.o: bitmap/bitmap_image.cpp
	$(CC) $(CXXFLAGS) bitmap/bitmap_image.cpp
