#include <stdio.h>
#include "mainFunctions.h"
#include "animal.h"
#include "employee.h"
#include "food.h"



int main() {
    int input;
    char stringInput[MAX_INPUT];

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
                            break;
                        case threePopularFoods:
                            break;
                        case deleteFood:
                            break;
                        case deleteAllFoods:
                            break;
                        default:
                            printf("Invalid input. Try again:\n");
                            break;
                    }
                } while (input < addFood || input > deleteAllFoods);
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




