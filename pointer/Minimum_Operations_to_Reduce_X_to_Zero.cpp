/**
 * ============================================================================
 * LeetCode 1658: Minimum Operations to Reduce X to Zero
 * ============================================================================
 *
 * Problem Statement:
 * You are given an integer array `nums` and an integer `x`. In one operation,
 * you can either remove the leftmost or the rightmost element from the array
 * and subtract its value from `x`.
 * Return the minimum number of operations to reduce `x` to exactly 0 if it is
 * possible, otherwise, return -1.
 *
 * Approach Used: Inverse Target + Sliding Window
 * 1. Step 1 (Invert the Target): Instead of finding elements on the edges that
 *    sum to `x`, we find the longest contiguous subarray in the middle that
 *    sums to `k = total_sum - x`.
 * 2. Step 2 (Edge Case Check): If the total sum is less than `x`, `k` will be
 *    negative. Since all numbers are positive, the sliding window will naturally
 *    fail to find a match and return -1.
 * 3. Step 3 (Sliding Window): Use two pointers (`i` and `j`) to maintain a
 *    window with a running sum `s2`.
 * 4. Expand the window by adding `nums[j]` to `s2`.
 * 5. If `s2` exceeds our target `k`, shrink the window from the left by
 *    subtracting `nums[i]` and incrementing `i` until `s2 <= k`.
 * 6. If `s2 == k`, we record the maximum length of this window.
 * 7. Finally, subtract this maximum length from the total array length `n`
 *    to get the minimum number of edge operations.
 *
 * Complexity:
 * - Time Complexity: O(N) -> The right pointer `j` iterates through the array
 *   once. The left pointer `i` also traverses the array at most once.
 * - Space Complexity: O(1) -> Only primitive integer variables are used.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <numeric>   // Required for accumulate (if used)
#include <algorithm> // Required for max()

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = 0;

        // Calculate the total sum of the array
        for (int x : nums)
        {
            sum += x;
        }

        int i = 0;
        int j = 0;

        // k is the target sum for the middle subarray
        int k = sum - x;
        int s2 = 0;
        int len = -1;

        // Sliding window to find the longest subarray summing to exactly 'k'
        for (int j = 0; j < n; j++)
        {
            // Expand the window by including nums[j]
            s2 += nums[j];

            // If the window sum is too large, shrink it from the left
            while (s2 > k && i <= j)
            {
                s2 -= nums[i];
                i++;
            }

            // If we found a valid subarray, update the maximum length
            if (s2 == k)
            {
                len = max(len, j - i + 1);
            }
        }

        // If len is still -1, it means no valid subarray was found
        if (len == -1)
            return -1;

        // Minimum operations = total elements - maximum elements left in the middle
        return n - len;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard case
    // Array: [1, 1, 4, 2, 3], x = 5
    // Remove 2 from the right and 3 from the right (Operations: 2)
    vector<int> nums1 = {1, 1, 4, 2, 3};
    int x1 = 5;
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [1, 1, 4, 2, 3], x = 5" << endl;
    cout << "Minimum Operations: " << solution.minOperations(nums1, x1) << endl;
    // Expected: 2

    cout << "-----------------------------------" << endl;

    // Test Case 2: Impossible case
    // Array: [5, 6, 7, 8, 9], x = 4
    // Cannot reach exactly 4.
    vector<int> nums2 = {5, 6, 7, 8, 9};
    int x2 = 4;
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [5, 6, 7, 8, 9], x = 4" << endl;
    cout << "Minimum Operations: " << solution.minOperations(nums2, x2) << endl;
    // Expected: -1

    cout << "-----------------------------------" << endl;

    // Test Case 3: Need to remove all elements
    // Array: [3, 2, 20, 1, 1, 3], x = 10
    // Remove 3, 2 from left and 1, 1, 3 from right. Total operations: 5
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    int x3 = 10;
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [3, 2, 20, 1, 1, 3], x = 10" << endl;
    cout << "Minimum Operations: " << solution.minOperations(nums3, x3) << endl;
    // Expected: 5

    return 0;
}