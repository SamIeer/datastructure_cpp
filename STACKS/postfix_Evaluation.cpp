#include <iostream>
#include <cstring>
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
};
Stack::Stack(int size){
        this->size = size;
        top = -1;
        S = new int[this->size];};

Stack::~Stack(){
            delete[] S;};

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
    for(int i=top; i>=0;i--){
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

//parenthsis matching
bool isBalanced(char *exp){
    Stack stk((int)strlen(exp));
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('){
            stk.push(exp[i]);
        }
        else if(exp[i]==')'){
            if(stk.isEmpty()){
                return false;
            }
            else{
            stk.pop();}
        }
    }
    return stk.isEmpty() ? true : false;
    }

    int isoperand(char x){
        if(x=='+'||x=='-'||x=='-'||x=='/'){
            return 0;
        }
        return 1;
    }

    int operations(char op,int x,int y){
        switch(op){
            case '+':
              return x+y;
              break;
            case '-':
              return x-y;
              break;
            case '*':
              return x*y;
              break;
            case '/':
              return x/y;
              break;
            default:
             return -1;
        }
    }

   
int Post_Evaluate(char *postfix) {
    Stack<int> stk;
    int x, y, result;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            stk.push(postfix[i] - '0');
        } else {
            y = stk.pop();
            x = stk.pop();
            result = performOperation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.pop();
    return result;
}

    int main(){
        char *postfix[]="35*45/+4-";
        cout<<Postfix_Evaluate(postfix)<<endl;
        return 0;

    }