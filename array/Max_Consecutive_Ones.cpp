#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem Name: Max Consecutive Ones
Platform: LeetCode
Problem Number: 485
========================================================

Problem Statement:
Given a binary array nums, return the maximum number
of consecutive 1's in the array.

Example:
Input:  [1,1,0,1,1,1]
Output: 3

Explanation:
The first two digits or the last three digits are
consecutive 1s. The maximum number is 3.

========================================================
Approach Used

We scan the array and whenever we find a 1,
we start checking how long the consecutive
sequence of 1s continues.

Two pointers are used:

i → start of the sequence
j → moves forward until a 0 appears

Length of sequence = j - i

We keep updating the maximum length.

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int i = 0;        // start pointer
        int j = 0;        // end pointer
        int count = 0;    // not really needed but kept as in original code
        int ans = 0;      // stores maximum consecutive ones

        while (i < nums.size() && j < nums.size()) {

            // If a sequence of 1s starts
            if (nums[i] == 1) {

                j = i + 1;
                count = 0;

                // Move j until a zero is found
                while (j < nums.size() && nums[j] != 0) {
                    j++;
                }

                // Update maximum length
                ans = max(ans, j - i);
            }

            // Move to next position
            i++;
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {1,1,0,1,1,1};

    Solution obj;

    int result = obj.findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive ones: " << result;

    return 0;
}