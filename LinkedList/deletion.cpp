//Deletion 
#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=new Node[sizeof(struct Node)];
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=new Node[sizeof(struct Node)];
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    } 
}

int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}

void Display(struct Node *p){
    while(p!=NULL){
        cout<<" "<<p->data;
        p=p->next;
    }
}

int Delete(struct Node *p,int index){
    struct  Node *q=NULL;
    int x=-1;
    if(index<1 ||index>count(p))
    return -1;

    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
         q=p;
         p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int main(){
    int A[]={10,20,30,40,50,60,60};
    create(A,7);
    Delete(first,6);
    Display(first);
    return 0;
}