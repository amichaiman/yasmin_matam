
#ifndef YASMIN_MATAM_MAINFUNCTIONS_H
#define YASMIN_MATAM_MAINFUNCTIONS_H
#include <stdio.h>

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
    threePopularFoods,
    deleteFood,
    deleteAllFoods
};

/*  print options for user  */
void printQueryOptions();
void printAnimalQueries();
void printEmployeeQueries();
void printFoodQueries();

#endif
