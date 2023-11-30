#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
#include <time.h>
#include "GameMechs.h"

#define BOARD_X 30
#define BOARD_Y 15


// Food::Food()
// {
//     foodPos = objPos();
// }

Food::Food(objPos currentPos)
{
    foodPos = objPos();
    generateFood(currentPos);
}

Food::~Food()
{

}
void Food::generateFood(objPos blockOff)
{
    srand(time(0));
    int candX = 0;
    int candY = 0;
    bool flag = false;

    objPos tempFoodPos; //for food position
    objPos snakePos;

    do 
    {
        
        // TODO: create the getBoardSizeX() instead of BOARD_X
        candX = rand() % (BOARD_X - 2) + 1;
        candY = rand() % (BOARD_Y - 2) + 1;

        tempFoodPos = objPos(candX, candY, '%');

        // for(int i= 0; i < blockOff->getSize(); i++){
        //     blockOff->getElement(snakePos, i);
        //     // samePos = tempPos.isPosEqual()
        //     if(tempFoodPos.isPosEqual(&snakePos)){
        //         flag = true;
        //     }
        // }

    } while(blockOff.isPosEqual(&tempFoodPos) && flag);

    

    foodPos = tempFoodPos;
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}