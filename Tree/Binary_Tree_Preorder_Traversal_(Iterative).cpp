/**
 * ============================================================================
 * LeetCode 144: Binary Tree Preorder Traversal (Iterative)
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 *
 * Approach Used: Iterative Depth-First Search (DFS) using a Stack
 * Preorder traversal follows the order: Root -> Left -> Right.
 * Instead of the call stack (recursion), we manually use a `stack` data structure.
 * 1. If the root is NULL, return an empty array.
 * 2. Push the root node onto the stack.
 * 3. While the stack is not empty:
 *    - Pop the top node and add its value to our answer array (Root).
 *    - Push the RIGHT child into the stack first.
 *    - Push the LEFT child into the stack second.
 *    * Why right first? Because a stack is Last-In-First-Out (LIFO).
 *      By pushing the right child first, the left child ends up on top,
 *      ensuring it gets processed before the right child.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node in the tree exactly once.
 * - Space Complexity: O(H) -> Where H is the height of the tree. In the worst
 *   case (a skewed tree), the stack size could be O(N).
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <stack> // Required for the iterative stack approach

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st; // Stack to simulate recursive calls
        vector<int> ans;      // Array to store the traversal result

        // Base case: if the tree is empty
        if (!root)
            return ans;

        // Start by pushing the root node
        st.push(root);

        // Process nodes until the stack is empty
        while (!st.empty())
        {
            // Retrieve and remove the node at the top of the stack
            TreeNode *node = st.top();
            st.pop();

            // Step 1: Visit the Root
            ans.push_back(node->val);

            // Step 2: Push the RIGHT child first
            // It gets pushed first so that it sits at the bottom of the stack,
            // meaning it will be processed AFTER the left child.
            if (node->right)
            {
                st.push(node->right);
            }

            // Step 3: Push the LEFT child second
            // It gets pushed last so that it sits at the top of the stack,
            // meaning it will be processed NEXT.
            if (node->left)
            {
                st.push(node->left);
            }
        }

        return ans;
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

    // Execute the iterative traversal
    vector<int> result = solution.preorderTraversal(root);

    // Output the result to the console
    cout << "Iterative Preorder Traversal: [ ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << "]" << endl;

    // Clean up dynamically allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}