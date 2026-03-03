#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Search a 2D Matrix
Platform: LeetCode
Problem Number: 74
========================================================

Problem Statement:
You are given an m x n matrix where:
1️⃣ Each row is sorted in ascending order.
2️⃣ The first element of each row is greater than the last element of the previous row.

Given a target value, return true if it exists in the matrix,
otherwise return false.

Example:
Input:
matrix =
[
 [1, 3, 5, 7],
 [10,11,16,20],
 [23,30,34,60]
]
target = 3

Output: true

========================================================
Approach Used (Two Binary Searches):

Step 1️⃣:
Binary search on rows to find the correct row
where the target could exist.
We compare target with first element of each row.

Step 2️⃣:
Binary search inside that selected row.

Time Complexity: O(log m + log n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();       // Number of rows
        int n = matrix[0].size();    // Number of columns

        // If target is outside global matrix range
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
            return false;
        }

        int start = 0;
        int end = m - 1;
        int mid = 0;
        int ans = 0;   // Row index where target may exist

        // -----------------------------------------
        // Step 1: Binary search to find correct row
        // -----------------------------------------
        while (start <= end) {
            mid = start + (end - start) / 2;

            if (matrix[mid][0] > target) {
                end = mid - 1;
            } 
            else {
                ans = mid;          // Possible row
                start = mid + 1;
            }
        }

        // -----------------------------------------
        // Step 2: Binary search inside that row
        // -----------------------------------------
        start = 0;
        end = n - 1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (matrix[ans][mid] == target)
                return true;

            else if (matrix[ans][mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return false;  // Target not found
    }
};


int main() {

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    Solution obj;
    bool found = obj.searchMatrix(matrix, target);

    if (found)
        cout << "Target Found" << endl;
    else
        cout << "Target Not Found" << endl;

    return 0;
}