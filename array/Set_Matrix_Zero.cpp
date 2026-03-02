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
Given an m x n integer matrix,
if an element is 0, set its entire row and column to 0.

You must do it in-place.

Example:
Input:
[
 [1,1,1],
 [1,0,1],
 [1,1,1]
]

Output:
[
 [1,0,1],
 [0,0,0],
 [1,0,1]
]

========================================================
Approach Used (Extra Row & Column Storage):

Step 1:
Traverse the matrix and store:
- Row indices containing 0 → vi
- Column indices containing 0 → vj

Step 2:
For every stored row index, set entire row to 0.

Step 3:
For every stored column index, set entire column to 0.

Time Complexity: O(m × n)
Space Complexity: O(m + n)

========================================================
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();       // Number of rows
        int n = matrix[0].size();    // Number of columns

        vector<int> vi;  // Stores row indices where 0 appears
        vector<int> vj;  // Stores column indices where 0 appears

        // ----------------------------------------
        // Step 1: Find all positions containing 0
        // ----------------------------------------
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 0) {
                    vi.push_back(i);
                    vj.push_back(j);
                }
            }
        }

        // ----------------------------------------
        // Step 2: Set entire rows to 0
        // ----------------------------------------
        for (int a = 0; a < vi.size(); a++) {
            for (int j = 0; j < n; j++) {
                matrix[vi[a]][j] = 0;
            }
        }

        // ----------------------------------------
        // Step 3: Set entire columns to 0
        // ----------------------------------------
        for (int a = 0; a < vj.size(); a++) {
            for (int i = 0; i < m; i++) {
                matrix[i][vj[a]] = 0;
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