Class Map
{
    Public:
        Map();
        Map(Resolution resolution);
        int* getMap();
        Resolution getResolution();
        void changeWeight(int x, int y, int amount);
        void setMap(Map newMap);
        void 
    Private:
        Resolution res;
        int* map;
};
