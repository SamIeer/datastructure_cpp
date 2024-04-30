#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <climits>

int maxArea(std::vector<int>& nums) {
    int maxi = INT_MIN;
    int n = nums.size() - 1; // Fix off-by-one error
    int j = 0;
    int k = n;

    while (j < k) {
        maxi = std::max(maxi, std::min(nums[j], nums[k]) * (k - j));
        if (nums[j] < nums[k]) {
            j++;
        } else {
            k--;
        }
    }

    return maxi;
}

int main() {
    std::vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Use std::vector<int>
    std::cout << "Try programiz.pro\n";
    std::cout << maxArea(a);

    return 0;
}
