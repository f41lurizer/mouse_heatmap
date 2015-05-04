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
    std::cout << "made it to constructor\n";
    setFileName(fileName);
    std::cout << "set file name successfully\n";
    setMapFromFile();
    std::cout << "set map successfully\n";

}

Map InputReader::getMap()
{
    return map;
}

void InputReader::setFileName(const char* fileName)
{
    file = fileName;
    std::cout << "set file name\n";
    setMapFromFile();
    std::cout << "set Map from file\n";
}

//uses fstream
void InputReader::setMapFromFile()
{
    //file IO to get the map
    //set map to whatever comes out of file
    std::ifstream in(file, std::ifstream::in);
    std::cout << "set fstream\n";
    //get resolution
    std::string resolution;
    std::getline(in, resolution);
    int x, y;
    std::vector<std::string> split = splitString(resolution, "x");
    std::vector<std::string>::iterator itr = split.begin();
    x = std::stoi(*itr);
    itr++;
    y = std::stoi(*itr);
    std::cout << "setting resolution\n";
    Resolution res(x, y);
    std::cout << "set resolution" << res.getX() << res.getY() << "\n";
    //now that we have a resolution, create a map with this resolution
    map = new Map(res);
    std::cout << "created map";
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
    std::cout << "made it through while loop";
    in.close();
    map.dither();
}

