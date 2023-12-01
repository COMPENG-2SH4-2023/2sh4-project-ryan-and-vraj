#include "Player.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPos.h"

Player::Player(GameMechs* thisGMRef, Food* foodReference)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    food = foodReference;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                        mainGameMechsRef->getBoardSizeY()/2,
                        '*');
    // more actions to be included

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    //for debugging purpose, insert anotehr 4 segments
    // playerPosList->insertHead(tempPos);
    // playerPosList->insertHead(tempPos);
    // playerPosList->insertHead(tempPos);
    // playerPosList->insertHead(tempPos);
    

}


Player::~Player()
{
    // delete any heap members here
    //empty for now
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    //returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list (dont worrty about this for now)
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    //Where do I get tyhe input?? How do i check for inputs???
    //Hint1 defintely not by calling macuiliv_getchar()!!
    //hint 2 coordinate with you team member whos designing game mechanism classs
    //hint 3 there will be a mthod in GameMecahnism clas that collectively 
    //checks inoput and store the most recvent input, you just need to figure out
    //HOw to get to it
    //HOW??? it lies within the GameMechs* inside private member
    char input = mainGameMechsRef->getInput();
    switch(input){
        case 'w': // for w
            if(myDir == STOP || myDir == LEFT || myDir == RIGHT){
                myDir = UP;
                
            }
            break;
        case 'a': //for a
            if(myDir == STOP || myDir == UP || myDir == DOWN){
                myDir = LEFT;
                
            }
            break;
        case 's': //for s
            if(myDir == STOP || myDir == LEFT || myDir == RIGHT){
                myDir = DOWN;
            }
            break; 
        case 'd': //for d
            if(myDir == STOP || myDir == UP || myDir == DOWN){
                myDir = RIGHT;
            }
            break;   
        default:
            break;      
    }     
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos currHead;
    playerPosList->getHeadElement(currHead); // holding pos information of the curent head
    //board size from gamemechanism
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();


    if(myDir == UP){
        currHead.y--;
        //if playerPos is too exceeds the border, then reset back at bottom of border
        if(currHead.y < 1){
            currHead.y = boardY-2;
        }
    } else if (myDir == LEFT){
        currHead.x--;
        //if the playerPos is too much to the left then reset the position all the way to the right before border
        if(currHead.x < 1){
            currHead.x = boardX-2;
        }
    } else if (myDir == DOWN){
        currHead.y++;
        //if the playerPos exceeds the border at the bottom, then reset him back to the top
        if(currHead.y > boardY-2){
            currHead.y = 1;
        }

    } else if (myDir == RIGHT){
        currHead.x++;
        //if the playerPos exceeds the border at the right, then reset back to the left
        if(currHead.x > boardX-2){
            currHead.x = 1;
        }
    }

    //new currenth ead should be inserted ot the head of the list
    

    if(checkFoodConsumption()){
        // playerPosList->insertHead(currHead);
        // playerPosList->removeTail();
        increasePlayerLength();
    } else {

        playerPosList->insertHead(currHead);
        playerPosList->removeTail();
    }

}


bool Player::checkFoodConsumption(){

    objPos tempFoodPos;
    food->getFoodPos(tempFoodPos);

    objPos currHead;
    playerPosList->getHeadElement(currHead);
    
    if(tempFoodPos.isPosEqual(&currHead)){
        //increasePlayerLength();
        mainGameMechsRef->incrementScore();

        //implement after figuring out how arrayList implementation works
        //objPosArrayList* playerBody = getPlayerPos();
        food->generateFood(playerPosList);

        return true;

    }
    return false;
}




void Player::increasePlayerLength(){
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    playerPosList->insertHead(currHead);
}


bool Player::checkSelfCollision(){ //the program suspends immediately whenever snake body is more than one, why?
    objPos tempPos;
    playerPosList->getHeadElement(tempPos); //can i just add headPos as a private memeber so i donty have tp declare it everytime i want to use it
    bool flag = false;
    
    for(int i =1; i < playerPosList->getSize(); i++){ //starting from 1 so it can skip the head
        objPos currHead;
        playerPosList->getElement(currHead,i); //get the current element of each of the player body

        if(tempPos.isPosEqual(&currHead)){ //if the head touches any other element of the player then collision is detected
            return true;
        }
        flag = tempPos.isPosEqual(&currHead);
    }
    return false; // no collisiojn
}
