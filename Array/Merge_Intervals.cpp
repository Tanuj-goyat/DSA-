/**
 * ============================================================================
 * GFG: Merge Intervals
 * ============================================================================
 *
 * Problem Statement:
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 *
 * Approach Used: Sorting + Greedy Merge
 * 1. Step 1 (Sort): Sort the intervals based on their start values. This ensures
 *    that if two intervals overlap, they will be adjacent in the sorted array.
 * 2. Step 2 (Iterate): Loop through the sorted intervals.
 * 3. Base Case: If the `result` list is empty, push the first interval into it.
 * 4. Merge Check: For subsequent intervals, compare the current interval's `start`
 *    with the `end` of the last interval stored in `result` (result.back()[1]).
 *    - If `start <= result.back()[1]`, they overlap! We update the `end` of our
 *      merged interval to be the maximum of both ends.
 *    - If they do not overlap, we simply push the current interval into `result`
 *      as a new standalone interval.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> Sorting the array takes O(N log N) time. The
 *   single linear pass to merge them takes O(N) time.
 * - Space Complexity: O(N) -> In the worst case (no overlapping intervals), the
 *   result array will store all N intervals.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort() and max()

using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        // Sort the intervals based on their starting points
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;

        for (int i = 0; i < arr.size(); i++)
        {
            int start = arr[i][0];
            int end = arr[i][1];

            // If it's the very first interval, add it directly
            if (result.empty())
            {
                result.push_back({start, end});
            }
            else if (!result.empty())
            {
                // If the current interval overlaps with the last merged interval
                if (start <= result.back()[1])
                {
                    // Update the end to encompass both intervals
                    result.back()[1] = max(end, result.back()[1]);
                }
                else
                {
                    // No overlap, so start a new merged interval
                    result.push_back({start, end});
                }
            }
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

    // Test Case 1: Standard overlapping intervals
    // Input: [[1,3],[2,6],[8,10],[15,18]]
    // The intervals [1,3] and [2,6] overlap, merging into [1,6].
    vector<vector<int>> arr1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    cout << "Test Case 1:" << endl;
    cout << "Input:  [[1,3], [2,6], [8,10], [15,18]]" << endl;
    vector<vector<int>> result1 = solution.mergeOverlap(arr1);

    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); ++i)
    {
        cout << "[" << result1[i][0] << "," << result1[i][1] << "]" << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    // Expected: [[1,6], [8,10], [15,18]]

    cout << "-----------------------------------" << endl;

    // Test Case 2: Intervals completely subsume one another
    // Input: [[1,4],[4,5]]
    // The intervals share the boundary 4, so they merge into [1,5].
    vector<vector<int>> arr2 = {{1, 4}, {4, 5}};

    cout << "Test Case 2:" << endl;
    cout << "Input:  [[1,4], [4,5]]" << endl;
    vector<vector<int>> result2 = solution.mergeOverlap(arr2);

    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); ++i)
    {
        cout << "[" << result2[i][0] << "," << result2[i][1] << "]" << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    // Expected: [[1,5]]

    return 0;
}