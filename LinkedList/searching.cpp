#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    struct Node*t,*last;
    first=new Node[sizeof(struct Node)];
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=0;i<n;i++){
        t=new Node[sizeof(struct Node)];
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

struct Node* search(struct Node*p,int key){
    struct Node *q;
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
        return 0;
    }

int main(){
    int arr[]={34,34,21,53,764,98,9,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    create(arr,n);
    struct Node *temp=search(first,34);
    cout<<temp->data<<endl;
    return 0;
}