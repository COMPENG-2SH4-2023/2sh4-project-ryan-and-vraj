#ifndef FOOD_H
#define FOOD_H

class Food
{
    private:
        objPos foodPos;

    public:
        //Food();
        Food();
        ~Food();

        void generateFood(objPosArrayList *blockOff); // you need to upgrade this somehow
        //need to accept playerbody array list
        //go through each array list element to make sure they are 
        //all blocked off from random food gerenatiuon

    
        void getFoodPos(objPos &returnPos);
};

#endif