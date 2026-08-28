/**
 * ============================================================================
 * LeetCode 103: Binary Tree Zigzag Level Order Traversal
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 *
 * Approach Used: Breadth-First Search (BFS) with a Direction Flag
 * 1. We use a queue to perform a standard level-by-level BFS traversal.
 * 2. We introduce a boolean `flag` that dictates the direction of insertion
 *    for the current level (true = left-to-right, false = right-to-left).
 * 3. For each level, we pre-allocate a vector `level` of the exact size needed.
 * 4. As we pop nodes from the queue, we determine their target index in the
 *    `level` array based on the `flag`:
 *    - If left-to-right: index = i (normal order).
 *    - If right-to-left: index = size - i - 1 (reverse order).
 * 5. We push the children of the current node into the queue for the next level.
 * 6. Finally, we toggle the `flag` before moving to the next level.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node in the binary tree exactly
 *   once. Calculating the index takes O(1) time.
 * - Space Complexity: O(N) -> The queue can hold at most N/2 nodes at the
 *   widest level (the leaves). The output vector also takes O(N) space.
 * ============================================================================
 */

#include <iostream>
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        // Base case: If the tree is empty, return an empty result
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        // Flag to track direction: true means left-to-right, false means right-to-left
        bool flag = true;

        while (!q.empty())
        {
            int size = q.size();

            // Pre-allocate the vector with the exact size to allow direct index assignment
            vector<int> level(size, 0);

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // Determine the correct index based on the current zigzag direction
                int index = i;
                if (!flag)
                {
                    index = size - i - 1; // Insert backwards
                }

                // Assign the node's value to the calculated index
                level[index] = node->val;

                // Add child nodes to the queue for the next level
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Add the processed level to the final result
            result.push_back(level);

            // Toggle the flag for the next level
            flag = !flag;
        }

        return result;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: [3, 9, 20, null, null, 15, 7]
    //      3      (Left to Right) -> [3]
    //     / \
    //    9  20    (Right to Left) -> [20, 9]
    //       / \
    //      15  7  (Left to Right) -> [15, 7]
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Test Case 1:" << endl;
    vector<vector<int>> res1 = solution.zigzagLevelOrder(root1);
    cout << "[" << endl;
    for (size_t i = 0; i < res1.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < res1[i].size(); ++j)
        {
            cout << res1[i][j] << (j < res1[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res1.size() - 1 ? "," : "") << endl;
    }
    cout << "]" << endl;
    // Expected: [[3], [20, 9], [15, 7]]

    cout << "-----------------------------------" << endl;

    // Test Case 2: [1]
    TreeNode *root2 = new TreeNode(1);

    cout << "Test Case 2:" << endl;
    vector<vector<int>> res2 = solution.zigzagLevelOrder(root2);
    cout << "[" << endl;
    for (size_t i = 0; i < res2.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < res2[i].size(); ++j)
        {
            cout << res2[i][j] << (j < res2[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res2.size() - 1 ? "," : "") << endl;
    }
    cout << "]" << endl;
    // Expected: [[1]]

    // Clean up dynamically allocated memory
    delete root1->right->right;
    delete root1->right->left;
    delete root1->right;
    delete root1->left;
    delete root1;

    delete root2;

    return 0;
}