//  Two Sum
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace  std;

vector<int> twoSum(vector<int>& nums, int target) {
         vector<int> num;
         int n = sizeof(nums)/sizeof(nums[0]);
          int k=0;
         for(int i=0 ; i<n ; i++){
            for(int j =1 ; j<n ; j++){
                 if(nums[i]+nums[j]==target){
                     cout<<i<<","<<j<<endl;
                 }
            }
         }
    }

int main(){
    vector<int> nums = {2,7,4,5};
    int target = 6;
    twoSum(nums, target);
    return 0;
}

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                return result; // Return indices of the two numbers
            }
        }
    }
    // If no such pair found, you may return an empty vector or throw an exception
    return result;
}
};



//optimal solution
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
    map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = target - nums[i];
            if(m.find(num) != m.end()){
                  return {m[num],i};
            }
            m[nums[i]] = i;
        }
        return {-1,-1};
     }
};