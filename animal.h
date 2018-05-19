#ifndef YASMIN_MATAM_ANIMAL_H
#define YASMIN_MATAM_ANIMAL_H
#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANIMAL_ID_LENGTH 5
#define MAX_HEALTH_STATUS 100
#define MIN_HEALTH_STATUS 1
#define MAX_NUM_OF_KIDS 1000
#define FOOD_TYPE 20
#define MAX_MEALS_PER_DAY 10
#define DATE_LENGTH 10
#define MAX_INPUT 30

typedef struct {
    char *type;
    char *color;
    char *name;
    char id[ANIMAL_ID_LENGTH+1];
    char date[DATE_LENGTH+1];
    char *birthLocation;
    int healthStatus;
    int numberOfKids;
    char kidsId[MAX_NUM_OF_KIDS][ANIMAL_ID_LENGTH+1];
    char foodType[FOOD_TYPE];
    int numberOfMealsPerDays;
} Animal;

typedef struct animalNode {
    Animal *animal;
    struct animalNode* left;
    struct animalNode* right;
} AnimalNode;

/*  return empty animal tree*/
AnimalNode* createAnimalTree();

/*  gets animal from input and ads it to tree   */
void addNewAnimal(AnimalNode** root);

void printAnimalTree(AnimalNode *curNode);
#endif
