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

    objPos tempPos;

    do 
    {
        // TODO: create the getBoardSizeX() instead of BOARD_X
        candX = rand() % (BOARD_X - 2) + 1;
        candY = rand() % (BOARD_Y - 2) + 1;

        tempPos = objPos(candX, candY, '%');

    } while(blockOff.isPosEqual(&tempPos));

    foodPos = tempPos;
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}