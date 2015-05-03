
#ifndef INPUTREADER_H
#define INPUTREADER_H
/* Author: Mazin Jindeel
** Date:   5/15
** Class Name: InputReader
** Class Purpose: open an inputreader that will read in a screen resolution and mouse movement array and make those objects available
*/

#include "Map.h"

class InputReader
{
    public: 
        //default constructor
        InputReader(){}
        
        //constructor that takes in a filename of a heatmap input
        InputReader(const char *fileName);
        
        //method to retrieve contents of a inputReader as the map (RAW map)
        Map getMap();
        
        //method to set a fileName (for reading multiple files)
        Map setFileName(const char* fileName);

    private:
        //the Map object that holds the inputReader's current map
        Map map;
        const char *file;
        
        //method to read map from current fileName
        Map setMapFromFile();
};
#endif
