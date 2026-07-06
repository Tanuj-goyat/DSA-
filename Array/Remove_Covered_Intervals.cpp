#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Remove Covered Intervals
Platform: LeetCode (1288)
========================================================

Problem Statement:
Given a list of intervals.

An interval is covered if another
interval completely contains it.

Return the number of intervals
remaining after removing all covered
intervals.

Example:
Input:
[[1,4],[3,6],[2,8]]

Output:
2

Explanation:
[3,6] is covered by [2,8].

========================================================
Approach Used (Sorting)

Step 1:
Sort intervals by:

- Increasing start point.
- If start points are equal,
  decreasing end point.

Step 2:
Maintain the maximum ending point
seen so far.

Step 3:
If the current interval ends before
or at the current maximum ending point,
it is covered.

Step 4:
Otherwise,
update the maximum ending point.

Time Complexity: O(n log n)
Space Complexity: O(1)
(excluding sorting space)

========================================================
*/

class Solution {
public:

    int removeCoveredIntervals(
        vector<vector<int>>& matrix) {

        int lastMax = 0;

        int count = matrix.size();

        // ------------------------------
        // Sort intervals
        // ------------------------------
        sort(matrix.begin(),
             matrix.end(),
             [](const vector<int>& a, const vector<int>& b) {

                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });

        // ------------------------------
        // Count uncovered intervals
        // ------------------------------
        for (int i = 0; i < matrix.size(); i++) {

            if (lastMax >= matrix[i][1]) {

                count--;
            }

            lastMax = max(lastMax,  matrix[i][1]);
        }

        return count;
    }
};


int main() {

    vector<vector<int>> matrix =
    {
        {1, 4},
        {3, 6},
        {2, 8}
    };

    Solution obj;

    int answer = obj.removeCoveredIntervals(matrix);

    cout << answer << endl;

    return 0;
}