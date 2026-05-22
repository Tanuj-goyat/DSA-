#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Max Consecutive Ones III
Platform: LeetCode (1004)
========================================================

Problem Statement:
Given a binary array nums and an integer k,
return the maximum number of consecutive 1's
if you can flip at most k zeros.

Example:
Input:
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2

Output:
6

Explanation:
Flip two zeros to get:
[1,1,1,0,0,1,1,1,1,1,1]

Longest consecutive 1's = 6

========================================================
Approach Used (Sliding Window):

Step 1:
Use two pointers:
- i = window start
- j = window end

Step 2:
Count zeros inside window

Step 3:
If zero count exceeds k,
shrink window from left

Step 4:
Track maximum valid window size

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int longestOnes(vector<int>& nums,
                    int k) {

        int maxLen = 0;

        int i = 0;
        int j = 0;

        int n = nums.size();

        // Count zeros in window
        int zero = 0;

        // ------------------------------
        // Sliding window traversal
        // ------------------------------
        while (j < n) {

            // Include current element
            if (nums[j] == 0)
                zero++;

            // ------------------------------
            // Invalid window
            // ------------------------------
            if (zero > k) {

                // Remove left element
                if (nums[i] == 0)
                    zero--;

                i++;
            }

            // ------------------------------
            // Valid window
            // ------------------------------
            if (zero <= k)

                maxLen =
                    max(maxLen,
                        j - i + 1);

            j++;
        }

        return maxLen;
    }
};


int main() {

    vector<int> nums =
        {1,1,1,0,0,0,1,1,1,1,0};

    int k = 2;

    Solution obj;

    int result =
        obj.longestOnes(nums, k);

    cout << "Maximum Consecutive Ones: "
         << result << endl;

    return 0;
}