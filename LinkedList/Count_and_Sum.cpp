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
int count(struct Node *p){
    int l=0;
    while(){
        l++;
        p=p->next;
    }
    return l;
}

int sum(struct Node* p){
    int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;
    }
    return s;
}

int main(){
    int A[]={3,4,2,6,98,3,1};
    create(A,7);
    cout<<"count :"<<count(first)<<endl;
    cout<<"sum :"<<sum(first)<<endl;
return 0;
}