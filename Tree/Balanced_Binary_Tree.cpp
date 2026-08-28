/**
 * ============================================================================
 * LeetCode 110: Balanced Binary Tree
 * ============================================================================
 *
 * Problem Statement:
 * Given a binary tree, determine if it is height-balanced.
 * A height-balanced binary tree is defined as a binary tree in which the left
 * and right subtrees of every node differ in height by no more than 1.
 *
 * Approach Used: Bottom-Up Recursion (Optimized)
 * 1. We use a helper function `len(root)` that calculates the height of the
 *    tree, but with a twist: it returns -1 if the tree is unbalanced.
 * 2. We recursively find the height of the left (`lh`) and right (`rh`) subtrees.
 * 3. If either subtree returns -1, it means an imbalance was found deeper in
 *    the tree. We immediately propagate this -1 upwards.
 * 4. We also check the current node: if the absolute difference between `lh`
 *    and `rh` is greater than 1, the current node is unbalanced, so we return -1.
 * 5. If it is balanced, we return its actual height: `1 + max(lh, rh)`.
 * 6. Finally, `isBalanced` just checks if the total height returned is -1.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit each node exactly once in a bottom-up
 *   fashion, completely avoiding the repeated work of the top-down approach.
 * - Space Complexity: O(H) -> Where H is the height of the tree. This accounts
 *   for the recursion call stack. In the worst case (skewed tree), it's O(N).
 * ============================================================================
 */

#include <iostream>
#include <algorithm> // Required for max()
#include <cmath>     // Required for abs()

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
    // Helper function that returns the height of the tree,
    // or -1 if the tree is unbalanced at any point.
    int len(TreeNode *root)
    {
        if (!root)
            return 0; // Base case: height of empty tree is 0

        int lh = len(root->left);  // Get left subtree height
        int rh = len(root->right); // Get right subtree height

        // If left is unbalanced, right is unbalanced, or the current node is unbalanced
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
        {
            return -1; // Propagate the unbalanced signal upwards
        }

        // If balanced, return the actual height of this subtree
        return 1 + max(lh, rh);
    }

    // Main function to check if the tree is balanced
    bool isBalanced(TreeNode *root)
    {
        int ans = len(root);

        // If our helper function returned -1, an imbalance was found
        if (ans == -1)
            return false;

        return true;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Balanced Tree -> [3, 9, 20, null, null, 15, 7]
    //      3
    //     / \
    //    9  20
    //       / \
    //      15  7
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Test Case 1 (Balanced): "
         << (solution.isBalanced(root1) ? "true" : "false") << endl; // Expected: true

    // Test Case 2: Unbalanced Tree -> [1, 2, 2, 3, 3, null, null, 4, 4]
    //         1
    //        / \
    //       2   2
    //      / \
    //     3   3
    //    / \
    //   4   4
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "Test Case 2 (Unbalanced): "
         << (solution.isBalanced(root2) ? "true" : "false") << endl; // Expected: false

    // Clean up dynamically allocated memory
    delete root1->right->right;
    delete root1->right->left;
    delete root1->right;
    delete root1->left;
    delete root1;

    delete root2->left->left->right;
    delete root2->left->left->left;
    delete root2->left->right;
    delete root2->left->left;
    delete root2->right;
    delete root2->left;
    delete root2;

    return 0;
}