#include <stdio.h>
#include "mainFunctions.h"

int main() {
    Node *animalRoot;
    Node *employeeRoot;
    Node *foodRoot;


    animalRoot = createTree();
    employeeRoot= createTree();
    foodRoot = createTree();

    getUserQueries(animalRoot,employeeRoot,foodRoot);

    return 0;
}

