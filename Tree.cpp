//Tree Recursion
// //A tree is a collection of nodes where each node has at most two children, referred to as the left child and right child.
#include <iostream>
using namespace std;

void Tree(int n){
    if(n>0){
        cout<<n<<endl;
        Tree(n-1);
        Tree(n-1);}
}
int main(){
    int n=5;
    Tree(n);
    return 0;}