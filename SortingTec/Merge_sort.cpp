#include <iostream>
using namespace std;

void merge(int a[],int p,int q,int r){
    int b[5];
    int i,j,k;
    k = 0;
    i = p;
    j = q+1;
    while(i<=q && j<=r){
        if(a[i] < a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }
    while(i<=q){
        b[k++] = a[i++];
    }
    while(j<=r){
        b[k++] = a[i++];
    }
    for(i=r; i>=p; i--){
        a[i] = b[--k];
    }
}
void merge_sort(int a[], int p, int r){
    int q;
    if(p<r){
        q = (p+r)/2;
        merge_sort(a, p ,q);
        merge_sort(a, q+1, r);
        merge(a,p,q,r);
    }
}

int main(){
    int arr[5] = {34,2,11,5,1};
    merge_sort(arr,0,4);
    cout<<"sorted array:";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}