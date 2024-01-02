#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

int linear_search(struct Array *arr,int key){
    for(int i=0;i<arr->length;i++){
        if(key==arr->A[i])
           return i;
    }
    return -1;
}

int main(){
    struct Array A = {{23,76,43,23,53,13,532,52,12},10,9};
    int x;
    cout<<"enter the number :";
    cin>>x;
    cout<<"Element found at index:"<<linear_search(&A,x);
    return 0;
}