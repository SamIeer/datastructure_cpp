#include <iostream>
using namespace std;
//fibonacci series
int fib(int n){
    if(n<=1){
        return n;
    }
    else{
        return fib(n-2)+fib(n-1);
    }
}

//using memoization
int F[10];

int mfib(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2] = mfib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1] = mfib(n-1);}
        return F[n-2]+F[n-1];
    }
}

int main(){
    for(int i=0;i<10;i++){
    F[i]=-1;}
    int n;
    cin>>n;
    cout<<n<<"the terms are:"<<fib(n-1)<<endl;
    cout<<n<<"the term:"<<mfib(n-1)<<endl;
}