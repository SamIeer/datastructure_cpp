//TAYLOR SERIES
//Taylor series for e^x = 1 + x/1! + (x)^2/2! + (x)^3
#include <iostream>
using namespace std;
double e(int x,int n){
    static double p=1,f=1;
    double r;
    if(n==0){
        return 0;
    }
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r + p/f;
    }
}

int main(){
    int x,n;
    cout<<"Enter the value of x:"<<endl;
    cin>>x>>n;
    cout<<e(x,n);
    return 0;
}