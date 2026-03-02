#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Set Matrix Zeroes
Platform: LeetCode
Problem Number: 73
========================================================

Problem Statement:
Given an m x n matrix,
if an element is 0, set its entire row and column to 0.

You must do it in-place with O(1) extra space.

========================================================
Approach Used (Using First Row & First Column as Markers)

Instead of using extra arrays, we use:
- First row to mark which columns should be zero
- First column to mark which rows should be zero

Steps:

1️⃣ Check if first row has any zero → store in isr0
2️⃣ Check if first column has any zero → store in isc0

3️⃣ For rest of matrix (excluding first row & column):
   If matrix[i][j] == 0:
      - Mark row by setting matrix[i][0] = 0
      - Mark column by setting matrix[0][j] = 0

4️⃣ Zero out rows based on first column markers

5️⃣ Zero out columns based on first row markers

6️⃣ Finally, zero out first row/column if needed

Time Complexity: O(m × n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool isr0 = false;  // Does first row contain zero?
        bool isc0 = false;  // Does first column contain zero?

        // ---------------------------------------
        // Step 1: Check first column
        // ---------------------------------------
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                isc0 = true;
                break;
            }
        }

        // ---------------------------------------
        // Step 2: Check first row
        // ---------------------------------------
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                isr0 = true;
                break;
            }
        }

        // ---------------------------------------
        // Step 3: Use first row & column as markers
        // ---------------------------------------
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;  // Mark column
                    matrix[i][0] = 0;  // Mark row
                }
            }
        }

        // ---------------------------------------
        // Step 4: Zero out rows (except first row)
        // ---------------------------------------
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // ---------------------------------------
        // Step 5: Zero out columns (except first column)
        // ---------------------------------------
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // ---------------------------------------
        // Step 6: Handle first row
        // ---------------------------------------
        if (isr0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // ---------------------------------------
        // Step 7: Handle first column
        // ---------------------------------------
        if (isc0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};


int main() {

    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    Solution obj;
    obj.setZeroes(matrix);

    cout << "Modified Matrix:\n";

    for (auto row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}