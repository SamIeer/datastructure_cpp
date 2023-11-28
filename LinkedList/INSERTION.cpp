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

//inserting node in sorted linked list
void  Sorted_Insert(struct Node *p,int x){
    struct Node *t,*q=NULL;
    t=new Node[sizeof(struct Node)];
    t->data=x;
    t->next=NULL;
    if(first==NULL)
     first=t;
    else{
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int main(){
    int A[]={1,2,3,4,5,6,7,8,9,1234};
    create(A,10);
    // Insert(first,0,67);
    // Insert(first,7,345);
    Sorted_Insert(first,54);
    Display(first);
    return 0;
}