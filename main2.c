#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//prototyping our functions:
void greet(void);
int chooseJuice(void);
int checkJuiceAnswer(int answer);
int chooseLiters(void);
int checkLiters(int liters, int digit_is_true);
int scanCanAnswer(int answer);
int chooseCanisters(int answer);
int evalCanisterQuantity(int liters, int canisters);

int scanCanAnswer(int answer);
int costsCalc(int answer, int liters, int canisters, int canisterSize);
void confirmOrder(void);
void cleanBuffer(void);
int main(){
    int answer, liters, canistersize, canisters;
    greet();
    answer = chooseJuice();
    liters = chooseLiters();
    canistersize = chooseCanisters(answer);
    canisters = evalCanisterQuantity(liters, canistersize);
    costsCalc(answer, liters, canisters, canistersize);
    confirmOrder();
}
void greet(void){
    printf("Welcome to the juice filling machine calculator!\n");
}

int chooseJuice(){
    int answer;
    printf("\nWhich juice do you want to fill?\n1. Orange juice\n2. Apple juice\n>");
    scanf("%d", &answer);
    answer = checkJuiceAnswer(answer);
    return answer;
}

int checkJuiceAnswer(int answer){
    if(answer == 1 || answer == 2){
        return answer;
    }else{
        while(answer != 1 && answer != 2){
             cleanBuffer();
            //then we print our error message, so that we don't get it twice
            printf("Invalid input! Please choose a valid juice.\n");
            scanf("%d", &answer);            
        }
        return answer;
    }
}

int chooseLiters(void){
    int liters, digit_is_true;
    printf("\nHow many litres do you want to fill? (1 to 1000)\n >");
    digit_is_true = scanf("%d", &liters);
    liters = checkLiters(liters, digit_is_true);
    return liters;
}

int checkLiters(int liters, int digit_is_true){
    if(digit_is_true){
         if(liters >= 1 && liters <= 1000){
            return liters;
         }else{
             while(liters < 1 || liters > 1000 || !digit_is_true){
            cleanBuffer();
            printf("Invalid input! Please choose a valid amount.\n");
            digit_is_true = scanf("%d", &liters);
            }
            return liters;
         }
    }else{
        while(liters < 1 || liters > 1000 || !digit_is_true){
            //dispose of the rest of the characters, that the user may have typed wrong:
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input! Please choose a valid amount.\n");
            digit_is_true = scanf("%d", &liters);
        }
        return liters;
    }
    //  if(scanf("%d", &liters) != 1){//if it doesn't match the digit format;
         
    //         if(liters >= 1 && liters <= 1000){
    //             return 1;
    //         }else{
    //             while(liters < 1 || liters > 1000){
    //                 printf("Invalid input! Please choose a valid amount.\n");
    //             }
    //             return 1;
    //         }
    // }
    return 0;
}

int chooseCanisters(int answer){
    int litersperCanister;
    if(answer == 1){
        printf("\nWhich size of canister would you like to use for your orange juice?\n");
        printf("- 5 litres\n- 10 litres\n- 20 litres\n > ");
        litersperCanister = scanCanAnswer(answer);
    }else if(answer == 2){//we could obviously skip this equality
        printf("\nWhich size of canister would you like to use for your apple juice?\n");
        printf("- 5 litres\n- 15 litres\n- 25 litres\n > ");
        litersperCanister =  scanCanAnswer(answer);
    }
    return litersperCanister;
}

int scanCanAnswer(int answer){
    int canisterCapacity, reply_is_true = 0;//the reply for our canisters;
    int reply_is_digit = scanf("%d", &canisterCapacity);
    while(!reply_is_digit){
        cleanBuffer();
        printf("Invalid input! Please choose a valid canister size.\n");
        reply_is_digit = scanf("%d", &canisterCapacity);
    }//the answer must be a digit
    while(!reply_is_true){
       
        if(answer == 1){
            int array[3] = {5, 10, 20};
            for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++){
                if(array[i] == canisterCapacity){
                    reply_is_true = 1;
                }
            }
            if(reply_is_true == 0){
                cleanBuffer();
                printf("Invalid input! Please choose a valid canister size.\n");
                scanf("%d", &canisterCapacity);
            }
        }else if(answer == 2){
            int array[3] = {5, 15, 25};
            for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++){
                if(array[i] == canisterCapacity){
                    reply_is_true = 1;
                }
            }
            if(reply_is_true == 0){
                cleanBuffer();
                printf("Invalid input! Please choose a valid canister size.\n");
                scanf("%d", &canisterCapacity);

            }
        }
    }
    return canisterCapacity;
    
}

int evalCanisterQuantity(int liters, int canistersize){
    int fullcanisters, leftover, result;
    fullcanisters = floor(liters / canistersize);
    leftover = liters % canistersize;

    printf("\nIt is possible to fill %d canisters with the size of %d litres.\n", fullcanisters, canistersize);
    printf("This results in %d left-over litres.\n", leftover);
    return fullcanisters;
}

int  costsCalc(int answer, int liters,int canisters, int canisterSize){
    //juice type:
    double costPerLiter, canisterPrice, juiceCosts, totalCost, machineFlatRate = 5.00;
    char * array[2] = {"Orange", "Apple"}; 
    printf("\nThe filling costs are:\n----------------------------------------------\n");
    if(answer == 1){
        costPerLiter = 0.2;
    }else{
        costPerLiter = 0.15;
    }
    juiceCosts = costPerLiter * liters;
    switch(canisterSize){
        case(5): {
            canisterPrice = 0.1 * canisters;
            break;
        }
        case(10): {
            canisterPrice = 0.15 * canisters;
            break;
        }
        case(15): {
            canisterPrice = 0.2 * canisters;
            break;
        }
        case(20): {
            canisterPrice = 0.2 * canisters;
            break;
        }
        case(25): {
            canisterPrice = 0.25 * canisters;
            break;
        }
    }
    totalCost = juiceCosts + canisterPrice + machineFlatRate;
    printf("- %d litres of %s juice: %.2f \u20AC\n", liters, array[answer - 1], juiceCosts);
    printf("- %d canisters: %.2f €\n", canisters, canisterPrice);
    printf("- Flat rate for using the machine: %.2f \u20AC\n", machineFlatRate);
    printf("----------------------------------------------\n");
    printf("This results in a total cost of %.2f \u20AC.\n", totalCost);
    return 0;
}

void confirmOrder(void){
    int is_digit, answer, is_true = 0;
    printf("\nAre you sure you want to fill the canisters?\n1. Yes\n2. No\n >");
    is_digit = scanf("%d", &answer);
    cleanBuffer();
    while(!is_true){
        if(answer == 1){
            printf("\nThe canisters will be filled as soon as we receive your payment.\n");
            printf("Thank you for using the juice filling machine calculator!\n");
            is_true = 1;
        }else if(answer == 2){
            is_true = 1;
        }else{
            printf("Invalid input! Please choose a valid option.\n");
            is_digit = scanf("%d", &answer);
            cleanBuffer();
        }
    }
    
}

void cleanBuffer (void){
    //dispose of the rest: (We don't care about the rest as long as first character is an integer)
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
