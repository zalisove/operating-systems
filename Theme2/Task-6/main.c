#include <stdlib.h>
#include <stdio.h>
#include "lib/matrix.h"

int main(int argc, char const *argv[]){
    
    //New matrix
    Matrix* matrix1 = newMatrix(2,2);
    initMatrixByConsole(matrix1);

    //Save matrix
    saveMatrixInFile(matrix1,"matrix.data");

    //Read saved matrix
    Matrix* savedMatrix = readMatrixFromTheFile("matrix.data");

    //Print saved matrix
    printf("\n");
    printMatrix(savedMatrix);
    printf("\n");

    //New matrix 2
    Matrix* matrix2 = newMatrix(2,2);
    initMatrixByConsole(matrix2);

    //Print matrix 1 and 2
    printMatrix(matrix1);
    printMatrix(matrix2);

    printf("Sum: \n");
    Matrix* sumMatrix = sum(matrix1,matrix2);
    printMatrix(sumMatrix);

    printf("Subtraction : \n");
    Matrix* subtractionMatrix = subtraction(matrix1,matrix2);
    printMatrix(subtractionMatrix);

    //Set and get matrix item
    set(matrix1,0,0,999);
    printf("get: %0.2lf\n\n", get(matrix1,0,0));

    //Resized matrix
    resizeMatrix(matrix1,3,2);
    resizeMatrix(matrix2,2,3);

    //Input Matrix
    printf("\n");
    initMatrixByConsole(matrix1);
    printf("\n");
    initMatrixByConsole(matrix2);

    printf("\n");
    printMatrix(matrix1);
    printf("\n");
    printMatrix(matrix2);

    //Multiplication matrix
    Matrix* multiplicationMatrix = multiplication(matrix1,matrix2);

    printf("\n");
    printMatrix(multiplicationMatrix);

    //Multiplication to num;

    Matrix* multiplicationMatrixByNumber = multiplicatioByNumber(matrix1,5);
    printf("\n");
    printMatrix(multiplicationMatrixByNumber);


    clearMatrix(matrix1);
    clearMatrix(matrix2);
    clearMatrix(sumMatrix);
    clearMatrix(subtractionMatrix);
    clearMatrix(multiplicationMatrix);
    clearMatrix(multiplicationMatrixByNumber);
    return 0;
}
