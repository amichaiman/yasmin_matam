
#ifndef YASMIN_MATAM_MAINFUNCTIONS_H
#define YASMIN_MATAM_MAINFUNCTIONS_H

#include <stdio.h>
#include "animal.h"
#include "employee.h"
#include "food.h"

enum inputOptions{
    animal,
    employee,
    food,
    EXIT
};

enum animalOptions{
    addAnimal,
    animalWithGivenFoodType,
    animalWithGivenColor,
    animalWithGivenBirthYear,
    averageNumberOfChildren,
    delAnimal,
    delAllAnimals,
    printAnimals
};

enum employeeOptions{
    addEmployee,
    find,
    print,
    delEmployee,
    delAllEmployees
};

enum foodOptions{
    addFood,
    threePopFoods,
    delFood,
    delAllFoods,
    printFoods
};

/*  print options for user  */
void printQueryOptions();
void printAnimalQueries();
void printEmployeeQueries();
void printFoodQueries();

/*  wait for queries from user  */
void getUserQueries(AnimalNode *animalRoot, EmployeeNode *employeeRoot, FoodNode *foodRoot);
#endif
