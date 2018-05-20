
#ifndef YASMIN_MATAM_FOOD_H
#define YASMIN_MATAM_FOOD_H
#include <zconf.h>
#include <stdlib.h>
#include "commonFunctions.h"
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



typedef struct foodNode {
    Food *food;
    struct foodNode* left;
    struct foodNode* right;
} FoodNode;

typedef struct foodListNode{
    char id[FOOD_ID_LENGTH+1];
    int count;
    struct foodListNode* next;
} FoodListNode;

typedef struct {
    FoodListNode * head;
} FoodList;

FoodNode *createFoodTree();
void addNewFood(FoodNode **root);
void printFoodTree(FoodNode *curNode);

/*  receives food id to delete. returns true if food was deleted, false otherwise   */
FoodNode * deleteFood(FoodNode *root, char *id);

/*  return min value node   */
FoodNode * foodFindMin(FoodNode *t, FoodNode **parent);

/*  return max value node   */
FoodNode * foodFindMax(FoodNode *t, FoodNode **parent);

/*  return pointer to food node if found, null ortherwise   */
FoodNode * foodFind(FoodNode *curNode, char *id, FoodNode **parent);

void deleteAllFoods(FoodNode *curNode);

#endif