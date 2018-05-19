
#ifndef YASMIN_MATAM_FOOD_H
#define YASMIN_MATAM_FOOD_H
#include <zconf.h>
#include <stdlib.h>

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


FoodNode *createFoodTree();


#endif