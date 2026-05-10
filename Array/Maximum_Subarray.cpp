#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================================================
Problem: Maximum Subarray
Platform: LeetCode (53)
========================================================

Problem Statement:
Given an integer array nums,
find the contiguous subarray with the largest sum
and return its sum.

Example:
Input:
[-2,1,-3,4,-1,2,1,-5,4]

Output:
6

Explanation:
Subarray [4,-1,2,1] has maximum sum = 6

========================================================
Approach Used (Kadane's Algorithm):

Key Idea:
- If current sum becomes negative,
  it can never help future subarrays.

Step 1: Maintain running sum

Step 2: Update maximum sum

Step 3: If sum < 0,
        reset sum to 0

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int maxSum = INT_MIN;
        int sum = 0;

        // ------------------------------
        // Kadane's Algorithm
        // ------------------------------
        for (int i = 0; i < n; i++) {

            // Add current element
            sum += nums[i];

            // Update answer
            maxSum = max(maxSum, sum);

            // Reset if negative
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};


int main() {

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution obj;

    int result = obj.maxSubArray(nums);

    cout << "Maximum Subarray Sum: "
         << result << endl;

    return 0;
}