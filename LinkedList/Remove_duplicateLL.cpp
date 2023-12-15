#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void create(int A[],int n){
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void RemoveDuplicate(struct Node *p){
    struct Node *q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=p->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void Reversel(struct Node *p){
    int *A,i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*sizeof(p));
    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }
}

int main(){
    int A[]={10,20,20,30,40,50,50,60,70,70,70};
    create(A,11);
    RemoveDuplicate(first);
    Display(first);
    printf("\n");
    Reversel(first);
    Display(first);
    return 0;
}