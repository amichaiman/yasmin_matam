

#include "animal.h"
Animal *getAnimalFromInput();


FoodListNode *getFoodTypeListNode(FoodListNode *curNode, char *foodId);

void sortList(FoodList *list);

int compareAnimal(void* a1, void* a2){
    return strcmp(((Animal*)a1)->id,((Animal*)a2)->id);
}

void addNewAnimal(Node **root) {
    Animal *animalToAdd = getAnimalFromInput();
    *root = addNodeToTree(*root, (void*)animalToAdd,compareAnimal);
}

int animalNumberWithGivenFoodKind(Node *curNode, char *foodType) {
    int hasFoodKind;

    if (curNode == NULL){
        return 0;
    }

    hasFoodKind = strcmp(((Animal*)curNode->data)->foodType,foodType) == 0 ? TRUE : FALSE;

    return (animalNumberWithGivenFoodKind(curNode->left,foodType) + animalNumberWithGivenFoodKind(curNode->right,foodType)) + hasFoodKind;
}

int animalNumberWithGivenColor(Node *curNode, char *color) {
    int hasColor;

    if (curNode == NULL){
        return 0;
    }

    hasColor = strcmp(((Animal*)curNode->data)->color,color) == 0;

    return (animalNumberWithGivenColor(curNode->left,color) + animalNumberWithGivenColor(curNode->right,color)) + hasColor;
}

void printAnimalsForGivenBirthYear(Node *curNode, int year) {
    char *animalYear;

    if (curNode == NULL){
        return;
    }
    animalYear = ((Animal*)curNode->data)->date;
    printAnimalsForGivenBirthYear(curNode->left,year);
    if (atoi(animalYear+6) == year){
        printAnimal(curNode->data);
    }
    printAnimalsForGivenBirthYear(curNode->right,year);
}


void freeAnimal(Node *node) {
    Animal* animalData = (Animal*)(node->data);
    free(animalData->type);
    free(animalData->color);
    free(animalData->name);
    free(animalData->birthLocation);
    free(animalData);
    free(node);
}

void printAnimal(void* data) {
    Animal* animal = (Animal*)data;
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
    char inputString[MAX];
    int i;

    clearBuffer();

    printf("Enter animal type:\n");
    fgets(inputString,MAX,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->type = (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->type,inputString);

    if (!animal->type){
        exit(1);
    }

    printf("Enter animal color:\n");
    fgets(inputString,MAX,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->color= (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->color,inputString);

    if (!animal->color){
        exit(1);
    }


    printf("Enter animal name:\n");
    fgets(inputString,MAX,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->name= (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->name,inputString);

    if (!animal->name){
        exit(1);
    }

    printf("Enter id:\n");
    fgets(animal->id,ANIMAL_ID_LENGTH+1,stdin);
    animal->id[strcspn(animal->id,"\n")] = '\0';

    while (!allDigits(animal->id)){
        printf("Invalid input. Try again:\n");
        fgets(animal->id,ANIMAL_ID_LENGTH+1,stdin);
        animal->id[strcspn(animal->id,"\n")] = '\0';
    }

    clearBuffer();

    printf("Enter animal birth date:\n");
    fgets(animal->date,DATE_LENGTH+1,stdin);
    animal->date[strcspn(animal->date,"\n")] = '\0';

    while (strlen(animal->date) != DATE_LENGTH){
        printf("Invaid input. Try again:\n");
        fgets(animal->date,DATE_LENGTH+1,stdin);
        animal->date[strcspn(animal->date,"\n")] = '\0';
    }

    printf("Enter birth location:\n");
    fgets(inputString,MAX,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    animal->birthLocation= (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(animal->birthLocation,inputString);

    if (!animal->birthLocation){
        exit(1);
    }
    clearBuffer();
    printf("Enter health status\n");
    if (scanf("%d", &animal->healthStatus) != 1){
        clearBuffer();
        printf("Invalid input, Try again:\n");
    }
    while (!(animal->healthStatus >= MIN_HEALTH_STATUS && animal->healthStatus <= MAX_HEALTH_STATUS)){
        printf("Invalid health status\n");
    }
    clearBuffer();
    printf("Enter number of kids\n");
    if (scanf("%d", &animal->numberOfKids) != 1){
        clearBuffer();
        printf("Invalid input, Try again:\n");
    }
    while (!(animal->numberOfKids >= 0 && animal->numberOfKids <= MAX_NUM_OF_KIDS)){
        printf("Invalid number of kids\n");
    }
    clearBuffer();

    for (i=0; i<animal->numberOfKids; i++){
        printf("enter kid id\n");
        fgets(animal->kidsId[i],ANIMAL_ID_LENGTH+1,stdin);
        animal->kidsId[i][strcspn(animal->kidsId[i],"\n")] = '\0';
        clearBuffer();
    }

    printf("Enter food type\n");
    fgets(animal->foodType,FOOD_TYPE+1,stdin);
    animal->foodType[strcspn(animal->foodType,"\n")] = '\0';

    while (strlen(animal->foodType) != FOOD_TYPE && allDigits(animal->foodType)){
        printf("invlid input. food type must be %d numbers long\n", FOOD_TYPE);
        fgets(animal->foodType,FOOD_TYPE+1,stdin);
        animal->foodType[strcspn(animal->foodType,"\n")] = '\0';
    }
    clearBuffer();
    printf("Enter number of meals per day:\n");
    if (scanf("%d", &animal->numberOfMealsPerDays) != 1){
        clearBuffer();
        printf("Invalid input, Try again:\n");
    }
    while (!(animal->numberOfMealsPerDays >= 0 && animal->numberOfMealsPerDays <= MAX_MEALS_PER_DAY)){
        printf("Invlid number of meals\n");
    }

    return animal;
}

/*   created linked list with each food type, and how often it appears   */
void getFoodCount(Node *curNode, FoodList *list){
    FoodListNode *currentAnimalsFood;

    if (curNode == NULL){
        return;
    }

    currentAnimalsFood = getFoodTypeListNode(list->head,((Animal*)curNode->data)->foodType);

    if (currentAnimalsFood == NULL) {
        currentAnimalsFood = (FoodListNode *) malloc (sizeof(FoodListNode));
        strcpy(currentAnimalsFood->id,((Animal*)curNode->data)->foodType);
        currentAnimalsFood->count = 1;
        currentAnimalsFood->next = list->head;
        list->head = currentAnimalsFood;
    } else {
        currentAnimalsFood->count++;
    }
    getFoodCount(curNode->left,list);
    getFoodCount(curNode->right,list);

}

FoodListNode *getFoodTypeListNode(FoodListNode *curNode, char *foodId) {
    if (curNode == NULL) {
        return NULL;
    }

    if (strcmp(curNode->id,foodId) == 0){
        return curNode;
    }

    return getFoodTypeListNode(curNode->next,foodId);

}

char **threePopularFoods(Node *root){
    FoodList list;
    char **arrayOfPopularFoods;
    int i;
    FoodListNode *curNode;
    list.head = NULL;


    getFoodCount(root,&list);
    sortList(&list);

    curNode = list.head;

    arrayOfPopularFoods = (char **) malloc(NUMBER_OF_POP_FOODS* sizeof(char *));

    if (curNode == NULL){
        curNode = (FoodListNode*) malloc(sizeof(FoodListNode));
        strcpy(curNode->id,"NO FOODS FOUND");
    }
    for (i=0; i<NUMBER_OF_POP_FOODS; i++){
        arrayOfPopularFoods[i] = (char *) malloc((FOOD_ID_LENGTH+1) * sizeof (char));
        strcpy(arrayOfPopularFoods[i],curNode->id);
        if (curNode->next != NULL) {
            curNode = curNode->next;
        }
    }
    return arrayOfPopularFoods;
}

int getNumberOfKids(Node *node) {
    return ((Animal*)node->data)->numberOfKids;
}

void addNode(FoodList *list, FoodListNode *toAdd){
    FoodListNode *curNode = list->head;

    if (list->head == NULL){
        list->head = toAdd;
        return;
    }

    while (curNode->next != NULL){
        if (strcmp(curNode->next->id,toAdd->id) < 0){
            toAdd->next = curNode->next;
            curNode->next = toAdd;
            return;
        }
        curNode = curNode->next;
    }

    curNode->next = toAdd;
    toAdd->next = NULL;
}

void sortList(FoodList *list) {
    FoodListNode *curNode;
    FoodList temp;
    temp.head = NULL;

    while (list->head != NULL){
        curNode = list->head;
        list->head = curNode->next;
        addNode(&temp,curNode);
    }
    list->head = temp.head;
}

