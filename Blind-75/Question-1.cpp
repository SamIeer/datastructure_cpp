// Merge Strings Alternately
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void merge_string(string str1, string str2){
    int n = strlen(str1);
    int m = strlen(str2);
    string str3[n+m+1]; //+1 for null termenator
    int i=0 ,j=0,k=0;
    while( i<n && j<m ){
        if(k%2==0){
            str3[k] = str1[i];
            i++;
        }
        else{
            str3[k] = str2[j];
            j++;
        }
        k++;
    }
    while(i < n){
        str3[k]=str1[i];
        i++;
        k++;
    }
    while(j < m){
        str3[k] = str2[j];
        j++;
        k++;
    }

    str3[k] = '\0'; // Null terminator

    std::cout << "merged string: " << str3 <<endl;
}

int main(){
    string str1 = "abcjk";
    string str2 = "pqr";
    merge_string(str1,str2);
    return 0;
}


//optimized solution 
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
    int m = word2.size();
    string str = ""; 
    int i=0 ,j=0;
    while( i< n && j<m ){
         str += word1[i++];
         str += word2[j++];
    }
    while(i < n){
        str += word1[i++];
    }
    while(j < m){
        str += word2[j++];
    }
    return  str;
    }
};