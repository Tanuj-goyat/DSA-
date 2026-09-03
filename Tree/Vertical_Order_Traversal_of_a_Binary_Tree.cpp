/**
 * ============================================================================
 * LeetCode 987: Vertical Order Traversal of a Binary Tree
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, calculate the vertical order traversal of
 * the binary tree. For each node at position (row, col), its left and right
 * children will be at positions (row + 1, col - 1) and (row + 1, col + 1).
 * The root of the tree is at (0, 0).
 * The vertical order traversal sorts nodes by column. If multiple nodes are in
 * the same row and column, they should be sorted by their values.
 *
 * Approach Used: Breadth-First Search (BFS) with Nested Maps
 * 1. We use a BFS approach with a queue to traverse the tree level by level.
 *    The queue stores the node along with its (column, row) coordinates.
 * 2. We use a nested map structure: `map<column, map<row, multiset<value>>>`.
 *    - The outer `map` automatically sorts the columns from left to right.
 *    - The inner `map` automatically sorts the rows from top to bottom.
 *    - The `multiset` automatically sorts multiple nodes that land on the exact
 *      same (column, row) coordinate by their values (and allows duplicates).
 * 3. During BFS, we calculate the coordinates for the left and right children
 *    and push them into the queue.
 * 4. Finally, we iterate through our perfectly sorted map structure and flatten
 *    the multisets into our 2D result vector.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> Where N is the number of nodes. Traversing
 *   the tree takes O(N), but inserting into the map and multiset takes O(log N)
 *   time per insertion.
 * - Space Complexity: O(N) -> The map, multiset, and queue will collectively
 *   store all N nodes in the worst case.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // Map structure: Column -> (Row -> Sorted Node Values)
        map<int, map<int, multiset<int>>> nodes;

        // Queue structure: Pair(Node, Pair(Column, Row))
        queue<pair<TreeNode *, pair<int, int>>> todo;

        // Initialize BFS with the root node at coordinate (0, 0)
        todo.push({root, {0, 0}});

        while (!todo.empty())
        {
            auto joda = todo.front(); // 'joda' extracts the paired element
            todo.pop();

            TreeNode *node = joda.first;
            int col = joda.second.first;
            int row = joda.second.second;

            // Insert the node's value into the appropriate column and row.
            // The multiset ensures values at the same coordinate are sorted.
            nodes[col][row].insert(node->val);

            // Left child goes down one row (row + 1) and left one column (col - 1)
            if (node->left)
            {
                todo.push({node->left, {col - 1, row + 1}});
            }

            // Right child goes down one row (row + 1) and right one column (col + 1)
            if (node->right)
            {
                todo.push({node->right, {col + 1, row + 1}});
            }
        }

        vector<vector<int>> ans;

        // Iterate through the sorted columns
        for (auto key : nodes)
        {
            vector<int> col;
            // Iterate through the sorted rows within this column
            for (auto p : key.second)
            {
                // Insert all sorted values from the multiset into the column array
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            // Add the completed column to our final answer
            ans.push_back(col);
        }

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
    //
    // Coordinate breakdown:
    // col -2: [4]
    // col -1: [2]
    // col  0: [1, 5, 6] (5 and 6 are at the same row/col, so they are sorted)
    // col  1: [3]
    // col  2: [7]
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    cout << "Test Case 1:" << endl;
    vector<vector<int>> result1 = solution.verticalTraversal(root1);

    cout << "[" << endl;
    for (size_t i = 0; i < result1.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < result1[i].size(); ++j)
        {
            cout << result1[i][j] << (j < result1[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < result1.size() - 1 ? "," : "") << endl;
    }
    cout << "]" << endl;
    // Expected: [[4], [2], [1, 5, 6], [3], [7]]

    // Clean up dynamically allocated memory
    delete root1->left->left;
    delete root1->left->right;
    delete root1->right->left;
    delete root1->right->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    return 0;
}