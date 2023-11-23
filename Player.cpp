#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                        mainGameMechsRef->getBoardSizeY()/2,
                        '@');
    // more actions to be included

    //no heap memeber yet -  never used new keyword

}


Player::~Player()
{
    // delete any heap members here
    //empty for now
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list (dont worrty about this for now)
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

    //board size from gamemechanism
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();

    switch(myDir){
        case UP:
            playerPos.y = (playerPos.y-1+boardY)%boardY; //in chance of negative add boardY size
        case DOWN:
            playerPos.y = (playerPos.y+1)%boardY; //dont need to add since playerPos.y can only exceed and modulo covers that 
        case LEFT:
            playerPos.x = (playerPos.x-1+boardX)%boardX; // same reasoning as y positions
        case RIGHT:
            playerPos.x = (playerPos.x+1)%boardX;
        default:
            break;
    }

}

