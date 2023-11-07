//Program for demonstrating tail--recursion
#include <iostream>
using namespace std;
// int tail(int n){
//     if(n>0){
//     cout<<n*n<<endl;
//     tail(n-1);
//     }
// }

// int main(){
//     int s;
//     cout<<"enter the number:"<<endl;
//     cin>>s;
//     cout<<tail(s);
//     return 0;
// }

//Program for demonstrating Head--recursion
int head(int m,int n){
    if(n>0){
        head(m,n-1);
        cout<<n*m<<endl;
    }
}
int main(){
    int h,n;
    cout<<"enter the number"<<endl;
    cin>>h,n;
    head(h,n);
}