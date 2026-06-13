#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Merge Intervals
Platform: LeetCode (56)
========================================================

Problem Statement:
Given an array of intervals where:

intervals[i] = [starti, endi]

Merge all overlapping intervals and
return the resulting intervals.

Example:
Input:
[[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]

========================================================
Approach Used (Sorting + Merge)

Step 1:
Sort intervals according to start time.

Step 2:
Traverse intervals one by one.

Step 3:
If current interval overlaps with
the previous merged interval,
merge them.

Step 4:
Otherwise add a new interval.

Time Complexity: O(n log n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    vector<vector<int>> merge(
        vector<vector<int>>& matrix) {

        // ------------------------------
        // Sort intervals
        // ------------------------------
        sort(matrix.begin(),
             matrix.end());

        vector<vector<int>> v;

        int n = matrix.size();

        int index = 0;

        // ------------------------------
        // Traverse all intervals
        // ------------------------------
        for (int i = 0; i < n; i++) {

            // Add current interval
            v.push_back(
                {matrix[i][0],
                 matrix[i][1]});

            // Check overlap
            if (index > 0) {

                if (v[index][0] <=
                    v[index - 1][1]) {

                    // Extend previous interval
                    if (v[index][1] >
                        v[index - 1][1]) {

                        v[index - 1][1] =
                            v[index][1];
                    }

                    // Remove merged interval
                    v.pop_back();

                    index--;
                }
            }

            index++;
        }

        return v;
    }
};


// Helper function
void printIntervals(
    vector<vector<int>>& intervals) {

    cout << "[ ";

    for (int i = 0; i < intervals.size(); i++) {

        cout << "["
             << intervals[i][0]
             << ","
             << intervals[i][1]
             << "] ";

    }

    cout << "]" << endl;
}


int main() {

    vector<vector<int>> matrix = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    Solution obj;

    vector<vector<int>> ans =
        obj.merge(matrix);

    cout << "Merged Intervals:\n";

    printIntervals(ans);

    return 0;
}