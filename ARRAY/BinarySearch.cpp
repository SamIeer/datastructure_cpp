#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

int Binary_Search(struct Array arr,int key){
    int l, mid , h;
    l=0;
    h=arr.length -1;
    while (l<=h){
        mid = (l+h)/2; 
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else{
            l= mid +1;
        }
    }
    return -1;
}

int main(){
    struct Array A = {{12,43,65,78,90,32,11,765},10,8};
    int x;
    cout<<"enter the number :";
    cin>>x;
    cout<<"the index of the element is :"<<Binary_Search(A,x);
    return 0;
}