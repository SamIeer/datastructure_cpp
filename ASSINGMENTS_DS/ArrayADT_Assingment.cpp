#include <iostream>
using namespace std;
//ANSWER1: 
int Binary_search(int *A,int n,long key){
    int l,h,mid;
    l=0; h =n-1;
    while (l<=h)
    {
       mid=(l+h)/2;
       if(key==A[mid])
          return mid;
        else if(key < A[mid])
          h=mid-1;
        else 
         l=mid+1;
    }
    return -1;}

int main(){
    int A[] = {4,9,16,25,49,64,144,169,625};
    int n = sizeof(A)/sizeof(A[0]);
    cout << "Enter the Key"<<endl;
    long x;
    cin>>x;
    long key=x*x;
    int result = Binary_search(A,n,key);
    cout<<"Element found at Index :"<<result;
    return 0;
    }

//ANSWER 3:
void swap(int *a,int *b){    //function for swaping two number 
    int temp =*a;
    *a=*b;
    *b=temp;}
void sorted_array(int *A, int n);
void Is_sorted(int *A,int n){   //function for checking wether the array is sorted or not if not then returning the sorted array
     bool sort=true;   
     for(int i=0; i<n-1; i++){
         if(A[i]>A[i+1])
            sort=false;
     }
     if(sort){
        cout<< "THE ARRAY IS SORTED"<<endl;
     }
     else{
        cout<< "THE ARRAY IS NOT SORTED"<<endl;
        cout<<"SORTED ARRAY WILL BE: "<<endl;
        sorted_array(A,n);}
}

void sorted_array(int *A, int n){   //funtion for sorting the array
     for(int i=0; i <= n-1; i++){
         for(int j=i+1; j<n; j++){
          if(A[i]>A[j])
            swap(&A[i],&A[j]);}
     }
     for(int i=0;i<n;i++){
        cout<<A[i]<<" ";}
}
int main(){
   //  int A[] = {45,89,212,321,444};  //first input sorted array
 
   int A[] = {200,34,568,124,7893,3453}; // unsorted array

    int n = sizeof(A)/sizeof(A[0]);
    Is_sorted(A,n);
    return 0;
}