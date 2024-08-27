#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits> // For numeric limits

using namespace std;

vector<int> findTwoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;  // To store the difference and corresponding index
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    
    // Backup if no solution is found, though problem guarantees one exists.
    return {-1, -1};
}

int main() {
    int n, target;
    vector<int> nums;
    
    // Input validation for the number of elements in the array
    do {
        cout << "Enter the number of elements in the array (2 <= nums.length <= 104): ";
        cin >> n;
        if (n < 2 || n > 104) {
            cout << "Invalid input. Please enter a value between 2 and 104." << endl;
        }
    } while (n < 2 || n > 104);
    
    // Input validation for the elements in the array
    cout << "Enter the elements of the array (-10^9 <= nums[i] <= 10^9):" << endl;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        while (num < -1000000000 || num > 1000000000) {
            cout << "Invalid input. Please enter a value between -10^9 and 10^9: ";
            cin >> num;
        }
        nums.push_back(num);
    }
    
    // Input validation for the target value
    cout << "Enter the target value (-10^9 <= target <= 10^9): ";
    cin >> target;
    while (target < -1000000000 || target > 1000000000) {
        cout << "Invalid input. Please enter a value between -10^9 and 10^9: ";
        cin >> target;
    }
    
    vector<int> result = findTwoSum(nums, target);
    
    if (result[0] != -1) {
        cout << "Indices found: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No valid solution found." << endl; // This case won't occur given the problem constraints.
    }

    return 0;
}
