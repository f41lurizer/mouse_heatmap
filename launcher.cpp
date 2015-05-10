#include "Map.h"
#include "InputReader.h"
#include "bitmap/bitmap_image.cpp"
#include "Resolution.h" //just for debugging 

int main(int argc,char* argv[])
{
    std::cout << "reading map\n";
    InputReader reader(argv[2]);
    std::cout << "read map\n";
    
    Map activityMap = reader.getActivityMap();
    Map restMap = reader.getRestMap();
    //uncomment next two liens to ouput a map of smallest possible size
    //int gcf = map.getResolution().gcf();
    //Resolution smallRes(map.getResolution().getX() / gcf, map.getResolution().getY() / gcf);

    //output a map that reduces each dimension by a factor of 10 (1/100 total size)
    Resolution smallRes(activityMap.getResolution().getX() / 10, activityMap.getResolution().getY() / 10);
    Map smallActivityMap = activityMap.reduceMap(smallRes);
    Map smallRestMap = restMap.reduceMap(smallRes);

    //output small activity map to console to see what's going on
    std::cout << "Activity Map: \n";
    for(int i = 0; i < smallActivityMap.getResolution().getY(); i++)
    {
        for(int n = 0; n < smallActivityMap.getResolution().getX(); n++)
        {
            std::cout << smallActivityMap.getWeight(n, i);
        }   
        std::cout << std::endl;
    }
    
    //output small rest map to console to see what's going on
    std::cout << "Rest Map: \n";
    for(int i = 0; i < smallRestMap.getResolution().getY(); i++)
    {
        for(int n = 0; n < smallRestMap.getResolution().getX(); n++)
        {
            std::cout << smallRestMap.getWeight(n, i);
        }   
        std::cout << std::endl;
    }

    //create the actual bitmap now
    bitmap_image activityBMP(smallRes.getX(), smallRes.getY());
    bitmap_image restBMP(smallRes.getX(), smallRes.getY());

    for(int y = 0; y < smallRes.getY(); y++)
    {
        for(int x = 0; x < smallRes.getX(); x++)
        {
            //set activity pixel/file first
            int weight = smallActivityMap.getWeight(x, y);
            int green = 255;//weight > 0 ? weight < 255 ? weight : 0 : 255;
            int blue = 255;//weight > 0 ? weight < 255 ? weight : 0 : 255;
            int red = weight > 0 ? weight < 255 ? weight : 0 : 255;
            activityBMP.set_pixel(x, y, blue, green, red); 

            //set rest pixel/file second
            weight = smallRestMap.getWeight(x, y);
            green = 255;//weight > 0 ? weight < 255 ? weight : 0 : 255;
            blue = weight > 0 ? weight < 255 ? weight : 0 : 255;
            red = 255;//weight > 0 ? weight < 255 ? weight : 0 : 255;
            restBMP.set_pixel(x, y, blue, green, red); 
        }
    }
    activityBMP.save_image("activity.bmp"); 
    restBMP.save_image("rest.bmp"); 
    std::cout << "Image saved\n";
    std::cout << "RestDuration: " << reader.getRestDuration() << " ActivityDuration: " << reader.getActivityDuration() << std::endl;
}
