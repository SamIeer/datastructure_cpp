#include <iostream>
using namespace std;
class DEQueue{
      private: 
        int Front;
        int Rear;
        int size;
        int *Q;
      public:
         DEQueue(int size);
         ~DEQueue();
         void display();
         void enqueueFront(int x);
         void enqueueRear(int x);
         int dequeueFront();
         int dequeueRear();
         bool isEmpty();
         bool isFull();
};
DEQueue::DEQueue(int size){
    this->size = size;
    Front = -1 ; Rear=-1;
    Q = new int[size];
};

DEQueue::~DEQueue(){
    delete  [] Q;
}

bool DEQueue::isEmpty(){
    if(Front==Rear){
        return true;
    }
    return false;
}

bool DEQueue::isFull(){
    if(Rear==size-1){
        return true;
    }
    return false;
}

void DEQueue::enqueueFront(int x){
    if(Front==-1){
        cout<<"DEqueue overflow"<<endl;
    }
    else{
        Q[Front]=x;
        Front--;
    }
}

void DEQueue::enqueueRear(int x){
    if(Rear == size-1){
        cout<<"DEQueue overflow"<<endl;
    }
    else{
        Rear++;
        Q[Rear]=x;
    }
}

int DEQueue::dequeueFront(){
    int x=-1;
    if(isEmpty()){
        cout<<"DEQueue underflow"<<endl;
    }
    else{
        x=Q[Front];
        Front++;
    }
     return x;
}

int DEQueue::dequeueRear(){
  int x=-1;
  if(isEmpty()){
    cout<<"DEQueue underflow"<<endl;
  }
  else{
    x=Q[Rear];
    Rear--;
  }
  return x;
}

void DEQueue::display(){
    for(int i=Front+1;i<=Rear;i++){
        cout<<Q[i]<<flush;
    
    if(i<Rear){
        cout<<"<-"<<flush;
    }}
    cout<<endl;
}

int main(){

    int A[]={21,56,74,23,78,9};
    int B[]={45,76,84,90,34};
    int n=sizeof(A)/sizeof(A[0]);
    int m=sizeof(B)/sizeof(B[0]);
    DEQueue De(n);
    for(int i=0;i<n;i++){
        De.enqueueRear(A[i]);
    }
    De.display();
    De.enqueueRear(56);
    De.dequeueFront();
    De.dequeueRear();
    De.enqueueFront(478);
    De.enqueueRear(541);
    De.display();

    return 0;
}