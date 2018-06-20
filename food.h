
#ifndef YASMIN_MATAM_FOOD_H
#define YASMIN_MATAM_FOOD_H
#include <zconf.h>
#include <stdlib.h>
#include "commonFunctions.h"
#include "Tree.h"
#include <string.h>

#define FOOD_ID_LENGTH 20
#define MAX_BAGS_IN_SUPPLY 10000
#define MAX_BAG_SIZE 50
#define MIN_BAG_SIZE 1


typedef struct {
    char id[FOOD_ID_LENGTH+1];
    char *manufacturer;
    char **animalConsumers;
    int numOfBagsInSupply;
    float bagSize;
} Food;



typedef struct foodListNode{
    char id[FOOD_ID_LENGTH+1];
    int count;
    struct foodListNode* next;
} FoodListNode;

typedef struct {
    FoodListNode * head;
} FoodList;

void addNewFood(Node **root);
void printFoodTree(Node *curNode);
int compareFood(void* f1, void* f2);
void freeFood(Node *node);
void printFood(void* data);
#endif