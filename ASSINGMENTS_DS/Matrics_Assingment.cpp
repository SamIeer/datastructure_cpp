#include <iostream>
using namespace std;

//ANSWER ; 1
bool Is_toeplitz(int **mat, int rows , int cols){
     for(int i=1 ; i<rows ; ++i){
        for(int j=1 ; j<cols ; ++j){
            if(mat[i][j] != mat[i-1][j-1]){
                return false;
            }
        }
     }
     return true;
}
int main(){
   int A[3][4] = {
             {1,2,3,4},{5,1,2,3},{9,5,1,2}};
    int rows = 3;  int cols = 4;

    int** matrix = new int*[rows];
    for(int i = 0;i<rows;++i){
        matrix[i] = new int[cols];
        for(int j=0; j<cols; ++j){
            matrix[i][j] = A[i][j];
        }
    }
    
   if (Is_toeplitz(matrix, rows, cols)) {
        std::cout << "The matrix is a Toeplitz matrix." << std::endl;
    } else {
        std::cout << "The matrix is not a Toeplitz matrix." << std::endl;
    }
}

//ANSWER ;2
void Transpose_Matrix(int **A,int rows , int colms){
    int B[colms][rows];
    for(int i=0; i<rows ; ++i){
        for(int j=0; j<colms ; ++j){
            B[j][i] = A[i][j];
        }
    }

    cout<<"The required Transpose Matrix :"<<endl;
     for(int i=0; i<colms ; ++i){
        for(int j=0; j<rows ; ++j){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}};
    int rows = 3 ; int colms = 3;
    int **mat = new int*[rows];
    for(int i = 0;i<rows;++i){
        mat[i] = new int[colms];
        for(int j=0; j<colms; ++j){
            mat[i][j] = A[i][j];
        }
    };

    Transpose_Matrix(mat , rows , colms);
    return 0;
}