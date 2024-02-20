#include <iostream>
#include <string>
using namespace std;

//Solution 1:
// int main() {
//     char A[] = "TuTDudeDsa094@gmail.com";
//     int uc =0 , lc=0 , sc=0 , nc=0;
//     for(int i = 0; A[i] != '\0'; i++) {
//         if(A[i]>=97 && A[i]<=122){
//             lc +=1;}
//         else if( A[i] >= 65 && A[i]<=90){
//               uc+=1;}
//         else if(A[i] = 48 && A[i] <=57 ){
//             nc+=1;
//         }
//         else{
//            sc+=1;
//         }
//     }
//     cout <<"nUmber of Uppercase in the string :"<<uc<<'\n';
//     cout <<"nUmber of lowercase in the string :"<<lc<<'\n';
//     cout <<"nUmber of specialcase in the string :"<<sc<<'\n';
//     cout <<"nUmber of Numericcase in the string :"<<nc<<'\n';
//     return 0;
// }

//Solution 2:
string MinMax(char A[]){
    int Min_word = INT16_MAX; int Max_word = INT16_MIN; int count = 0;
    for(int i=0; A[i]!='\0';i++){
        //for the words seprated by space
        if(A[i] != ' '){
            count ++;
        } else{
            if(count > 0){
            if(count < Min_word) Min_word  = count;
            if(count > Max_word) Max_word = count;
            count = 0;}
        }
    }
    
    //for the last word if it is not a space
        if(count > 0){
            if(count < Min_word) Min_word  = count;
            if(count > Max_word) Max_word = count;
        }
    
     return "Minimum length: " + to_string(Min_word) + ", Maximum length: " + to_string(Max_word);
}
int main(){
      char B[] = "hello my name is sameerr";
      cout<<MinMax(B);  
      return 0;
}
