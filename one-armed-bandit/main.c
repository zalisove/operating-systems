#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "protected-input.h"
#include "user-interface-text.h"

int* generateArray(int length);
void printArray(int* array, int length);
int maxNumberIdenticalElements(int* array, int length);
int countIdenticalElements(int* array, int length, int number);
int countIdenticalElements(int* array, int length, int number);
int contains(int* array, int length, int number);

int main() {
    srand(time(NULL));

    int length = 3;

    
    double budget;
    
    printEnterBudget();

    while (1){
        budget = protectedInputDouble();
        if (budget > 0){
            break;
        }
        printf("Your introduced a negative budget or your budget equals zero\n");
        printEnterBudget();
    }
    

    int play = 1;
    while (play) {

        printEnterYourBet();
        double bet;

        while (1){
            bet = protectedInputDouble();
            if (bet > 0 && (budget-bet) >= 0){
                break;
            }
            printf("Your introduced a negative bet or your bet is more than budget\n");
            printEnterYourBet();
            
        }
        
        int* array = generateArray(length);
        printArray(array, length);

        if (countIdenticalElements(array, length, 7) == length) {
            printYouWinX(3);
            budget += bet * 3.0;
        } else if (maxNumberIdenticalElements(array,length) == length) {
            printYouWinX(2);
            budget += bet * 2.0;
        } else if (contains(array, length, 7)) {
            printReturnYourBet();
        } else if (maxNumberIdenticalElements(array,length) >= (length * 2.0 / 3.0)){
            printReturnYourBet();
        }else {
            printYouLose();
            budget -= bet;
        }

        printYourCurrentBudget(budget);

        if (budget <= 0) {
            printGameOver();
            play = 0;
        } else {
            printDoYouWantContinue();
            int wannaContinue = choice();
            if (wannaContinue == 0) {
                play = 0;
            }
        }
    }

    printThanksForPlaying();
    return 0;
}



int* generateArray(int length) {
    int* array = (int*)malloc(sizeof(char) * length);
    
    for (int index = 0 ; index < length ; index++) {
        array[index] = (rand() % 7) + 1;
    }

    return array;
}

void printArray(int* array, int length) {
    for (int index = 0; index < length; index++) {
        printf("%d ", array[index]);
    }
    printf("\n");
}

int maxNumberIdenticalElements(int* array, int length){
    int maxCount = 0;
    
    for (int i = 0; i < length; i++){
        int currectCount = countIdenticalElements(array,length,array[i]);
        if (maxCount < currectCount){
            maxCount = currectCount;
        }
    }
    return maxCount;
}

int countIdenticalElements(int* array, int length, int number){
    int count = 0;

    for (int i = 0; i < length; i++){
        if (array[i] == number){
            count++;
        }
    }
    return count;
}

int contains(int* array, int length, int number) {
    for (int index = 0; index < length; index++) {
        if (array[index] == number) {
            return 1;
        }
    }
    
    return 0;
}
