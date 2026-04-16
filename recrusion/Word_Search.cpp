#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Word Search
Platform: LeetCode
Problem Number: 79
========================================================

Problem Statement:
Given a 2D board and a word, return true if the word
exists in the grid.

Rules:
- Can move up, down, left, right
- Cannot reuse same cell

========================================================
Approach (Backtracking / DFS)

1️⃣ Start from every cell

2️⃣ Match characters one by one

3️⃣ Mark visited cell (avoid reuse)

4️⃣ Explore all 4 directions

5️⃣ Backtrack (restore cell)

========================================================
Time Complexity: O(m * n * 4^L)
Space Complexity: O(L)
========================================================
*/

class Solution {
public:

    bool f(vector<vector<char>>& box,
           string& word,
           int index,
           int i,
           int j) {

        // Step 1: Character mismatch
        if (box[i][j] != word[index])
            return false;

        // Step 2: If last character matched
        if (index == word.size() - 1)
            return true;

        // Step 3: Mark visited
        char temp = box[i][j];
        box[i][j] = '#';

        // Explore all 4 directions

        // Up
        if (i > 0 && f(box, word, index + 1, i - 1, j))
            return true;

        // Down
        if (i < box.size() - 1 &&
            f(box, word, index + 1, i + 1, j))
            return true;

        // Right
        if (j < box[0].size() - 1 &&
            f(box, word, index + 1, i, j + 1))
            return true;

        // Left
        if (j > 0 &&
            f(box, word, index + 1, i, j - 1))
            return true;

        // Step 4: Backtrack
        box[i][j] = temp;

        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        // Try every cell as starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (f(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};


int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution obj;

    cout << "Exists: "
         << (obj.exist(board, word) ? "YES" : "NO");

    return 0;
}