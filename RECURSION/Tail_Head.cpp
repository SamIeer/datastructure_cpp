//TAIL RECURSION 
//recursive call is the last statement in the function
//after the call there is no other statement ,Time = O(n) , space = O(n)-n
#include <iostream>
using namespace std;

void tail(int n){
    if(n>0){
        cout<<n<<endl;
        head(n-1);
    }}


int main(){
    cout<<"Enter a number:"<<endl;
    int a;
    cin>>a;
    tail(a);
    return 0;}



//HEAD RECURSION
//recursive call is not the last statement in the function, it can be anywhere.
//time complexity : O(logN), Space Complexity:O(1)
void head(int n){
    if(n>0){
        head(n-1);
        cout<<n<<endl;
    }}

int main(){
    cout<<"Enter a number:"<<endl;
    int a;
    cin>>a;
    head(a);
    return 0;}