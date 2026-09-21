/**
 * ============================================================================
 * LeetCode 236: Lowest Common Ancestor of a Binary Tree
 * ============================================================================
 *
 * Problem Statement:
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree. The LCA is defined between two nodes p and q as the
 * lowest node in T that has both p and q as descendants (where we allow a
 * node to be a descendant of itself).
 *
 * Approach Used: Depth-First Search (DFS) / Post-order Traversal
 * 1. Base Cases: If we reach a null node, or if the current node is exactly
 *    `p` or `q`, we immediately return the current node. This signals to the
 *    parent calls that we found a target.
 * 2. Recursive Step: We recursively search the left and right subtrees.
 * 3. Merge Step:
 *    - If BOTH left and right recursive calls return non-null, it means `p`
 *      and `q` are split across the current node's left and right branches.
 *      Therefore, the current `root` MUST be their Lowest Common Ancestor!
 *    - If only ONE subtree returns a non-null node, it means both `p` and `q`
 *      are located in that subtree (or one is found and the other is its descendant).
 *      We pass that non-null node further up the chain.
 *    - If BOTH return null, neither `p` nor `q` exists in this subtree.
 *
 * Complexity:
 * - Time Complexity: O(N) -> In the worst case, we visit every node exactly once.
 * - Space Complexity: O(H) -> Where H is the height of the tree. This accounts
 *   for the maximum depth of the recursion call stack.
 * ============================================================================
 */

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *f(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base case: If we hit a null node, or find either p or q
        if (!root || root == p || root == q)
        {
            if (!root)
                return NULL;
            return root;
        }

        // Search left and right subtrees
        TreeNode *left = f(root->left, p, q);
        TreeNode *right = f(root->right, p, q);

        // If only the right subtree found a target, pass it up
        if (right && !left)
            return right;
        // If only the left subtree found a target, pass it up
        else if (!right && left)
            return left;
        // If neither found a target, return null
        else if (!right && !left)
            return NULL;

        // If BOTH left and right found targets, THIS root is the LCA!
        return root;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return f(root, p, q);
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case Tree Construction:
    //         3
    //       /   \
    //      5     1
    //     / \   / \
    //    6   2 0   8
    //       / \
    //      7   4
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    cout << "Tree Structure:" << endl;
    cout << "        3        " << endl;
    cout << "      /   \\      " << endl;
    cout << "     5     1     " << endl;
    cout << "    / \\   / \\    " << endl;
    cout << "   6   2 0   8   " << endl;
    cout << "      / \\        " << endl;
    cout << "     7   4       " << endl;
    cout << "-----------------------------------" << endl;

    // Test Case 1: Nodes on different branches
    // p = 5, q = 1 (LCA should be 3)
    TreeNode *p1 = root->left;  // Node 5
    TreeNode *q1 = root->right; // Node 1
    TreeNode *lca1 = solution.lowestCommonAncestor(root, p1, q1);

    cout << "Test Case 1:" << endl;
    cout << "p = 5, q = 1" << endl;
    cout << "Lowest Common Ancestor: " << (lca1 ? to_string(lca1->val) : "NULL") << endl;
    // Expected: 3

    cout << "-----------------------------------" << endl;

    // Test Case 2: One node is a descendant of the other
    // p = 5, q = 4 (LCA should be 5)
    TreeNode *p2 = root->left;               // Node 5
    TreeNode *q2 = root->left->right->right; // Node 4
    TreeNode *lca2 = solution.lowestCommonAncestor(root, p2, q2);

    cout << "Test Case 2:" << endl;
    cout << "p = 5, q = 4" << endl;
    cout << "Lowest Common Ancestor: " << (lca2 ? to_string(lca2->val) : "NULL") << endl;
    // Expected: 5

    // Clean up dynamically allocated memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}