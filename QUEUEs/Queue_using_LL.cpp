#include <iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;
};

class Queue{
    private:
     Node*Front;
     Node*Rear;
    public:
     Queue();
     ~Queue();
     void enqueue(int x);
     int dequeue();
     bool isEmpty();
     void display();
};

Queue::Queue(){
    Front=nullptr;
    Rear=nullptr;
}

void Queue::enqueue(int x){
    Node*t=new Node;
    if(t==nullptr){
        cout<<"Queue overflow"<<endl;
    }
    else{
        t->data=x;
        t->next=nullptr;
        if(Front==nullptr){
            Front=t;
            Rear=t;
        }else {
            Rear->next = t;
            Rear = t;
        }
    }
}

int Queue::dequeue(){
    int x=-1;
    Node*p;
    if(isEmpty()){
        cout<<"Queue underflow"<<endl;
    }
    else{
        p=Front;
        Front=Front->next;
        x=p->data;
        delete p;}
        return x;
    }

bool Queue::isEmpty(){
    if(Front==nullptr){
        return true;
    }
    return false;
}

Queue::~Queue(){
    Node*p=Front;
    while(Front){
        Front=Front->next;
        delete p;
        p=Front;
    }
}

void Queue::display(){
    Node*p=Front;
    while(p){
        cout<<p->data<<flush;
        p=p->next;
        if(p!=nullptr){
            cout<<"<-"<<flush;
        }
    }
    cout<<endl;
}

int main(){
    int A[] = {34,53,12,76,86,345};
    int n=sizeof(A)/sizeof(A[0]);
    Queue q;
    for(int i=0;i<n;i++){
        q.enqueue(A[i]);
    }
    q.display();
    cout<<q.dequeue()<<endl;
    q.enqueue(56);
    q.display();
    return 0;
}