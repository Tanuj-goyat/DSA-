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
 * Approach Used: Top-Down Recursion
 * 1. We use a helper function `len(root)` that calculates the maximum depth
 *    (height) of a given subtree.
 * 2. In the main `isBalanced` function, we first handle the base case: an
 *    empty tree is always balanced.
 * 3. We calculate the height of the left subtree (`l`) and right subtree (`r`).
 * 4. If the absolute difference between `l` and `r` is strictly greater than 1,
 *    the tree is not balanced at this current node, so we return false.
 * 5. If the current node is balanced, we recursively call `isBalanced` on both
 *    the left and right children to ensure every single node in the tree also
 *    satisfies the height-balance property.
 *
 * Complexity:
 * - Time Complexity: O(N^2) in the worst case -> For every node, we traverse
 *   its descendants to calculate the height. In a perfectly balanced tree,
 *   this is O(N log N), but in a skewed tree, it degrades to O(N^2).
 * - Space Complexity: O(N) -> The recursion call stack can go as deep as the
 *   height of the tree, which is O(N) in the worst case (skewed tree).
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
    // Helper function to calculate the maximum depth (height) of a subtree
    int len(TreeNode *root)
    {
        if (!root)
            return 0; // Base case: empty node has height 0

        int lef = len(root->left); // Height of left subtree
        int rh = len(root->right); // Height of right subtree

        return 1 + max(lef, rh); // Current height is 1 + max of children's heights
    }

    // Main function to check if the tree is balanced
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true; // Base case: an empty tree is balanced

        // Step 1: Get the height of the left and right subtrees
        int l = len(root->left);
        int r = len(root->right);

        // Step 2: Check if the current node violates the balance condition
        if (abs(l - r) > 1)
            return false;

        // Step 3: Recursively check if the left and right subtrees are balanced
        bool lef = isBalanced(root->left);
        bool rh = isBalanced(root->right);

        // If either subtree is unbalanced, the whole tree is unbalanced
        if (!lef || !rh)
            return false;

        // If we passed all checks, the tree rooted at this node is balanced
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