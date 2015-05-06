#include "Resolution.h"
/* Author: Mazin Jindeel
** Date: 5/15
** Class Name: Resolution
** Class Purpose: Stores a simple integer resolution and provides ways to access and modify it
*/

Resolution::Resolution(){ x = y = 0;}
Resolution::Resolution(int xVal, int yVal)
{
    setX(xVal);
    setY(yVal);
}
int Resolution::getX(){return x;}
int Resolution::getY(){return y;}
bool Resolution::mappable(){return (x > 0 && y > 0);}
void Resolution::setX(int val) {x = val;}
void Resolution::setY(int val) {y = val;}
int Resolution::gcf()
{
    int xTemp = x, yTemp = y, gcf = 1;
    for(int i = yTemp > xTemp? xTemp : yTemp; i > 0; i--)
        {
            if(xTemp % i == 0 && yTemp % i == 0) //if both are divisible by Y
            {
                xTemp/= i; 
                yTemp /= i;
                gcf *= i;
            }
        }
    return gcf;
}
