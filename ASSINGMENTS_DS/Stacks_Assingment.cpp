#include <iostream>
using namespace std;

class Stack{
    private:
     int size;
     int top;
     int *S;
    public:
     Stack(int size);
     ~Stack();
     void push(int x);
     int pop();
     void display();
};
Stack::Stack(int size){
    this->size = size;
    top=-1;
    S = new int[size];
}

Stack::~Stack(){
    delete [] S;
}

void Stack::push(int x){
    if(top==size-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        S[top]=x;
        top--;
    }
}

int Stack::pop(){
    int x=-1;
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        x=S[top];
        top--;
    }
    return x;
}

void Stack::display(){
    for(int i=top:i>0;i++){
        cout<<S[i]<<"<-"<<flush;
    }
    cout<<endl;
}

int main(){
    
}