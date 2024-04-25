#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preffix(n), suffix(n);
        vector<int>solution(n);
        preffix[0] = 1;
        suffix[n-1] = 1;
        for(int i=1 ; i<n;i++){
            preffix[i] = preffix[i-1]*nums[i-1];
        }
        for(int i = n-2; i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        for(int i =0; i<n;i++){
           solution[i] = preffix[i]*suffix[i];
        }

    return solution;
    }
};

//238. Product of Array Except Self