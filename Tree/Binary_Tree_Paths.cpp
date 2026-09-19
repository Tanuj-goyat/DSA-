/**
 * ============================================================================
 * LeetCode 257: Binary Tree Paths
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * A leaf is a node with no children.
 *
 * Approach Used: Depth-First Search (DFS) with String Concatenation
 * 1. We use a recursive DFS helper function `f` that carries the current path
 *    as a string `s`.
 * 2. At each node, we append the node's value to the current string `s`.
 * 3. Base Case (Leaf Node): If both the left and right children are null,
 *    we have reached a leaf. We push the completed path string into our `result`
 *    vector and return.
 * 4. Recursive Step: If a left or right child exists, we recursively call `f`
 *    for that child, appending "->" to the string.
 * 5. Because the string `s` is passed by value (not by reference), each recursive
 *    branch gets its own independent copy of the string. This elegantly removes
 *    the need to manually backtrack or erase characters from the string after
 *    exploring a branch.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node exactly once. (Note: String
 *   concatenation creates copies, which can technically push this to O(N * H)
 *   where H is the height of the tree).
 * - Space Complexity: O(H) -> Where H is the height of the tree. This accounts
 *   for the recursion call stack.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>

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
    void f(vector<string> &result, TreeNode *root, string s)
    {
        // Append the current node's value to the path
        s += to_string(root->val);

        // Base Case: If it's a leaf node, add the completed path to the result
        if (!root->left && !root->right)
        {
            result.push_back(s);
            return;
        }

        // Recursively traverse the left subtree if it exists
        if (root->left)
        {
            f(result, root->left, s + "->");
        }

        // Recursively traverse the right subtree if it exists
        if (root->right)
        {
            f(result, root->right, s + "->");
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;

        if (!root)
            return result;

        // Start the DFS from the root with an empty initial string
        f(result, root, "");

        return result;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1:
    //        1
    //      /   \
    //     2     3
    //      \
    //       5
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);

    cout << "Test Case 1:" << endl;
    vector<string> result1 = solution.binaryTreePaths(root1);

    cout << "Paths: [ ";
    for (size_t i = 0; i < result1.size(); ++i)
    {
        cout << "\"" << result1[i] << "\"" << (i < result1.size() - 1 ? ", " : "");
    }
    cout << " ]" << endl;
    // Expected Output: [ "1->2->5", "1->3" ]

    cout << "-----------------------------------" << endl;

    // Test Case 2: Single Node Tree
    //        1
    TreeNode *root2 = new TreeNode(1);

    cout << "Test Case 2:" << endl;
    vector<string> result2 = solution.binaryTreePaths(root2);

    cout << "Paths: [ ";
    for (size_t i = 0; i < result2.size(); ++i)
    {
        cout << "\"" << result2[i] << "\"" << (i < result2.size() - 1 ? ", " : "");
    }
    cout << " ]" << endl;
    // Expected Output: [ "1" ]

    // Clean up dynamically allocated memory
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2;

    return 0;
}