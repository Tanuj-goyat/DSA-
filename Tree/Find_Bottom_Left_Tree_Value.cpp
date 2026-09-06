/**
 * ============================================================================
 * LeetCode 513: Find Bottom Left Tree Value
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, return the leftmost value in the last row
 * of the tree.
 *
 * Approach Used: Depth-First Search (DFS) using a Stack
 * 1. We use a Stack to perform a pre-order style traversal, storing pairs of
 *    `(TreeNode*, current_row)`.
 * 2. We keep track of the `last` row depth we have seen.
 * 3. Crucial Step: We push the right child onto the stack FIRST, followed by
 *    the left child. Because a stack is LIFO (Last-In-First-Out), this ensures
 *    that for any given level, the leftmost node is popped and processed before
 *    any nodes to its right.
 * 4. Whenever we pop a node and find that its `row` is strictly greater than
 *    `last`, it means this is the very first node we are exploring at this
 *    new depth. Thanks to our push order, it is guaranteed to be the leftmost
 *    node of this new row! We update our `ans` and `last`.
 * 5. The traversal continues until all nodes are visited, leaving `ans` as
 *    the leftmost node of the absolute deepest row.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node in the binary tree exactly once.
 * - Space Complexity: O(H) -> Where H is the height of the tree. This accounts
 *   for the maximum number of nodes stored in the stack at any given time.
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
    int findBottomLeftValue(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});

        int ans = root->val;
        int last = 0; // Tracks the maximum depth seen so far

        while (!st.empty())
        {
            auto p = st.top();
            st.pop();

            TreeNode *node = p.first;
            int row = p.second;

            // If we reached a new deeper row, this must be the leftmost node
            if (row > last)
            {
                ans = node->val;
                last = row;
            }

            // Push right child first so it is processed AFTER the left child
            if (node->right)
            {
                st.push({node->right, row + 1});
            }

            // Push left child second so it is processed NEXT
            if (node->left)
            {
                st.push({node->left, row + 1});
            }
        }

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1:
    //      2
    //     / \
    //    1   3
    // The bottom-left value is 1.
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    cout << "Test Case 1:" << endl;
    cout << "Bottom Left Value: " << solution.findBottomLeftValue(root1) << endl;
    // Expected: 1

    cout << "-----------------------------------" << endl;

    // Test Case 2:
    //        1
    //       / \
    //      2   3
    //     /   / \
    //    4   5   6
    //       /
    //      7
    // The deepest row is the one containing 7, making it the bottom-left value.
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->right->left = new TreeNode(5);
    root2->right->right = new TreeNode(6);
    root2->right->left->left = new TreeNode(7);

    cout << "Test Case 2:" << endl;
    cout << "Bottom Left Value: " << solution.findBottomLeftValue(root2) << endl;
    // Expected: 7

    // Clean up dynamically allocated memory
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->right->left->left;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->left->left;
    delete root2->right;
    delete root2->left;
    delete root2;

    return 0;
}