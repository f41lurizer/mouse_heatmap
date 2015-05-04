#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H
#include <vector>
#include <string>
#include <iostream>
 
std::vector<std::string> splitString(std::string input, std::string delimiter)
    {
        std::vector<std::string> output;
        std::size_t start = 0;
        std::size_t end = 0;
  
        while (start != std::string::npos && end != std::string::npos)
        {
            start = input.find_first_not_of(delimiter, end);
  
            if (start != std::string::npos)
            {
                end = input.find_first_of(delimiter, start);
  
                if (end != std::string::npos)
                {
                    output.push_back(input.substr(start, end - start));
                }
                else
                {
                     output.push_back(input.substr(start));
                }
            }
        }
  
     return output;
  
  }
#endif
