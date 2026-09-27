/**
 * ============================================================================
 * LeetCode 435: Non-overlapping Intervals
 * ============================================================================
 *
 * Problem Statement:
 * Given an array of intervals where intervals[i] = [start_i, end_i], return
 * the minimum number of intervals you need to remove to make the rest of
 * the intervals non-overlapping.
 *
 * Approach Used: Greedy Algorithm + Sorting
 * 1. Step 1 (Sort): Sort the intervals. By default, this sorts them in ascending
 *    order based on their start times.
 * 2. Step 2 (Initialize): Track the `end` time of the first interval.
 * 3. Step 3 (Iterate & Compare): Iterate from the second interval onwards.
 *    - If `currStart < end`, an OVERLAP is detected. We must remove one.
 *      Greedy Choice: To minimize future overlaps, we want the retained interval
 *      to end as early as possible. Thus, we update our tracked `end` to be the
 *      minimum of the current and previous end times (`min(currEnd, end)`). We
 *      increment our removal count.
 *    - If `currStart >= end`, there is NO overlap. We safely keep the current
 *      interval and update our tracked `end` to be `currEnd`.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> The bottleneck is sorting the array. The
 *   subsequent loop processes the intervals in a single O(N) pass.
 * - Space Complexity: O(1) auxiliary space -> Only primitive integer variables
 *   are used (ignoring the O(log N) stack space used by the sorting algorithm).
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort() and min()

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        // Edge case for empty or single interval
        if (n <= 1)
            return 0;

        // Sort by start times
        sort(intervals.begin(), intervals.end());

        // Track the end time of the most recently "kept" interval
        int end = intervals[0][1];
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            // Overlap detected!
            if (currStart < end)
            {
                count++;

                // Greedy move: Keep the interval that ends earlier to leave
                // maximum space for future intervals
                end = min(currEnd, end);
            }
            // No overlap, safely transition to the next interval
            else
            {
                end = currEnd;
            }
        }

        return count;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard overlapping intervals
    // Intervals: [[1,2], [2,3], [3,4], [1,3]]
    // The interval [1,3] overlaps with both [1,2] and [2,3].
    // Removing [1,3] leaves the rest non-overlapping.
    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Test Case 1:" << endl;
    cout << "Input: [[1,2], [2,3], [3,4], [1,3]]" << endl;
    cout << "Minimum Removals: " << solution.eraseOverlapIntervals(intervals1) << endl;
    // Expected: 1

    cout << "-----------------------------------" << endl;

    // Test Case 2: All intervals overlap
    // Intervals: [[1,2], [1,2], [1,2]]
    // Must remove 2 of them to leave a single valid interval.
    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << "Test Case 2:" << endl;
    cout << "Input: [[1,2], [1,2], [1,2]]" << endl;
    cout << "Minimum Removals: " << solution.eraseOverlapIntervals(intervals2) << endl;
    // Expected: 2

    cout << "-----------------------------------" << endl;

    // Test Case 3: No overlapping intervals
    // Intervals: [[1,2], [2,3]]
    vector<vector<int>> intervals3 = {{1, 2}, {2, 3}};
    cout << "Test Case 3:" << endl;
    cout << "Input: [[1,2], [2,3]]" << endl;
    cout << "Minimum Removals: " << solution.eraseOverlapIntervals(intervals3) << endl;
    // Expected: 0

    return 0;
}