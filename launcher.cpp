#include "Map.h"
#include "InputReader.h"
#include "bitmap/bitmap_image.cpp"
//#include "Resolution.h" //just for debugging 

int main(int argc,char* argv[])
{
    std::cout << argv[2] << std::endl;
    InputReader reader(argv[2]);
    std::cout << "made it this far" << std::endl;
    Map map = reader.getMap();
    std::cout << "made it even further" << map.getResolution().getX() << " " << map.getResolution().getY() << " \n";
   for(int i = 0; i < map.getResolution().getY(); i++)
    {
        for(int n = 0; n < map.getResolution().getX(); n++)
            if(map.getWeight(n,i) > 0)
                std::cout << map.getWeight(n, i) << " x was: " << n << " y was: " << i <<  std::endl;
    }
    
        
}
