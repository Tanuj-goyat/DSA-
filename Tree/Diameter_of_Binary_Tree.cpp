/**
 * ============================================================================
 * LeetCode 543: Diameter of Binary Tree
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return the length of the diameter of the tree.
 * The diameter of a binary tree is the length of the longest path between any
 * two nodes in a tree. This path may or may not pass through the root.
 * The length of a path between two nodes is represented by the number of edges
 * between them.
 *
 * Approach Used: Bottom-Up Depth-First Search (DFS)
 * 1. We use a helper function `f` that essentially calculates the height (max
 *    depth) of the tree.
 * 2. As we recursively calculate the height of the left (`lh`) and right (`rh`)
 *    subtrees, we also compute the diameter passing through the current node.
 * 3. The diameter passing through any node is simply the sum of the heights of
 *    its left and right subtrees (`lh + rh`).
 * 4. We maintain a reference variable `maxi` that keeps track of the maximum
 *    diameter seen so far across all nodes.
 * 5. The helper function returns `1 + max(lh, rh)` to tell its parent node
 *    what its height is.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node in the binary tree exactly
 *   once during our post-order traversal.
 * - Space Complexity: O(H) -> Where H is the height of the tree. This accounts
 *   for the recursion call stack. In the worst case (skewed tree), it's O(N).
 *   In a perfectly balanced tree, it's O(log N).
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
    // Helper function to calculate height and update maximum diameter
    int f(TreeNode *root, int &maxi)
    {
        // Base case: If node is null, its height is 0
        if (!root)
            return 0;

        // Recursively find the height of left and right subtrees
        int lh = f(root->left, maxi);
        int rh = f(root->right, maxi);

        // The longest path passing through this node is lh + rh.
        // Update the global maximum if this path is the longest found so far.
        maxi = max(maxi, lh + rh);

        // Return the height of the tree rooted at this node
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        // Base case: Empty tree has a diameter of 0
        if (!root)
            return 0;

        int ans = 0; // This will hold our maximum diameter

        // Call the helper function. We pass 'ans' by reference.
        // We capture the return value in 'x', though we don't need to use it
        // since our answer is accumulated inside 'ans'.
        int x = f(root, ans);

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: [1, 2, 3, 4, 5]
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    // The longest path is [4,2,1,3] or [5,2,1,3], which has 3 edges.
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    cout << "Test Case 1 (Standard Tree): " << endl;
    cout << "Diameter: " << solution.diameterOfBinaryTree(root1) << endl; // Expected: 3
    cout << "-----------------------------------" << endl;

    // Test Case 2: [1, 2]
    //       1
    //      /
    //     2
    // The longest path is [1,2], which has 1 edge.
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    cout << "Test Case 2 (Two Nodes): " << endl;
    cout << "Diameter: " << solution.diameterOfBinaryTree(root2) << endl; // Expected: 1

    // Clean up dynamically allocated memory
    delete root1->left->right;
    delete root1->left->left;
    delete root1->right;
    delete root1->left;
    delete root1;

    delete root2->left;
    delete root2;

    return 0;
}