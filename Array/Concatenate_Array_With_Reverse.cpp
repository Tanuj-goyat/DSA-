#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Concatenate Array With Reverse
Platform: LeetCode (3925)
========================================================

Problem Statement:
Given an array nums,
create a new array such that:

- First half contains original array
- Second half contains reverse of original array

Example:
Input:
[1,2,3]

Output:
[1,2,3,3,2,1]

========================================================
Approach Used (Two Pointer Filling):

Step 1: Create answer array of size 2*n

Step 2:
        - Fill front using original order
        - Fill back using reverse placement

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    vector<int> concatWithReverse(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(2 * n, 0);

        int j = 2 * n - 1;

        // ------------------------------
        // Fill original + reverse
        // ------------------------------
        for (int i = 0; i < n; i++) {

            // Original order
            ans[i] = nums[i];

            // Reverse order
            ans[j] = nums[i];

            j--;
        }

        return ans;
    }
};


int main() {

    vector<int> nums = {1,2,3};

    Solution obj;

    vector<int> result =
        obj.concatWithReverse(nums);

    cout << "Result Array:\n";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}