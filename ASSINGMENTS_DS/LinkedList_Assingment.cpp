#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

//Function to insert element in the end
void Insert_end(Node*& p, int x) {
    Node* t = new Node(x);
    if (p == nullptr) {
        p = t;
        return;
    }
    Node* current = p;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = t;
}

void Display(Node* p) {
    while (p != nullptr) {
        cout << "->" << p->data;
        p = p->next;
    }
    cout<<endl;
}


int main() {
    Node* first = nullptr;
    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++) {
        Insert_end(first, A[i]);
    }
    Insert_end(first,7);

    // Display the linked list
    cout << "Linked List: ";
    Display(first);

    return 0;
}
