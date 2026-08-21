/**
 * ============================================================================
 * LeetCode 523: Continuous Subarray Sum
 * ============================================================================
 *
 * Problem Statement:
 * Given an integer array `nums` and an integer `k`, return `true` if `nums` has
 * a continuous subarray of size at least two whose elements sum up to a multiple
 * of `k`, or `false` otherwise.
 *
 * Approach Used: Prefix Sum & Hash Map (Modulo Arithmetic)
 * 1. The core mathematical concept here is:
 *    If (prefix_sum[j] - prefix_sum[i]) % k == 0, then
 *    prefix_sum[j] % k == prefix_sum[i] % k.
 * 2. We maintain a running sum of the array elements.
 * 3. At each step, we calculate the remainder of the running sum divided by k.
 * 4. We use an unordered_map `m` to store the *first time* we see a specific
 *    remainder, along with its index.
 * 5. We initialize the map with `m[0] = -1` to handle the edge case where a
 *    valid subarray starts from the very first element (index 0).
 * 6. If we encounter a remainder we have seen before, we check the distance
 *    between the current index `i` and the stored index. If the distance is
 *    >= 2, we found a valid subarray and return true.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We traverse the array exactly once. Hash map
 *   insertions and lookups take O(1) time on average.
 * - Space Complexity: O(min(N, K)) -> The hash map stores at most N distinct
 *   remainders, but since remainders are modulo k, it stores at most K items.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Map to store (remainder -> first index where this remainder occurred)
        unordered_map<int, int> m;

        // Handle the case where the valid subarray starts at index 0
        m[0] = -1;

        int sum = 0; // Running prefix sum

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            // Calculate the remainder of the current sum
            int suji = sum % k;

            // If the remainder has been seen before
            if (m.find(suji) != m.end())
            {
                // Check if the subarray length is at least 2
                if (i - m[suji] >= 2)
                {
                    return true;
                }
            }
            // If it's a new remainder, store it with its index.
            // Note: We use an 'else' block because we only want to store the
            // *first* occurrence of a remainder to maximize subarray length.
            else
            {
                m[suji] = i;
            }
        }

        // If we finish the loop without finding a valid subarray
        return false;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    // The subarray [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
    cout << "Array: [23, 2, 4, 6, 7], k = 6" << endl;
    cout << "Result: " << (solution.checkSubarraySum(nums1, k1) ? "true" : "false") << endl;

    cout << "-----------------------------------" << endl;

    // Test Case 2
    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;
    // The subarray [23, 2, 6, 4, 7] has sum 42, which is a multiple of 6 (7 * 6).
    cout << "Array: [23, 2, 6, 4, 7], k = 6" << endl;
    cout << "Result: " << (solution.checkSubarraySum(nums2, k2) ? "true" : "false") << endl;

    cout << "-----------------------------------" << endl;

    // Test Case 3
    vector<int> nums3 = {23, 2, 6, 4, 7};
    int k3 = 13;
    // No subarray sum is a multiple of 13.
    cout << "Array: [23, 2, 6, 4, 7], k = 13" << endl;
    cout << "Result: " << (solution.checkSubarraySum(nums3, k3) ? "true" : "false") << endl;

    return 0;
}