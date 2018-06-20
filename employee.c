#include "employee.h"

Employee *getEmployeeFromInput() {
    Employee *employee = (Employee *) malloc (sizeof(Employee));
    char inputString[MAX];
    int i;

    clearBuffer();

    printf("Enter first name:\n");
    fgets(inputString,MAX,stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    employee->firstName = (char *) malloc ((strlen(inputString)+1)* sizeof(char));
    strcpy(employee->firstName,inputString);

    if (!employee->firstName){
        exit(1);
    }

    printf("Enter last name:\n");
    fgets(inputString,MAX,stdin);
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
    if (scanf("%d", &employee->numOfAnimals) != 1){
        clearBuffer();
        printf("Invalid input, Try again:\n");
    }
    while (!(employee->numOfAnimals >= 0 && employee->numOfAnimals<= MAX_NUM_OF_ANIMAL_PER_EMPLOYEE)){
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


int compareEmployee(void* e1, void * e2){
    return strcmp(((Employee*)e1)->id,((Employee*)e2)->id);
}


void addNewEmployee(Node **root) {
    Employee *employeeToAdd = getEmployeeFromInput();
    *root = addNodeToTree(*root, (void *) employeeToAdd, compareEmployee);
}




void printEmployee(void *data) {
    Employee* employee = (Employee*)data;
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

void addEmployeeWithGivenNumberOfEmployeesRec(List **list, Node *curNode, int numberOfEmployees) {
    if (curNode == NULL){
        return;
    }

    addEmployeeWithGivenNumberOfEmployeesRec(list,curNode->right,numberOfEmployees);
    addEmployeeWithGivenNumberOfEmployeesRec(list,curNode->left,numberOfEmployees);

    if (((Employee*)curNode->data)->numOfAnimals== numberOfEmployees){
        ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));

        newNode->data = curNode->data;
        newNode->next = (*list)->head;
        (*list)->head = newNode;
    }
}

List *findEmployee(Node *root) {
    int input;
    int numberOfEmployees;
    char stringInput[MAX];
    Node node;
    Employee employee;
    List *list = (List*) malloc (sizeof(List));
    list->head = NULL;

    printf("1) find by id.\n2) find by number of employees\n");
    scanf("%d",&input);
    clearBuffer();
    do {
        switch (input) {
            case 1:
                printf("Enter id:\n");
                fgets(stringInput,MAX,stdin);
                stringInput[strcspn(stringInput,"\n")] = '\0';
                strcpy(employee.id,stringInput);
                node.data = (void*)&employee;
                return findNode(NULL,root,&node,compareEmployee);
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

void printEmployeeList(ListNode *curNode){
    if (curNode == NULL){
        return;
    }
    printEmployee(curNode->data);
    printEmployeeList(curNode->next);
}


void freeEmployee(Node *node) {
    int i;

    Employee* employee = (Employee*)node->data;

    free(employee->firstName);
    free(employee->lastName);

    for (i=0; i<employee->numOfAnimals; i++){
        free(employee->animalId[i]);
    }
    free(employee->animalId);
    free(employee);
    free(node);
}

void freeList(List *l){
    ListNode *toDelete;

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