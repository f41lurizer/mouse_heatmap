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
    map = Map();
    setFileName(fileName);

}

Map InputReader::getMap()
{
    return map;
}

void InputReader::setFileName(const char* fileName)
{
    file = fileName;
    setMapFromFile();
}

//uses fstream
void InputReader::setMapFromFile()
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
    //map = 
    //Map newMap();  
    //map.setResolution()
    map.setResolution(res.getX(), res.getY());
    int i = 1;
    std::string xStr, yStr;
    while(in >> xStr >> yStr)
    {
        //std::cout << "on line: " << i << "x = " << xStr << "y = " << yStr << std::endl; 
        //std::getline(in, entry);
        x = std::stoi(xStr.substr(2, xStr.length() -2));
        y = std::stoi(yStr.substr(2, yStr.length() -2));
        //update map to reflect more weight
        map.changeWeight(x, y, 1);
        //load a mappable array and a resolution
        i++;
    }
    in.close();
    //map.dither();
}

