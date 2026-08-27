/**
 * ============================================================================
 * LeetCode 104: Maximum Depth of Binary Tree
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
 * Approach Used: Recursive Depth-First Search (DFS)
 * 1. Base Case: If the current node is NULL, its depth is 0. This stops the
 *    recursion when we reach beyond a leaf node.
 * 2. Recursive Step: We recursively calculate the maximum depth of the left
 *    subtree and the right subtree.
 * 3. Return Value: The depth of the current node is 1 (for the node itself)
 *    plus the maximum of the depths of its left and right subtrees.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every single node in the binary tree
 *   exactly once to calculate its depth, where N is the number of nodes.
 * - Space Complexity: O(H) -> Where H is the height of the tree. This accounts
 *   for the memory used by the recursion call stack. In the worst case (a
 *   skewed tree), this will be O(N). In the best case (a balanced tree), it
 *   will be O(log N).
 * ============================================================================
 */

#include <iostream>
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
    int maxDepth(TreeNode *root)
    {
        // Base case: If the tree is empty or we reached past a leaf
        if (!root)
            return 0;

        // Recursively find the maximum depth of the left subtree
        int le = maxDepth(root->left);

        // Recursively find the maximum depth of the right subtree
        int rh = maxDepth(root->right);

        // The maximum depth at the current node is 1 + the greater of the two subtree depths
        return 1 + max(le, rh);
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

    // Execute the function
    int depth = solution.maxDepth(root);

    // Output the result to the console
    cout << "Tree structure: [3, 9, 20, null, null, 15, 7]" << endl;
    cout << "Maximum Depth: " << depth << endl; // Expected: 3

    // Clean up dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}