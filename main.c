#include <stdio.h>
#include "mainFunctions.h"

int main() {
    AnimalNode *animalRoot;
    EmployeeNode *employeeRoot;
    FoodNode *foodRoot;


    animalRoot = createAnimalTree();
    employeeRoot= createEmployeeTree();
    foodRoot = createFoodTree();

    getUserQueries(animalRoot,employeeRoot,foodRoot);

    return 0;
}

