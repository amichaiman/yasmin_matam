#include "food.h"
#define MAX_INPUT 30

void printFood(Food *food);

FoodNode *createFoodTree() {
    return NULL;
}

Food *getFoodFromInput() {
    Food *food = (Food *) malloc (sizeof(Food));
    char inputString[MAX_INPUT];

    clearBuffer();


    printf("Enter id:\n");
    fgets(food->id,FOOD_ID_LENGTH+1,stdin);
    inputString[strcspn(food->id,"\n")] = '\0';

    while (!allDigits(food->id)){
        printf("Invalid input. Try again:\n");
        fgets(food->id,FOOD_ID_LENGTH+1,stdin);
        food->id[strcspn(food->id,"\n")] = '\0';
    }


    clearBuffer();

    printf("Enter manufacturer:\n");
    fgets(inputString,MAX_INPUT+1,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    food->manufacturer = (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(food->manufacturer,inputString);

    printf("Enter number of bags in supply:\n");

    while (!(scanf("%d",&food->numOfBagsInSupply) == 1 && food->numOfBagsInSupply >= 0 && food->numOfBagsInSupply <= MAX_BAGS_IN_SUPPLY)){
        printf("Invlid number of bags in supply\n");
    }
    printf("Enter number of bags size:\n");

    while (!(scanf("%f",&food->bagSize) == 1 && food->bagSize >= MIN_BAG_SIZE && food->bagSize <= MAX_BAG_SIZE)){
        printf("Invlid bag size\n");
    }

    return food;
}

FoodNode * insertFoodToTree(FoodNode *curNode, Food *foodToAdd) {
    if (curNode == NULL){
        FoodNode* nodeToAdd = (FoodNode*) malloc (sizeof(FoodNode));
        if (!nodeToAdd){
            exit(1);
        }
        nodeToAdd->food = foodToAdd;
        nodeToAdd->left = nodeToAdd->right = NULL;
        return nodeToAdd;
    }

    if (strcmp(curNode->food->id,foodToAdd->id) > 0){
        curNode->left = insertFoodToTree(curNode->left,foodToAdd);
    } else {
        curNode->right = insertFoodToTree(curNode->right,foodToAdd);
    }

    return curNode;
}

void addNewFood(FoodNode **root) {
    Food *foodToAdd = getFoodFromInput();
    *root = insertFoodToTree(*root, foodToAdd);
}

void printFoodTree(FoodNode *curNode){
    if (curNode == NULL){
        return;
    }

    printFoodTree(curNode->left);
    printFood(curNode->food);
    printFoodTree(curNode->right);

}

void printFood(Food *food) {
    printf("------------------------------------------------\n");
    printf("Id: %s\n",food->id);
    printf("Maufacturer: %s\n",food->manufacturer);
    printf("Number of bags in supply: %d\n",food->numOfBagsInSupply);
    printf("Bag size: %f\n",food->bagSize);
    printf("------------------------------------------------\n");
}


FoodNode * foodFindMin(FoodNode *t, FoodNode **parent) {
    if (!t) return NULL;
    if (t->left) {
        if (parent) *parent = t;
        return foodFindMin(t->left, parent);
    } else {
        return t;
    }
}

FoodNode * foodFindMax(FoodNode *t, FoodNode **parent) {
    if (!t) return NULL;
    if (t->right) {
        if (parent) *parent = t;
        return foodFindMax(t->right, parent);
    } else {
        return t;
    }
}
int isFoodLeaf(FoodNode *node) {
    return node->left == NULL && node->right == NULL;
}

FoodNode * foodFind(FoodNode *curNode, char *id, FoodNode **parent) {
    if (!curNode) {
        return NULL;
    }
    if (strcmp(id,curNode->food->id) > 0) {
        if (parent)
            *parent = curNode;
        return foodFind(curNode->right, id, parent);
    } else if (strcmp(id,curNode->food->id) < 0) {
        if (parent)
            *parent = curNode;
        return foodFind(curNode->left, id, parent);
    } else {
        return curNode;
    }
}

void freeFood(FoodNode *node) {
    free(node->food->manufacturer);
    free(node->food);
    free(node);
}

FoodNode *deleteFood(FoodNode *root, char *id) {
    FoodNode *node, *node2, *parent;
    Food *tempFood;

    parent = NULL;
    node = foodFind(root, id, &parent);
    if (!node) {
        return root;
    }
    if (isFoodLeaf(node)) {
        if (parent) {
            if (parent->left == node) {
                parent->left=NULL;
            } else {
                parent->right=NULL;
            }
            freeFood(node);
            return root;
        } else {
            freeFood(node);
            return NULL;
        }
    }
    if (node->left) {
        node2 = foodFindMax(node->left, NULL);
        tempFood = node->food;
        node->food = node2->food;
        node2->food = tempFood;
        node->left = deleteFood(node->left, id);
    } else {
        node2 = foodFindMin(node->right, NULL);
        tempFood = node->food;
        node->food = node2->food;
        node2->food = tempFood;
        node->right = deleteFood(node->right, id);
    }
    return root;
}

void deleteAllFoods(FoodNode *curNode) {
    if (curNode == NULL){
        return;
    }

    deleteAllFoods(curNode->left);
    deleteAllFoods(curNode->right);

    freeFood(curNode);
}
