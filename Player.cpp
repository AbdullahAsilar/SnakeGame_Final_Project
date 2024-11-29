#include "Player.h"


// This would be your constructor. 
Player::Player(GameMechs* thisGMRef, Food* thisFREf)
{
    mainGameMechsRef = thisGMRef;
    myFSMMode = STOP; // default state to stop 
    mainFoodRef= thisFREf;

    // more actions to be included
    // We divide by 2, so that we could start in the middle. 
    playerPos.pos ->x = mainGameMechsRef ->getBoardSizeX() /2;
    playerPos.pos ->y = mainGameMechsRef ->getBoardSizeY() /2;
    playerPos.symbol = '*';
    objPos tempPos;
    tempPos.setObjPos(playerPos.pos ->x,playerPos.pos ->y,playerPos.symbol);
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);


}


Player::~Player()
{
    // delete any heap members here
    // nothing is placed in the heap for now
    // so you could leave empty for now. 
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
     // this is return by value. 
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
        // }
        // input = 0;s
    // }
    // switch (input)  
    // {
        
        case 'w':
            if (myFSMMode != DOWN){
                    myFSMMode = UP;
                break;
            } else {
                break;
            }
    
        case 'a':
            if (myFSMMode != RIGHT){
                    myFSMMode = LEFT;
                break;
            } else {
                break;
            }

        case 's':
            if (myFSMMode != UP){
                    myFSMMode = DOWN;
                break;
            } else {
                break;
            }
        

        case 'd':
            if (myFSMMode != LEFT){
                    myFSMMode = RIGHT;
                break;
            } else {
                break;
            }
        input = 0;
    }
    }
    mainGameMechsRef->clearInput();

}



//     switch (myFSMMode)
//     {

//         // This is the state
//         case LEFT:
//             // stopped = 0;
//             // This is an event
//             if(input == 'W' || input == 'w'){
//                 myFSMMode = UP;
//                 break;
//             }

//             else if(input == 'S' || input == 's'){
//                 myFSMMode = DOWN;
//                 break;
//             }
//         // This is the state
//         case RIGHT:
//             // stopped = 0;

//             if(input == 'W' ||  input == 'w'){
//                 myFSMMode = UP;
//                 break;
//             }

//             else if(input == 'S' || input == 's'){
//                 myFSMMode = DOWN;
//                 break;
//             }

//         case UP:
//             // stopped = 0;

//             if(input == 'A' || input == 'a'){
//                 myFSMMode = LEFT;
//                 break;
//             }

//             else if(input == 'D' ||  input == 'd'){
//                 myFSMMode = RIGHT;
//                 break;
//             }

//         case DOWN:
//             // stopped = 0;

//             if(input == 'A' ||  input == 'a'){
//                 myFSMMode = LEFT;
//                 break;
//             }

//             else if(input == 'D' || input == 'd'){
//                 myFSMMode = RIGHT;
//                 break;
//             }

//         case STOP:
//             // stopped = 1;
//             if(input == 'A' || input == 'a'){
//                 myFSMMode = LEFT;
//                 break;
//             }
//             else if(input == 'D' || input == 'd'){
//                 myFSMMode = RIGHT;
//                 break;
//             }
//             else if(input == 'W' || input == 'w'){
//                 myFSMMode = UP;
//                 break;
//             }
//             else if(input == 'S' || input == 's'){
//                 myFSMMode = DOWN;
//                 break;
//             }
//             // else
//             // {
//             //     myFSMMode = STOP; 
//             //     break; 
//             // }

//         default:
//             // myFSMMode = STOP;
//             break;
//     }


//     mainGameMechsRef->clearInput(); // resets input

// }}

// void Player::movePlayer()
// {
    // PPA3 Finite State Machine logic
//     switch (myFSMMode)
//     {
//     case LEFT:
//         playerPos.pos ->x --; // Shifting string left by 1 character
//         if (playerPos.pos ->x < 1){
//             playerPos.pos ->x = mainGameMechsRef->getBoardSizeX() - 2;
//         }
//         break;


//     case RIGHT:
//         playerPos.pos ->x ++; // Shifting string left by 1 character
//         if (playerPos.pos ->x > mainGameMechsRef->getBoardSizeX() - 2){
//             playerPos.pos ->x = 1;
//         }
//         break;


//     case UP: 
//         playerPos.pos ->y --; // Shifting string left by 1 character
//         if (playerPos.pos ->y < 1){
//             playerPos.pos ->y = mainGameMechsRef->getBoardSizeY() -2;
//         }
//         break;



//     case DOWN: 
//         playerPos.pos ->y ++; // Shifting string down by 1 character
//         if (playerPos.pos ->y > mainGameMechsRef->getBoardSizeY() -2){
//             playerPos.pos ->y = 1;
//         }
//         break;

//     // case STOP: 

//     //     playerPos.pos ->x = mainGameMechsRef ->getBoardSizeX() /2;
//     //     playerPos.pos ->y = mainGameMechsRef ->getBoardSizeY() /2;
//     //     playerPos.symbol = '*';

//     default:
//         break;
//     }
// }



    
    // mainGameMechsRef->clearInput(); // resets input



void Player::movePlayer()
{
    
    // PPA3 Finite State Machine logic

    
    objPos currentHead= playerPosList->getHeadElement();

    switch (myFSMMode)
    {
    case LEFT:
        currentHead.pos ->x --; // Shifting string left by 1 character
        if (currentHead.pos ->x < 1){
            currentHead.pos ->x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        break;

    
    case RIGHT:
        currentHead.pos ->x ++; // Shifting string left by 1 character
        if (currentHead.pos ->x > mainGameMechsRef->getBoardSizeX() - 2){
            currentHead.pos ->x = 1;
        }
        break;

        
    case UP: 
        currentHead.pos ->y --; // Shifting string left by 1 character
        if (currentHead.pos ->y < 1){
            currentHead.pos ->y = mainGameMechsRef->getBoardSizeY() -2;
        }
        break;

        

    case DOWN: 
        currentHead.pos ->y ++; // Shifting string down by 1 character
        if (currentHead.pos ->y > mainGameMechsRef->getBoardSizeY() -2){
            currentHead.pos ->y = 1;
        }
        break;

    // case STOP: 
        
    //     playerPos.pos ->x = mainGameMechsRef ->getBoardSizeX() /2;
    //     playerPos.pos ->y = mainGameMechsRef ->getBoardSizeY() /2;  
    //     playerPos.symbol = '*';                
        
    default:
        break;
    }

    // new current head should be inserted to the head of the list
    playerPosList->insertHead(currentHead);
    //then, remove tail
    playerPosList->removeTail();
}   

//More methods to be added