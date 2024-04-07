#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

struct Node *createNode(int key){
    struct Node* node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node ;
}

int getbalancedfactor(struct Node *n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}