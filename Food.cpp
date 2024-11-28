#include "Food.h"
#include "Player.h"
// #include "GameMechs.h"

#define ITEM_COUNT 1

Food::Food(GameMechs* thisGMRef){
    MechsRef = thisGMRef;
    
    foodPos.setObjPos(-1,-1,'o');

    foodBucket = new objPosArrayList();
    foodBucket->insertHead(foodPos);
}

Food::~Food(){
    delete foodBucket;
}

objPosArrayList* Food::getFoodBucket(){
    return foodBucket;
}

void Food::setFoodIndex(int i){
    foodIndex = i;
}

int Food::getFoodIndex(){
    return foodIndex;
}


void Food::generateFood(objPosArrayList* blockOff){

    srand(time(NULL));

    int sizeX = MechsRef->getBoardSizeX();
    int sizeY = MechsRef->getBoardSizeY();
 
    
    for(int b = 0; b < 5; b++)
    {
        char symRandChar;
        int repeat = 1;
        int past;
        if(b < 3){
            foodPos.symbol = 'o';
        } 
        else
        {
            while(repeat == 1)
            {
                symRandChar = 33 + rand() % 93;
                if(symRandChar != 111 && symRandChar != 32)
                {
                    foodPos.symbol = symRandChar;
                    break;
                }
            }
        }
        
        while (repeat == 1)
        {
            int yRand = 1 + rand() % (sizeY - 2);
            int xRand = 1 + rand() % (sizeX - 2);

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

        foodBucket->insertTail(foodPos);
    }


        
}
