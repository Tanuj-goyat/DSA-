/**
 * ============================================================================
 * LeetCode 199: Binary Tree Right Side View
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it. Return the values of the nodes you can see ordered from top to bottom.
 *
 * Approach Used: Depth-First Search (DFS) with Right-First Traversal
 * 1. We use a recursive DFS approach to traverse the tree, keeping track of
 *    the current `level` (depth) of each node.
 * 2. Traversal Order: We intentionally make the recursive call to the `right`
 *    child BEFORE the `left` child.
 * 3. Level Tracking: We use an `unordered_map` to store the rightmost node
 *    for each level. Because we always explore the right side first, the
 *    VERY FIRST time we reach a new `level`, the size of our map will be exactly
 *    equal to that `level` (e.g., at level 0, size is 0; at level 1, size is 1).
 * 4. When `level == m.size()` is true, we record the node's value. Any subsequent
 *    nodes found at this same level (from the left branches) will fail this
 *    condition and be ignored.
 * 5. Finally, we iterate from 0 to the map's size to build our resulting array.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node exactly once.
 * - Space Complexity: O(H) -> Where H is the height of the tree. This accounts
 *   for the maximum depth of the recursion call stack, plus the hash map storing
 *   H elements. In the worst case (skewed tree), this is O(N).
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>

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
    void f(TreeNode *root, int level, unordered_map<int, int> &m)
    {
        // Base case: If the node is null, stop recursion
        if (!root)
        {
            return;
        }

        // If the current level equals the map's size, it means this is the
        // first time we are visiting this depth. Because we traverse right first,
        // this is guaranteed to be the rightmost node of this level.
        if (level == m.size())
        {
            m[level] = root->val;
        }

        // Recursively traverse the RIGHT branch first
        f(root->right, level + 1, m);

        // Then recursively traverse the LEFT branch
        f(root->left, level + 1, m);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        unordered_map<int, int> m;

        // Start DFS traversal from the root at level 0
        f(root, 0, m);

        vector<int> ans;

        // The map's size tells us exactly how deep the tree goes.
        // We iterate from 0 to size-1 to maintain the top-to-bottom order.
        for (int i = 0; i < m.size(); i++)
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