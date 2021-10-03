#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct {
    
    char lastName[12];
    int group;
    double assessmentWebTechnologies;
    double assessmentUkrLanguage;
    double assessmentDesignInformationSystems;

}Sturdent;

double averageScoreByGroup(Sturdent students[], int len, int group);
void printAllStudentsWhoHaveDebts(Sturdent students[], int len);
double percentageOfStudentsWhoPassedWellOrExcellently(Sturdent students[], int len);
void nameOfTheItemThatWereHandedOverBest(Sturdent students[], int len);
int worstPerformingGroup(Sturdent students[], int len);
void initStudent(Sturdent students[], int len);

int main(int argc, char const *argv[]){
    
    Sturdent students [30];
    srand(time(NULL));
    initStudent(students, 30);

    printAllStudentsWhoHaveDebts(students, 30);
    printf("Percentage of students who passed well or excellently %lf\n",percentageOfStudentsWhoPassedWellOrExcellently(students, 30));
    
    nameOfTheItemThatWereHandedOverBest(students, 30);
    
    printf("Group : %d\n", worstPerformingGroup(students, 30));

    return 0;
}

void initStudent(Sturdent students[], int len){
    for (size_t i = 0; i < len; i++){
        students[i].assessmentDesignInformationSystems = rand() % 100 + 1;
        students[i].assessmentUkrLanguage = rand() % 100 + 1;
        students[i].assessmentWebTechnologies = rand() % 100 + 1;
        students[i].group = rand() % 4 + 1;
        students[i].lastName[0] = '\0';
        for (size_t j = 0; j < 11; j++){
           students[i].lastName[j] = rand()%(90 - 65) + 65;
        }
        students[i].lastName[11] = '\0';
    }
}

void printAllStudentsWhoHaveDebts(Sturdent students[], int len){
    int count = 0;
    for (size_t i = 0; i < len; i++){
        if (students[i].assessmentDesignInformationSystems < 50 || students[i].assessmentUkrLanguage < 50|| students[i].assessmentWebTechnologies <50){
            printf("Name : %s Ukr language: %0.2lf Design information systems: %0.2lf Web technologies: %0.2lf \n", 
                students[i].lastName, students[i].assessmentUkrLanguage, students[i].assessmentDesignInformationSystems, students[i].assessmentWebTechnologies);
            count++;
        }
    }
    printf("count: %d\n", count);
}


double percentageOfStudentsWhoPassedWellOrExcellently(Sturdent students[], int len){
    int count = 0;
    for (size_t i = 0; i < len; i++){
        if (students[i].assessmentDesignInformationSystems > 50 
            && students[i].assessmentUkrLanguage > 50
            && students[i].assessmentWebTechnologies > 50){
            count++;
        }
    }
    return (double)(count * 100) / len;
}

void nameOfTheItemThatWereHandedOverBest(Sturdent students[], int len){
    double assessmentWebTechnologies = 0;
    double assessmentUkrLanguage = 0;
    double assessmentDesignInformationSystems = 0;

    for (size_t i = 0; i < len; i++){
        assessmentWebTechnologies = students[i].assessmentWebTechnologies;
        assessmentDesignInformationSystems = students[i].assessmentDesignInformationSystems;
        assessmentUkrLanguage = students[i].assessmentUkrLanguage;
    }
    if (assessmentUkrLanguage > assessmentDesignInformationSystems 
        && assessmentUkrLanguage > assessmentWebTechnologies){
        printf("Best to pass the subject of Ukr Language\n");

    }else if (assessmentWebTechnologies > assessmentUkrLanguage
        && assessmentWebTechnologies > assessmentDesignInformationSystems){
        
        printf("Best to pass the subject of Design Information Systems\n");
    }else{
        printf("Best to pass the subject of  Web Technologies\n");
    }  
}

int worstPerformingGroup(Sturdent students[], int len){
    double averageScoreByGroup1 = averageScoreByGroup(students,len,1);
    double averageScoreByGroup2 = averageScoreByGroup(students,len,2);
    double averageScoreByGroup3 = averageScoreByGroup(students,len,3);
    double averageScoreByGroup4 = averageScoreByGroup(students,len,4);

    if (averageScoreByGroup1 > averageScoreByGroup2 
        && averageScoreByGroup1 > averageScoreByGroup3
        && averageScoreByGroup1 > averageScoreByGroup4){
        return 1;
    }else if (averageScoreByGroup2 > averageScoreByGroup3
        && averageScoreByGroup2 > averageScoreByGroup1
        && averageScoreByGroup2 > averageScoreByGroup4){
        return 2;
    }else if (averageScoreByGroup3 > averageScoreByGroup1
        && averageScoreByGroup3 > averageScoreByGroup2
        && averageScoreByGroup3 > averageScoreByGroup4){
        return 3;
    }else{
        return 4;
    } 

}

double averageScoreByGroup(Sturdent students[], int len, int group){
    int count = 0;
    double sum = 0;

    for (size_t i = 0; i < len; i++){
        if (students[i].group == group){
            count++;
            sum += students[i].assessmentDesignInformationSystems + 
            students[i].assessmentUkrLanguage + students[i].assessmentWebTechnologies;
        }
    }
    return sum / count;
}