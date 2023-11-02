//Sum of natural number using recursion
#include <iostream> 
using namespace std;
int sum_natural(int n){
    if(n>0){
        return sum_natural(n-1)+n;
    }
}

//Factorial using recursion
int Factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return Factorial(n-1)*n;
    }
}

//Power of a number using recursion
int power1(int m,int n){
    if(n==0){
        return 1;
    }
    else{
        return power1(m,n-1)*m;
    }
}

//Power of a number using recursion Efficient way : reducing the number of multiplication approxmatily to half
int power2(int m,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return power2(m*m , n/2);
    }
    else{
        return m*power2(m*m , (n-1)/2);
    }
}

int main(){
    cout<<"Enter the natural number:"<<endl;
    int n;
    cin>>n;
    cout<<sum_natural(n)<<endl;
    cout<<Factorial(n)<<endl;
    cout<<power1(3,5)<<endl;
    cout<<power2(3,5)<<endl;
}