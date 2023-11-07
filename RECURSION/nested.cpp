//NESTED RECURSION
//Recursion function will pass parameter as a recursive call
#include <iostream>
using namespace std;

int nest(int n){
    if(n>100){
        return n-10;
    }
    else{
        return nest(nest(n+11));
    }
}

int main(){
    cout<<"enter a number"<<endl;
    int n;
    cin>>n;
    cout<<nest(n);
    return 0;
}