#include "Food.h"

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

    int sizeX = MechsRef ->getBoardSizeX();
    int sizeY = MechsRef ->getBoardSizeY();
    

    for(int b = 0; b<5; b++){
        foodPos.symbol = 'o';

        int yRand = 1 + rand() % (sizeY - 2);
        int xRand = 1 + rand() % (sizeX - 2);
    }
}
