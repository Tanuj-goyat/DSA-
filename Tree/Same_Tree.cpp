/**
 * ============================================================================
 * LeetCode 100: Same Tree
 * ============================================================================
 *
 * Problem Statement:
 * Given the roots of two binary trees `p` and `q`, write a function to check
 * if they are the same or not. Two binary trees are considered the same if
 * they are structurally identical, and the nodes have the same value.
 *
 * Approach Used: Depth-First Search (DFS) / Pre-order Traversal
 * 1. Base Case 1: If both nodes `p` and `q` are NULL, they are structurally
 *    identical at this point. Return true.
 * 2. Base Case 2: If only one of the nodes is NULL (structural mismatch), OR
 *    if both nodes exist but their values are different (value mismatch),
 *    return false.
 * 3. Recursive Step: Recursively call the function for the left subtrees (`lhs`)
 *    and the right subtrees (`rhs`).
 * 4. Combine: If either the left subtree or the right subtree returns false,
 *    the trees are not identical. Otherwise, they are identical.
 *
 * Complexity:
 * - Time Complexity: O(N) -> Where N is the number of nodes in the smaller tree.
 *   We visit each node at most once.
 * - Space Complexity: O(H) -> Where H is the height of the tree, representing
 *   the depth of the recursion call stack. In the worst case (skewed tree),
 *   this is O(N). In a perfectly balanced tree, it is O(log N).
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // If both nodes are null, they are identical up to this point
        if (!p && !q)
            return true;

        // If one is null and the other isn't, OR their values differ, they don't match
        if ((p && !q) || (!p && q) || (p->val != q->val))
            return false;

        // Recursively check the left children
        bool lhs = isSameTree(p->left, q->left);

        // Recursively check the right children
        bool rhs = isSameTree(p->right, q->right);

        // If either side fails the match, the whole tree is not the same
        if (!lhs || !rhs)
            return false;

        // If it passed all checks, the trees are identical
        return true;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Identical Trees
    // Tree p:      Tree q:
    //    1            1
    //   / \          / \
    //  2   3        2   3
    TreeNode *p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    cout << "Test Case 1 (Identical Trees): "
         << (solution.isSameTree(p1, q1) ? "true" : "false") << endl; // Expected: true

    cout << "-----------------------------------" << endl;

    // Test Case 2: Structurally Different
    // Tree p:      Tree q:
    //    1            1
    //   /              \
    //  2                2
    TreeNode *p2 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode *q2 = new TreeNode(1, nullptr, new TreeNode(2));

    cout << "Test Case 2 (Structurally Different): "
         << (solution.isSameTree(p2, q2) ? "true" : "false") << endl; // Expected: false

    cout << "-----------------------------------" << endl;

    // Test Case 3: Same Structure, Different Values
    // Tree p:      Tree q:
    //    1            1
    //   / \          / \
    //  2   1        1   2
    TreeNode *p3 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode *q3 = new TreeNode(1, new TreeNode(1), new TreeNode(2));

    cout << "Test Case 3 (Different Values): "
         << (solution.isSameTree(p3, q3) ? "true" : "false") << endl; // Expected: false

    // Clean up dynamically allocated memory
    delete p1->left;
    delete p1->right;
    delete p1;
    delete q1->left;
    delete q1->right;
    delete q1;

    delete p2->left;
    delete p2;
    delete q2->right;
    delete q2;

    delete p3->left;
    delete p3->right;
    delete p3;
    delete q3->left;
    delete q3->right;
    delete q3;

    return 0;
}