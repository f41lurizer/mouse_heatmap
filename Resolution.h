/* Author: Mazin Jindeel
** Date: 5/15
** Class Name: Resolution
** Class Purpose: Stores a simple integer resolution and provides ways to access and modify it
*/

class Resolution
{
    public:

        Resolution();
        Resolution(int xVal, int yVal);
        int getX();
        int getY();
        bool mappable();
        void setX(int val);
        void setY(int val);
        int gcf();
    private:
        int x, y;
};
