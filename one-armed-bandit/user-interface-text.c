#include <stdio.h>

/** -------------------------------Input data messages-------------------------------*/
void printEnterBudget() {
    printf("Enter your budget: ");
}

void printEnterYourBet() {
    printf("Enter your bet: ");
}

/** -------------------------------Game messages-------------------------------*/
void printYouWinX(int number) {
    printf("You win x%d!\n", number);
}
void printReturnYourBet() {
    printf("Return your bet\n");
}
void printDoYouWantContinue() {
    printf("Do you want to continue playing?(1(Yes) / 0(No)): ");
}
void printYouLose() {
    printf("You lose\n");
}
void printYourCurrentBudget(int budget) {
    printf("Your current budget: %d\n", budget);
}
void printGameOver() {
    printf("Game Over! You lose all your money!\n");
}
void printThanksForPlaying() {
    printf("Thank you for playing!\n");
}
