#include "mainFunctions.h"

void printQueryOptions(){
    printf("WELCOME TO THE ZOO!\n"
                   "1) Animal options\n"
                   "2) Employee options\n"
                   "3) Food options\n"
                   "4) Exit\n");
}

void printAnimalQueries(){
    printf("ANIMAL OPTIONS:\n"
                   "1) Add animal\n"
                   "2) Number of animals with given food type\n"
                   "3) Number of animals with given color\n"
                   "4) Animals with given birth year\n"
                   "5) Average number of children\n"
                   "6) Delete animal\n"
                   "7) Delete all animals\n"
                   "8) Print animals\n");
}
void printEmployeeQueries(){
    printf("EMPLOYEE OPTIONS:\n"
                   "1) Add employee\n"
                   "2) Find employee\n"
                   "3) print employee\n"
                   "4) Delete employee\n"
                   "5) Delete all employees\n");
}
void printFoodQueries(){
    printf("FOOD QUERIES\n"
                   "1) Add food\n"
                   "2) Three popular foods\n"
                   "3) Delete food\n"
                   "4) Delete all foods\n"
                   "5) Print foods\n");
}


void getUserQueries(Node *animalRoot, Node *employeeRoot, Node *foodRoot) {
    List *list;
    int input;
    int i;
    char stringInput[MAX];
    char **threeMostPopularFoods = NULL;
    Node* NodetoFind;
    Animal *animalToFind;
    Employee emp;
    Food food1;
    printQueryOptions();
    if (scanf("%d", &input) != 1){
        clearBuffer();
        printf("Invalid input, Try again:\n");

    }

    while (--input != EXIT){
        switch (input) {
            case animal:
                printAnimalQueries();
                do {
                    if (scanf("%d", &input) != 1){
                        clearBuffer();
                        printf("Invalid input, Try again:\n");
                    }
                    switch (--input) {
                        case addAnimal:
                            addNewAnimal(&animalRoot);
                            break;
                        case animalWithGivenFoodType:
                            getchar();
                            printf("Enter food to check:\n");
                            fgets(stringInput,MAX,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            printf("Number of animals with %s food type: %d\n",stringInput,animalNumberWithGivenFoodKind(animalRoot,stringInput));
                            break;
                        case animalWithGivenColor:
                            getchar();
                            printf("Enter color to check:\n");
                            fgets(stringInput,MAX,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            printf("Number of animals with %s color : %d\n",stringInput,animalNumberWithGivenColor(animalRoot,stringInput));
                            break;
                        case animalWithGivenBirthYear:
                            getchar();
                            printf("Enter birth year:\n");
                            if (scanf("%d", &input) != 1){
                                clearBuffer();
                                printf("Invalid input, Try again:\n");
                            }
                            printAnimalsForGivenBirthYear(animalRoot,input);
                            break;
                        case averageNumberOfChildren:
                            input = 0;
                            printf("Average number of children: %.2f\n",averageKey(animalRoot,&input,getNumberOfKids));
                            break;
                        case delAnimal:
                            getchar();
                            printf("Enter animal's id:\n");
                            fgets(stringInput,MAX,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            NodetoFind = (Node*) malloc (sizeof(Node));
                            NodetoFind->left = NodetoFind->right = NULL;
                            animalToFind = (Animal*) malloc (sizeof(Animal));
                            strcpy(animalToFind->id,stringInput);
                            animalRoot = deleteNode(animalRoot, animalToFind,compareAnimal,freeAnimal);
                            break;
                        case delAllAnimals:
                            deleteAllNodes(animalRoot,freeAnimal);
                            animalRoot = NULL;
                            break;
                        case printAnimals:
                            printTree(animalRoot,printAnimal); break;
                        default:
                            printf("Invalid input. Try again:\n");
                            break;
                    }
                } while (input > delAllAnimals || input < addAnimal);
                break;
            case employee:
                printEmployeeQueries();
                do {
                    if (scanf("%d", &input) != 1){
                        clearBuffer();
                        printf("Invalid input, Try again:\n");
                    }
                    switch (--input) {
                        case addEmployee:
                            addNewEmployee(&employeeRoot); break;
                        case find:
                            list = findEmployee(employeeRoot);
                            if (!list){
                                printf("No emp found\n");
                            } else {
                                printEmployeeList(list->head);
                            }
                            freeList(list);
                            break;
                        case print:
                            printTree(employeeRoot,printEmployee); break;
                        case delEmployee:
                            getchar();

                            printf("Enter emp's id:\n");
                            fgets(stringInput,MAX,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            strcpy(emp.id,stringInput);
                            employeeRoot = deleteNode(employeeRoot, (void*)&emp,compareEmployee,freeEmployee);
                            break;
                        case delAllEmployees:
                            deleteAllNodes(employeeRoot,freeEmployee);
                            employeeRoot = NULL;
                            break;
                        default:
                            printf("Invalid input. Try again:\n");
                            break;
                    }
                } while (input < addEmployee || input > delAllEmployees);
                break;
            case food:
                printFoodQueries();
                do {
                    if (scanf("%d", &input) != 1){
                        clearBuffer();
                        printf("Invalid input, Try again:\n");
                    }
                    switch (--input) {
                        case addFood:
                            addNewFood(&foodRoot);
                            break;
                        case threePopFoods:
                            threeMostPopularFoods = threePopularFoods(animalRoot);
                            for (i=0; i<NUMBER_OF_POP_FOODS; i++){
                                printf("%d) %s\n",i+1,threeMostPopularFoods[i]);
                            }
                            break;
                        case delFood:
                            getchar();
                            printf("Enter food's id:\n");
                            fgets(stringInput,MAX,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            strcpy(food1.id,stringInput);
                            foodRoot = deleteNode(foodRoot,(void*)&food1,compareFood,freeFood);
                            break;
                        case delAllFoods:
                            deleteAllNodes(foodRoot,freeFood);
                            foodRoot = NULL;
                            break;
                        case printFoods:
                            printTree(foodRoot,printFood);
                            break;
                        default:
                            printf("Invalid input. Try again:\n");

                            break;
                    }
                } while (input < addFood || input > printFoods);
                break;
            default:
                printf("Invalid input: Try again:\n");
                if (scanf("%d", &input) != 1){
                    clearBuffer();
                    printf("Invalid input, Try again:\n");
                }
                break;

        }
        printQueryOptions();
        if (scanf("%d", &input) != 1){
            clearBuffer();
            printf("Invalid input, Try again:\n");
        }
    }
}
