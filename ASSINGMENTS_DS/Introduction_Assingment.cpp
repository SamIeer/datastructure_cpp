#include <iostream>
using namespace std;
//ANSWER 1: TO CHECK WETHER A NUNBER IS PRIME OR NOT
void prime(int a){
    if(a==1){
        cout<<"Nether prime nor composite";}
    else if(a==2){
          cout<<"PRIME NUMBER";}
    else{
     bool is_prime = true;
     for(int i=2;i<a;i++){
        if(a%i==0){
            is_prime = false;
            break;}
        }
    if (is_prime){
        cout<<"PRIME NUMBER";
    }else{
        cout<<"COMPOSITE";
    }}
}
int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;
    prime(n);
}
//TIME COMPLEXITY: id O(n) where n is given number


//ANSWER 2:SUM OF ALL THE ELEMENTS IN ARRAY USING DYNAMIC  MEMORY ALLOCATION
void sum_array(int n,int *A){
    int s=0;
    for(int i=0;i<n;i++){
        s+=A[i];
    }
    cout<<s;
}

int main(){
    int n;
    cout<<"ENTER THE SIZE OF ARRAY:";
    cin>>n;
    int* A= new int[n];
    cout<<"ENTER THE ARRAY ELEMENTS:";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A[i]=x;
    }
    cout<<"SUM OF THE ARRAY:";
    sum_array(n,A);
    cout<<endl;
    delete[] A;
}