#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem Name: N-Queens
Platform: LeetCode
Problem Number: 51
========================================================

Problem Statement:
Place n queens on an n×n chessboard such that:
✔ No two queens attack each other

A queen can attack:
- Same row
- Same column
- Diagonals

Return all distinct solutions.

Example:
Input: n = 4

Output:
[
 [".Q..",
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]
]

========================================================
Approach (Backtracking)

We place queens column by column.

For each column:
- Try placing queen in every row
- Check if it is safe
- If safe → place queen and move to next column
- After recursion → remove queen (backtrack)

Safety check:
✔ Upper-left diagonal
✔ Lower-left diagonal
✔ Same column
✔ Same row

========================================================
Time Complexity: O(n!)
Space Complexity: O(n²)
========================================================
*/

class Solution {
public:

    // Check if it's safe to place queen at (row, col)
    bool safe(int row, int col, vector<string> box, int n) {

        int i = row;
        int j = col;

        // Check upper-left diagonal
        while(row >= 0 && col >= 0) {
            if(box[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = i;
        col = j;

        // Check lower-left diagonal
        while(row < n && col >= 0) {
            if(box[row][col] == 'Q') return false;
            row++;
            col--;
        }

        row = i;
        col = j;

        // Check same column (upwards)
        while(row >= 0) {
            if(box[row][col] == 'Q') return false;
            row--;
        }

        row = i;

        // Check same row (left side)
        while(col >= 0) {
            if(box[row][col] == 'Q') return false;
            col--;
        }

        return true;
    }


    // Backtracking function
    void f(int col, vector<string> &box, vector<vector<string>> &ans, int n) {

        // If all columns are filled → valid solution
        if(col == n) {
            ans.push_back(box);
            return;
        }

        // Try placing queen in every row
        for(int row = 0; row < n; row++) {

            if(safe(row, col, box, n)) {

                // Place queen
                box[row][col] = 'Q';

                // Move to next column
                f(col + 1, box, ans, n);

                // Backtrack (remove queen)
                box[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Initialize empty board
        vector<string> box(n);
        string s(n, '.');

        for(int i = 0; i < n; i++) {
            box[i] = s;
        }

        // Start from column 0
        f(0, box, ans, n);

        return ans;
    }
};


int main() {

    int n = 4;

    Solution obj;

    vector<vector<string>> result = obj.solveNQueens(n);

    cout << "Solutions:\n";

    for(auto &board : result) {
        cout << "--------\n";
        for(auto &row : board) {
            cout << row << endl;
        }
    }

    return 0;
}