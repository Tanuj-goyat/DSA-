/**
 * ============================================================================
 * LeetCode 144: Binary Tree Preorder Traversal
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 *
 * Approach Used: Recursive Depth-First Search (DFS)
 * Preorder traversal visits nodes in the following order: Root -> Left -> Right.
 * 1. We create a helper function `f` that takes the result vector by reference.
 * 2. Base Case: If the current node is NULL, we return (stop recursion).
 * 3. Processing: We push the current node's value into our answer vector.
 * 4. Recursive Calls: We then recursively call the function for the left child,
 *    followed by the right child.
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
    // Helper function to perform the recursive preorder traversal
    void f(vector<int> &ans, TreeNode *root)
    {
        // Base case: If the node is null, stop and backtrack
        if (root == NULL)
        {
            return;
        }

        // Step 1: Visit the Root (store its value)
        ans.push_back(root->val);

        // Step 2: Traverse the Left Subtree
        f(ans, root->left);

        // Step 3: Traverse the Right Subtree
        f(ans, root->right);
    }

    // Main function called by LeetCode
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans; // Vector to store the traversal result
        f(ans, root);    // Start the recursive traversal
        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
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
    vector<int> result = solution.preorderTraversal(root);

    // Output the result to the console
    cout << "Preorder Traversal: [ ";
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