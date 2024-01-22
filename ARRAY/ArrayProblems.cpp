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

//Function for merging two array
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


//Function to find missing a single missing element in the ARray
//DIFF BETWEEN THE NUMBER AN ITS INDEX SHOULD BE CONSTANT;
int single_missing(struct Array arr){
       int Diff = arr.A[0] - 0;
       for(int i=0; i<arr.length ; i++){
         if(arr.A[i]-i != Diff){
            return i + Diff;
         }
       }
}


//Function to find multiple missing element in the Array
//UPDATE THE DIFFERENCE WHEN MISSING ELEMENT IS REACHED
void Multiple_missing(struct Array arr){
    int diff = arr.A[0] - 0;
    for(int i=0 ; i<arr.length ; i++){
        while(arr.A[i]-i > diff){
            cout<< "at index :"<< i << " is " << i + diff << "\n" ;
            diff++;}
    }
}


//FINDING DUPLUCATE ELEMENT IN THE SORTEDD ARRAY
void duplicate_S(struct Array arr){
    int last_duplicate = 0;
    for(int i=0 ; i<arr.length ; i++){
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != last_duplicate){
               cout<<"The duplicate elements are:"<<arr.A[i]<<"\n";
               last_duplicate = arr.A[i];}
    }
}


 //FINDING DUPLICATE ELEMENTS IN NSORTED ARRAY
void duplicate_US(struct Array arr){
    for(int i=0 ; i<arr.length ; i++){
         int count = 1;
         if(arr.A[i] != -1){
            for( int j =i+1; j <arr.length ; j++){
                 if(arr.A[i] == arr.A[j]){
                    count ++;
                    arr.A[j] = -1;
                 }
            }
            if(count > 1){
                    cout <<"The duplicate elements are :"  <<arr.A[i] << "\n";
                 }
         }
    }
 }

int main(){
    struct Array A = {{1,3,4,4,5,6,7,8,9,9},10,10};
    struct Array B = {{2,2,6,69,69,70,89},10,7};
    cout<< "\n The Merged Array : \n";
    Merge_Arr(A,B); cout<<endl;

    cout << "\n The single missing elemnt is :"<< single_missing(A);

    cout << "\n The Multple missing elements are \n";
    Multiple_missing(A);

    cout<< "\n duplicate elements in sorted Array: \n";
    duplicate_S(A);

    cout<< "\n duplicate elements in Unsorted Array: \n";
    duplicate_US(B);

    return 0;
}