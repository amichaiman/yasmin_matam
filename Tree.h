
#ifndef YASMIN_MATAM_TREE_H
#define YASMIN_MATAM_TREE_H


typedef struct node {
    void* data;
    struct node* left;
    struct node* right;
} Node;

typedef struct listNode{
    void *data;
    struct listNode* next;
} ListNode;

typedef struct {
    ListNode *head;
} List;
void* createTree();
float averageKey(Node *curNode, int *numNodes,int(*getKey)(Node*));
List*findNode(List* list,Node* curNode, Node* dataToFind, int(*compare)(void *, void *));
Node* deleteNode(Node* cur,void* data,int(*compare)(void *, void *),void(*freeNode)(Node*));
Node * findNodeToDelete(Node *curNode, Node *dataToFind, Node **parent, int(*compare)(void *, void *));
Node* addNodeToTree(Node *curNode, void *data, int(*compare)(void *, void *));
void deleteAllNodes(Node *curNode,void(*freeNode)(Node*));
void printTree(Node *curNode,void(*printData)(void*));
Node ** fillArrayWithNodes(Node *root);
#endif
