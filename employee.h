
#ifndef YASMIN_MATAM_EMPLOYEE_H
#define YASMIN_MATAM_EMPLOYEE_H
#include <zconf.h>
#define EMPLOYEE_ID_LENGTH 9
#include "animal.h"
#define MAX_NUM_OF_ANIMAL_PER_EMPLOYEE 200

typedef struct {
    char *firstName;
    char *lastName;
    char id[EMPLOYEE_ID_LENGTH+1];
    int numOfAnimals;
    char *animalId[ANIMAL_ID_LENGTH+1];
    char startDate[DATE_LENGTH+1];
} Employee;


typedef struct employeeNode {
    Employee *employee;
    struct employeeNode* left;
    struct employeeNode* right;
} EmployeeNode;

EmployeeNode *createEmployeeTree();


#endif
