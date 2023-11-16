#include <iostream>
using namespace std;
class Circular_Queue{
      private:
       int size;
       int front;
       int rear;
       int *CQ;
      public:
       Circular_Queue(int size);
       ~Circular_Queue();
       bool isFull();
       bool isEmpty();
       void enqueue(int x);
       int dequeue();
       void display();
};

//constructor to initialize the circular queue.
Circular_Queue::Circular_Queue(int size){
    this->size=size;
    front=0;
    rear=0;
    CQ=new int[size];
}
//destructor for deallocating memory space.
Circular_Queue::~Circular_Queue(){
    delete [] CQ;
}
//function to check if the circular queue is full or not.
bool Circular_Queue::isFull(){
    if((rear+1)%size==front){
        return true;
    
    }
    return false;

}
//function to check if the circular queue is empty or not.
bool Circular_Queue::isEmpty(){
    if(front==rear){
        return true;
    }
    else{
        return false;
    }
}
//function to add an element in the circular queue.
void Circular_Queue::enqueue(int x){
    if(isFull()){
        cout<<"C_Queue Overflow"<<endl;
    }
    else{
        rear=(rear+1)%size;
        CQ[rear]=x;
    }
}
//function to remove an element from the circular queue.
int Circular_Queue::dequeue(){
    int x=-1;
    if(isEmpty()){
        cout<<"C_Queue Underflow"<<endl;
    }
    else{
        front=(front+1)%size;
        x=CQ[front];
    }
    return x;
}

//function to display the Circular Queue
void Circular_Queue::display(){
    int i=front+1;
    do{
        cout<<CQ[i]<<flush;
        if(i<rear){
            cout<<"<-"<<flush;
        }
        i=(i+1)%size;
    }while(i!=(rear+1)%size);
}

int main(){
    int A[]={34,67,89,43,21,67,89,43,322};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<n<<endl;
    Circular_Queue cq(n);
    for(int i=0;i<n;i++){
        cq.enqueue(A[i]);
    }
    cq.display();
    cout<<endl;
    for(int i=0;i<n;i++){
         cq.dequeue();
    }
    cq.display();
    cout<<endl;
    cq.enqueue(57);
    cout<<endl;
    cq.display();
    cq.dequeue();
    return 0;
}