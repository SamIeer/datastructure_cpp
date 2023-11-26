//Implementation of LINkEd List
//Collectioh of nodes where each node contain data and head pointer to next node
//Head pointer points to first node
//Address of the nodes are not continous,,created in heap
#include <iostream>
using namespace std;
class Node{
    public:
     int data;
     Node *next;
};

int main(){
   int A[]={3,5,2,52,1,8};
   Node*head = new Node;
   Node* temp;
   Node* last;

   head->data = A[0];
   head->next=nullptr;
   last=head;

   //create a Linked List
   int n=sizeof(A)/sizeof(A[0]);
   for(int i=1; i<n;i++){
    //Create a 2temporary Node 
    temp = new Node;

    //populate temporary Node
    temp->data=A[i];
    temp->next=nullptr;

    //last next is pointing to temp
    last->next=temp;
    last=temp;
   }

   Node* p=head;
   while(p!=nullptr){
    cout<<p->data<< "->"<<flush;
    p=p->next;
   }
   return 0;
}

