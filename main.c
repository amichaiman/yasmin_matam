#include <stdio.h>
#include "mainFunctions.h"
#include "animal.h"
#include "employee.h"
#include "food.h"




int main() {
    int input;
    int i;
    char stringInput[MAX_INPUT];
    char **threeMostPopularFoods = NULL;
    AnimalNode *animalRoot;
    EmployeeNode *employeeRoot;
    FoodNode *foodRoot;
    EmployeeList *list;

    animalRoot = createAnimalTree();
    employeeRoot= createEmployeeTree();
    foodRoot = createFoodTree();

    printQueryOptions();
    scanf("%d", &input);

    while (--input != EXIT){
        switch (input) {
            case animal:
                printAnimalQueries();
                scanf("%d", &input);
                do {
                    switch (--input) {
                        case addAnimal:
                            addNewAnimal(&animalRoot);
                            break;
                        case animalWithGivenFoodType:
                            getchar();
                            printf("Enter food to check:\n");
                            fgets(stringInput,MAX_INPUT,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            printf("Number of animals with %s food type: %d\n",stringInput,animalNumberWithGivenFoodKind(animalRoot,stringInput));
                            break;
                        case animalWithGivenColor:
                            getchar();
                            printf("Enter color to check:\n");
                            fgets(stringInput,MAX_INPUT,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            printf("Number of animals with %s color : %d\n",stringInput,animalNumberWithGivenColor(animalRoot,stringInput));
                            break;
                        case animalWithGivenBirthYear:
                            getchar();
                            printf("Enter birth year:\n");
                            scanf("%d", &input);
                            printAnimalsForGivenBirthYear(animalRoot,input);
                            break;
                        case averageNumberOfChildren:
                            input = 0;
                            printf("Average number of children: %d\n",averageNumOfChildren(animalRoot,&input));
                            break;
                        case delAnimal:
                            getchar();
                            printf("Enter animal's id:\n");
                            fgets(stringInput,MAX_INPUT,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            animalRoot = deleteAnimal(animalRoot, stringInput);
                            break;
                        case delAllAnimals:
                            deleteAllAnimals(animalRoot);
                            animalRoot = NULL;
                            break;
                        case printAnimals:
                            printAnimalTree(animalRoot); break;
                        default:
                            printf("Invalid input. Try again:\n");
                            break;
                    }
                } while (input > delAllAnimals || input < addAnimal);
                break;
            case employee:
                printEmployeeQueries();
                scanf("%d", &input);
                do {
                    switch (--input) {
                        case addEmployee:
                            addNewEmployee(&employeeRoot); break;
                        case find:
                            list = findEmployee(employeeRoot);
                            if (!list){
                                printf("No employee found\n");
                            } else {
                                printEmployeeList(list->head);
                            }
                            freeList(list);
                            break;
                        case print:
                            printEmployeeTree(employeeRoot); break;
                        case delEmployee:
                            getchar();
                            printf("Enter employee's id:\n");
                            fgets(stringInput,MAX_INPUT,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            employeeRoot = deleteEmployee(employeeRoot, stringInput);
                            break;
                        case delAllEmployees:
                            deleteAllEmployees(employeeRoot);
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
                scanf("%d", &input);
                do {
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
                            fgets(stringInput,MAX_INPUT,stdin);
                            stringInput[strcspn(stringInput,"\n")] = '\0';
                            foodRoot = deleteFood(foodRoot,stringInput);
                            break;
                        case delAllFoods:
                            deleteAllFoods(foodRoot);
                            foodRoot = NULL;
                            break;
                        case printFoods:
                            printFoodTree(foodRoot);
                            break;
                        default:
                            printf("Invalid input. Try again:\n");
                            break;
                    }
                } while (input < addFood || input > printFoods);
                break;
            default:
                printf("Invalid input: Try again:\n");
                break;

        }
        printQueryOptions();
        scanf("%d", &input);
    }
    return 0;
}




