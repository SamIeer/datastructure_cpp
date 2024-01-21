#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int length;
    int size;
};

void Display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a,int *b){
    int temp = *a;
    *a= *b;
    *b=temp;
}

void revere(struct Array *arr){
    int *B; int i,j;
    B=(int *)malloc(arr->length*sizeof(int));

    for(i=arr->length-1,j=0;i>=0;i--,j++)
         B[j]=arr->A[i];
       for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}

int main(){
    struct Array ar = {{23,45,2,234,56},10,5};
    revere(&ar);
    Display(ar);
    return 0;
}