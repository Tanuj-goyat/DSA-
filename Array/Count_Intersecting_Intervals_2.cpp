/**
 * ============================================================================
 * Problem 4057: Count Intersecting Intervals
 * ============================================================================
 *
 * Problem Statement:
 * Given a 2D array of intervals where intervals[i] = [start_i, end_i], return
 * the total number of pairs of intervals that intersect.
 *
 * Approach Used: Decoupled Sorting & Two-Pointer Sweep
 * 1. Step 1 (Memory Allocation): Pre-allocate `start` and `end` vectors of size
 *    `n` to avoid dynamic resizing overhead.
 * 2. Step 2 (Decouple): Separate all the `start` times and `end` times into
 *    the two independent arrays.
 * 3. Step 3 (Sort): Sort both arrays in ascending order.
 * 4. Step 4 (Sweep): Iterate through the sorted `start` times using index `i`.
 * 5. For each start time `start[i]`, advance pointer `j` for every `end[j]`
 *    that finishes strictly before the current interval begins (`end[j] < start[i]`).
 * 6. Add `i - j` to the running total `ans`. This mathematically represents the
 *    number of intervals that have started but not yet ended, meaning they
 *    intersect with the current interval.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> Sorting takes O(N log N). The two-pointer
 *   sweep processes each element in O(N) time.
 * - Space Complexity: O(N) -> Two vectors of size N are created.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

class Solution
{
public:
    long long countIntersectingIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        // Pre-allocate vectors to avoid dynamic resizing overhead
        vector<int> start(n), end(n);

        // Decouple the endpoints
        for (int i = 0; i < n; i++)
        {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        // Sort both arrays to simulate a chronological timeline
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        // Use long long to prevent overflow (max pairs can be ~N^2 / 2)
        long long ans = 0;
        int j = 0;

        for (int i = 0; i < n; i++)
        {

            // Advance j for all intervals that have ended strictly before start[i]
            while (j < n && end[j] < start[i])
            {
                j++;
            }

            // Add the number of currently active intervals
            ans += i - j;
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

    // Test Case 1: Standard overlaps
    // Intervals: [1,5], [2,3], [4,6]
    // Pair 1: [1,5] intersects with [2,3]
    // Pair 2: [1,5] intersects with [4,6]
    // Total intersecting pairs = 2
    vector<vector<int>> nums1 = {{1, 5}, {2, 3}, {4, 6}};
    cout << "Test Case 1:" << endl;
    cout << "Intervals: [[1,5], [2,3], [4,6]]" << endl;
    cout << "Intersecting Pairs: " << solution.countIntersectingIntervals(nums1) << endl;
    // Expected: 2

    cout << "-----------------------------------" << endl;

    // Test Case 2: Touching boundaries
    // Intervals: [1,3], [2,4], [3,5]
    // Pair 1: [1,3] and [2,4]
    // Pair 2: [1,3] and [3,5] (Touches at 3)
    // Pair 3: [2,4] and [3,5]
    // Total intersecting pairs = 3
    vector<vector<int>> nums2 = {{1, 3}, {2, 4}, {3, 5}};
    cout << "Test Case 2:" << endl;
    cout << "Intervals: [[1,3], [2,4], [3,5]]" << endl;
    cout << "Intersecting Pairs: " << solution.countIntersectingIntervals(nums2) << endl;
    // Expected: 3

    cout << "-----------------------------------" << endl;

    // Test Case 3: Completely disjoint intervals
    // Intervals: [1,2], [3,4], [5,6]
    // No intervals overlap.
    vector<vector<int>> nums3 = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Test Case 3:" << endl;
    cout << "Intervals: [[1,2], [3,4], [5,6]]" << endl;
    cout << "Intersecting Pairs: " << solution.countIntersectingIntervals(nums3) << endl;
    // Expected: 0

    return 0;
}