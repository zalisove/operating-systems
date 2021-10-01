#include <stdio.h>
#include <stdlib.h>

int protectedInputInt(){
    char buff [5];

    fflush(stdin);
    fgets(buff, 5, stdin);

    int number = atoi(buff);
        
    return number;
}


int protectedInputDouble(){
    char buff [20];

    fflush(stdin);
    fgets(buff, 20, stdin);
    
    return atof(buff);
}

int choice(){
    int choose = protectedInputInt();
    if (choose == 1 || choose == 0) {
        return choose;
    } else {
        printf("Incorrect data input (1 or 0)");
    }
}
