/* Author: Mazin Jindeel
** Date: 5/15
** Class Name: Resolution
** Class Purpose: Stores a simple integer resolution and provides ways to access and modify it
*/

#ifndef RESOLUTION_H
#define RESOLUTION_H
class Resolution
{
    public:

        Resolution(){ x = y = 0;}
        Resolution(int xVal, int yVal)
        {
            setX(xVal);
            setY(yVal);
        }
        int getX(){return x;}
        int getY(){return y;}
        bool mappable(){return (x > 0 && y > 0);}
        void setX(int val) {x = val;}
        void setY(int val) {y = val;}
    private:
        int x, y;
};
#endif
