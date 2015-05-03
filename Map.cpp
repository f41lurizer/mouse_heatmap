/* Author: Mazin Jindeel
** Date: 5/15
** Class Name: Map
*/
#include "Map.h"
Map::Map()
{
    res = Resolution();
    map = 0;
}

Map::Map(Resolution resolution)
{
    res = resolution;
    initMap();
}

Map::Map(Resolution oldRes, int** oldMap)
{
    res = oldRes;
    initMap();
    //copy old map by value
    for(int y = 0; y < res.getY(); y++)
        for(int x = 0; x < res.getX(); x++)
            setWeight(x, y, *(*oldMap+y)+x);   
}

int** Map::getMap()
{
    return map;
}

Map Map::dither()
{
    //TODO: dithering algorithm
    return Map();
}

Resolution Map::getResolution()
{
    return res;
}

int Map::getWeight(int x, int y) 
{
    return (x < res.getX() && y < res.getY()) ? *(*(map + y) + x):-1;
}

void Map::setWeight(int x, int y, int amount)
{
    if(x < res.getX() && y < res.getY())
        *(*(map + y)+x) = amount;
}

int Map::changeWeight(int x, int y, int amount)
{
    if(x < res.getX() && y < res.getY())
    {
        *(*(map + y) + x) += amount;
        return *(*(map + y) + x);
    }
}

void Map::initMap()
{
    if(!res.mappable())
        return;
    map = new int*[res.getY()];
    for(int y = 0; y < res.getY(); y++)
    {
        *(map+y) = new int[res.getY()];
        for(int x = 0; x < res.getX(); x++)
            *(*(map + y) + x) = 0;
    }
}
