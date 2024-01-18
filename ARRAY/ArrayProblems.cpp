#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    for(int i =0 ; i<arr.length; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void Merge_Arr(struct Array A,struct Array B){
        int n= B.length ,m=A.length ,i=0,j=0,k=0;
        int C[20];
        while( i<m &&  j<n){
            if(A.A[i]<B.A[j]){
                C[k++]=A.A[i++];
            }
            else{
                C[k++]=B.A[j++];
            }
        }
        //FOR REMAINING ELEMENTS
        for(i ; i<m;i++)
            C[k++]=A.A[i];

        for(j ; j<n ; j++)
            C[k++]=B.A[j];
       //DISPLAYING THE MERGED ARRAY
       for (int l = 0; l < m+n; l++)
       {
        cout<<C[l]<<" ";
       }     
}

int main(){
    struct Array A = {{1,3,5,23,67,56,87},10,7};
    struct Array B = {{2,4,6,7,69,70,89},10,7};
    Merge_Arr(A,B);
    return 0;
}