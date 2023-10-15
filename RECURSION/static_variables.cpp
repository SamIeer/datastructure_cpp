//STATIC VARIABLE:Static variables in recursion are variables that retain their values across multiple function calls in a recursive function.
// These variables are not reinitialized with each function call, and their values are preserved between recursive calls. 
// This behavior can be useful in certain situations when you need to maintain or update state information during recursive function execution
//When you declare a variable as static within a function, it means that the variable's value persists between function calls
//,and it's not allocated and deallocated on the stack like regular local variables.

#include <iostream>
using namespace std;

// Recursion without static varible
int func(int n){
    if(n>0){
        return func(n-1) + n;
    }
}
int main(){
    int a=4;
    cout<<func(a);
    return 0;
}


//Recursion with static varible
int funs(int n){
     static int x=0;
     if(n>0){
        x++;
        cout<<x<<endl;
        return  funs(n-1) + x;
     }
     return 0;
}

int main(){
    int a = 5;
    cout<<funs(a);
    return 0;
}