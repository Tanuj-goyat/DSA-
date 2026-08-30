/**
 * ============================================================================
 * Problem: Rat in a Maze
 * ============================================================================
 *
 * Problem Statement:
 * Consider a rat placed at (0, 0) in an m x n square matrix. The rat wants to
 * reach the destination at (m-1, n-1). Find all possible paths that the rat can
 * take to reach from source to destination. The directions in which the rat can
 * move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 means the cell
 * is blocked and 1 means the cell is open.
 *
 * Approach Used: Depth-First Search (DFS) & Backtracking
 * 1. Base Case: If the rat reaches the bottom-right cell, the current path
 *    string `s` is added to the results.
 * 2. Visited Tracking: To avoid infinite loops, the current cell is temporarily
 *    marked as visited by changing its value from 1 to 0.
 * 3. Directional Moves: We attempt to move Down, Left, Right, and Up. This
 *    specific D-L-R-U order ensures the resulting paths are sorted alphabetically.
 * 4. Backtracking: After exploring all valid paths from the current cell, we
 *    revert its value back to 1 (unmark it) and pop the last move from the string
 *    so that other paths can reuse this cell.
 *
 * Complexity:
 * - Time Complexity: O(4^(M*N)) -> In the worst-case scenario (an empty grid),
 *   the rat has 4 choices at almost every cell.
 * - Space Complexity: O(M*N) -> The maximum depth of the recursion call stack
 *   (the longest possible path) is bounded by the number of cells in the maze.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void f(vector<vector<int>> &maze, vector<string> &ans, string &s, int row, int col)
    {
        int m = maze.size();
        int n = maze[0].size();

        // Base Case: Reached the destination
        if (row == m - 1 && col == n - 1)
        {
            ans.push_back(s);
            return;
        }

        // Mark the current cell as visited to prevent cycles
        maze[row][col] = 0;

        // Move DOWN
        if (row + 1 < m && maze[row + 1][col] == 1)
        {
            s.push_back('D');
            f(maze, ans, s, row + 1, col);
            s.pop_back(); // Backtrack
        }

        // Move LEFT
        if (col - 1 >= 0 && maze[row][col - 1] == 1)
        {
            s.push_back('L');
            f(maze, ans, s, row, col - 1);
            s.pop_back(); // Backtrack
        }

        // Move RIGHT
        if (col + 1 < n && maze[row][col + 1] == 1)
        {
            s.push_back('R');
            f(maze, ans, s, row, col + 1);
            s.pop_back(); // Backtrack
        }

        // Move UP
        if (row - 1 >= 0 && maze[row - 1][col] == 1)
        {
            s.push_back('U');
            f(maze, ans, s, row - 1, col);
            s.pop_back(); // Backtrack
        }

        // Unmark the current cell so it can be used in other paths
        maze[row][col] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        string s = "";
        vector<string> ans;

        // Edge Case: If the starting cell is blocked, no paths exist
        if (maze[0][0] == 0)
            return ans;

        f(maze, ans, s, 0, 0);

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: 4x4 Maze
    // 1 0 0 0
    // 1 1 0 1
    // 1 1 0 0
    // 0 1 1 1
    vector<vector<int>> maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    cout << "Test Case 1 (4x4 Maze):" << endl;
    vector<string> result1 = solution.ratInMaze(maze1);

    if (result1.empty())
    {
        cout << "No paths found." << endl;
    }
    else
    {
        for (const string &path : result1)
        {
            cout << path << endl;
        }
    }
    // Expected Output:
    // DDRDRR
    // DRDDRR

    cout << "-----------------------------------" << endl;

    // Test Case 2: 2x2 Maze where destination is blocked
    // 1 1
    // 1 0
    vector<vector<int>> maze2 = {
        {1, 1},
        {1, 0}};

    cout << "Test Case 2 (Blocked Destination):" << endl;
    vector<string> result2 = solution.ratInMaze(maze2);

    if (result2.empty())
    {
        cout << "No paths found." << endl;
    }
    else
    {
        for (const string &path : result2)
        {
            cout << path << endl;
        }
    }
    // Expected Output: No paths found.

    return 0;
}