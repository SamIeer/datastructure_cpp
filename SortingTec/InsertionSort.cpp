#include <iostream>
using namespace std;

void Insertion_sort(int *arr,int length){
    int i,j,key;
    for(i=1;i<length; i++){
        j = i;
        while(j>0 && arr[j-1] > arr[j]){
            key = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = key;
            j--;
        }
    }
    cout << "Sorted Array :"<<endl;
    for(i=0; i<length ; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int A[] = {34,134,1,54,3,12,0,45,65,7};
    int n = sizeof(A)/sizeof(A[0]);
    Insertion_sort(A,n);
    return 0;
}