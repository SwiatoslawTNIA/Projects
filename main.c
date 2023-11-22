// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// //prototyping the function:
// int greeting(void);
// int checkAnswer(int answer);
// int checkLiters(int literAmount);
// int checkCanister( int answer, int canisterSize);


// int main(){
//     int answer, check, canisterSize;
//     double literAmount;

//     answer = greeting();
//     //function check the answer;
//     check = checkAnswer(answer);
    
//     // //choosing the amount of juice in liters;
//     // printf("\nHow many liters do you want to fill? (1 to 1000)\n>");
//     // scanf("%lf", &literAmount);
//     // // checkLiters(literAmount);
//     // //now we know that literAmount is alright.Canister size:
//     // while(literAmount > 1000 || literAmount < 1){

//     //         printf("Invalid Input. Please choose a valid amount!\n>");
//     //         scanf("%lf", &literAmount);
//     //         if(literAmount <= 1000 && literAmount >= 1){
//     //             break;
//     //         }
//     // }
//     // //canister size:(working with answer);
//     // if(answer == 1){
//     //     printf("\nWhich size of canister would you like to use for your orange juice?\n- 5 litres\n");
//     //     printf("- 10 litres\n- 20 litres\n > ");
//     // }else{
//     //     printf("\nWhich size of canister would you like to use for your apple juice?\n- 5 litres\n");
//     //     printf("- 15 litres\n- 25 litres\n > ");
//     // }
//     // scanf("%d", &canisterSize);

//     // char canisterRight = checkCanister(answer, canisterSize);//check if the value is true;
//     // while(canisterRight == 'F'){
//     //     printf("Invalid input! Please choose a valid canister size.\n");
//     //     scanf("%d", &canisterSize);

//     // }
//     return 0;
// }
// int checkCanister(int answer, int canisterSize){
//     char value = 'F';
//     if(answer == 1){//if it is orange juice
//         int possibilities[3] = {5, 10, 20};

//         for(int i = 0; i < sizeof(possibilities) / sizeof(possibilities[0]); i++){
//             if(possibilities[i] == canisterSize){
//                 value = 'T';
//             }
//         }
//     }else if(answer == 2){
//         int possibilities[3] = {5, 15, 25};

//         for(int i = 0; i < sizeof(possibilities) / sizeof(possibilities[0]); i++){
//             if(possibilities[i] == canisterSize){
//                 value = 'T';
//             }
//         }
//     }
//     return value;
// }
// int checkLiters(int literAmount){
//     // if(isdigit(literAmount) && literAmount >= 1 && literAmount <= 1000){
//     //     return 0;
//     // }else{
//     //     printf("Invalid Input. Please choose a valid amount!.\n>");
//     //     scanf("%d", &literAmount);

       
//         // return (checkLiters(literAmount));
//         return 0;
//     // }
// }

// int checkAnswer(int answer){
//     if(answer == 1 || answer == 2){
//        return 1;
//     }else{
//         //if we type several letters, then the message will be displayed several times, so:
//          while(answer != 1 && answer != 2){
//             printf("Invalid Input. Please choose a valid juice.\n");
//             scanf("%d", &answer);
//             //clean the buffer of characters:(reads the characters, continues until it encounters either a 
//             //new line or an end of file)
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);

//             if( answer == 1 || answer == 2){
//                 return answer;
//             }
            
//         }
      
//     }
    
//     return 0;
// }
// int greeting(void){
//     int answer;
//     printf("Welcome to the juice machine calculator!\n");
//     printf("Which juice do you want to fill?\n");
//     printf("1. Orange juice\n");
//     printf("2. Apple juice\n");
//     scanf("%d", &answer);
//     return (answer);
// }