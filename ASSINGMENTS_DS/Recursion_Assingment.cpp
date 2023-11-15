#include <iostream>
using namespace std;
//Question :  Program for demonstrating tail--recursion
int tail(int num,int multiplier){
    if(multiplier>10){
      return 0;
    }
    else{
        cout<<num<<"x"<<multiplier<<" ="<<num*multiplier<<endl;
        return tail(num,multiplier+1);}
}
int main(){
    int num;
    cout<<"enter the number"<<endl;
    cin>>num;
    tail(num ,1);
    return 0;
}


//Question 2: Program for demonstrating Head--recursion
void head(int n,int multiplier){
    if(multiplier>=1){
        head(n,multiplier-1);
        cout<<n<<"x"<<multiplier<<" ="<<n*multiplier<<endl;
    }}

int main(){
    cout<<"Enter a number:"<<endl;
    int a;
    cin>>a;
    head(a,10);
    return 0;}

//Question 3: Recursion program for the sum of  Whole number upto given number
int Sum_whole(int n){
    if(n==0){
        return 0;
    }
    else{
        return Sum_whole(n-1) + n;
    }
}

int main(){
    int n;
    cout<<"enter the number:"<<endl;
    cin>>n;
    cout<<"the sum is : "<<Sum_whole(n);
    }
