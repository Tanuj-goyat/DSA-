/**
 * ============================================================================
 * LeetCode 114: Flatten Binary Tree to Linked List
 * ============================================================================
 *
 * Problem Statement:
 * Given the root of a binary tree, flatten the tree into a "linked list":
 * - The "linked list" should use the same TreeNode class where the right child
 *   pointer points to the next node in the list and the left child pointer is
 *   always null.
 * - The "linked list" should be in the same order as a pre-order traversal
 *   of the binary tree.
 *
 * Approach Used: Iterative Pre-order Traversal with a Dummy Node
 * 1. We use a Stack to simulate a pre-order traversal (Root -> Left -> Right).
 * 2. We create a dummy `head` node and a `temp` pointer to help build our
 *    flattened list on the fly.
 * 3. We push the root onto the stack. In each iteration, we pop the top node.
 * 4. Crucially, we push the `right` child FIRST, then the `left` child. Because
 *    a stack is LIFO (Last-In-First-Out), pushing right then left ensures we
 *    process the left child next, matching pre-order traversal.
 * 5. We rewire the `temp` pointer's right child to the popped node, set its
 *    left child to NULL, and move `temp` forward.
 * 6. Because we do this in-place using the original tree nodes, the tree itself
 *    is permanently restructured into a linked list!
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node in the binary tree exactly once.
 * - Space Complexity: O(H) -> Where H is the height of the tree, representing
 *   the maximum number of nodes in the stack at any given time. In the worst
 *   case (a skewed tree), this is O(N).
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
    void flatten(TreeNode *root)
    {
        // Base case: If tree is empty, do nothing
        if (!root)
            return;

        // Dummy node to simplify the linked list construction
        TreeNode *head = new TreeNode();
        TreeNode *temp = head;

        // Stack for iterative pre-order traversal
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            // Push right child first so it is processed AFTER the left child
            if (node->right)
            {
                st.push(node->right);
            }

            // Push left child second so it is processed NEXT (top of stack)
            if (node->left)
            {
                st.push(node->left);
            }

            // Rewire the current node into our flattened "linked list"
            temp->right = node;
            temp->left = NULL; // Left child must be nullified

            // Move the temp pointer forward
            temp = temp->right;
        }

        // Redundant for the in-place requirement, but conceptually points to the new root
        root = head->right;

        // Optional best practice: free the dynamically allocated dummy node
        delete head;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard Tree
    //      1
    //     / \
    //    2   5
    //   / \   \
    //  3   4   6
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(6);

    cout << "Flattening Tree: [1, 2, 5, 3, 4, null, 6]" << endl;
    solution.flatten(root1);

    // Output the flattened tree
    cout << "Flattened Result: ";
    TreeNode *curr = root1;
    while (curr)
    {
        cout << curr->val << " -> ";
        curr = curr->right;
    }
    cout << "NULL" << endl;
    // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

    // Clean up dynamically allocated memory for the modified list structure
    curr = root1;
    while (curr)
    {
        TreeNode *nextNode = curr->right;
        delete curr;
        curr = nextNode;
    }

    return 0;
}