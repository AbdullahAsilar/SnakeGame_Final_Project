#include "Food.h"
#include "Player.h"
// #include "GameMechs.h"

#define ITEM_COUNT 5

Food::Food(GameMechs* thisGMRef){
    MechsRef = thisGMRef;
    
    // starting off with not being on the board. 
    foodPos.setObjPos(-1,-1,'o');

    
    foodBucket = new objPosArrayList();
    foodBucket->insertHead(foodPos);
}

Food::~Food(){
    // destructor 
    delete foodBucket;
}

objPosArrayList* Food::getFoodBucket(){
    // returning the foodbucket. 
    return foodBucket;
}

void Food::setFoodIndex(int i){
    foodIndex = i;
}

int Food::getFoodIndex(){
    return foodIndex;
}


void Food::generateFood(objPosArrayList* blockOff){

    // This updates every new time. 
    srand(time(NULL));
    
    int sizeX = MechsRef->getBoardSizeX();
    int sizeY = MechsRef->getBoardSizeY();

    
    for(int b = 0; b < ITEM_COUNT; b++)
    {   
        // used for random character generation 
        char symRandChar;
        int repeat = 1;
        int past;
        if(b < 3){
            foodPos.symbol = 'o';
        } 
        else
        {
            
        // generating random symbol. 

            while(repeat == 1)
            {   
                
                symRandChar = 33 + rand() % 93;
            // Checking if it doesnt equal the player symbol or #
                if(symRandChar != 111 && symRandChar != 32)
                {   
                    // assigning it a new character symbol 
                    foodPos.symbol = symRandChar;
                    break;
                }
            }
        }
        
        // generating random x and y position. 
        while (repeat == 1)
        {
            // Choosing a random y and x position. 
            int yRand = 1 + rand() % (sizeY - 2); 
            int xRand = 1 + rand() % (sizeX - 2);

            // Where are we creating the size of the list? 
            for(int i = 0; i < blockOff->getSize(); i++)
            {
                objPos tempBody = blockOff->getElement(i);
                

                if(tempBody.pos->x == xRand && tempBody.pos->y == yRand)
                {
                    repeat = 1; 
                    break;

                } else {
                    foodPos.setObjPos(xRand, yRand, foodPos.symbol);
                    repeat = 0;
                }
            }
        }
        // adding to the end of the tail.
        foodBucket->insertTail(foodPos);
    }


        
}
