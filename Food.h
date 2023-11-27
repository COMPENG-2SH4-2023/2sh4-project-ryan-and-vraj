

class Food
{
    private:
        objPos foodPos;

    public:
        //Food();
        Food(objPos currentPos);
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
};
