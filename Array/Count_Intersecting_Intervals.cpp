/**
 * ============================================================================
 * Problem 4056: Count Intersecting Intervals
 * ============================================================================
 *
 * Problem Statement:
 * Given a 2D array of intervals where intervals[i] = [start_i, end_i], return
 * the total number of pairs of intervals that intersect.
 * Note: In this logic, intervals that merely touch at the boundaries
 * (e.g., [1,3] and [3,5]) are considered intersecting.
 *
 * Approach Used: Decoupled Sorting & Two-Pointer Sweep
 * 1. Step 1 (Decouple): Separate all the `start` times and `end` times into
 *    two independent arrays, `s` and `e`.
 * 2. Step 2 (Sort): Sort both arrays. Sorting them destroys the original pairing,
 *    but we only care about the *timeline* of events, not which interval owns
 *    which endpoint.
 * 3. Step 3 (Sweep): We iterate through the sorted start times using index `i`.
 * 4. For each start time `s[i]`, we use a secondary pointer `j` to check the
 *    end times. If an end time `e[j]` is strictly less than the current start
 *    time (`e[j] < s[i]`), it means that interval has completely finished, so
 *    we advance `j`.
 * 5. At any point `i`, the number of intervals that have started is `i` (since
 *    we are looking at the i-th start time). The number of intervals that have
 *    completely ended is `j`.
 * 6. Therefore, `i - j` gives us exactly the number of intervals that are
 *    currently "active" and overlapping with the new interval starting at `s[i]`.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> Sorting both the `start` and `end` arrays
 *   takes O(N log N). The two-pointer sweep processes each array at most once,
 *   taking O(N) time.
 * - Space Complexity: O(N) -> We allocate two separate arrays `s` and `e` of
 *   size N to store the endpoints.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

class Solution
{
public:
    int countIntersectingIntervals(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<int> s;
        vector<int> e;

        // Decouple the start and end times
        for (int i = 0; i < n; i++)
        {
            s.push_back(nums[i][0]);
            e.push_back(nums[i][1]);
        }

        // Sort both arrays to simulate a chronological timeline
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int j = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // Advance j for all intervals that have ended strictly before s[i]
            // Note: Use e[j] <= s[i] if touching boundaries shouldn't count as intersections
            while (j < n && e[j] < s[i])
            {
                j++;
            }

            // Add the number of currently active intervals that intersect with interval i
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