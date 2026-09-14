/**
 * ============================================================================
 * LeetCode 2640: Find the Score of All Prefixes of an Array
 * ============================================================================
 *
 * Problem Statement:
 * We define the conversion array `conver` of an array `arr` as follows:
 * `conver[i] = arr[i] + max(arr[0..i])` where max(arr[0..i]) is the maximum
 * value of `arr` from index 0 to i.
 * We also define the score of an array `arr` as the sum of the values of
 * the conversion array `conver`.
 * Given a 0-indexed integer array `nums`, return an array `ans` of the same
 * length where `ans[i]` is the score of the prefix `nums[0..i]`.
 *
 * Approach Used: One-Pass Running Sum
 * 1. Instead of creating a separate `conver` array, we can calculate the prefix
 *    score dynamically in a single pass.
 * 2. We maintain a variable `x` to track the maximum element seen so far.
 * 3. For each element `nums[i]`, we update `x`. The current conversion value
 *    is `nums[i] + x`.
 * 4. We maintain a running total `sum` of these conversion values.
 *    `sum` inherently represents the score of the prefix up to `i`.
 * 5. We push `sum` into our `result` array at each step.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We iterate through the `nums` array exactly once.
 * - Space Complexity: O(1) auxiliary space -> Excluding the `result` array
 *   required for the output, we only use a few tracking variables.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for max()
#include <climits>   // Required for INT_MIN

using namespace std;

class Solution
{
public:
    vector<long long> findPrefixScore(vector<int> &nums)
    {
        int n = nums.size();

        // Use long long to prevent integer overflow since prefix scores can grow very large
        long long sum = 0;

        // Tracks the maximum element seen in the prefix so far
        int x = INT_MIN;

        vector<long long> result;

        for (int i = 0; i < n; i++)
        {
            // Update the maximum element found in nums[0...i]
            x = max(x, nums[i]);

            // Calculate the conversion value and add it to our running prefix score
            sum += nums[i] + x;

            // Store the score of the prefix up to index i
            result.push_back(sum);
        }

        return result;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1
    // nums = [2, 3, 7, 5, 10]
    // Max so far: [2, 3, 7, 7, 10]
    // Conversion: [4, 6, 14, 12, 20]
    // Prefix Sum: [4, 10, 24, 36, 56]
    vector<int> nums1 = {2, 3, 7, 5, 10};
    cout << "Test Case 1:" << endl;
    cout << "Input: [2, 3, 7, 5, 10]" << endl;
    vector<long long> res1 = solution.findPrefixScore(nums1);
    cout << "Output: [ ";
    for (long long val : res1)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
    // Expected: [ 4 10 24 36 56 ]

    cout << "-----------------------------------" << endl;

    // Test Case 2
    // nums = [1, 1, 2, 4, 8, 16]
    vector<int> nums2 = {1, 1, 2, 4, 8, 16};
    cout << "Test Case 2:" << endl;
    cout << "Input: [1, 1, 2, 4, 8, 16]" << endl;
    vector<long long> res2 = solution.findPrefixScore(nums2);
    cout << "Output: [ ";
    for (long long val : res2)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
    // Expected: [ 2 4 8 16 32 64 ]

    return 0;
}