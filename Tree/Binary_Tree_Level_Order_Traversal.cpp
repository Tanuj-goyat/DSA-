/**
 * ============================================================================
 * LeetCode 102: Binary Tree Level Order Traversal
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 * Approach Used: Breadth-First Search (BFS)
 * To traverse the tree level by level, we use a Queue.
 * 1. If the root is null, return an empty 2D vector.
 * 2. Push the root node into the queue to start.
 * 3. While the queue is not empty, determine its current size. This size
 *    represents the number of nodes at the current level.
 * 4. Iterate exactly 'size' times: pop a node, store its value, and push its
 *    left and right children (if they exist) into the queue for the next level.
 * 5. Store the current level's values in the final answer array.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node in the tree exactly once,
 *   where N is the number of nodes.
 * - Space Complexity: O(N) -> The queue will hold at most N/2 nodes at the
 *   widest level (the leaves). The output 2D vector also takes O(N) space.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <queue> // Required for the queue data structure

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;     // Queue to manage the BFS
        vector<vector<int>> ans; // 2D vector to store the final result

        // Base case: if the tree is empty
        if (!root)
            return ans;

        // Start BFS by pushing the root
        q.push(root);

        // Continue traversing as long as there are nodes in the queue
        while (!q.empty())
        {
            int size = q.size(); // Number of nodes at the current level
            vector<int> level;   // Vector to store values of the current level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // If a left child exists, queue it for the next level
                if (node->left)
                {
                    q.push(node->left);
                }

                // If a right child exists, queue it for the next level
                if (node->right)
                {
                    q.push(node->right);
                }

                // Add the current node's value to the level's vector
                level.push_back(node->val);
            }

            // Add the completed level to the final answer
            ans.push_back(level);
        }

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    // Constructing a sample test tree: [3, 9, 20, null, null, 15, 7]
    //      3
    //     / \
    //    9  20
    //       / \
    //      15  7
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;

    // Execute the traversal
    vector<vector<int>> result = solution.levelOrder(root);

    // Output the result to the console
    cout << "Level Order Traversal: [" << endl;
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ",";
        cout << endl;
    }
    cout << "]" << endl;

    // Clean up dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}