/**
 * ============================================================================
 * Problem: Preorder, Inorder, and Postorder Traversals in One Pass
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a Binary Tree, return its Preorder, Inorder, and Postorder
 * traversals in a single 2D array.
 *
 * Approach Used: Iterative Stack with State Tracking
 * Instead of doing three separate recursive traversals, we can do it in one pass
 * using a Stack that stores a pair: {TreeNode*, state}.
 * The 'state' tells us how many times we've visited this node:
 * - State 1 (First visit): We are at the root. Add to Preorder. Increment state
 *   to 2, and push the left child (if any) to the stack.
 * - State 2 (Second visit, returning from left): Add to Inorder (mid). Increment
 *   state to 3, and push the right child (if any) to the stack.
 * - State 3 (Third visit, returning from right): Add to Postorder. We are done
 *   with this node, so we pop it from the stack.
 *
 * Complexity:
 * - Time Complexity: O(N) -> Every node is pushed to the stack once and visited
 *   exactly 3 times. Thus, the time is strictly linear.
 * - Space Complexity: O(N) -> We use a stack which in the worst case (skewed tree)
 *   takes O(N) space. We also use O(N) space for the result vectors.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
#include <utility> // Required for pair

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> treeTraversal(TreeNode *root)
    {
        // Stack stores the node and its current "state" (1, 2, or 3)
        stack<pair<TreeNode *, int>> st;

        vector<int> pre;  // Preorder traversal
        vector<int> post; // Postorder traversal
        vector<int> mid;  // Inorder traversal

        // Edge case: empty tree
        if (root == nullptr)
            return {mid, pre, post};

        // Push the root with initial state 1
        st.push({root, 1});

        while (!st.empty())
        {
            auto it = st.top();

            // STATE 1: First time visiting the node (Preorder phase)
            if (it.second == 1)
            {
                pre.push_back(it.first->data); // Add to Preorder
                it.second++;                   // Move to state 2
                st.top() = it;                 // Update the top of the stack

                // Traverse left
                if (it.first->left != NULL)
                {
                    st.push({it.first->left, 1});
                }
            }
            // STATE 2: Second time visiting, returning from left (Inorder phase)
            else if (it.second == 2)
            {
                mid.push_back(it.first->data); // Add to Inorder
                it.second++;                   // Move to state 3
                st.top() = it;                 // Update the top of the stack

                // Traverse right
                if (it.first->right != NULL)
                {
                    st.push({it.first->right, 1});
                }
            }
            // STATE 3: Third time visiting, returning from right (Postorder phase)
            else
            {
                post.push_back(it.first->data); // Add to Postorder
                st.pop();                       // Completely done with this node
            }
        }

        // Combine all traversals into a single 2D vector
        // Order required by your return statement: {Inorder, Preorder, Postorder}
        vector<vector<int>> ans = {mid, pre, post};
        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    // Constructing a sample test tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;

    // Execute the traversal
    vector<vector<int>> result = solution.treeTraversal(root);

    // Output the results to the console
    cout << "Inorder (Mid): [ ";
    for (int val : result[0])
        cout << val << " ";
    cout << "]" << endl;

    cout << "Preorder:      [ ";
    for (int val : result[1])
        cout << val << " ";
    cout << "]" << endl;

    cout << "Postorder:     [ ";
    for (int val : result[2])
        cout << val << " ";
    cout << "]" << endl;

    // Expected Output:
    // Inorder (Mid): [ 4 2 5 1 3 ]
    // Preorder:      [ 1 2 4 5 3 ]
    // Postorder:     [ 4 5 2 3 1 ]

    // Clean up dynamically allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}