#include <bits/stdc++.h>
using namespace std;

/*
========================================================
Problem Name: Rat in a Maze
Platform: GeeksforGeeks
Problem Number: N/A (Classic Backtracking Problem)
========================================================

Problem Statement:
Given a maze of size n x n where:
1 → path is open
0 → path is blocked

Find all possible paths from (0,0) to (n-1,n-1).

Allowed moves:
U → Up
D → Down
L → Left
R → Right

========================================================
Approach (Backtracking)

1️⃣ Start from (0,0)
2️⃣ Try all 4 directions:
   - Up
   - Down
   - Right
   - Left

3️⃣ Mark current cell as visited (avoid cycles)

4️⃣ If destination reached → store path

5️⃣ Backtrack:
   - Unmark cell
   - Remove last move

========================================================
Time Complexity: O(4^(n*n)) worst case
Space Complexity: O(n*n)
========================================================
*/

class Solution
{
public:

    // Backtracking function
    void f(vector<string> &ans,
           string &s,
           vector<vector<int>> &maze,
           int i,
           int j)
    {
        // Base case: reached destination
        if (i == maze.size() - 1 && j == maze[0].size() - 1)
        {
            ans.push_back(s);
            return;
        }

        // Mark current cell as visited
        maze[i][j] = -1;

        // ----------------------------
        // Move Up
        // ----------------------------
        if (i > 0 && maze[i - 1][j] == 1)
        {
            s.push_back('U');
            f(ans, s, maze, i - 1, j);
            s.pop_back();
        }

        // ----------------------------
        // Move Down
        // ----------------------------
        if (i < maze.size() - 1 && maze[i + 1][j] == 1)
        {
            s.push_back('D');
            f(ans, s, maze, i + 1, j);
            s.pop_back();
        }

        // ----------------------------
        // Move Right
        // ----------------------------
        if (j < maze[0].size() - 1 && maze[i][j + 1] == 1)
        {
            s.push_back('R');
            f(ans, s, maze, i, j + 1);
            s.pop_back();
        }

        // ----------------------------
        // Move Left
        // ----------------------------
        if (j > 0 && maze[i][j - 1] == 1)
        {
            s.push_back('L');
            f(ans, s, maze, i, j - 1);
            s.pop_back();
        }

        // Backtrack: unmark cell
        maze[i][j] = 1;
    }


    vector<string> findPath(vector<vector<int>> &maze, int n)
    {
        vector<string> ans;
        string s;

        // If starting point is blocked
        if (maze[0][0] == 0)
            return ans;

        f(ans, s, maze, 0, 0);

        return ans;
    }
};


int main()
{
    Solution obj;

    // Example maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int n = maze.size();

    vector<string> result = obj.findPath(maze, n);

    // Output
    if (result.empty())
    {
        cout << -1;
    }
    else
    {
        for (auto &path : result)
        {
            cout << path << " ";
        }
    }

    return 0;
}