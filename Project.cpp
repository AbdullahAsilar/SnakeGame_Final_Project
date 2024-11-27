#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
// #include "GameMechs.h" do you not need this bc you have included it already in player.h

#include "player.h" // so we can have access to file

using namespace std;

#define DELAY_CONST 100000

// used to creating a pointer to point to the heap, pointer will be returned 
Player *myPlayer; // Global pointer 
GameMechs *myGM;

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
    myPlayer = new Player(myGM); 



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
    objPos playerPos = myPlayer -> getPlayerPos(); 
    // MacUILib_printf("Player [x, y, symbol]: [%d][%d][%c]", playerPos.pos -> x,\
    //             playerPos.pos->y, playerPos.symbol);    


    for (int row =0; row < myGM->getBoardSizeY(); row ++){
        if(row ==0 || row == (myGM->getBoardSizeY() - 1)){
            for (int column = 0; column < myGM->getBoardSizeX(); column++){
                MacUILib_printf("#");
            }
        }
        else{
            for (int column = 0; column < myGM->getBoardSizeX(); column++){
                if (row == playerPos.pos->y && column == playerPos.pos->x){
                    MacUILib_printf("%c", playerPos.symbol);
                }
                else if (column == 0 || column == (myGM->getBoardSizeX() -1)){
                    MacUILib_printf("#");
                }
                else{
                    MacUILib_printf(" ");
                }
            }
        }
        printf("\n");
    }

    // We will be using this to print the speed on the screen. 
    
    // Adding some information for the user to see. 
    MacUILib_printf("Current x Position = %d ", playerPos.pos->x);
    MacUILib_printf(", Current y Position = %d\n", playerPos.pos->y);
    
    

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
