#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
    bool isRed; // Red = true, Black = false
};

Node* root = nullptr; // Define root outside of main

Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->isRed = true; // Newly inserted node is always red
    return newNode;
}

void leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void insertFixup(Node* z) {
    while (z != root && z->parent->isRed) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->isRed) {
                z->parent->isRed = false;
                y->isRed = false;
                z->parent->parent->isRed = true;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->isRed = false;
                z->parent->parent->isRed = true;
                rightRotate(z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->isRed) {
                z->parent->isRed = false;
                y->isRed = false;
                z->parent->parent->isRed = true;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->isRed = false;
                z->parent->parent->isRed = true;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->isRed = false;
}

void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Insert elements into the Red-Black Tree
    root = createNode(5);
    root->isRed = false; // Root is always black
    root->left = createNode(33);
    root->left->isRed = true; // Newly inserted node is always red
    root->left->parent = root;
    root->right = createNode(21);
    root->right->isRed = true;
    root->right->parent = root;
    root->right->right = createNode(23);
    root->right->right->isRed = true;
    root->right->right->parent = root->right;

    cout << "Red-Black Tree with elements 5, 33, 21, 23 has been created." << endl;

    // Delete the Red-Black Tree
    deleteTree(root);
    root = nullptr; // Set root to nullptr after deletion

    return 0;
}


