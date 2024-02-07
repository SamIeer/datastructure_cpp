#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Bubble_sort(int *A, int n){
    int i,j,temp;
    for(int i=0; i<n;i++){
        for(j=0; j<n-i-1; j++){
            if(A[j]>A[j+1]){
                swap(A[j], A[j+1]);
            }
        }
    }
    cout<<"The sorted Array: ";
    for(int i=0;i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int A[] = {3,1,56,2,4,76,11};
    int n = sizeof(A)/sizeof(A[0]);
    Bubble_sort(A, n);
    return 0;
}