/**
 * ============================================================================
 * LeetCode 94: Binary Tree Inorder Traversal
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 * Approach Used: Recursive Depth-First Search (DFS)
 * Inorder traversal visits nodes in the following order: Left -> Root -> Right.
 * 1. We create a helper function `f` that takes the node and the result vector
 *    by reference.
 * 2. Base Case: If the current node is NULL, we return (stop recursion).
 * 3. Traverse Left: We recursively call the function for the left child.
 * 4. Visit Root: We push the current node's value into our answer vector.
 * 5. Traverse Right: We recursively call the function for the right child.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node in the tree exactly once,
 *   where N is the number of nodes.
 * - Space Complexity: O(N) -> In the worst case (a completely skewed tree),
 *   the recursion stack will take O(N) space. The output vector also takes O(N).
 * ============================================================================
 */

#include <iostream>
#include <vector>

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
    // Helper function to perform the recursive inorder traversal
    void f(TreeNode *root, vector<int> &v)
    {
        // Base case: If the node is null, stop and backtrack
        if (!root)
        {
            return;
        }

        // Step 1: Traverse the Left Subtree
        f(root->left, v);

        // Step 2: Visit the Root (store its value)
        v.push_back(root->val);

        // Step 3: Traverse the Right Subtree
        f(root->right, v);
    }

    // Main function called by LeetCode
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v; // Vector to store the traversal result
        f(root, v);    // Start the recursive traversal
        return v;
    }
};


int main()
{
    // Constructing a sample test tree: [1, null, 2, 3]
    //   1
    //    \
    //     2
    //    /
    //   3
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;

    // Execute the traversal
    vector<int> result = solution.inorderTraversal(root);

    // Output the result to the console
    cout << "Inorder Traversal: [ ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << "]" << endl;

    // Clean up dynamically allocated memory (good practice)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}