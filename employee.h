
#ifndef YASMIN_MATAM_EMPLOYEE_H
#define YASMIN_MATAM_EMPLOYEE_H
#include <zconf.h>
#include "animal.h"
#include "commonFunctions.h"

#define EMPLOYEE_ID_LENGTH 9
#define MAX_NUM_OF_ANIMAL_PER_EMPLOYEE 200

typedef struct {
    char *firstName;
    char *lastName;
    char id[EMPLOYEE_ID_LENGTH+1];
    int numOfAnimals;
    char **animalId;
    char startDate[DATE_LENGTH+1];
} Employee;


typedef struct employeeNode {
    Employee *employee;
    struct employeeNode* left;
    struct employeeNode* right;
} EmployeeNode;

typedef struct employeeListNode {
    Employee *employee;
    struct employeeListNode *next;
} EmployeeListNode;

typedef struct {
    EmployeeListNode *head;
} EmployeeList;

EmployeeNode *createEmployeeTree();

/*  gets Employee from input and ads it to tree   */
void addNewEmployee(EmployeeNode** root);

/*  print all employees*/
void printEmployeeTree(EmployeeNode *curNode);

/*  prints one employees details    */
void printEmployee(Employee *employee);
/*  returns employee with given id if found, NULL otherwise */
Employee *findEmployeeById(EmployeeNode *curNode, char string[30]);

/*  returns list containing all employees. employee can be searched by id, or by number of employees  */
EmployeeList *findEmployee(EmployeeNode *root);

/*  prints given employee list  */
void printEmployeeList(EmployeeListNode *curNode);

/*  free list   */
void freeList(EmployeeList *l);

/*  receives employee id to delete. returns true if employee was deleted, false otherwise   */
EmployeeNode * deleteEmployee(EmployeeNode *root, char *id);

/*  return min value node   */
EmployeeNode * employeeFindMin(EmployeeNode *t, EmployeeNode **parent);

/*  return max value node   */
EmployeeNode * employeeFindMax(EmployeeNode *t, EmployeeNode **parent);

/*  return pointer to employee node if found, null ortherwise   */
EmployeeNode * employeeFind(EmployeeNode *curNode, char *id, EmployeeNode **parent);

void deleteAllEmployees(EmployeeNode *curNode);

#endif
