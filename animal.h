#ifndef YASMIN_MATAM_ANIMAL_H
#define YASMIN_MATAM_ANIMAL_H
#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "food.h"
#include "commonFunctions.h"

#define ANIMAL_ID_LENGTH 5
#define MAX_HEALTH_STATUS 100
#define MIN_HEALTH_STATUS 1
#define MAX_NUM_OF_KIDS 1000
#define FOOD_TYPE 20
#define MAX_MEALS_PER_DAY 10
#define DATE_LENGTH 10
#define MAX 30
#define NUMBER_OF_POP_FOODS 3
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

int getNumberOfKids(Node *node);
int compareAnimal(void* a1, void* a2);
void freeAnimal(Node *node);
/*  gets animal from input and ads it to tree   */
void addNewAnimal(Node** root);

void printAnimal(void* data);

/*  returns number of animals with given food type  */
int animalNumberWithGivenFoodKind(Node *curNode, char *foodType);

/*  prints animals with given birth year*/
void printAnimalsForGivenBirthYear(Node *curNode, int year);

/*  returns number of animals with given color */
int animalNumberWithGivenColor(Node *curNode, char *color);


/*  return min value node   */
Node * findMin(Node *t, Node **parent);

/*  return max value node   */
Node * findMax(Node *t, Node **parent);


/*  returns string array containing 3 most popular food's ids*/
char **threePopularFoods(Node *root);
#endif
