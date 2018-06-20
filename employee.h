
#ifndef YASMIN_MATAM_EMPLOYEE_H
#define YASMIN_MATAM_EMPLOYEE_H
#include <zconf.h>
#include "animal.h"
#include "commonFunctions.h"
#include "Tree.h"
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


typedef struct employeeListNode {
    Employee *employee;
    struct employeeListNode *next;
} EmployeeListNode;

typedef struct {
    EmployeeListNode *head;
} EmployeeList;


/*  gets Employee from input and ads it to tree   */
void addNewEmployee(Node** root);

/*  prints one employees details    */
void printEmployee(void* data);
/*  returns employee with given id if found, NULL otherwise */
Employee *findEmployeeById(Node *curNode, char string[30]);

/*  returns list containing all employees. employee can be searched by id, or by number of employees  */
List * findEmployee(Node *root);

/*  prints given employee list  */
void printEmployeeList(ListNode *curNode);

/*  free list   */
void freeList(List *l);


int compareEmployee(void* e1, void * e2);

void freeEmployee(Node *node);
#endif
