//circualr Linked List
#include <iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* next;
};
class CircularLinkedList{
    private:
     Node* head;
    public:
     CircularLinkedList(int A[],int n);
     void Display();
     Node* getHead(){return head;}
     ~CircularLinkedList();
};

CircularLinkedList::CircularLinkedList(int *A,int n){
    Node* t; Node* tail;
    head = new Node;
    head->data=A[0];head->next=head;
    tail=head;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=tail->next;
        tail->next=t; tail=t;
    }
};

void CircularLinkedList::Display(){
    Node* p=head;
    do{
        cout<<p->data<<"->"<<flush;
        p=p->next;}while(p!=head);
        cout<<endl;
}

CircularLinkedList::~CircularLinkedList(){
    Node* p=head;
    while(p->next!=head){
        p=p->next;
    }
    while(p!=head){
        p->next=head->next;
        delete head;
        head=p->next;
    }
    if(p==head){
        delete head;
        head=nullptr;
    }
}
int length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

//Deleting element from circular linked list
int delete(struct Node *p,int index){
    struct Node *q;
    int i,x;
    if(index<0||index>length(head))
    return -1;
    if(index==1){
        while(p->next!=head)p=p->next;
        x=head->data;
        if(head==p){
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else{
        for(i=0;i<index-2;i++)
        p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}




int main(){
    int A[]={1,2,3,4,5,6};
    CircularLinkedList cl(A,sizeof(A)/sizeof(A[0]));
    cl.Display();
    delete(first,3);
    cl.Display();
    return 0;
}