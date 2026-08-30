/**
 * ============================================================================
 * Problem: All Paths From Top Left to Bottom Right
 * ============================================================================
 *
 * Problem Statement:
 * Given an M x N matrix, find all possible paths from the top-left cell (0, 0)
 * to the bottom-right cell (M-1, N-1). You can only move either down or right
 * at any point in time.
 *
 * Approach Used: Depth-First Search (DFS) / Backtracking
 * 1. We start at the top-left cell (0, 0) and push its value into our current `path`.
 * 2. Base Case: If we reach the bottom-right cell, we have completed a valid path.
 *    We add a copy of this `path` to our `paths` result list.
 * 3. Recursive Step: From the current cell, we attempt to move Right (if within bounds).
 *    Then, we attempt to move Down (if within bounds).
 * 4. Backtracking: After exploring all possible paths originating from the current cell,
 *    we remove its value from the `path` (pop_back) so that the previous recursive
 *    calls can explore different branches with a clean slate.
 *
 * Complexity:
 * - Time Complexity: O(2^(N+M)) -> In the worst case, every step gives us 2 choices
 *   (Right or Down). The length of any path is exactly (N-1) + (M-1) steps.
 * - Space Complexity: O(N+M) -> Excluding the space required to store the final paths,
 *   the recursion call stack and the temporary `path` vector will take O(N+M) space.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void findPaths(vector<vector<int>> &mat, int i, int j, vector<int> &path, vector<vector<int>> &paths)
    {
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Include the current cell's value in the current path
        path.push_back(mat[i][j]);

        // Step 2: Base Case -> If we reach the bottom-right cell, save the path
        if (i == n - 1 && j == m - 1)
        {
            paths.push_back(path);
        }
        else
        {
            // Step 3: Move Right (if within column bounds)
            if (j + 1 < m)
            {
                findPaths(mat, i, j + 1, path, paths);
            }
            // Step 3: Move Down (if within row bounds)
            if (i + 1 < n)
            {
                findPaths(mat, i + 1, j, path, paths);
            }
        }

        // Step 4: Backtrack -> Remove the current cell to explore other branches
        path.pop_back();
    }

    vector<vector<int>> allPaths(vector<vector<int>> &mat)
    {
        vector<vector<int>> paths;
        vector<int> path;

        // Start the DFS from the top-left corner (0, 0)
        findPaths(mat, 0, 0, path, paths);

        return paths;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: 2x3 Matrix
    // 1 2 3
    // 4 5 6
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6}};

    cout << "Test Case 1 (2x3 Matrix): " << endl;
    vector<vector<int>> result1 = solution.allPaths(mat1);
    for (size_t i = 0; i < result1.size(); ++i)
    {
        cout << "Path " << i + 1 << ": [ ";
        for (int val : result1[i])
        {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    // Expected Output:
    // [ 1 2 3 6 ]
    // [ 1 2 5 6 ]
    // [ 1 4 5 6 ]

    cout << "-----------------------------------" << endl;

    // Test Case 2: 2x2 Matrix
    // 10 20
    // 30 40
    vector<vector<int>> mat2 = {
        {10, 20},
        {30, 40}};

    cout << "Test Case 2 (2x2 Matrix): " << endl;
    vector<vector<int>> result2 = solution.allPaths(mat2);
    for (size_t i = 0; i < result2.size(); ++i)
    {
        cout << "Path " << i + 1 << ": [ ";
        for (int val : result2[i])
        {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    // Expected Output:
    // [ 10 20 40 ]
    // [ 10 30 40 ]

    return 0;
}