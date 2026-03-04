#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Search a 2D Matrix II
Platform: LeetCode
Problem Number: 240
========================================================

Problem Statement:
You are given an m x n matrix where:

1️⃣ Each row is sorted in ascending order.
2️⃣ Each column is sorted in ascending order.

Given a target integer, return true if the target
exists in the matrix, otherwise return false.

Example:

Matrix =
[
 [1, 4, 7, 11, 15],
 [2, 5, 8, 12, 19],
 [3, 6, 9, 16, 22],
 [10,13,14,17,24],
 [18,21,23,26,30]
]

Target = 5

Output: true

========================================================
Approach Used (Top Right Corner Search)

Start from the TOP-RIGHT corner.

Why?

At position (r, c):

If matrix[r][c] > target
    → Move LEFT (because everything below is bigger)

If matrix[r][c] < target
    → Move DOWN (because everything left is smaller)

If equal
    → Target found

This works because both rows and columns are sorted.

========================================================
Time Complexity: O(m + n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();      // number of rows
        int n = matrix[0].size();   // number of columns

        int r = 0;       // start from first row
        int c = n - 1;   // start from last column (top-right corner)

        while (r < m && c >= 0) {

            // If target found
            if (matrix[r][c] == target)
                return true;

            // Move down if current element is smaller
            if (matrix[r][c] < target) {
                r++;
            }

            // Move left if current element is larger
            else {
                c--;
            }
        }

        return false;   // target not found
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int target = 5;

    Solution obj;

    if(obj.searchMatrix(matrix, target))
        cout << "Target Found";
    else
        cout << "Target Not Found";

    return 0;
}