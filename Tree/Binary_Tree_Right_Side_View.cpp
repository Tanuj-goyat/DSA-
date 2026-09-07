/**
 * ============================================================================
 * LeetCode 199: Binary Tree Right Side View
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it. Return the values of the nodes you can see ordered from top to bottom.
 *
 * Approach Used: Breadth-First Search (BFS) with Level Tracking
 * 1. We use a queue to perform a level-order traversal (BFS), storing pairs
 *    of `(TreeNode*, current_depth_row)`.
 * 2. We use an `unordered_map` to store the node values at each depth.
 * 3. Crucial Step: Because our BFS processes nodes from left to right, we can
 *    unconditionally overwrite the value in our map (`m[row] = node->val`).
 *    The last node processed at any given row will naturally be the rightmost
 *    node visible from the side!
 * 4. We manually track the maximum depth (`depth`) to avoid the O(log N)
 *    overhead of a sorted `std::map`.
 * 5. Finally, we iterate from row 0 down to `depth` to extract the right side
 *    view from top to bottom.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node exactly once. Hash map
 *   insertions/updates take O(1) average time.
 * - Space Complexity: O(N) -> The queue and hash map take O(N) space to store
 *   the nodes and depth information.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm> // Required for max()

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        // Map stores row_depth -> node_val
        unordered_map<int, int> m;
        int depth = 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            TreeNode *node = p.first;
            int row = p.second;

            // Track the deepest row we've seen so far
            depth = max(depth, row);

            // Unconditionally overwrite the map. The last node processed
            // at this row will be the rightmost node!
            m[row] = node->val;

            // Enqueue left child, then right child
            if (node->left)
            {
                q.push({node->left, row + 1});
            }
            if (node->right)
            {
                q.push({node->right, row + 1});
            }
        }

        // Reconstruct the array from top (row 0) to bottom (max depth)
        for (int i = 0; i <= depth; i++)
        {
            ans.push_back(m[i]);
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

    // Test Case 1: Standard Tree
    //      1            <--- Right View: 1
    //    /   \
    //   2     3         <--- Right View: 3
    //    \     \
    //     5     4       <--- Right View: 4
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(4);

    cout << "Test Case 1 (Standard Tree):" << endl;
    vector<int> result1 = solution.rightSideView(root1);

    cout << "Right Side View: [ ";
    for (int val : result1)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
    // Expected Output: [ 1 3 4 ]

    cout << "-----------------------------------" << endl;

    // Test Case 2: Left branch is deeper than right branch
    //      1            <--- Right View: 1
    //    /   \
    //   2     3         <--- Right View: 3
    //  /
    // 4                 <--- Right View: 4
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);

    cout << "Test Case 2 (Left Branch Deeper):" << endl;
    vector<int> result2 = solution.rightSideView(root2);

    cout << "Right Side View: [ ";
    for (int val : result2)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
    // Expected Output: [ 1 3 4 ]

    // Clean up dynamically allocated memory
    delete root1->left->right;
    delete root1->right->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}