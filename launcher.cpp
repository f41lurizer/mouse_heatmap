#include "Map.h"
#include "InputReader.h"
#include "bitmap/bitmap_image.cpp"

int main(int argc,char* argv[])
{
    std::cout << argv[2] << std::endl;
    InputReader reader(argv[2]);
    std::cout << "made it this far" << std::endl;
    Map map = reader.getMap();
    
}
