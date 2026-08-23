/**
 * ============================================================================
 * LeetCode 4031: Missing Ranges
 * ============================================================================
 *
 * Problem Statement:
 * You are given an inclusive range [lower, upper] and a sorted integer array
 * `nums`. Return the shortest sorted list of ranges that exactly covers all
 * the missing numbers in the range [lower, upper].
 *
 * Approach Used: Range Tracking (One-Pass Traversal)
 * 1. We first sort the array to ensure we process numbers in ascending order.
 * 2. We maintain a variable `cur` (initialized to `lower`) to track the start
 *    of the next potential missing range.
 * 3. We iterate through each number in `nums`:
 *    - If the number is outside our target bounds [lower, upper], we skip it.
 *    - If `cur < num`, it means there is a missing gap between the expected
 *      number and the actual number. We add the range [cur, num - 1] to our result.
 *    - We then safely update `cur` to `num + 1` (using `max` to prevent moving
 *      backwards in case of duplicate elements).
 *    - If `cur` exceeds `upper`, our required range is fully covered, so we break.
 * 4. After the loop, if `cur` is still less than or equal to `upper`, it means
 *    there is a final missing range at the end. We add [cur, upper].
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> The time is dominated by the `sort()` function.
 *   (If the problem guarantees the input array is already sorted, this drops to O(N)).
 * - Space Complexity: O(1) -> Excluding the space required for the output array,
 *   we only use a few integer variables.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort() and max()

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDisappearedNumbers(vector<int> &nums, int lower, int upper)
    {
        // Sort the array to process numbers in ascending order
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        // 'cur' tracks the next expected number in the range
        int cur = lower;

        for (int num : nums)
        {

            // Ignore numbers that fall outside the required [lower, upper] boundaries
            if (num < lower || num > upper)
            {
                continue;
            }

            // If the current expected number is strictly less than the actual number,
            // we've found a missing gap. Add [cur, num - 1] to results.
            if (cur < num)
            {
                res.push_back({cur, num - 1});
            }

            // Update the next expected number to be right after the current number.
            // Using max() safely handles duplicate numbers in the array.
            cur = max(cur, num + 1);

            // Optimization: If our expected number has surpassed the upper bound,
            // we don't need to check the rest of the array.
            if (cur > upper)
            {
                break;
            }
        }

        // Handle the remaining numbers if the array ends before reaching 'upper'
        if (cur <= upper)
        {
            res.push_back({cur, upper});
        }

        return res;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard case with multiple gaps
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

    // Test Case 2: Empty array
    vector<int> nums2 = {};
    int lower2 = 1;
    int upper2 = 1;

    vector<vector<int>> result2 = solution.findDisappearedNumbers(nums2, lower2, upper2);

    cout << "Array: [], lower = 1, upper = 1" << endl;
    cout << "Missing Ranges: [" << endl;
    for (size_t i = 0; i < result2.size(); ++i)
    {
        cout << "  [" << result2[i][0] << ", " << result2[i][1] << "]";
        if (i < result2.size() - 1)
            cout << ",";
        cout << endl;
    }
    cout << "]" << endl;
    // Expected output: [[1, 1]]

    return 0;
}