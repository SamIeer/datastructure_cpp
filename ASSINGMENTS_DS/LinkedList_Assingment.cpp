#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first=NULL;

int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}

void create(int A[],int n){
    struct Node *t,*last;
    first=new Node[sizeof(struct Node)];
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node[sizeof(struct Node)];
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

void Display(struct Node *p){
    while(p!=NULL){
        cout<<"->"<<p->data;
        p=p->next;
    }
}

void Insert_end(struct Node*& p, int x) {
    // Create a new node and allocate memory
    struct Node* t = new Node(x);

    if (p == nullptr) {
        // If the linked list is empty, make the new node the head
        p = t;
        return;
    }

    // Traverse to the end of the linked list
    Node* current = p;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = t;
}




int main(){
    int A[]={1,2,3,4,5,6,7,8,9,1234};
    create(A,10);
    Insert_end(first,5);
    Display(first);
    return 0;
}