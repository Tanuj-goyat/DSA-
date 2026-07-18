#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

/*
========================================================
Problem: Find Greatest Common Divisor of Array
Platform: LeetCode (1979)
========================================================

Problem Statement:
Given an integer array nums.

Find:

- The smallest element.
- The largest element.

Return the Greatest Common Divisor (GCD)
of these two values.

Example:
Input:
nums = [2,5,6,9,10]

Output:
2

========================================================
Approach Used (Linear Traversal)

Step 1:
Traverse the array once.

Step 2:
Find the minimum and maximum
elements.

Step 3:
Return:

gcd(maximum, minimum)

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int findGCD(vector<int>& nums) {

        int mini = INT_MAX;

        int maxi = INT_MIN;

        // ------------------------------
        // Find minimum and maximum
        // ------------------------------
        for (int i = 0;
             i < nums.size();
             i++) {

            mini = min(mini,
                       nums[i]);

            maxi = max(maxi,
                       nums[i]);
        }

        // ------------------------------
        // Return GCD
        // ------------------------------
        return __gcd(maxi,
                   mini);
    }
};


int main() {

    vector<int> nums =
        {2, 5, 6, 9, 10};

    Solution obj;

    int answer =
        obj.findGCD(nums);

    cout << answer << endl;

    return 0;
}