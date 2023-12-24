#include <iostream>
using namespace std;
// //forming a Node using Class
// class Node{
//     private:
//      int data;
//      Node* next;
//      Node(int value) :data(value),next(nullptr){ }
// }

// //NOde by using structure
// struct Node{
//     int data:
//     Node(int value) :data(value),next(nullptr){}
// }


//ANSWER2:insering elemnt in linked list from the end
// struct Node {
//     int data;
//     Node* next;

//     // Constructor to initialize data and next pointer
//     Node(int value) : data(value), next(nullptr) {}
// };

// //Function to insert element in the end
// void Insert_end(Node*& p, int x) {
//     Node* t = new Node(x);
//     if (p == nullptr) {
//         p = t;
//         return;
//     }
//     Node* current = p;
//     while (current->next != nullptr) {
//         current = current->next;
//     }
//     current->next = t;
// }

// void Display(Node* p) {
//     while (p != nullptr) {
//         cout << "->" << p->data;
//         p = p->next;
//     }
//     cout<<endl;
// }

// int main() {
//     Node* first = nullptr;
//     int A[] = {1, 2, 3, 4, 5};
//     int n = sizeof(A) / sizeof(A[0]);

//     for (int i = 0; i < n; i++) {
//         Insert_end(first, A[i]);
//     }
//     Insert_end(first,7);

//     // Display the linked list
//     cout << "Linked List: ";
//     Display(first);

//     return 0;
// }

//Answeer3:insertion of element from any position
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


void Insert(struct Node *p,int index,int x){
    struct Node *t;
    if(index<0 || index >> count(p))
      return ;
    t=new Node[sizeof(struct Node)];
    t->data=x;

    if(index == 0){    
        t->next=first;
        first=t;
    }

    else{
        for(int i=0;i<index-1;i++)
         p=p->next;
         t->next=p->next;
         p->next=t;
    }
}

int main(){
    int A[]={1,2,3,4,5,6,7,8,9,1234};
    create(A,10);
    Insert(first,0,67);
    Insert(first,7,345);
    return 0;
}