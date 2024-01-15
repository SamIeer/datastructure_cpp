#include<iostream>
using namespace std;
struct Node{
    struct Node*prev;
    int data;
    struct Node *next;
}*first=NULL;
void create(int A[],int n){
    struct Node *t,*last;
    int i;
    first=new Node[sizeof(struct Node)];
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node[sizeof(struct Node)];
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void Insert(struct Node *p,int index,int x)
{
   struct Node *t;
   int i;
   if(index<0||index>length(p))
   return;
   if(index==0){
    t=new Node[sizeof(struct Node)];
    t->data=x;
    t->prev=NULL;
    t->next=first;
    first->prev=t;
    first=t;
   }
   else{
    for(int i=0;i<index-1;i++){
      p=p->next;
      t=new Node[sizeof(struct Node)];
      t->data=x;
      t->prev=p;
      t->next=p->next;
      if(p->next)p->next->prev=t;
      p->next=t;
    }
   }
}

int Delete(struct Node *p,int index){
    int x =-1;
    if(index<1||index>length(p))
    return -1;
    if(index==1){
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        free(p);
    }
    else{
        for(int i=0;i<index-1;i++)
        p=p->next;
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
            x=p->data;
            free(p);
        }
       return x;
    }
}

void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
        first=p;
    }
}

int main(){
    int A[]={10,20,30,40,50,60};
    create(A,6);
    Display(first);
    Reverse(first);
    cout<<endl;
    Display(first);
    return 0;
}


//Reversing in doublly linklist
#include <iostream>
using namespace std;
class Node{
    public:
    Node* prev;
    int data;
    Node* next;
};

class DoublyLinkedList{
    private:
     Node* head;
    public:
     DoublyLinkedList();//Default constructor 
     DoublyLinkedList(int A[],int n);//parameterised constructor
     ~DoublyLinkedList();//Destructor
     void Display();
     int Length();
     void Reverse();
};

DoublyLinkedList::DoublyLinkedList(){
    head=new Node;
    head->prev= nullptr;
    head->data=0;
    head->next=nullptr;
}

DoublyLinkedList::DoublyLinkedList(int *A,int n){
    head=new Node;
    head->prev=nullptr;
    head->data=A[0];
    head->next=nullptr;
    Node*tail=head;

    for(int i=1;i<n;i++){
        Node* t=new Node;
        t->prev=tail;
        t->data=A[i];
        t->next=tail->next;//tail-next is pointing to NULL
        tail->next=t;
        tail=t;
    }
}

void DoublyLinkedList::Display(){
    Node*p=head;
    while(p!=nullptr){
        cout<<p->data<<flush;
        p=p->next;
        if(p!=nullptr){
            cout<<"<->"<<flush;
        }
    }
    cout<<endl;
}

int DoublyLinkedList::Length(){
    int length=0;
    Node*p=head;
    while(p!=nullptr){
        length++;
        p=p->next;
    }
    return length;
}
void DoublyLinkedList::Reverse(){
    Node*p=head;
    Node* temp;
    while(p!=nullptr){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;

        //Need to check the following contions again 
        if(p->next==nullptr){
            p->next=p->prev;
            p->prev=nullptr;
            head=p;
            break;
        }
    }
}

DoublyLinkedList::~DoublyLinkedList(){
    Node* p=head;
    while(head){
        head=head->next;
        delete p;
        p=head;
    }
}
int main(){
    int A[]={1,3,5,7,9};
    int n=sizeof(A)/sizeof(A[0]);
    DoublyLinkedList dl(A,n);
    cout<<"length :"<<dl.Length()<<endl;

    dl.Reverse();
    dl.Display();

    return 0;
}