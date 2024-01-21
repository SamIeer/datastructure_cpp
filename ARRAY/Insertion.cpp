#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    cout<<"the array elements are :";
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
}

void append(struct Array *arr,int x){
    if(arr->length < arr->size ){
        arr-> A[arr->length] = x;
        arr->length++;
    }
}

void insert(struct Array *arr,int index,int x){
    if(index>=0 && index<arr->length){
        for(int i =arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int main(){
    struct Array arr1 = {{1,2,4,5,6},10,5};
    append(&arr1,20);
    insert(&arr1,3,30);
    Display(arr1);
    return 0;
}