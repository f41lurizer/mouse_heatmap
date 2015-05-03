/* Author: Mazin Jindeel
** Date: 5/15
** Class Name: Resolution
** Class Purpose: Stores a simple integer resolution and provides ways to access and modify it
*/

#ifndef RESOLUTION_H
#define RESOLUTION_H
Class Resolution
{
    Public:

        Resolution(){}
        Resolution(int xVal, int yVal)
        {
            setX(xVal);
            setY(yVal);
        }
        int getX(){return x;}
        int getY(){return y;}

        void setX(int val) {x = val;}
        void setY(int val) (y = val;)
    Private:
        int x, y;
};
#endif
