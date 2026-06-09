#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================================================
Problem: Maximum Total Subarray Value
Platform: LeetCode (3689)
========================================================

Problem Statement:
Given an integer array nums and an integer k,

Find:
(maximum element - minimum element)

and return:

k * (maximum element - minimum element)

Example:
Input:
nums = [1,5,2,8]
k = 3

Output:
21

Explanation:
max = 8
min = 1

difference = 7

answer = 3 * 7 = 21

========================================================
Approach Used (Single Traversal):

Step 1:
Find minimum element

Step 2:
Find maximum element

Step 3:
Compute difference

Step 4:
Multiply by k

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    long long maxTotalValue(vector<int>& nums,
                            int k) {

        // Minimum element
        int minimum = INT_MAX;

        // Maximum element
        int maximum = INT_MIN;

        // ------------------------------
        // Find min and max
        // ------------------------------
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] < minimum)
                minimum = nums[i];

            if (nums[i] > maximum)
                maximum = nums[i];
        }

        // Difference
        long long diff =
            (long long)maximum - minimum;

        // Final answer
        return diff * k;
    }
};


int main() {

    vector<int> nums = {1,5,2,8};

    int k = 3;

    Solution obj;

    long long result =
        obj.maxTotalValue(nums, k);

    cout << "Maximum Total Value: "
         << result << endl;

    return 0;
}