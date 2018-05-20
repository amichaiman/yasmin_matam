#include "employee.h"

EmployeeNode *createEmployeeTree() {
    return NULL;
}

Employee *getEmployeeFromInput() {
    Employee *employee = (Employee *) malloc (sizeof(Employee));
    char inputString[MAX_INPUT];
    int i;

    clearBuffer();

    printf("Enter first name:\n");
    fgets(inputString,MAX_INPUT,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    employee->firstName = (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(employee->firstName,inputString);

    if (!employee->firstName){
        exit(1);
    }

    printf("Enter last name:\n");
    fgets(inputString,MAX_INPUT,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    employee->lastName= (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(employee->lastName,inputString);

    if (!employee->lastName){
        exit(1);
    }

    printf("Enter id:\n");
    fgets(employee->id,EMPLOYEE_ID_LENGTH+1,stdin);
    employee->id[strcspn(employee->id,"\n")] = '\0';

    while (!allDigits(employee->id)){
        printf("Invalid input. Try again:\n");
        fgets(employee->id,EMPLOYEE_ID_LENGTH+1,stdin);
        employee->id[strcspn(employee->id,"\n")] = '\0';
    }

    clearBuffer();

    printf("Enter number of animals\n");

    while (!(scanf("%d",&employee->numOfAnimals) == 1 && employee->numOfAnimals >= 0 && employee->numOfAnimals<= MAX_NUM_OF_ANIMAL_PER_EMPLOYEE)){
        printf("Invalid number of animals\n");
    }

    employee->animalId = (char **) malloc (employee->numOfAnimals* sizeof(char*));
    clearBuffer();

    for (i=0; i<employee->numOfAnimals; i++){
        employee->animalId[i] = (char *) malloc ((ANIMAL_ID_LENGTH+1)* sizeof(char));
        printf("enter animal id:\n");
        fgets(employee->animalId[i],ANIMAL_ID_LENGTH+1,stdin);
        employee->animalId[i][strcspn(employee->animalId[i],"\n")] = '\0';
        clearBuffer();
    }

    printf("Enter start date\n");
    fgets(employee->startDate,DATE_LENGTH+1,stdin);
    employee->startDate[strcspn(employee->startDate,"\n")] = '\0';
    clearBuffer();

    while (strlen(employee->startDate) != DATE_LENGTH){
        printf("Invaid input. Try again:\n");
        fgets(employee->startDate,DATE_LENGTH+1,stdin);
        employee->startDate[strcspn(employee->startDate,"\n")] = '\0';
    }


    return employee;
}

EmployeeNode * insertEmployeeToTree(EmployeeNode *curNode, Employee *employeeToAdd) {
    if (curNode == NULL){
        EmployeeNode* nodeToAdd = (EmployeeNode*) malloc (sizeof(EmployeeNode));
        if (!nodeToAdd){
            exit(1);
        }
        nodeToAdd->employee = employeeToAdd;
        nodeToAdd->left = nodeToAdd->right = NULL;
        return nodeToAdd;
    }

    if (strcmp(curNode->employee->id,employeeToAdd->id) > 0){
        curNode->left = insertEmployeeToTree(curNode->left,employeeToAdd);
    } else {
        curNode->right = insertEmployeeToTree(curNode->right,employeeToAdd);
    }

    return curNode;
}

void addNewEmployee(EmployeeNode **root) {
    Employee *employeeToAdd = getEmployeeFromInput();
    *root = insertEmployeeToTree(*root, employeeToAdd);
}

void printEmployeeTree(EmployeeNode *curNode){
    if (curNode == NULL){
        return;
    }

    printEmployeeTree(curNode->left);
    printEmployee(curNode->employee);
    printEmployeeTree(curNode->right);
}

void printEmployee(Employee *employee) {
    int i;
    printf("------------------------------------------------\n");
    printf("First name: %s\n",employee->firstName);
    printf("Last name: %s\n",employee->lastName);
    printf("Id: %s\n",employee->id);
    printf("Number of employees: %d\n",employee->numOfAnimals);
    for (i=0; i<employee->numOfAnimals; i++){
        printf("Employee number %d's id: %s\n",i,employee->animalId[i]);
    }
    printf("Start date: %s\n",employee->startDate);
    printf("------------------------------------------------\n");
}

Employee *findEmployeeById(EmployeeNode *curNode, char* id) {
    if (curNode == NULL){
        return NULL;
    }

    if (strcmp(curNode->employee->id,id) > 0){
        return findEmployeeById(curNode->left,id);
    } else if (strcmp(curNode->employee->id,id) < 0){
        return findEmployeeById(curNode->right,id);
    } else {
        return curNode->employee;
    }
}

void addEmployeeWithGivenNumberOfEmployeesRec(EmployeeList **list, EmployeeNode *curNode, int numberOfEmployees) {
    if (curNode == NULL){
        return;
    }

    addEmployeeWithGivenNumberOfEmployeesRec(list,curNode->right,numberOfEmployees);
    addEmployeeWithGivenNumberOfEmployeesRec(list,curNode->left,numberOfEmployees);

    if (curNode->employee->numOfAnimals== numberOfEmployees){
        EmployeeListNode *newNode = (EmployeeListNode*) malloc(sizeof(EmployeeListNode));

        newNode->employee = curNode->employee;
        newNode->next = (*list)->head;
        (*list)->head = newNode;
    }
}

EmployeeList *findEmployee(EmployeeNode *root) {
    int input;
    int numberOfEmployees;
    char stringInput[MAX_INPUT];
    Employee *e;

    EmployeeList *list = (EmployeeList*) malloc (sizeof(EmployeeList));
    list->head = NULL;

    printf("1) find by id.\n2) find by number of employees\n");
    scanf("%d",&input);
    clearBuffer();
    do {
        switch (input) {
            case 1:
                printf("Enter id:\n");
                fgets(stringInput,MAX_INPUT,stdin);
                stringInput[strcspn(stringInput,"\n")] = '\0';
                e = findEmployeeById(root, stringInput);
                if (!e){
                    return NULL;
                }
                list->head = (EmployeeListNode*) malloc (sizeof(EmployeeListNode));
                list->head->employee = e;
                list->head->next = NULL;

                return list;
            case 2:
                printf("Enter number of employees:\n");
                scanf("%d",&numberOfEmployees);
                addEmployeeWithGivenNumberOfEmployeesRec(&list, root, numberOfEmployees);
                return list;
            default:
                printf("Invalid input. Try again:\n");
                scanf("%d",&input);
        }
    } while (input < 1 || input > 2);
    return NULL;
}

void printEmployeeList(EmployeeListNode *curNode){
    if (curNode == NULL){
        return;
    }
    printEmployee(curNode->employee);
    printEmployeeList(curNode->next);
}


EmployeeNode * employeeFindMin(EmployeeNode *t, EmployeeNode **parent) {
    if (!t) return NULL;
    if (t->left) {
        if (parent) *parent = t;
        return employeeFindMin(t->left, parent);
    } else {
        return t;
    }
}

EmployeeNode * employeeFindMax(EmployeeNode *t, EmployeeNode **parent) {
    if (!t) return NULL;
    if (t->right) {
        if (parent) *parent = t;
        return employeeFindMax(t->right, parent);
    } else {
        return t;
    }
}
int isEmployeeLeaf(EmployeeNode *node) {
    return node->left == NULL && node->right == NULL;
}

EmployeeNode * employeeFind(EmployeeNode *curNode, char *id, EmployeeNode **parent) {
    if (!curNode) {
        return NULL;
    }
    if (strcmp(id,curNode->employee->id) > 0) {
        if (parent)
            *parent = curNode;
        return employeeFind(curNode->right, id, parent);
    } else if (strcmp(id,curNode->employee->id) < 0) {
        if (parent)
            *parent = curNode;
        return employeeFind(curNode->left, id, parent);
    } else {
        return curNode;
    }
}

void freeEmployee(EmployeeNode *node) {
    int i;

    free(node->employee->firstName);
    free(node->employee->lastName);

    for (i=0; i<node->employee->numOfAnimals; i++){
        free(node->employee->animalId[i]);
    }
    free(node->employee->animalId);
    free(node->employee);
    free(node);
}

EmployeeNode *deleteEmployee(EmployeeNode *root, char *id) {
    EmployeeNode *node, *node2, *parent;
    Employee *tempEmployee;

    parent = NULL;
    node = employeeFind(root, id, &parent);
    if (!node) {
        return root;
    }
    if (isEmployeeLeaf(node)) {
        if (parent) {
            if (parent->left == node) {
                parent->left=NULL;
            } else {
                parent->right=NULL;
            }
            freeEmployee(node);
            return root;
        } else {
            freeEmployee(node);
            return NULL;
        }
    }
    if (node->left) {
        node2 = employeeFindMax(node->left, NULL);
        tempEmployee = node->employee;
        node->employee = node2->employee;
        node2->employee = tempEmployee;
        node->left = deleteEmployee(node->left, id);
    } else {
        node2 = employeeFindMin(node->right, NULL);
        tempEmployee = node->employee;
        node->employee = node2->employee;
        node2->employee = tempEmployee;
        node->right = deleteEmployee(node->right, id);
    }
    return root;
}

void deleteAllEmployees(EmployeeNode *curNode) {
    if (curNode == NULL){
        return;
    }

    deleteAllEmployees(curNode->left);
    deleteAllEmployees(curNode->right);

    free(curNode);
}


void freeList(EmployeeList *l){
    EmployeeListNode *toDelete;

    if (l->head == NULL){
        free(l);
        return;
    }

    /*  delete head */
    toDelete = l->head;
    l->head = toDelete->next;
    free(toDelete);

    freeList(l);
}