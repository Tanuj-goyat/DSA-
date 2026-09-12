/**
 * ============================================================================
 * LeetCode 101: Symmetric Tree
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 * Approach Used: Iterative DFS with Two Stacks
 * 1. We use two stacks to traverse the left and right subtrees simultaneously.
 *    - `st1` handles the left subtree.
 *    - `st2` handles the right subtree.
 * 2. We initialize the stacks by pushing the left and right children of the root.
 * 3. While both stacks are not empty, we pop the top nodes from both:
 *    - If both are NULL, we continue (this is a valid symmetric dead-end).
 *    - If only one is NULL, or their values do not match, the tree is asymmetrical
 *      and we immediately return false.
 * 4. Mirrored Traversal: To maintain symmetry, we must push the children in
 *    opposite orders:
 *    - Push `node1->left` and `node2->right`. (Comparing outer nodes)
 *    - Push `node1->right` and `node2->left`. (Comparing inner nodes)
 * 5. If the loop completes and both stacks are empty, the tree is perfectly symmetric.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node in the binary tree exactly once.
 * - Space Complexity: O(H) -> Where H is the height of the tree. In the worst case
 *   (a completely unbalanced tree), this is O(N), but for a symmetric tree, it
 *   bounds to O(log N) at any given depth.
 * ============================================================================
 */

#include <iostream>
#include <stack>

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
    bool isSymmetric(TreeNode *root)
    {
        // An empty tree is inherently symmetric
        if (!root)
            return true;

        stack<TreeNode *> st1;
        stack<TreeNode *> st2;

        // Initialize the stacks with the immediate children of the root
        st1.push(root->left);
        st2.push(root->right);

        while (!st1.empty() && !st2.empty())
        {
            TreeNode *node1 = st1.top();
            TreeNode *node2 = st2.top();

            st1.pop();
            st2.pop();

            // Both nodes are null, which is perfectly symmetric
            if (!node1 && !node2)
                continue;

            // One node is null while the other isn't, OR their values don't match
            if (!node1 || !node2 || node1->val != node2->val)
            {
                return false;
            }

            // Push the OUTER children to be compared next
            st1.push(node1->left);
            st2.push(node2->right);

            // Push the INNER children to be compared next
            st1.push(node1->right);
            st2.push(node2->left);
        }

        // Ensure no leftover nodes exist in either stack
        return st1.empty() && st2.empty();
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Symmetric Tree
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    3   4 4   3
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    cout << "Test Case 1 (Symmetric):" << endl;
    cout << "Is Symmetric: " << (solution.isSymmetric(root1) ? "true" : "false") << endl;
    // Expected: true

    cout << "-----------------------------------" << endl;

    // Test Case 2: Asymmetric Tree
    //         1
    //       /   \
    //      2     2
    //       \     \
    //        3     3
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    cout << "Test Case 2 (Asymmetric):" << endl;
    cout << "Is Symmetric: " << (solution.isSymmetric(root2) ? "true" : "false") << endl;
    // Expected: false

    // Clean up dynamically allocated memory
    delete root1->left->left;
    delete root1->left->right;
    delete root1->right->left;
    delete root1->right->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->right;
    delete root2->right->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}