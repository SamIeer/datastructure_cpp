#include <iostream>
using namespace std;

int indexofminimum(int arr[],int s,int n){
    int minValue = arr[s];
    int minIndex = s;
    for(int i = minIndex + 1;i< n; i++){
        if(arr[i] < minValue){
            minIndex = i;
            minValue = arr[i];
        }
    }
    return minIndex;
}

void Selection_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int index = indexofminimum(arr,i,n);
        int temp;
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    cout <<"Sorted Elements : ";
    for(int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
}

int main(){
    int A[] = {23,45,21,9,11,4};
    int n = sizeof(A)/sizeof(A[0]);
    Selection_sort(A,n);
}