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
    //create the actual bitmap now
    bitmap_image bmp(map.getResolution().getX(), map.getResolution().getY());
    for(int y = 0; y < map.getResolution().getY(); y++)
    {
        for(int x = 0; x < map.getResolution().getX(); x++)
        {
            int weight = map.getWeight(x, y);
            int green = weight > 0 ? weight < 255 ? weight : 0 : 255;
            int blue = weight > 0 ? weight < 255 ? weight : 0 : 255;
            int red = weight > 0 ? weight < 255 ? weight : 0 : 255;
            /*int green = weight;
            int red = weight;
            int blue = weight;*/
            if(weight > 0)
                bmp.set_pixel(x, y, red, green, blue); 
            if(map.getWeight(x,y) > 0)
            {
                std::cout << weight  << " x was: " << x << " y was: " << y <<  std::endl;
            std::cout << "colorValue: " << green << " weight: " << weight << std::endl;
            }
        }
    }
    bmp.save_image("image.bmp");
    
        
}
