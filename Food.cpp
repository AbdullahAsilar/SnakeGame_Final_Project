// #include "Food.h"
// // #include "Player.h"
// // #include "GameMechs.h"

// #define ITEM_COUNT 1

// Food::Food(GameMechs* thisGMRef){
//     MechsRef = thisGMRef;
    
//     foodPos.setObjPos(-1,-1,'o');

//     foodBucket = new objPosArrayList();
//     foodBucket->insertHead(foodPos);
// }

// Food::~Food(){
//     delete foodBucket;
// }

// objPosArrayList* Food::getFoodBucket(){
//     return foodBucket;
// }

// void Food::setFoodIndex(int i){
//     foodIndex = i;
// }

// int Food::getFoodIndex(){
//     return foodIndex;
// }

// void Food::generateFood(objPosArrayList* blockOff){

//     // srand(time(NULL));

//     // int sizeX = MechsRef ->getBoardSizeX();
//     // int sizeY = MechsRef ->getBoardSizeY();
    

//     // for(int b = 0; b<5; b++){
//     //     foodPos.symbol = 'o';

//     //     int yRand = 1 + rand() % (sizeY - 2);
//     //     int xRand = 1 + rand() % (sizeX - 2);
//     // }


//     char result_char[ITEM_COUNT] = {0}; // intiaizing all the arrays below. 
//     int result_x[ITEM_COUNT] = {0};
//     int result_y[ITEM_COUNT] = {0};
//     int i; 
//     int count_char = 0;  // intailizing the array count to start at 0 for all variables. 
//     int any_char_count = 0;
//     int count_x = 0;
//     int count_y = 0; 

//     char candidate = 0;  // NULL  the next three lines represent the the struct members we are currently using. 
//     int candidate_x= 0;
//     int candidate_y = 0;

//     // Two things to add, 
//     // 1. We cant have the letters overlap on the player to begin with, and second it cannot have the same charcter (latter)

//     // Seed the random number (integer) generation (RNG)

//     srand(time(NULL)); // this is so we can update the seed every time the current time changes
//                        // This helps us create more randoness. 

//     // int xRange = 18;
//     // int yRange = 8; 
//     int row_boardsize = MechsRef ->getBoardSizeX() - 2;
//     int column_boardsize = MechsRef ->getBoardSizeX() - 2;

//     // Method 2: Bit-Vector (faster generation)
//     // int index_arr[1] = {0}; // bit vector look up table.
//     int index_arr_x[row_boardsize] = {0}; // 0-row size
//     int index_arr_y[column_boardsize] = {0}; // 0- column size 


//     // while (any_char_count < ITEM_COUNT) // The next three are used to select from a random pull of numbers. 
//     // {
//     //     // candidate = rand() %93; // [0, 92] 


//     //     // if (index_arr[candidate] == 0 && candidate + 33 != '#' && candidate + 33 != ' ' && candidate + 33 != '$' && candidate + 33 != result_char[0] && candidate + 33 != result_char[1]){ // not taken

//     //     //     index_arr[candidate] = 1;
//     //     //     result_char[any_char_count + 2] = candidate + 33; // this is so it equals a letter. 
//     //     //     any_char_count++; 
//     //     // }



//     // }
//     count_x = 0; 

//     while (count_x < ITEM_COUNT) 
//     {
//         candidate_x = rand() %row_boardsize; // [0, 17]

//         if (candidate_x == PlayerPosx){
//             candidate_x = rand() %xRange; // [0, 17] re-roll 
//         }

//         if (index_arr_x[candidate_x] == 0){ // not taken

//             index_arr_x[candidate_x] = 1;
//             result_x[count_x] = candidate_x + 1;
//             count_x++; 
//         }
//     }
//     count_y = 0; 
//     while (count_y < 5)
//     {
//         candidate_y = rand() %yRange; // [0, 7]


//         if (index_arr_y[candidate_y] == 0){ // not taken

//             index_arr_y[candidate_y] = 1;
//             result_y[count_y] = candidate_y + 1;
//             count_y++; 
//         }
//     }

//     // this is kinda redunant, I couldve define it above. // but it actually wont let me. 
//     for(i=0; i<5; i++){
//         item_bin[i].symbol = result_char[i];
//     }
//     // printf("\n");
//     for(i=0; i<5; i++){
//         item_bin[i].x = result_x[i];
//     }
//     // printf("\n");

//     for(i=0; i<5; i++){
//         item_bin[i].y = result_y[i];
//     }

// }
