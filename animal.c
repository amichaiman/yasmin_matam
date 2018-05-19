

#include "animal.h"

Animal *getAnimalFromInput();

AnimalNode *insertAnimalToTree(AnimalNode *curNode, Animal *animalToAdd);

int allDigits(char *s);

void printAnimal(Animal *animal);

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

void printAnimal(Animal *animal) {
    int i;

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
}


Animal *getAnimalFromInput() {
    Animal *animal = (Animal *) malloc (sizeof(Animal));
    char inputString[MAX_INPUT];
    int i;

    getchar();

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

    getchar();

    printf("Enter animal birth date:\n");
    fgets(animal->date,DATE_LENGTH+1,stdin);
    inputString[strcspn(animal->date,"\n")] = '\0';


    printf("Enter birth location:\n");
    fgets(inputString,MAX_INPUT,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->birthLocation= (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->birthLocation,inputString);

    if (!animal->birthLocation){
        exit(1);
    }

    printf("Enter health status\n");
    scanf("%d",&animal->healthStatus);

    while (animal->healthStatus < MIN_HEALTH_STATUS || animal->healthStatus > MAX_HEALTH_STATUS){
        printf("Invlid health status\n");
        scanf("%d",&animal->healthStatus);
    }

    printf("Enter number of kids\n");
    scanf("%d",&animal->numberOfKids);

    while (animal->numberOfKids < 0 || animal->numberOfKids > MAX_NUM_OF_KIDS){
        printf("Invlid number of kids\n");
        scanf("%d",&animal->numberOfKids);
    }

    for (i=0; i<animal->numberOfKids; i++){
        printf("enter kid id\n");
        fgets(animal->kidsId[i],ANIMAL_ID_LENGTH+1,stdin);
        inputString[strcspn(animal->kidsId[i],"\n")] = '\0';
    }

    printf("Enter food type\n");
    fgets(animal->foodType,FOOD_TYPE+1,stdin);
    inputString[strcspn(animal->foodType,"\n")] = '\0';

    while (strlen(animal->foodType) != FOOD_TYPE && allDigits(animal->foodType)){
        printf("invlid input. food type must be %d numbers long\n", FOOD_TYPE);
        fgets(animal->foodType,FOOD_TYPE+1,stdin);
        inputString[strcspn(animal->foodType,"\n")] = '\0';
    }

    printf("Enter number of meals per day:\n");
    scanf("%d", &animal->numberOfMealsPerDays);

    while (animal->numberOfMealsPerDays < 0 || animal->numberOfMealsPerDays > MAX_MEALS_PER_DAY){
        printf("Invlid number of meals\n");
        scanf("%d",&animal->numberOfMealsPerDays);
    }

    return animal;
}

int allDigits(char *s) {
    int len = strlen(s);
    int i;

    for (i=0; i<len; i++){
        if (!isdigit(s[i]))
            return 0;
    }
    return 1;
}
