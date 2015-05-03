/* Author: Mazin Jindeel
** Date: 5/15
** Class Name: Map
*/

Map::Map()
{
    res = null;
    map = null;
}

Map::Map(Resolution resolution)
{
    res = resolution;
    initMap();
}

Map::Map(Map oldMap)
{
    res = oldMap.getResolution();
    initMap();
    //copy old map by value
    for(int y = 0; y < res.getY(); y++)
        for(int x = 0; x < res.getX(); x++)
            setWeight(x, y, oldMap.getWeight(x, y));   
}

int* Map::getMap()
{
    return map;
}

Map Map::dither()
{
    //TODO: dithering algorithm
    return null;
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
    if(resolution == null)
        return;
    map = new int*[res.getY()];
    for(int y = 0; y < res.getY(); y++)
    {
        *(map+y) = new int[res.getY()];
        for(int x = 0; x < res.getX(); x++)
            *(*(map + y) + x) = 0;
    }
}
