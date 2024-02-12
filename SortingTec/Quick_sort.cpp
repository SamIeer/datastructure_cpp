#include <iostream>
using namespace std;

int partition(int a[],int beg,int end){
    int left,right,temp,loc,flag;
    loc = left = beg;
    right = end;
    flag = 0;
    while(flag!=1){
        while((a[loc]=a[right])&&(loc!=right)){
            right--;
            if(loc == right){
                flag = 1;
            }
            else if(a[loc]<a[right]){
                temp = a[loc];
                a[loc] = a[right];
                a[right] = temp;
                loc = right;
            }
            if(flag!=1){
                while((a[loc]=a[left])&&(loc!=left)){
                    left++;
                    if(loc == left){
                        flag = 1;
                    }else if(a[loc]<a[left]){
                        temp = a[loc];
                        a[loc] = a[left];
                        a[left] = temp;
                        loc = left;
                    }
                }
            }
        }
        return loc;
    }
}

void Quick_sort(int a[],int beg,int end){
    int loc;
    if(beg<end){
        loc = partition(a, beg,end);
        Quick_sort(a, beg,loc-1);
        Quick_sort(a,loc+1,end);
    }
    cout<<"sorted Array:";
    for(int i=0;i<end+1;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int A[] = {23,1,45,10,3,5,78,4};
    int n = sizeof(A)/sizeof(A[0]);
    Quick_sort(A,0,n-1);
    return 0;

}