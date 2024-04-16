#include <iostream>
using namespace std;

// int partition(int a[], int beg , int end){
//     int pivot = a[beg];
//     int left = beg;
//     int right = end;
//     while(left < right){
//         while(a[left] <= pivot){
//             left ++;
//         }
//         while(a[right] > pivot){
//             right--;
//         }
//         if(left < right){
//             swap(a[left] , a[right]);
//         }
//     }
//      swap(a[beg] , a[right]);
//      return right;
// }

// void Quick_sort(int a[], int beg , int end){
//     if(beg < end){
//         int pivot = partition(a , beg , end);
//         Quick_sort(a, beg, pivot-1);
//         Quick_sort(a, pivot+1, end);
//     }
// }

// int main(){
//     int A[] = {23,12,4,21,5,11,5};
//     cout <<"Array :"<<endl;
//     int n = sizeof(A)/sizeof(A[0]);
//     Quick_sort(A,0,n-1);
//     cout<<"sorted Array:";
//     for(int i=0;i<n;i++){
//         cout<<A[i]<<" ";
//     }
//     return 0;
// }

//ANSWER 2 :
int merge(int a[],int beg,int mid,int end){
    int i = beg;
    int j = end;
    int k = beg;
    int b[end + 1 - beg];
    while(i<=mid && j<=end){
        if(a[i]<=a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= end){
            b[k] = a[j];
            j++; k++;
        }
    }
    else{
        while(i <= mid){
            b[k] = a[i];
            i++; k++;
        }
    }
    for (int x = beg; x <= end; x++) {
        a[x] = b[x];
    }
    return 0;
}
void merge_sort(int a[], int beg , int end){
    if(beg < end){
       int mid = (beg + end)/2;
       merge_sort(a, beg, end);
       merge_sort(a, beg+1 , end);
       merge(a,beg,mid,end);
    }
}

int main() {
    int arr[] = {5, 27, 3, 22, 45, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}