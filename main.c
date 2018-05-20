#include <stdio.h>
#include "mainFunctions.h"
#include "animal.h"
#include "employee.h"
#include "food.h"


void getUserQueries(AnimalNode *animalRoot, EmployeeNode *employeeRoot, FoodNode *foodRoot);

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

