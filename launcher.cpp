#include "Map.h"
#include "InputReader.h"
#include "bitmap/bitmap_image.cpp"
#include "Resolution.h" //just for debugging 

int main(int argc,char* argv[])
{
    std::cout << "reading map\n";
    InputReader reader(argv[2]);
    std::cout << "read map\n";
    
    Map map = reader.getActivityMap();
    //uncomment next two liens to ouput a map of smallest possible size
    //int gcf = map.getResolution().gcf();
    //Resolution smallRes(map.getResolution().getX() / gcf, map.getResolution().getY() / gcf);
    std::cout << "got activity Map\n";
    //output a map that reduces each dimension by a factor of 10 (1/100 total size)
    Resolution smallRes(map.getResolution().getX() / 10, map.getResolution().getY() / 10);
    Map smallMap = map.reduceMap(smallRes);

    //output small map to console to see what's going on
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
            int green = weight > 0 ? weight < 255 ? weight : 0 : 255;
            int blue = weight > 0 ? weight < 255 ? weight : 0 : 255;
            int red = weight > 0 ? weight < 255 ? weight : 0 : 255;
            bmp.set_pixel(x, y, red, green, blue); 
        }
    }
    bmp.save_image("image.bmp"); 
    std::cout << "Image saved\n";
    std::cout << "RestDuration: " << reader.getRestDuration() << " ActivityDuration: " << reader.getActivityDuration() << std::endl;
}
