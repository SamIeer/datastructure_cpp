#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Stack {
private:
    int size;
    int top;
    T* S;

public:
    Stack(int size);
    ~Stack();
    void push(T x);
    T pop();
    T peek(int index);
    int isFull();
    int isEmpty();
    void display();
    T stackTop();
};

template <class T>
Stack<T>::Stack(int size) {
    this->size = size;
    top = -1;
    S = new T[this->size];
}

template <class T>
Stack<T>::~Stack() {
    delete[] S;
}

template <class T>
void Stack<T>::push(T x) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
    } else {
        top++;
        S[top] = x;
    }
}

template <class T>
T Stack<T>::pop() {
    T x = 1;
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}

template <class T>
T Stack<T>::peek(int index) {
    T x = -1;
    if (top - index + 1 < 0 || top - index + 1 == size) {
        cout << "Invalid position!" << endl;
    } else {
        x = S[top - index + 1];
    }
    return x;
}

template <class T>
int Stack<T>::isFull() {
    if (top == size - 1) {
        return 1;
    }
    return 0;
}

template <class T>
int Stack<T>::isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

template <class T>
void Stack<T>::display() {
    for (int i = top; i >= 0; i--) {
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}

template <class T>
T Stack<T>::stackTop() {
    if (isEmpty()) {
        return -1;
    }
    return S[top];
}

// Parenthesis matching
bool isBalanced(char *exp) {
    Stack<char> stk((int)strlen(exp));
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') {
            stk.push(exp[i]);
        } else if (exp[i] == ')') {
            if (stk.isEmpty()) {
                return false;
            } else {
                stk.pop();
            }
        }
    }
    return stk.isEmpty() ? true : false;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    return 1;
}

int performOperation(char op, int x, int y) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        default:
            return -1;
    }
}

int PostfixEvaluate(char *postfix) {
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

int main() {
    char postfix[] = "35*45/+4-";
    cout << PostfixEvaluate(postfix) << endl;
    return 0;
}
