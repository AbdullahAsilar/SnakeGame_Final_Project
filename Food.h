#ifndef FOOD_H
#define FOOD_H
// This header file declares the class that creates the 
// objects on the screen that can interact or be eaten by our snake

#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    private:
        objPos foodPos;
        GameMechs* MechsRef;
        objPosArrayList* foodBucket;
        int foodIndex; // dictates which food to spam depending on index

    public:
        // We need to add a default constrcutor? 
        Food(GameMechs* thisGMRef);
        ~Food();

        void setFoodIndex(int i);
        int getFoodIndex();

        void generateFood(objPosArrayList* blockOff);
        objPosArrayList* getFoodBucket();
};

#endif