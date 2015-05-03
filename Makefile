Pass in this flag -- not sure how -std=c++11 --needed for stoi in InputReader
Map.o: Map.cpp
	g++ -c Map.cpp
InputReader.o: InputReader.cpp
	g++ -c InputReader.cpp
bitmap_image.o: bitmap/bitmap_image.hpp
	g++ -c bitmap/bitmap_image.hpp
StringSplitter.o: StringSplitter.h
	g++ -c StringSplitter.h
