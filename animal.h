#ifndef YASMIN_MATAM_ANIMAL_H
#define YASMIN_MATAM_ANIMAL_H
#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "commonFunctions.h"

#define ANIMAL_ID_LENGTH 5
#define MAX_HEALTH_STATUS 100
#define MIN_HEALTH_STATUS 1
#define MAX_NUM_OF_KIDS 1000
#define FOOD_TYPE 20
#define MAX_MEALS_PER_DAY 10
#define DATE_LENGTH 10
#define MAX_INPUT 30
#define FALSE 0
#define TRUE 1


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
    char foodType[FOOD_TYPE+1];
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

/*  prints all animals */
void printAnimalTree(AnimalNode *curNode);

/*  returns number of animals with given food type  */
int animalNumberWithGivenFoodKind(AnimalNode *curNode, char *foodType);

/*  prints animals with given birth year*/
void printAnimalsForGivenBirthYear(AnimalNode *curNode, int year);

/*  returns number of animals with given color */
int animalNumberWithGivenColor(AnimalNode *curNode, char *color);

/*  computes and returns average of kids per animal */
int averageNumOfChildren(AnimalNode *curNode, int *numNodes);

/*  receives animal id to delete. returns true if animal was deleted, false otherwise   */
AnimalNode * deleteAnimal(AnimalNode *root, char *id);

/*  return min value node   */
AnimalNode * animalFindMin(AnimalNode *t, AnimalNode **parent);

/*  return max value node   */
AnimalNode * animalFindMax(AnimalNode *t, AnimalNode **parent);

/*  return pointer to animal node if found, null ortherwise   */
AnimalNode * animalFind(AnimalNode *curNode, char *id, AnimalNode **parent);

void deleteAllAnimals(AnimalNode *curNode);

#endif
