//Answer 1:
#include <iostream>
#include <unordered_set>
using namespace std;

void findPairWithSum(int arr[], int n, int targetSum) {
    unordered_set<int> hashSet;

    for (int i = 0; i < n; ++i) {
        int complement = targetSum - arr[i];
        if (hashSet.find(complement) != hashSet.end()) {
            cout << "Pair with sum " << targetSum << " found: (" << complement << ", " << arr[i] << ")" << endl;
            return;
        }
        hashSet.insert(arr[i]);
    }
    cout << "No pair with sum " << targetSum << " found." << endl;
}

int main() {
    int arr[] = {5, 27, 3, 22, 45, 90};
    int targetSum = 30;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPairWithSum(arr, n, targetSum);
    return 0;
}

//Answer2:
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findDuplicates(int arr[], int n) {
    unordered_set<int> hashSet;
    vector<int> duplicates;
    for (int i = 0; i < n; ++i) {
        if (hashSet.find(arr[i]) != hashSet.end()) {
            duplicates.push_back(arr[i]);
        } else {
            hashSet.insert(arr[i]);
        }
    }
    return duplicates;
}
int main() {
    int arr[] = {5, 27, 3, 22, 45, 90, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::vector<int> duplicates = findDuplicates(arr, n);

    if (duplicates.empty()) {
        std::cout << "No duplicates found." << std::endl;
    } else {
        std::cout << "Duplicates found: ";
        for (int i : duplicates) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
