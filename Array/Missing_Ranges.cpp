/**
 * ============================================================================
 * LeetCode 4031: Missing Ranges
 * ============================================================================
 *
 * Problem Statement:
 * You are given an inclusive range [lower, upper] and an integer array `nums`.
 * Return the shortest sorted list of ranges that exactly covers all the missing
 * numbers in the range [lower, upper].
 *
 * Approach Used: One-Pass Range Tracking
 * 1. Sort the input array to ensure we process numbers in strictly ascending order.
 * 2. Use the `lower` parameter itself as a pointer to track the next expected
 *    number in our required range.
 * 3. Iterate through each number in `nums`:
 *    - Skip any number that falls completely outside the [lower, upper] bounds.
 *    - If the current number is strictly greater than our expected `lower`, it
 *      means there is a gap. We push the range {lower, num - 1} into our answer.
 *    - Update `lower` to `num + 1` so we start looking for the next number
 *      immediately after the one we just processed.
 * 4. Once the loop finishes, if our expected `lower` is still less than or
 *    equal to `upper`, it means there is one final missing block at the end.
 *    We add {lower, upper} to the result.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> Sorting the array takes O(N log N). The
 *   subsequent loop runs in O(N).
 * - Space Complexity: O(1) -> We modify the inputs and use no extra space
 *   other than the required 2D vector for the answer.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDisappearedNumbers(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();

        // Step 1: Sort the array to process missing gaps sequentially
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        // Step 2: Iterate through the sorted numbers
        for (int num : nums)
        {
            // Ignore elements outside the target interval
            if (num < lower || num > upper)
                continue;

            // If the actual number is greater than the expected 'lower', we found a gap
            if (num > lower)
            {
                ans.push_back({lower, num - 1});
            }

            // Move the expected 'lower' to the next integer after 'num'
            // (If duplicate numbers exist, this perfectly safely re-assigns lower to the same value)
            lower = num + 1;
        }

        // Step 3: Check for any remaining gap after the last element in the array
        if (upper >= lower)
        {
            ans.push_back({lower, upper});
        }

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard case with multiple missing ranges
    vector<int> nums1 = {0, 1, 3, 50, 75};
    int lower1 = 0;
    int upper1 = 99;

    // Execute the function
    vector<vector<int>> result1 = solution.findDisappearedNumbers(nums1, lower1, upper1);

    // Output the result to the console
    cout << "Array: [0, 1, 3, 50, 75], lower = 0, upper = 99" << endl;
    cout << "Missing Ranges: [" << endl;
    for (size_t i = 0; i < result1.size(); ++i)
    {
        cout << "  [" << result1[i][0] << ", " << result1[i][1] << "]";
        if (i < result1.size() - 1)
            cout << ",";
        cout << endl;
    }
    cout << "]" << endl;
    // Expected output: [[2, 2], [4, 49], [51, 74], [76, 99]]

    cout << "-----------------------------------" << endl;

    // Test Case 2: Array with duplicates
    vector<int> nums2 = {2, 2, 5};
    int lower2 = 0;
    int upper2 = 9;

    vector<vector<int>> result2 = solution.findDisappearedNumbers(nums2, lower2, upper2);

    cout << "Array: [2, 2, 5], lower = 0, upper = 9" << endl;
    cout << "Missing Ranges: [" << endl;
    for (size_t i = 0; i < result2.size(); ++i)
    {
        cout << "  [" << result2[i][0] << ", " << result2[i][1] << "]";
        if (i < result2.size() - 1)
            cout << ",";
        cout << endl;
    }
    cout << "]" << endl;
    // Expected output: [[0, 1], [3, 4], [6, 9]]

    return 0;
}