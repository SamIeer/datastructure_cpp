#include <iostream>
using namespace std;

class Queue{
   private:
    int size;
    int front;
    int rear;
    int *Q;
   public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool IsEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[this->size];
}

Queue::~Queue(){
    delete [] Q;
}

bool Queue::isFull(){
    if(rear==(size-1)){
        return true;
    }
    else{
        return false;
    }
}

bool Queue::IsEmpty(){
    if(rear==front){
        return true;
    }
    else{
        return false;
    }
}

void Queue::enqueue(int size){   //Inserting the elements in the Queue from the back
   if(isFull()){
    cout<<"Queue Overflow"<<endl;
   }
   else{
    rear++;
    Q[rear] = size;
   }
}

int Queue::dequeue(){          //removing the element from Queue from the front
    int x=-1;   
    if(IsEmpty()){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<flush;
    if(i<rear){
        cout<<"<-"<<flush;
    }
    }
    cout<<endl;
}

int main(){
    int A[]={34,56,12,67,9,64};
    int n=sizeof(A)/sizeof(A[0]);
    Queue q(n);
    for (int i=0;i<n;i++){
        q.enqueue(A[i]);
    }
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(4);
    q.display();
    return 0;
}