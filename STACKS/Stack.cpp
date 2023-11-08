//Stacks Implementation
#include <iostream>
using namespace std;
class Stack {
    private:
        int size;
        int top;
        int* S;
    public:
        Stack(int size);
        ~Stack();
        void push(int x);
        int pop();
        int peek(int index);
        int isFull();
        int isEmpty();
        void display();
        int stackTop();
}
Stack::Stack(int size){
    this->size = size;
    top = -1;
    S = new int[this->size];}

Stack::~Stack(){
    delete[] S;
}

void Stack::push(int x){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;}
    else{
        top++;
        S[top]=x;
    }}

int Stack::pop(){
    int x = 1;
    if (isEmpty()){
        cout<<"Stack UNderflow"<<endl;}
    else{
        x=S[top];
        top--;
    }
    return x;
    }

int Stack::peek(int index){
    int x = -1;
    if(top-index+1 < 0 || top-index+1==size){
        cout<<"INvalid position!"<<endl;
    }
    else{
        x=S[top-index+1];
    }
    return x;
}

int Stack::isFull(){
    if(top == size-1){
        return 1;
    }
    return 0;
}

int Stack::isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

void Stack::display(){
    for(int i=top; i>=0;i++){
        cout<<S[i]<<" | "<<flush;
    }
    cout<<endl;
}

int Stack::stackTop(){
    if(isEmpty()){
        return -1;
    }
    return S[top];
}

int main(){
    int A[] = {1,2,3,5,7,9};
    Stack stk(sizof(A)/sizeof(A[0]));
}

