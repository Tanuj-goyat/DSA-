/**
 * ============================================================================
 * LeetCode 124: Binary Tree Maximum Path Sum
 * ============================================================================
 *
 * Problem Statement:
 * A path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. A node can only appear
 * in the sequence at most once. The path sum is the sum of the node's values
 * in the path. Given the root of a binary tree, return the maximum path sum
 * of any non-empty path.
 *
 * Approach Used: Bottom-Up Depth-First Search (DFS)
 * 1. We use a recursive helper function `f(root)` to calculate the maximum
 *    path sum branching down from the current node.
 * 2. We compute the max path sum of the left and right subtrees (`lv` and `rv`).
 *    Crucially, we use `max(0, ...)` to ignore paths that have a negative sum,
 *    as they would only decrease our total path sum.
 * 3. At each node, we calculate the local maximum path sum passing *through*
 *    the current node as the "bridge": `root->val + lv + rv`.
 * 4. We maintain a global reference variable `maxi` and update it if this
 *    local path sum is the largest we've seen so far.
 * 5. Finally, the function returns the maximum path sum extending down from the
 *    current node into at most *one* of its children (`root->val + max(lv, rv)`).
 *    This allows the parent node to continue the path.
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
#include <climits>   // Required for INT_MIN

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
    // Helper function to find max branch sum and update global max path sum
    int f(TreeNode *root, int &maxi)
    {
        // Base case: null node contributes 0 to the sum
        if (!root)
            return 0;

        // Recursively get the max path sum of left and right branches.
        // If a branch sum is negative, we drop it by replacing it with 0 (using max).
        int lv = max(0, f(root->left, maxi));
        int rv = max(0, f(root->right, maxi));

        // The maximum path sum passing *through* the current node (bridging left & right)
        maxi = max(maxi, (root->val + lv + rv));

        // Return the max sum of a path extending down only ONE branch (so the parent can use it)
        return (root->val + max(rv, lv));
    }

    int maxPathSum(TreeNode *root)
    {
        // Initialize ans to the smallest possible integer
        // (to handle trees where all nodes contain negative values)
        int ans = INT_MIN;

        // Call the helper function. We pass 'ans' by reference.
        int demo = f(root, ans);

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: [1, 2, 3]
    //       1
    //      / \
    //     2   3
    // The optimal path is 2 -> 1 -> 3 with a sum of 2 + 1 + 3 = 6.
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    cout << "Test Case 1: " << endl;
    cout << "Max Path Sum: " << solution.maxPathSum(root1) << endl; // Expected: 6
    cout << "-----------------------------------" << endl;

    // Test Case 2: [-10, 9, 20, null, null, 15, 7]
    //      -10
    //      /  \
    //     9   20
    //        /  \
    //       15   7
    // The optimal path is 15 -> 20 -> 7 with a sum of 15 + 20 + 7 = 42.
    TreeNode *root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);

    cout << "Test Case 2: " << endl;
    cout << "Max Path Sum: " << solution.maxPathSum(root2) << endl; // Expected: 42

    // Clean up dynamically allocated memory
    delete root1->right;
    delete root1->left;
    delete root1;

    delete root2->right->right;
    delete root2->right->left;
    delete root2->right;
    delete root2->left;
    delete root2;

    return 0;
}