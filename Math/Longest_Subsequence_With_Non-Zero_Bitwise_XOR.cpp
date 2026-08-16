/**
 * ============================================================================
 * LeetCode 3702: Longest Subsequence With Non-Zero Bitwise XOR
 * ============================================================================
 *
 * Problem Statement:
 * You are given an integer array `nums`. Return the length of the longest
 * subsequence in `nums` whose bitwise XOR is non-zero. If no such subsequence
 * exists, return 0.
 *
 * Approach Used: Bit Manipulation & Logical Deduction
 * 1. Calculate the XOR sum of all elements in the array. 
 * 2. If the total XOR sum is NOT 0, the longest valid subsequence is the
 *    entire array itself (length `n`).
 * 3. If the total XOR sum IS 0, we check if there is at least one non-zero
 *    element in the array (tracked using the `flag` variable).
 * 4. If a non-zero element exists, we can simply remove it from the array.
 *    The XOR sum of the remaining `n - 1` elements will then become non-zero.
 *    Thus, the max length is `n - 1`.
 * 5. If all elements in the array are 0, it's impossible to form a non-zero
 *    XOR sum. We return 0.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We traverse the array exactly once.
 * - Space Complexity: O(1) -> Only a few scalar variables are used.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int n = nums.size();
        bool flag = false;
        int zor = 0; // Stores the cumulative XOR sum

        // Iterate through the array to calculate total XOR
        // and check for non-zero elements
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                flag = true;
            zor ^= nums[i];
        }

        // If the total XOR is not 0, the whole array is the valid subsequence
        if (zor != 0)
            return n;

        // If XOR is 0 but there is at least one non-zero element,
        // dropping one non-zero element makes the XOR non-zero
        else if (flag)
            return n - 1;

        // If all elements are 0, no valid subsequence exists
        return 0;
    }
};


int main()
{
    Solution solution;

    // Test Case 1: Total XOR is non-zero
    vector<int> nums1 = {1, 2, 3, 4};
    // XOR = 1 ^ 2 ^ 3 ^ 4 = 4 (!= 0) -> Expected: 4
    cout << "Array: [1, 2, 3, 4] -> Longest Subsequence Length: "
         << solution.longestSubsequence(nums1) << endl;

    // Test Case 2: Total XOR is 0, but has non-zero elements
    vector<int> nums2 = {1, 2, 3};
    // XOR = 1 ^ 2 ^ 3 = 0. We drop one non-zero to get XOR != 0 -> Expected: 2
    cout << "Array: [1, 2, 3] -> Longest Subsequence Length: "
         << solution.longestSubsequence(nums2) << endl;

    // Test Case 3: All elements are 0
    vector<int> nums3 = {0, 0, 0};
    // XOR = 0, no non-zero elements -> Expected: 0
    cout << "Array: [0, 0, 0] -> Longest Subsequence Length: "
         << solution.longestSubsequence(nums3) << endl;

    return 0;
}