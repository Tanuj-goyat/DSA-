#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Sudoku Solver
Platform: LeetCode
Problem Number: 37
========================================================

Problem Statement:
Write a program to solve a Sudoku puzzle by filling
the empty cells.

Rules:
1️⃣ Each row must contain digits 1–9 without repetition
2️⃣ Each column must contain digits 1–9 without repetition
3️⃣ Each 3×3 subgrid must contain digits 1–9

Empty cells are denoted by '.'.

========================================================
Approach (Backtracking)

1️⃣ Traverse the board
2️⃣ If a cell is empty:
   - Try digits from '1' to '9'
   - Check if placing digit is valid
3️⃣ If valid:
   - Place digit
   - Recurse
4️⃣ If recursion fails:
   - Backtrack (remove digit)

========================================================
Time Complexity: Exponential (9^(n*n))
Space Complexity: O(n*n) recursion stack

========================================================
*/

class Solution {
public:

    // Check if placing 'a' at (i, j) is valid
    bool poss(int i, int j, char a, vector<vector<char>> &box) {

        for(int x = 0; x < 9; x++) {

            // Check row
            if(box[i][x] == a) return false;

            // Check column
            if(box[x][j] == a) return false;

            // Check 3x3 subgrid
            if(box[(i/3)*3 + (x / 3)][(j/3)*3 + (x % 3)] == a)
                return false;
        }

        return true;
    }


    // Backtracking function
    bool f(vector<vector<char>>& box) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // If empty cell found
                if(box[i][j] == '.') {

                    // Try all digits
                    for(char a = '1'; a <= '9'; a++) {

                        if(poss(i, j, a, box)) {

                            box[i][j] = a;   // place digit

                            if(f(box)) return true;

                            // Backtrack
                            box[i][j] = '.';
                        }
                    }

                    // If no digit works → fail
                    return false;
                }
            }
        }

        // If no empty cell left → solved
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        f(board);
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

    obj.solveSudoku(board);

    cout << "Solved Sudoku:\n";

    for(auto &row : board) {
        for(auto ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}