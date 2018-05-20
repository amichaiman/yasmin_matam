

#include <stdbool.h>
#include "animal.h"

Animal *getAnimalFromInput();

AnimalNode *insertAnimalToTree(AnimalNode *curNode, Animal *animalToAdd);

int allDigits(char *s);

void printAnimal(Animal *animal);

void clearBuffer();

void freeAnimal(AnimalNode *node);

AnimalNode *createAnimalTree() {
    return NULL;
}

void addNewAnimal(AnimalNode **root) {
    Animal *animalToAdd = getAnimalFromInput();
    *root = insertAnimalToTree(*root, animalToAdd);
}

AnimalNode * insertAnimalToTree(AnimalNode *curNode, Animal *animalToAdd) {
    if (curNode == NULL){
        AnimalNode* nodeToAdd = (AnimalNode*) malloc (sizeof(AnimalNode));
        if (!nodeToAdd){
            exit(1);
        }
        nodeToAdd->animal = animalToAdd;
        nodeToAdd->left = nodeToAdd->right = NULL;
        return nodeToAdd;
    }

    if (strcmp(curNode->animal->id,animalToAdd->id) > 0){
        curNode->left = insertAnimalToTree(curNode->left,animalToAdd);
    } else {
        curNode->right = insertAnimalToTree(curNode->right,animalToAdd);
    }

    return curNode;
}

void printAnimalTree(AnimalNode *curNode){
    if (curNode == NULL){
        return;
    }

    printAnimalTree(curNode->left);
    printAnimal(curNode->animal);
    printAnimalTree(curNode->right);
}

int animalNumberWithGivenFoodKind(AnimalNode *curNode, char *foodType) {
    int hasFoodKind;

    if (curNode == NULL){
        return 0;
    }

    hasFoodKind = strcmp(curNode->animal->foodType,foodType) == 0 ? TRUE : FALSE;

    return (animalNumberWithGivenFoodKind(curNode->left,foodType) + animalNumberWithGivenFoodKind(curNode->right,foodType)) + hasFoodKind;
}

int animalNumberWithGivenColor(AnimalNode *curNode, char *color) {
    int hasColor;

    if (curNode == NULL){
        return 0;
    }

    hasColor = strcmp(curNode->animal->color,color) == 0 ? TRUE : FALSE;

    return (animalNumberWithGivenColor(curNode->left,color) + animalNumberWithGivenColor(curNode->right,color)) + hasColor;
}

void printAnimalsForGivenBirthYear(AnimalNode *curNode, int year) {
    char *animalYear;

    if (curNode == NULL){
        return;
    }
    animalYear = curNode->animal->date;
    printAnimalsForGivenBirthYear(curNode->left,year);
    if (atoi(animalYear+6) == year){
        printAnimal(curNode->animal);
    }
    printAnimalsForGivenBirthYear(curNode->right,year);
}

/*TODO */
int averageNumOfChildren(AnimalNode *curNode, int *numNodes) {
    /*int averageLeft;
    int averageRight;
    int sumKids;

    if (curNode == NULL){
        return 0;
    }

    *numNodes++;

    averageLeft = averageNumOfChildren(curNode->left,numNodes);
    averageRight = averageNumOfChildren(curNode->right,numNodes);

    sumKids = averageLeft + averageRight + curNode->animal->ki

    return sumKids/(*numNodes);*/
}

AnimalNode * animalFindMin(AnimalNode *t, AnimalNode **parent) {
    if (!t) return NULL;
    if (t->left) {
        if (parent) *parent = t;
        return animalFindMin(t->left, parent);
    } else {
        return t;
    }
}

AnimalNode * animalFindMax(AnimalNode *t, AnimalNode **parent) {
    if (!t) return NULL;
    if (t->right) {
        if (parent) *parent = t;
        return animalFindMax(t->right, parent);
    } else {
        return t;
    }
}
int isAnimalLeaf(AnimalNode *node) {
    return node->left == NULL && node->right == NULL;
}

AnimalNode * animalFind(AnimalNode *curNode, char *id, AnimalNode **parent) {
    if (!curNode) {
        return NULL;
    }
    if (strcmp(id,curNode->animal->id) > 0) {
        if (parent)
            *parent = curNode;
        return animalFind(curNode->right, id, parent);
    } else if (strcmp(id,curNode->animal->id) < 0) {
        if (parent)
            *parent = curNode;
        return animalFind(curNode->left, id, parent);
    } else {
        return curNode;
    }
}

AnimalNode *deleteAnimal(AnimalNode *root, char *id) {
    AnimalNode *node, *node2, *parent;
    Animal *tempAnimal;

    parent = NULL;
    node = animalFind(root, id, &parent);
    if (!node) {
        return root;
    }
    if (isAnimalLeaf(node)) {
        if (parent) {
            if (parent->left == node) {
                parent->left=NULL;
            } else {
                parent->right=NULL;
            }
            freeAnimal(node);
            return root;
        } else {
            freeAnimal(node);
            return NULL;
        }
    }
    if (node->left) {
        node2 = animalFindMax(node->left, NULL);
        tempAnimal = node->animal;
        node->animal = node2->animal;
        node2->animal = tempAnimal;
        node->left = deleteAnimal(node->left, id);
    } else {
        node2 = animalFindMin(node->right, NULL);
        tempAnimal = node->animal;
        node->animal = node2->animal;
        node2->animal = tempAnimal;
        node->right = deleteAnimal(node->right, id);
    }
    return root;
}

void deleteAllAnimals(AnimalNode *curNode) {
    if (curNode == NULL){
        return;
    }

    deleteAllAnimals(curNode->left);
    deleteAllAnimals(curNode->right);

    free(curNode);
}

void freeAnimal(AnimalNode *node) {
    free(node->animal->type);
    free(node->animal->color);
    free(node->animal->name);
    free(node->animal->birthLocation);
    free(node->animal);
    free(node);
}

void printAnimal(Animal *animal) {
    int i;
    printf("------------------------------------------------\n");
    printf("animal type: %s\n",animal->type);
    printf("animal color: %s\n",animal->color);
    printf("animal name: %s\n",animal->name);
    printf("animal id: %s\n",animal->id);
    printf("animal date: %s\n",animal->date);
    printf("animal birth location: %s\n",animal->birthLocation);
    printf("animal health status: %d\n",animal->healthStatus);
    printf("animal number of kids: %d\n",animal->numberOfKids);

    for (i=0; i<animal->numberOfKids; i++){
        printf("kid number %d's id: %s\n",i,animal->kidsId[i]);
    }
    printf("animal food type: %s\n",animal->foodType);
    printf("animal number of meals per day: %d\n",animal->numberOfMealsPerDays);
    printf("------------------------------------------------\n");
}


Animal *getAnimalFromInput() {
    Animal *animal = (Animal *) malloc (sizeof(Animal));
    char inputString[MAX_INPUT];
    int i;

    clearBuffer();

    printf("Enter animal type:\n");
    fgets(inputString,MAX_INPUT,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->type = (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->type,inputString);

    if (!animal->type){
        exit(1);
    }

    printf("Enter animal color:\n");
    fgets(inputString,MAX_INPUT,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->color= (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->color,inputString);

    if (!animal->color){
        exit(1);
    }


    printf("Enter animal name:\n");
    fgets(inputString,MAX_INPUT,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->name= (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->name,inputString);

    if (!animal->name){
        exit(1);
    }

    printf("Enter id:\n");
    fgets(animal->id,ANIMAL_ID_LENGTH+1,stdin);
    inputString[strcspn(animal->id,"\n")] = '\0';

    while (!allDigits(animal->id)){
        printf("Invalid input. Try again:\n");
        fgets(animal->id,ANIMAL_ID_LENGTH+1,stdin);
        inputString[strcspn(animal->id,"\n")] = '\0';
    }

    clearBuffer();

    printf("Enter animal birth date:\n");
    fgets(animal->date,DATE_LENGTH+1,stdin);
    inputString[strcspn(animal->date,"\n")] = '\0';

    while (strlen(animal->date) != DATE_LENGTH){
        printf("Invaid input. Try again:\n");
        fgets(animal->date,DATE_LENGTH+1,stdin);
        inputString[strcspn(animal->date,"\n")] = '\0';
    }

    clearBuffer();

    printf("Enter birth location:\n");
    fgets(inputString,MAX_INPUT,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->birthLocation= (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->birthLocation,inputString);

    if (!animal->birthLocation){
        exit(1);
    }

    printf("Enter health status\n");


    while (!(scanf("%d",&animal->healthStatus) ==1 && animal->healthStatus >= MIN_HEALTH_STATUS && animal->healthStatus <= MAX_HEALTH_STATUS)){
        printf("Invlid health status\n");
    }

    printf("Enter number of kids\n");

    while (!(scanf("%d",&animal->numberOfKids) == 1 && animal->numberOfKids >= 0 && animal->numberOfKids <= MAX_NUM_OF_KIDS)){
        printf("Invlid number of kids\n");
    }
    clearBuffer();

    for (i=0; i<animal->numberOfKids; i++){
        printf("enter kid id\n");
        fgets(animal->kidsId[i],ANIMAL_ID_LENGTH+1,stdin);
        inputString[strcspn(animal->kidsId[i],"\n")] = '\0';
        clearBuffer();
    }

    printf("Enter food type\n");
    fgets(animal->foodType,FOOD_TYPE+1,stdin);
    inputString[strcspn(animal->foodType,"\n")] = '\0';
    clearBuffer();
    while (strlen(animal->foodType) != FOOD_TYPE && allDigits(animal->foodType)){
        printf("invlid input. food type must be %d numbers long\n", FOOD_TYPE);
        fgets(animal->foodType,FOOD_TYPE+1,stdin);
        inputString[strcspn(animal->foodType,"\n")] = '\0';
        clearBuffer();
    }

    printf("Enter number of meals per day:\n");

    while (!(scanf("%d", &animal->numberOfMealsPerDays) == 1 && animal->numberOfMealsPerDays >= 0 && animal->numberOfMealsPerDays <= MAX_MEALS_PER_DAY)){
        printf("Invlid number of meals\n");
    }

    return animal;
}



