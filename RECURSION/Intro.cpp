//RECURSION: A function calling itself and it have some base condition to terminate recursion.
//GENERLASING RECURSION;
#include <iostream>
using namespace std;

// void fun(int n){
//     if(n>0){
//         //calling     --------------ASSENDING PHASE
//         cout<<n<<" "; 
//         fun(n-1);
//         //returning   --------------DESCENDING PHASE
//     }
// }

//PROGRAM TO DEMONSTRATE THE WORKING OF RECURSION 
void count_till(int n){
    if(n>0){
       cout<<n<<" ";
       count_till(n-1);
    }
}

int main(){
    int num;
    cin>>num;
    count_till(num);
}