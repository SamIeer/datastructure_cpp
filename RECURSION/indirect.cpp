//INDIRECT RECURSION
//These are more than one functions and they are calling each other in a circular fashion
#include <iostream>
using namespace std;

void funA(int);
void funB(int);
int main(){
     cout<<"enter a number"<<endl;
     int num;
     cin>>num;
     funA(num);
     return 0;
}

void funA(int n){
    if(n>0){
        cout<<n<<endl;
        funB(n-1);
    }
}

void funB(int n){
    if(n>1){
       cout<<n<<endl;
       funA(n/2);
    }
}