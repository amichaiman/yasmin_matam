
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
    deleteAnimal,
    deleteAllAnimals,
    printAnimals
};

enum employeeOptions{
    addAEmployee,
    find,
    print,
    deleteEmployee,
    deleteAllEmployees
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
