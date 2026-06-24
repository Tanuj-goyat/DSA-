#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Valid Subarray with matching Sum Digits
Platform: LeetCode 3969
========================================================

Problem Statement:
Given:

- An integer array nums
- An integer x

A subarray is considered valid if:

1. The first digit of its sum is x
2. The last digit of its sum is x

Return the total number of valid
subarrays.

Example:
Input:
nums = [1, 2, 7]
x = 1

Subarray sums:
[1]     = 1
[1,2]   = 3
[1,2,7] = 10
[2]     = 2
[2,7]   = 9
[7]     = 7

Valid sums:
1

Output:
1

========================================================
Approach Used (Brute Force)

Step 1:
Generate every possible subarray.

Step 2:
Maintain the running sum.

Step 3:
Check whether:
- First digit of sum = x
- Last digit of sum = x

Step 4:
Count all valid subarrays.

Time Complexity: O(n²)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Check whether first and last
    // digit of n are equal to x
    // ------------------------------
    bool isValid(long long n,
                 int x) {

        // Check last digit
        if (n % 10 != x)
            return false;

        // Find first digit
        while (n >= 10) {

            n = n / 10;
        }

        // Check first digit
        if (n % 10 != x)
            return false;

        return true;
    }

    int countValidSubarrays(
        vector<int>& nums,
        int x) {

        int count = 0;

        // ------------------------------
        // Generate all subarrays
        // ------------------------------
        for (int i = 0;
             i < nums.size();
             i++) {

            long long sum = 0;

            for (int j = i;
                 j < nums.size();
                 j++) {

                sum += nums[j];

                if (isValid(sum, x))
                    count++;
            }
        }

        return count;
    }
};


int main() {

    vector<int> nums =
        {1, 2, 7};

    int x = 1;

    Solution obj;

    int answer =
        obj.countValidSubarrays(nums, x);

    cout << answer << endl;

    return 0;
}