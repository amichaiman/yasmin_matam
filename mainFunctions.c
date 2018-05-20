#include "mainFunctions.h"

void printQueryOptions(){
    printf("WELCOME TO THE ZOO!\n"
                   "1) Animal options\n"
                   "2) Employee options\n"
                   "3) Food options\n"
                   "4) Exit\n");
}

void printAnimalQueries(){
    printf("ANIMAL OPTIONS:\n"
                   "1) Add animal\n"
                   "2) Number of animals with given food type\n"
                   "3) Number of animals with given color\n"
                   "4) Animals with given birth year\n"
                   "5) Average number of children\n"
                   "6) Delete animal\n"
                   "7) Delete all animals\n"
                   "8) Print animals\n");
}
void printEmployeeQueries(){
    printf("EMPLOYEE OPTIONS:\n"
                   "1) Add employee\n"
                   "2) Find employee\n"
                   "3) print employee\n"
                   "4) Delete employee\n"
                   "5) Delete all employees\n");
}
void printFoodQueries(){
    printf("FOOD QUERIES\n"
                   "1) Add food\n"
                   "2) Three popular foods\n"
                   "3) Delete food\n"
                   "4) Delete all foods\n"
                   "5) Print foods\n");
}