// #include <iostream>
// using namespace std;

// class Stack{
//     private:
//      int size;
//      int top;
//      int *S;
//     public:
//      Stack(int size);
//      ~Stack();
//      void push(int x);
//      int pop();
//      void display();
// };
// Stack::Stack(int size){
//     this->size = size;
//     top=-1;
//     S = new int[size];
// }

// Stack::~Stack(){
//     delete [] S;
// }

// void Stack::push(int x){
//     if(top==size-1){
//         cout<<"Stack Overflow"<<endl;
//     }
//     else{
//         top++;
//         S[top]=x;
        
//     }
// }

// int Stack::pop(){
//     int x=-1;
//     if(top==-1){
//         cout<<"Stack Underflow"<<endl;
//     }
//     else{
//         x=S[top];
//         top--;
//     }
//     return x;
// }

// void Stack::display(){
//     for(int i=top;i>=0;i--){
//         cout<<S[i]<<flush;
//     }
//     cout<<endl;
// }

// Question 1: Revesing a string using a stack 
// int main(){
//     string S = "Tutedude" ;
//     int s = S.length();
//     Stack stk(s);
//     for(int i  =0 ; i<s ;i++){
//          stk.push(S[i]);
//     }
//     stk.display();
//     return 0;
//     }



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
     void sort();
     void insertSorted(int x);
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
        top++;
        S[top]=x;
        
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
    for(int i=top;i>=0;i--){
        cout<<S[i]<<"<-"<<flush;
    }
    cout<<endl;
}

// Ouestion 2: Sorting a stack using recursion
// Sorting a stack using recursion
void Stack::sort() {
    if (top != -1) {
        int temp = pop();
        sort();
        insertSorted(temp);
    }
}

void Stack::insertSorted(int x) {
    if (top == -1 || x > S[top]) {
        push(x);
        return;
    }

    int temp = pop();
    insertSorted(x);
    push(temp);
}

int main(){
    int A[]={23,54,12,7,2,90,1};
    int n=sizeof(A)/sizeof(A[0]);
    Stack S(n);
    for (int i = 0; i < n; i++)
    {
       S.push(A[i]);
    }
    cout << "The sorted array is:" << endl;
    S.display();
    S.sort();
    cout<<"sorted Stack"<<endl;
    S.display();
}
