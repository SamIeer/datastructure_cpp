#include <iostream>
using namespace std;

int partition(int a[], int beg , int end){
    int pivot = a[beg];
    int left = beg;
    int right = end;
    while(left < right){
        while(a[left] <= pivot){
            left ++;
        }
        while(a[right] > pivot){
            right--;
        }
        if(left < right){
            swap(a[left] , a[right]);
        }
    }
     swap(a[beg] , a[right]);
     return right;
}

void Quick_sort(int a[], int beg , int end){
    if(beg < end){
        int pivot = partition(a , beg , end);
        Quick_sort(a, beg, pivot-1);
        Quick_sort(a, pivot+1, end);
    }
}

int main(){
    int A[] = {23,12,4,21,5,11,5};
    cout <<"Array :"<<endl;
    int n = sizeof(A)/sizeof(A[0]);
    Quick_sort(A,0,n-1);
    cout<<"sorted Array:";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}