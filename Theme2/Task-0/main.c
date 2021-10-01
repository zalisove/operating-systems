#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

typedef struct{
    int x;
    int y;
    int weight;
}Point;

Point** generatePoints(int weightFrom, int weightTo, int xFrom,int yFrom, int xTo, int yTo, int lenght);
void printPoints(Point** points, int lenght);
int randByRange(int from,int to);
int indexPointLowestMass(Point** points, int lenght);
int indexPointClosestGivenOne(Point** points, int lenght, int value);
void removePointWithLowestMassAndPassMassNearest(Point*** points, int* lenght);

int main(int argc, char const *argv[]){
    
    srand(time(NULL));
 
    int lenght = 5;
    Point** points = generatePoints(1, 10, 1, 10, 1, 10, lenght);
    printPoints(points, lenght);
    printf("min index : %d \n", indexPointLowestMass(points,lenght));
    printf("min distance index : %d \n", indexPointClosestGivenOne(points,lenght, 1));
    
    while (lenght > 1){
        removePointWithLowestMassAndPassMassNearest(&points,&lenght);
    }
    
    printf("\nLast point : \nx: %d y: %d weight: %d \n", points[0]->x, points[0]->y, points[0]->weight);
   

    return 0;
}


Point** generatePoints(int weightFrom, int weightTo, int xFrom,int xTo, int yFrom, int yTo, int lenght){

    Point** points = (Point**)malloc(sizeof(Point*) * lenght);

   for (int i = 0; i < lenght; i++){
        Point* point = (Point*)malloc(sizeof(Point));
        point->x = rand()% (xTo - xFrom) + xFrom;;
        point->y = randByRange(yFrom,yTo);
        point->weight = randByRange(weightFrom,weightTo);
        points[i] = point;
    }
    return points;
}

void printPoints(Point** points, int lenght){
    Point* tmp;
    for (int i = 0; i < lenght; i++){
        tmp = points[i];
        printf("x : %d y: %d weight: %d\n", tmp->x, tmp->y, tmp->weight);
    }
    
}

int randByRange(int from,int to){
    return rand()% (to - from) + from;
}

int indexPointLowestMass(Point** points, int lenght){
    int index = 0;

    for (int i = 0; i < lenght; i++){
        if (points[index]->weight > points[i]->weight){
            index = i;
        }
    }
    return index;
}

int indexPointClosestGivenOne(Point** points, int lenght, int value){

    int index = 0;
    Point* a = points[value];
    int minDistance = __INT_MAX__;

    for (size_t i = 0; i < lenght; i++){
        if (i == value){
            continue;
        }
        
        Point* b = points[i];
        int distance = sqrt(pow((a->x - b->x),2) + pow(a->y - b->y, 2));

        if (minDistance > distance){
            minDistance = distance;
            index = i;
        }
    }
    return index;
}

void removePointWithLowestMassAndPassMassNearest(Point*** points, int* lenght){


    Point** pointsVal = *points;
    int lenghtVal = *lenght;

    int indexLowerMassPoint = indexPointLowestMass(pointsVal, lenghtVal);

    int closestPointIndex = indexPointClosestGivenOne(pointsVal, lenghtVal, indexLowerMassPoint);
    

    Point* lowerMassPoint =  pointsVal[indexLowerMassPoint];
    Point* closestPoint = pointsVal[closestPointIndex];

    closestPoint->weight += lowerMassPoint->weight;

    free(pointsVal[indexLowerMassPoint]);

    for (int i = indexLowerMassPoint; i < lenghtVal-1; i++){
        pointsVal[i] = pointsVal[i+1];
    }
    

    *points = realloc(pointsVal,lenghtVal);

    *lenght -= 1;
}