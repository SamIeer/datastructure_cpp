#include <iostream>
using namespace std;

class Stack{
    private:
     int size;
     int stop;
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
    stop=-1;
    S = new int[size];
}

Stack::~Stack(){
    delete [] S;
}

void Stack::push(int x){
    if(stop==size-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        stop++;
        S[stop]=x;
        
    }
}

int Stack::pop(){
    int x=-1;
    if(stop==-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        x=S[stop];
        stop--;
    }
    return x;
}

void Stack::display(){
    for(int i=stop;i>=0;i--){
        cout<<S[i]<<flush;
    }
    cout<<endl;
}

// Question 1: Revesing a string using a stack 
int main(){
    string S = "Tutedude" ;
    int s = S.length();
    Stack stk(s);
    for(int i  = 0 ; i<s ;i++){
         stk.push(S[i]);
    }
    while (s--) {
        cout << char(stk.pop()); 
    }
    cout << endl;
    return 0;
    }



#include <iostream>
#include <vector>
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
     bool isEmpty();
     void display();
     int stop();
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

bool Stack:: isEmpty(){
    if(top==-1){
        return true;}
     return false;
}

int Stack:: stop(){
    return S[top];

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
    for(int i=0;i <= top;i++){
        cout<<S[i]<<"<-"<<flush;
    }
    cout<<endl;
}



// // Ouestion 2: Sorting a stack using recursion

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
    cout << "The Array:" << endl;
    S.display();
    S.sort();
    cout<<"sorted Stack"<<endl;
    S.display();
}


//Question 4
int LRproduct(int* arr, int n) {
    vector<int> left(n,    0);
    vector<int> right(n, 0);
    Stack  s(n);

    // For the left side index
    for (int i = 0; i < n-1; ++i) {
        while (!s.isEmpty() && arr[s.stop()] <= arr[i]) {
            s.pop();
        }
        left[i] = s.isEmpty() ? 0 : s.stop() + 1;
        s.push(i);
    }

    // Clearing the stack for right indices
    while (!s.isEmpty()) {
        s.pop();
    }

    for (int i = n - 1; i >= 0; --i) {
        while (!s.isEmpty() && arr[s.stop()] <= arr[i]) {
            s.pop();
        }
        right[i] = s.isEmpty() ? 0 : s.stop() + 1;
        s.push(i);
    }

    // Calculate LRProduct and find the index with maximum LRProduct
    int maxIndex = -1;
    long long maxProduct = -1;

    for (int i = 0; i < n; ++i) {
        long long product = static_cast<long long>(left[i]) * right[i];
        if (product > maxProduct) {
            maxProduct = product;
            maxIndex = i + 1; 
        }
    }

    return maxIndex;
}

int main() {
    // Sample input array
    int arr[] = {5,4,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"size :"<<n<<endl;

    // Find the index with the maximum LRProduct
    int resultIndex = LRproduct(arr, n);

    // Output the result
    std::cout << "Index with maximum LRProduct: " << resultIndex << std::endl;

    return 0;
}
