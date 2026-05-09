#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================================================
Problem: Minimum Size Subarray Sum
Platform: LeetCode 209
========================================================

Problem Statement:
Given an array of positive integers nums
and a positive integer target,

return the minimal length of a subarray
whose sum is greater than or equal to target.

If no such subarray exists, return 0.

Example:
Input:
target = 7
nums = [2,3,1,2,4,3]

Output:
2

Explanation:
Subarray [4,3] has minimum length 2.

========================================================
Approach Used (Sliding Window):

Step 1: Expand window using j

Step 2: Keep adding elements until
        sum >= target

Step 3: Shrink window from left (i)
        while condition is satisfied

Step 4: Track minimum length

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        int sum = 0;

        int length = INT_MAX;

        // ------------------------------
        // Sliding Window
        // ------------------------------
        while (j < n) {

            // Expand window
            sum += nums[j];

            // ------------------------------
            // Shrink while valid
            // ------------------------------
            while (sum >= target) {

                length = min(length, j - i + 1);

                sum -= nums[i];
                i++;
            }

            j++;
        }

        // No valid subarray found
        if (length == INT_MAX)
            return 0;

        return length;
    }
};


int main() {

    int target = 7;

    vector<int> nums = {2,3,1,2,4,3};

    Solution obj;

    int result = obj.minSubArrayLen(target, nums);

    cout << "Minimum Length: " << result << endl;

    return 0;
}