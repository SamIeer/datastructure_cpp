class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}

    string longestPalindrome(string s) {
         int n = s.length();
    int maxx = 0;
    string longsub;
    for(int len = 1; len <= n; len++) { // Length of substrings
    string sub = " ";
        for(int start = 0; start <= n - len; start++) { // Starting index of substrings
             sub = s.substr(start, len);
            if(isPalindrome(sub) && sub.length() > maxx){
                longsub = sub;
            }
        }
        

    }
    return longsub;
    }
}; 

//CODE FOR THE PALINDROME
bool isPalindrome(string s){
     int start = 0;
    int end = s.length()-1;
    bool isPalindrome = true;
    while(start < end){
        if(s[start] != s[end]){
            isPalindrome = false;
            break;
        }
        start++;
            end--;
    }
        
    return isPalindrome;
}
int main() {
    // Write C++ code here
    string s = "lammal";
    cout << isPalindrome(s);

    return 0;
}