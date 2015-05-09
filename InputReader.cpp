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
    std::cout << "in constructor";
    activityMap = Map();
    restMap = Map();
    std::cout << "about to call setfilename\n";
    setFileName(fileName);

}

void InputReader::setFileName(const char* fileName)
{
    file = fileName;
    std::cout << "calling setdataonfile";
    setDataFromFile();
}

Map InputReader::getActivityMap()
{
    return activityMap;
}

Map InputReader::getRestMap()
{
    return restMap;
}

double InputReader::getActivityDuration()
{
    return activityDuration;
}

double InputReader::getActivityInterval()
{
    return activityDuration;
}

double InputReader::getRestDuration()
{
    return restDuration;
}

double InputReader::getRestInterval()
{
    return restInterval;
}
//uses fstream
void InputReader::setDataFromFile()
{
    std::cout << "in setdatafromfile\n";
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
    //now we have resolution, need to set resolution of both maps to it
    restMap.setResolution(res.getX(), res.getY());
    activityMap.setResolution(res.getX(), res.getY());

    std::cout << "set all the resolution stuff\n";
    int i = 1;//loop counter (for debugging only) to tell what line of input gives errors
    std::string xStr, yStr;
    int xPrev = -1, yPrev = -1;
    int totalRestDuration = 0, numRests = 0, totalActivityDuration = 0, numActivity = 0;
    bool rest = false, prevRest = true;
    while(in >> xStr >> yStr)
    {
        //std::cout << "on line: " << i << "x = " << xStr << "y = " << yStr << std::endl; 
        //std::getline(in, entry);
        x = std::stoi(xStr.substr(2, xStr.length() -2));
        y = std::stoi(yStr.substr(2, yStr.length() -2));

        //see if it's a rest or activity
        rest = (x == xPrev && y == yPrev);
        //update counters for rest/activity duration
        totalActivityDuration += !rest ? 1 : 0;
        totalRestDuration += rest ? 1 : 0;

        //if we are switching from rest to activity or activity to rest, increment either number of rests or number of activities

        if(rest != prevRest) 
        {
            std::cout << "switching from rest to active\n";
            numActivity += !rest ? 1 : 0;
            numRests += rest ? 1 : 0; 
            std::cout << "numActivity: " << numActivity << " numRests: " << numRests << std::endl; 
            std::cout << "activityDuration: " << totalActivityDuration << " restDuration: " << totalRestDuration << std::endl;
        }

        //update maps
        if(!rest)
            //update map to reflect more weight
            activityMap.changeWeight(x, y, 1);
        else if(rest)
            restMap.changeWeight(x, y, 1);
        
        //now we update variables
        xPrev = x;
        yPrev = y;
        prevRest = rest;
        i++;
    }
    //update the durations and intervals
    restDuration = numRests > 0 ? totalRestDuration / numRests : 0;
    activityDuration = numActivity > 0 ? totalActivityDuration / numActivity: 0;
    in.close();
    //map.dither();
}

