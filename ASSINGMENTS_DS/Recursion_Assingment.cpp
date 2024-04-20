//Program for demonstrating tail--recursion
#include <iostream>
using namespace std;
// int tail(int n){
//     if(n>0){
//     cout<<n*n<<endl;
//     tail(n-1);
//     }
// }
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


// int main(){
//     int s;
//     cout<<"enter the number:"<<endl;
//     cin>>s;
//     cout<<tail(s);
//     return 0;
// }
//Question 2: Program for demonstrating Head--recursion
void head(int n,int multiplier){
    if(multiplier>=1){
        head(n,multiplier-1);
        cout<<n<<"x"<<multiplier<<" ="<<n*multiplier<<endl;
    }}

//Program for demonstrating Head--recursion
// int head(int m,int n){
//     if(n>0){
//         head(m,n-1);
//         cout<<n*m<<endl;}
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
    int h,n;
    cout<<"enter the number"<<endl;
    cin>>h,n;
    head(h,n);

    int n;
    cout<<"enter the number:"<<endl;
    cin>>n;
    cout<<"the sum is : "<<Sum_whole(n);
    }