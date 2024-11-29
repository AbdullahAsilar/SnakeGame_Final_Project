#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
// #include "GameMechs.h" do you not need this bc you have included it already in player.h

#include "player.h" // so we can have access to file

using namespace std;

#define DELAY_CONST 100000

// used to creating a pointer to point to the heap, pointer will be returned 
Player *myPlayer; // Global pointer 
GameMechs *myGM;
Food *myFood;

//  Declaring functions 
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(); 
    myPlayer = new Player(myGM, myFood); 
    myFood =new Food(myGM);
    
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPosArrayList* foodBucket = myFood->getFoodBucket();

    myFood->generateFood(playerBody);
    // myGM->getExitFlagStatus() = false; Why dont you need this
}

void GetInput(void)
{
    myGM->getInput(); 

}

void RunLogic(void)
{
    
    // if (myGM->getInput() != 0){ 
        myPlayer ->updatePlayerDir();  
        // myGM ->getInput();
        myGM->clearInput(); 
        myPlayer ->movePlayer();
    // }
    

}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    bool drawn;
    objPos tempBody;
    objPos tempFoodPos;
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPosArrayList* foodBucket = myFood->getFoodBucket();
    
    // MacUILib_printf("Player [x, y, symbol]: [%d][%d][%c]", playerPos.pos -> x,\
    //             playerPos.pos->y, playerPos.symbol);    

    static int count = 0; 
    count ++; 
    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for(int j = 0; j < myGM->getBoardSizeX(); j++)
        {

            drawn = false;
            for(int k = 0; k < playerBody->getSize(); k++)
            {
               tempBody =  playerBody->getElement(k);

                if(tempBody.pos->x == j && tempBody.pos->y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn =true;
                    break;
                }
            }

            if(drawn) continue;
         

            for(int l = 0; l < foodBucket->getSize(); l++)
            {
                tempFoodPos = foodBucket->getElement(l);
                if(tempFoodPos.pos->x == j && tempFoodPos.pos->y == i)
                {
                    MacUILib_printf("%c", tempFoodPos.symbol);
                    drawn = true;
                }
            }

          
            if(drawn) continue;

            // draw border
            if(i == 0 || i == (myGM->getBoardSizeY() - 1)|| j == 0 || j == (myGM->getBoardSizeX() - 1))
            {
                MacUILib_printf("%c", '#');
            }
            else 
            {
                MacUILib_printf("%c", ' ');
            }
            
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Press ESC to quit\n");
    MacUILib_printf("%d", count);

    //Generating Ran

    // We will be using this to print the speed on the screen. 
    
    // Adding some information for the user to see. 
   
    

    // MacUILib_printf("Fastest game speed = '%.3f', ", 0.045);
    // MacUILib_printf("Slowest game speed = '%.2f'\n", 0.0);

    // MacUILib_printf("To increase your speed press '=', To decrease your speed press '-'");



}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    delete myGM; 
    delete myPlayer;  // deallocating 


    MacUILib_uninit();
}
