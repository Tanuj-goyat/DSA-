#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Valid Sudoku
Platform: LeetCode
Problem Number: 36
========================================================

Problem Statement:
Determine if a 9×9 Sudoku board is valid.

Rules:
1️⃣ Each row must contain digits 1–9 without repetition
2️⃣ Each column must contain digits 1–9 without repetition
3️⃣ Each 3×3 sub-box must contain digits 1–9 without repetition

Note:
- Board may not be completely filled
- Only check validity of current configuration

========================================================
Approach (Brute Force Checking)

For every non-empty cell:
1️⃣ Check entire row (excluding itself)
2️⃣ Check entire column (excluding itself)
3️⃣ Check corresponding 3×3 subgrid

If any duplicate is found → return false

========================================================
Time Complexity: O(9³) ≈ constant
Space Complexity: O(1)
========================================================
*/

class Solution {
public:

    // Check if placing value 'a' at (i, j) is valid
    bool poss(int i, int j, vector<vector<char>>& box, char a) {

        for (int x = 0; x < 9; x++) {

            // Check row
            if (box[i][x] == a && x != j)
                return false;

            // Check column
            if (box[x][j] == a && x != i)
                return false;

            // Check 3x3 subgrid
            int row = (i / 3) * 3 + x / 3;
            int col = (j / 3) * 3 + x % 3;

            if (box[row][col] == a && (row != i || col != j))
                return false;
        }

        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Check only filled cells
                if (board[i][j] != '.') {

                    if (!poss(i, j, board, board[i][j]))
                        return false;
                }
            }
        }

        return true;
    }
};


int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;

    if(obj.isValidSudoku(board))
        cout << "Valid Sudoku";
    else
        cout << "Invalid Sudoku";

    return 0;
}