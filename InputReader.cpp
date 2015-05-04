/* Author: Mazin Jindeel
** Date: 5/15
** Class Name: InputReader
*/

#include <fstream>
#include "Resolution.h"
#include <vector>
#include <string>
#include <sstream>
#include "StringSplitter.cpp"
#include "Resolution.h"
#include "InputReader.h"
#include <cstdio>

InputReader::InputReader(const char *fileName)
{
    setFileName(fileName);
    getMap();
}

Map InputReader::getMap()
{
    return map;
}

Map InputReader::setFileName(const char* fileName)
{
    file = fileName;
    return getMap();
}

//uses fstream
Map InputReader::setMapFromFile()
{
    //file IO to get the map
    //set map to whatever comes out of file
    std::ifstream in(file, std::ifstream::in);
    
    //get resolution
    std::string resolution;
    std::getline(in, resolution);
    int x, y;
    std::vector<std::string> split = splitString(resolution, "x");
    std::vector<std::string>::iterator itr = split.begin();
    x = std::stoi(*itr);
    itr++;
    y = std::stoi(*itr);
    
    Resolution res(x, y);
    //now that we have a resolution, create a map with this resolution
    map = Map(res);

    while(in.good())
    {
        std::string entry;
        std::getline(in, entry);
        split = splitString(entry, " ");
        itr = split.begin();
        //get rid of the 'x:' in input file
        x = std::stoi((*itr).substr(2, std::string::npos));
        itr++;
        //get rid of the 'y:' in input file
        y = std::stoi((*itr).substr(2, std::string::npos));

        //update map to reflect more weight
        map.changeWeight(x, y, 1); 
        //load a mappable array and a resolution
    }
    in.close();
    map.dither();
}

