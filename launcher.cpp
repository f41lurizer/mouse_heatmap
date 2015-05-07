#include "Map.h"
#include "InputReader.h"
#include "bitmap/bitmap_image.cpp"
#include "Resolution.h" //just for debugging 

int main(int argc,char* argv[])
{
    std::cout << argv[2] << std::endl;
    InputReader reader(argv[2]);
    std::cout << "made it this far" << std::endl;
    Map map = reader.getMap();

    std::cout << "made it even further" << map.getResolution().getX() << " " << map.getResolution().getY() << " \n";
    //int gcf = map.getResolution().gcf();
    //Resolution smallRes(map.getResolution().getX() / gcf, map.getResolution().getY() / gcf);
    Resolution smallRes(192, 108);
    std::cout << "new map with resolution: " << smallRes.getX() << " x " << smallRes.getY() << std::endl; 

    Map smallMap = map.reduceMap(smallRes);

    for(int i = 0; i < smallMap.getResolution().getY(); i++)
    {
        for(int n = 0; n < smallMap.getResolution().getX(); n++)
        {
            std::cout << smallMap.getWeight(n, i);
        }   
        std::cout << std::endl;
    }
    //create the actual bitmap now
    bitmap_image bmp(smallMap.getResolution().getX(), smallMap.getResolution().getY());
    for(int y = 0; y < smallMap.getResolution().getY(); y++)
    {
        for(int x = 0; x < smallMap.getResolution().getX(); x++)
        {
            int weight = smallMap.getWeight(x, y);
            if(weight > 0) std::cout << "weight was: " << weight << std::endl;
            int green = weight > 0 ? weight < 255 ? weight : 0 : 255;
            int blue = weight > 0 ? weight < 255 ? weight : 0 : 255;
            int red = weight > 0 ? weight < 255 ? weight : 0 : 255;
            bmp.set_pixel(x, y, red, green, blue); 
            std::cout << "green: " << green << " red: " << red << " blue: " << blue << "\n";
        }
    }
    bmp.save_image("image.bmp"); 
}
