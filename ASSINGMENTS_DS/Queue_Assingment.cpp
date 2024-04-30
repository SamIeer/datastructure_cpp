//Answer 1
#include <iostream>
using namespace std;

class Node{
    public:
      int data;
      Node*next;
};
class Queue{
    private:
      Node *front;
      Node *rear;
    public:
     Queue();
     ~Queue();
     void enqueue(int x);
     int dequeue();
     bool isEmpty();
     void display();
};

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
}
void Queue::enqueue(int x){
    Node*t = new Node;
    if(t == nullptr){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        t -> data = x;
        t -> next = nullptr;
        if(front == nullptr){
            front = t;
            rear = t;
        }else {
            rear->next = t;
            rear = t;
        }
    }
}
int Queue::dequeue(){
    int x = -1;
    Node * p;
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        p = front;
        front = front -> next;
        x = p-> data;
        delete p;
    }
    return x;
}

bool Queue::isEmpty(){
    if(front == nullptr){
        return true;
    }
    return false;
}

Queue::~Queue(){
    Node *p = front ;
    while(front){
        front = front -> next;
        delete p;
        p = front;
    }
}

void Queue::display(){
    Node*p=front;
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
    q.dequeue();
    q.dequeue();
    q.display();
}


// Answer 2;
class StackNode{
    public:
      int data;
      StackNode* next;

      StackNode(int data){
        this->data = data;
        this->next = nullptr;
      }
};

class Stack{
    private:
     StackNode* top;

    public:
       Stack(){
       top = nullptr;}
     
      //push operation 
      void push(int data){
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
      }

      int pop(){
        if(isEmpty()){
            cout<<"stack Underflow"<<endl;
            return -1;
        }
        int data = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return data;
      }

      bool isEmpty(){
        return top == nullptr;
      }

      int peek(){
        if(isEmpty()){
            cout<<"stack is Empty:"<<endl;
            return -1;
        }
        return top->data;
      }
};


class Queue{
    private:
      Stack s1;
      Stack s2;

    public:
      void enqueue(int x){
         s1.push(x);
      }
      int dequeue(){
        if(s2.isEmpty()){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        if(s2.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
        }
         return s2.pop();
      }

      bool isEmpty(){
        return s1.isEmpty() && s2.isEmpty();
      }

      void display() {
         Stack tempStack; // Create a temporary stack

        // Transfer elements from s2 to tempStack and print them
        while (!s2.isEmpty()) {
            int element = s2.peek();
            tempStack.push(element);
            cout << element << "<-" << endl;
            s2.pop();
           }
        // Transfer elements back to s2
        while (!tempStack.isEmpty()) {
            s2.push(tempStack.peek());
            tempStack.pop();
        }
     }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(45);
    q.enqueue(42);

    cout<<"Queue is :"<<endl;
    q.display();
}

//Answer 3:
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

Circular_Queue::Circular_Queue(int size){
    this->size = size;
    front = 0;
    rear = 0;
    CQ = new int[size];
}

Circular_Queue::~Circular_Queue(){
    delete [] CQ;
}

bool Circular_Queue::isFull(){
    if((rear+1)%size==front){
        return true;
    }
    return false;
}

bool Circular_Queue::isEmpty(){
    if(front == rear){
        return true;
    }
    else{
        return false;
    }
}

void Circular_Queue::enqueue(int x){
    if(isFull()){
        cout<<"Overflow "<<endl;
    }
    else{
        rear = (rear +1)%size;
        CQ[rear] = x;
    }
}

int Circular_Queue::dequeue(){
    int x = -1;
    if(isEmpty()){
        cout<<"Underflow"<<endl;
    }
    else{
        front = (front +1 )%size;
        x = CQ[front];
    }
    return x;
}
void Circular_Queue::display(){
    int i = front +1;
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
    return 0;}