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



//Taylor series 2nd apporach 
//Reducing the number of multiplications for the reducing the time complexity

double e_2(int x,int n){
    static double s=1;
    if(n==0){
        return s;
    }
    else{
        s=1+x*s/n;
        return e_2(x,n-1);
    }
}

//main function
int main(){
    int x,n;
    cout<<"Enter the value of x:"<<endl;
    cin>>x>>n;
    cout<<e(x,n)<<endl;
    cout<<"\ne("<<x<<","<<n<<")="<<e_2(x,n)<<endl;
    return 0;
}