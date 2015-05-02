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
