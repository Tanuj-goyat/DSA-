/**
 * ============================================================================
 * LeetCode 436: Find Right Interval
 * ============================================================================
 *
 * Problem Statement:
 * You are given an array of intervals where intervals[i] = [start_i, end_i]
 * and each start_i is unique. The "right interval" for an interval i is an
 * interval j such that start_j >= end_i and start_j is minimized.
 * Return an array of right interval indices for each interval i. If no
 * right interval exists for interval i, put -1 at index i.
 *
 * Approach Used: Hash Map + Sorting + Binary Search
 * 1. Step 1 (Map Original Indices): Since we need to return the original
 *    index of the right interval, we map every start point to its index
 *    using an `unordered_map`. (e.g., m[intervals[i][0]] = i).
 * 2. Step 2 (Extract & Sort): We extract all the start points into a separate
 *    vector `v` and sort it in ascending order.
 * 3. Step 3 (Binary Search): For every interval's end point, we use a custom
 *    binary search to find the smallest start point in `v` that is >= the end point.
 *    (Note: This perfectly mimics C++ `std::lower_bound`).
 * 4. Step 4 (Lookup): We check if the found start point exists in our map.
 *    If it does, we push its original index to the result. Otherwise, push -1.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> Sorting the start points takes O(N log N).
 *   We then perform N binary searches, each taking O(log N) time.
 * - Space Complexity: O(N) -> We use an unordered_map to store N index mappings
 *   and a vector to store N start points.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // Required for sort()

using namespace std;

class Solution
{
public:
    // Custom binary search to find the smallest element >= target
    // (Functionally identical to std::lower_bound)
    int search(vector<int> &start, int target)
    {
        if (start.empty())
        {
            return -1;
        }

        // If target is greater than the largest start point, it doesn't exist
        if (target > start.back())
        {
            return start.back() + 1; // Return an out-of-bounds sentinel value
        }

        int left = 0;
        int right = start.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (start[mid] == target)
            {
                return start[mid];
            }
            else if (start[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // 'left' will point to the first element strictly >= target
        return start[left];
    }

    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        unordered_map<int, int> m;
        vector<int> v;

        // Map each start point to its original index
        for (int i = 0; i < n; i++)
        {
            m[intervals[i][0]] = i;
            v.push_back(intervals[i][0]);
        }

        // Sort the start points to enable binary search
        sort(v.begin(), v.end());

        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            // Find the closest valid start point for the current interval's end point
            int x = search(v, intervals[i][1]);

            // If the start point isn't in our map, no valid right interval exists
            if (m.find(x) == m.end())
            {
                result.push_back(-1);
            }
            else
            {
                // Otherwise, append its original index
                result.push_back(m[x]);
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

    // Test Case 1: Only one interval
    // Input: [[1,2]]
    // Output: [-1] (No interval starts after 2)
    vector<vector<int>> intervals1 = {{1, 2}};
    cout << "Test Case 1:" << endl;
    cout << "Input: [[1,2]]" << endl;
    vector<int> res1 = solution.findRightInterval(intervals1);
    cout << "Output: [";
    for (size_t i = 0; i < res1.size(); i++)
        cout << res1[i] << (i < res1.size() - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: [-1]

    cout << "-----------------------------------" << endl;

    // Test Case 2: Standard unsorted intervals
    // Input: [[3,4], [2,3], [1,2]]
    // Output: [-1, 0, 1]
    // The right interval for [1,2] is [2,3] (index 1).
    // The right interval for [2,3] is [3,4] (index 0).
    // The right interval for [3,4] doesn't exist (-1).
    vector<vector<int>> intervals2 = {{3, 4}, {2, 3}, {1, 2}};
    cout << "Test Case 2:" << endl;
    cout << "Input: [[3,4], [2,3], [1,2]]" << endl;
    vector<int> res2 = solution.findRightInterval(intervals2);
    cout << "Output: [";
    for (size_t i = 0; i < res2.size(); i++)
        cout << res2[i] << (i < res2.size() - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: [-1, 0, 1]

    cout << "-----------------------------------" << endl;

    // Test Case 3: Intervals with gaps
    // Input: [[1,4], [2,3], [3,4]]
    // Output: [-1, 2, -1]
    vector<vector<int>> intervals3 = {{1, 4}, {2, 3}, {3, 4}};
    cout << "Test Case 3:" << endl;
    cout << "Input: [[1,4], [2,3], [3,4]]" << endl;
    vector<int> res3 = solution.findRightInterval(intervals3);
    cout << "Output: [";
    for (size_t i = 0; i < res3.size(); i++)
        cout << res3[i] << (i < res3.size() - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: [-1, 2, -1]

    return 0;
}