#include "Player.h"

// This would be your constructor. 
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myFSMMode = STOP; // default state to stop 

    // more actions to be included
    // We divide by 2, so that we could start in the middle. 
    playerPos.pos ->x = mainGameMechsRef ->getBoardSizeX() /2;
    playerPos.pos ->y = mainGameMechsRef ->getBoardSizeY() /2;
    playerPos.symbol = '*';


}


Player::~Player()
{
    // delete any heap members here
    // nothing is placed in the heap for now
    // so you could leave empty for now. 
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos; // this is return by value. 
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  
    // This switch case is used to determine which movement state it is in. 
    char input = mainGameMechsRef->getInput();
    // int stopped = 1; // start the game off stopped, this helps us in the printing stage. 
    
    // Should this be placed in here? 
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case '\033':  // exit
                mainGameMechsRef->setExitTrue();
                break;
                
            // Add more key processing here
            // Add more key processing here
            // Add more key processing here    
            default:
                break;
        }
        // input = 0;
    }
    switch (myFSMMode)  
    {
        
        // This is the state
        case LEFT:
            // stopped = 0;    
            // This is an event
            if(input == 'W'){
                myFSMMode = UP;
                break;
            }

            else if(input == 'S'){
                myFSMMode = DOWN;
                break;
            }
        // This is the state
        case RIGHT:
            // stopped = 0;

            if(input == 'W'){
                myFSMMode = UP;
                break;
            }

            else if(input == 'S'){
                myFSMMode = DOWN;
                break;
            }
            
        case UP:
            // stopped = 0;

            if(input == 'A'){
                myFSMMode = LEFT;
                break;
            }

            else if(input == 'D'){
                myFSMMode = RIGHT;
                break;
            }
        
        case DOWN:
            // stopped = 0;

            if(input == 'A'){
                myFSMMode = LEFT;
                break;
            }

            else if(input == 'D'){
                myFSMMode = RIGHT;
                break;
            }
            
        case STOP:
            // stopped = 1;
            if(input == 'A'){
                myFSMMode = LEFT;
                break;
            }
            else if(input == 'D'){
                myFSMMode = RIGHT;
                break;
            }
            else if(input == 'W'){
                myFSMMode = UP;
                break;
            }
            else if(input == 'S'){
                myFSMMode = DOWN;
                break;
            }
            else
            {
                myFSMMode = STOP; 
                break; 
            }

        default:
            myFSMMode = STOP;
            break;
    }

    
    // mainGameMechsRef->clearInput(); // resets input

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch (myFSMMode)
    {
    case LEFT:
        playerPos.pos ->x --; // Shifting string left by 1 character
        if (playerPos.pos ->x < 1){
            playerPos.pos ->x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        break;

    
    case RIGHT:
        playerPos.pos ->x ++; // Shifting string left by 1 character
        if (playerPos.pos ->x > mainGameMechsRef->getBoardSizeX() - 2){
            playerPos.pos ->x = 1;
        }
        break;

        
    case UP: 
        playerPos.pos ->y --; // Shifting string left by 1 character
        if (playerPos.pos ->y < 1){
            playerPos.pos ->y = mainGameMechsRef->getBoardSizeY() -2;
        }
        break;

        

    case DOWN: 
        playerPos.pos ->y ++; // Shifting string down by 1 character
        if (playerPos.pos ->y > mainGameMechsRef->getBoardSizeY() -2){
            playerPos.pos ->y = 1;
        }
        break;

    // case STOP: 
        
    //     playerPos.pos ->x = mainGameMechsRef ->getBoardSizeX() /2;
    //     playerPos.pos ->y = mainGameMechsRef ->getBoardSizeY() /2;  
    //     playerPos.symbol = '*';                
        
    default:
        break;
    }
}   

// More methods to be added