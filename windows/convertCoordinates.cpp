/* Author: Mazin Jindeel
** Class: convertInput
** Functionality: Edit every coordinate included by a given x and y integer value. This utility is intended for supporting multiple monitors on windows machines by allowing the user to align the leftmost bottom corner of screen to (0,0) to avoid having any negative coordinates in their input to the heatmap generator
**Usage: As command line arguments, enter the following: input file, output file, x adjustment, y adjustment 
*/
#include <iostream>
#include <fstream>
#include <cstdlib>


int main(int argc, char* argv[])
{
    std::ifstream in;
    in.open(argv[1]);
    std::ofstream out;
    out.open(argv[2]);
    int xAdjustment = std::atoi(argv[3]);
    int yAdjustment = std::atoi(argv[4]);
    std::string line;
    line 
}
