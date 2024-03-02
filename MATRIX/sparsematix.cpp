#include <iostream>
using namespace std;

int Non_zero(int m,int n,int **A){
    int count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n;  j++){
            if(A[i][j] != 0){
                count++;
            }
        }
    }
    return count;
    }

void sparse_mtx(int **A,int n){
  int B[3][n]= {0};
  int k=0;
  for(int i=0; i<3; i++){
     for(int j=0; j<n; j++){
     if(A[i][j] != 0 && A[i][j] != -1){
        B[0][k] = i;
        B[1][k] = j;
        B[2][k] = A[i][j];
        k++;
       cout<<"row:"<<i<<" "<<"colum:"<<j<<" "<<A[i][j]<<endl;
    }
     }
  }
  cout<<"sparse Matrix is:"<<'\n';
  for(int i=0; i<3; i++){
    for(int j=0; j<n; j++){
        cout<<B[i][j]<<" ";
    }
    cout<<endl;
  }
}



int main(){
int A[3][3] = {
        {0,0,3},
        {0,4,6},
        {7,0,0}
    };
    int rows = 3 ; int colms = 3;
    int **mat = new int*[rows];
    for(int i = 0;i<rows;++i){
        mat[i] = new int[colms];
        for(int j=0; j<colms; ++j){
            mat[i][j] = A[i][j];
        }
}
 int n = Non_zero(rows,colms,mat);
 sparse_mtx(mat,n);
}