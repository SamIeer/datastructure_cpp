//Combination formula using recursion
//This method is called pascal triangle it helps to reduce timecomplixity
#include <iostream>
using namespace std;
int C(int n,int r){
    if(r==0 || n==r){
        return 1;
    }
    else{
        return C(n-1,r-1) + C(n-1,r);
    }
}

int main(){
    cout<<"enter the number :"<<endl;
    int n,r;
    cin>>n>>r;
    cout<<C(n,r);
}