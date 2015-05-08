
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
        
        //method to retrieve the activity map (RAW map)
        Map getActivityMap();
        
        //method to retrieve the rest map (RAW map)
        Map getRestMap();

        //method to return the average activity time
        double getActivityDuration();

        //method to return average time between activity
        double getActivityInterval();

        //method to get average rest time
        double getRestDuration();
        
        //method to get average interval between rest 
        double getRestInterval();

        //method to set a fileName (for reading multiple files)
        void setFileName(const char* fileName);

    private:
        //the Map object that holds the inputReader's current map
        Map activityMap, restMap;
        double restDuration, restInterval, activityDuration, activityInterval;
        
        const char *file;
        
        //method to read map from current fileName
        void setDataFromFile();
};
#endif
