#include <iostream>

//Brute
//  iterate through all the elements and get the sub array of all elements then take the sum,and using max 
//  get the maximaum sub array sum 
//thaking the sum of all subaarry then finding the max amoung them
//iterate the array three times 
// t -> O(n^3)  s -> O(1)

//better
//iterate the array two times 
//for the first iteration we take the sum , and then second iteration keep udating it by adding cureent to previos
//then using max get the maximum subaarry
//// t -> O(n^2)  s -> O(1)

//OPTIMAL;
// use kadane's algo;
// fir take a sum and max variable
// then iterate trough the array
//updating the sum and assingning the maximum sum to max variable 
// if the sum is negative we take the sum as zero;
//// t -> O(n)  s -> O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, maxi = LONG_MIN;
        for(int i=0 ; i<n ; i++){
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};

// Maximum Subarray