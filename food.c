#include "food.h"
#define MAX 30


Food *getFoodFromInput() {
    Food *food = (Food *) malloc (sizeof(Food));
    char inputString[MAX];

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
    fgets(inputString,MAX+1,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    food->manufacturer = (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(food->manufacturer,inputString);

    printf("Enter number of bags in supply:\n");
    if (scanf("%d", &food->numOfBagsInSupply) != 1){
        clearBuffer();
        printf("Invalid input, Try again:\n");
    }
    while (!(food->numOfBagsInSupply >= 0 && food->numOfBagsInSupply <= MAX_BAGS_IN_SUPPLY)){
        printf("Invlid number of bags in supply\n");
    }
    printf("Enter number of bags size:\n");
    if (scanf("%f", &food->bagSize) != 1){
        clearBuffer();
        printf("Invalid input, Try again:\n");
    }
    while (!(food->bagSize >= MIN_BAG_SIZE && food->bagSize <= MAX_BAG_SIZE)){
        printf("Invlid bag size\n");
    }

    return food;
}


int compareFood(void* f1, void* f2){
    return strcmp(((Food*)f1)->id,((Food*)f2)->id);

}

void addNewFood(Node **root) {
    Food *foodToAdd = getFoodFromInput();
    *root = addNodeToTree(*root, foodToAdd,compareFood);
}

void printFood(void* data) {
    Food *food = (Food*)data;
    printf("------------------------------------------------\n");
    printf("Id: %s\n",food->id);
    printf("Maufacturer: %s\n",food->manufacturer);
    printf("Number of bags in supply: %d\n",food->numOfBagsInSupply);
    printf("Bag size: %f\n",food->bagSize);
    printf("------------------------------------------------\n");
}



void freeFood(Node *node) {
    free(((Food*)node->data)->manufacturer);
    free((Food*)node->data);
    free(node);
}
