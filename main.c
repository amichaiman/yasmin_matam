#include <stdio.h>
#include "mainFunctions.h"
#include "animal.h"
#include "employee.h"
#include "food.h"

int main() {
    int input;
    AnimalNode *animalRoot;
    EmployeeNode *employeeRoot;
    FoodNode *foodRoot;

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
                            break;
                        case animalWithGivenColor:
                            break;
                        case animalWithGivenBirthYear:
                            break;
                        case averageNumberOfChildren:
                            break;
                        case deleteAnimal:
                            break;
                        case deleteAllAnimals:
                            break;
                        case printAnimals:
                            printAnimalTree(animalRoot);
                        default:
                            printf("Invalid input. Try again:\n");
                            break;
                    }
                } while (input > deleteAllAnimals || input < addAnimal);
                break;
            case employee:
                printEmployeeQueries();
                scanf("%d", &input);
                do {
                    switch (--input) {
                        case addAEmployee:
                            break;
                        case find:
                            break;
                        case print:
                            break;
                        case deleteEmployee:
                            break;
                        case deleteAllEmployees:
                            break;
                        default:
                            printf("Invalid input. Try again:\n");
                            break;
                    }
                } while (input < addAEmployee || input > deleteAllEmployees);
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