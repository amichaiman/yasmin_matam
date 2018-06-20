
#include <stddef.h>
#include <stdlib.h>
#include "Tree.h"
#include "animal.h"

int getNumberOfNodes(Node *curNode);

void treeToArray(Node *curNode, Node **array, int *locationInArray);

void *createTree() {
    return NULL;
}

Node* addNodeToTree(Node *curNode, void *data, int (*compare)(void *, void *)) {
    if (curNode == NULL){
        Node* nodeToAdd =
                (Node*) malloc (sizeof(Node));
        if (!nodeToAdd){
            exit(1);
        }
        nodeToAdd->data = data;
        nodeToAdd->left = nodeToAdd->right = NULL;
        return nodeToAdd;
    }

    if (compare(curNode->data,data) > 0){
        curNode->left =
                addNodeToTree(curNode->left, data, compare);
    } else {
        curNode->right =
                addNodeToTree(curNode->right, data, compare);
    }

    return curNode;

}
int isLeaf(Node *node) {
    return node->left == NULL && node->right == NULL;
}

Node * findMin(Node *t, Node **parent) {
    if (!t) return NULL;
    if (t->left) {
        if (parent) *parent = t;
        return findMin(t->left, parent);
    } else {
        return t;
    }
}


Node * findMax(Node *t, Node **parent) {
    if (!t) return NULL;
    if (t->right) {
        if (parent) *parent = t;
        return findMax(t->right, parent);
    } else {
        return t;
    }
}


Node *deleteNode(Node *root, void *data, int (*compare)(void *, void *),
        void(*freeNode)(Node*)) {
    Node *node, *node2, *parent;
    Node *tempNode;

    parent = NULL;
    node = findNodeToDelete(root, data, &parent, compare);
    if (!node) {
        return root;
    }
    if (isLeaf(node)) {
        if (parent) {
            if (parent->left == node) {
                parent->left=NULL;
            } else {
                parent->right=NULL;
            }
            freeNode(node);
            return root;
        } else {
            freeNode(node);
            return NULL;
        }
    }
    if (node->left) {
        node2 = findMax(node->left, NULL);
        tempNode = node->data;
        node->data= node2->data;
        node2->data = tempNode;
        node->left = deleteNode(node->left, data,compare,freeNode);
    } else {
        node2 = findMin(node->right, NULL);
        tempNode = node->data;
        node->data= node2->data;
        node2->data= tempNode;
        node->right = deleteNode(node->left, data,compare,freeNode);
    }
    return root;
}

Node * findNodeToDelete(Node *curNode, Node *dataToFind, Node **parent, int(*compare)(void *, void *)){
    if (!curNode) {
        return NULL;
    }
    if (compare(dataToFind,curNode->data) > 0) {
        if (parent)
            *parent = curNode;
        return findNodeToDelete(curNode->right, dataToFind, parent, compare);
    } else if (compare(dataToFind,curNode->data) < 0) {
        if (parent)
            *parent = curNode;
        return findNodeToDelete(curNode->left, dataToFind, parent, compare);
    } else {
        return curNode;
    }
}





void deleteAllNodes(Node *curNode,void(*freeNode)(Node*)) {
    if (curNode == NULL){
        return;
    }

    deleteAllNodes(curNode->left,freeNode);
    deleteAllNodes(curNode->right,freeNode);

    freeNode(curNode);
}

void printTree(Node *curNode,void(*printData)(void*)){
    if (curNode == NULL){
        return;
    }

    printTree(curNode->left,printData);
    printData(curNode->data);
    printTree(curNode->right,printData);
}

List *findNode(List* list, Node *curNode, Node *dataToFind, int (*compare)(void *, void *)) {
    if (curNode == NULL){
        return NULL;
    }
    if (!list){
        list = (List*) malloc(sizeof(List));
    }
    findNode(list,curNode->left, dataToFind,compare);


    if (compare(dataToFind,curNode->data) == 0){
        ListNode* toAdd = (ListNode*) malloc(sizeof(ListNode));
        toAdd->data = curNode->data;
        toAdd->next = list->head;
        list->head = toAdd;
    }


    findNode(list,curNode->right, dataToFind,compare);

    return list;
}

float averageKey(Node *curNode, int *numNodes,int(*getKey)(Node*)) {

    float averageLeft;
    float averageRight;

    int numberOfNodesLeft;
    int numberOfNodesRight;

    if (curNode == NULL){
        *numNodes = 0;
        return 0;
    }

    averageLeft = averageKey(curNode->left,&numberOfNodesLeft,getKey);
    averageRight = averageKey(curNode->right,&numberOfNodesRight,getKey);

    *numNodes = numberOfNodesLeft + numberOfNodesRight + 1;


    return (averageLeft*numberOfNodesLeft + averageRight*numberOfNodesRight + getKey(curNode))/(*numNodes);
}

Node **fillArrayWithNodes(Node *root) {
    Node **array = NULL;
    int size = getNumberOfNodes(root);
    int locationInArray = 0;
    array = (Node**) malloc(size* sizeof(Node*));

    treeToArray(root, array, &locationInArray);
    return NULL;
}

void treeToArray(Node *curNode, Node **array, int *locationInArray) {
    if (!curNode){
        return;
    }
    treeToArray(curNode->left, array, locationInArray);

    array[(*locationInArray)++] = curNode; 

    treeToArray(curNode->right, array, locationInArray);
}

int getNumberOfNodes(Node *curNode) {
    if (!curNode){
        return 0;
    }
    return 1+getNumberOfNodes(curNode->right) + getNumberOfNodes(curNode->right);
}
