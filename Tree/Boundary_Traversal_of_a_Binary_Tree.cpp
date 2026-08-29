/**
 * ============================================================================
 * Problem: Boundary Traversal of a Binary Tree
 * ============================================================================
 *
 * Problem Statement:
 * Given a Binary Tree, find its Boundary Traversal. The traversal should be in
 * the following anti-clockwise order:
 * 1. Root node.
 * 2. Left boundary nodes: defined as the path from the root to the left-most
 *    node (excluding leaf nodes).
 * 3. Leaf nodes: all leaf nodes from left to right.
 * 4. Right boundary nodes: defined as the path from the right-most node back
 *    to the root (excluding leaf nodes and root, ordered bottom-up).
 *
 * Approach Used: Segmented Traversal
 * 1. `isLeaf`: Helper function to check if a node is a leaf.
 * 2. `lb` (Left Boundary): Traverse down the left side. If a left child exists,
 *    go left; otherwise, go right. Stop before hitting a leaf.
 * 3. `leaf` (Leaves): Use a standard pre-order traversal to collect all leaf
 *    nodes from left to right.
 * 4. `rb` (Right Boundary): Traverse down the right side. If a right child exists,
 *    go right; otherwise, go left. Stop before hitting a leaf. Store the values
 *    in a temporary array and reverse them (since we need them bottom-up).
 * 5. Combine the root, left boundary, leaves, and right boundary into one result.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit the left boundary, right boundary, and
 *   traverse the tree for leaves. Every node is visited at most twice.
 * - Space Complexity: O(H) -> Where H is the height of the tree. This accounts
 *   for the recursion stack during the leaf traversal and the temporary vector
 *   used for the right boundary.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
private:
    // Helper function to check if a node is a leaf
    bool isLeaf(Node *root)
    {
        if (root->left || root->right)
            return false;

        return true;
    }

    // Function to collect the left boundary (excluding leaves)
    void lb(Node *root, vector<int> &result)
    {
        if (!root)
            return;

        while (!isLeaf(root))
        {
            result.push_back(root->data);

            // Prefer left child for left boundary; if not, take right
            if (root->left)
                root = root->left;
            else
                root = root->right;
        }
        return;
    }

    // Function to collect all leaf nodes (left to right)
    void leaf(Node *root, vector<int> &result)
    {
        if (!root)
            return;

        if (isLeaf(root))
        {
            result.push_back(root->data);
            return;
        }
        else
        {
            leaf(root->left, result);
            leaf(root->right, result);
        }
        return;
    }

    // Function to collect the right boundary (bottom-up, excluding leaves)
    void rb(Node *root, vector<int> &result)
    {
        if (!root)
            return;

        vector<int> temp;

        while (!isLeaf(root))
        {
            temp.push_back(root->data);

            // Prefer right child for right boundary; if not, take left
            if (root->right)
                root = root->right;
            else
                root = root->left;
        }

        // Reverse the collected right boundary nodes since we need them bottom-up
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            result.push_back(temp[i]);
        }

        return;
    }

public:
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> result;

        // Base case: empty tree
        if (!root)
            return result;

        // Step 1: Add the root (if it's not a leaf to avoid duplication)
        if (!isLeaf(root))
        {
            result.push_back(root->data);
        }

        // Step 2: Add left boundary
        lb(root->left, result);

        // Step 3: Add all leaf nodes
        leaf(root, result);

        // Step 4: Add right boundary
        rb(root->right, result);

        return result;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    // Constructing a sample test tree:
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    //        / \
    //       8   9
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Execute the traversal
    vector<int> result = solution.boundaryTraversal(root);

    // Output the result to the console
    cout << "Boundary Traversal: [ ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << "]" << endl;

    // Expected Output: [ 1 2 4 8 9 6 7 3 ]

    // Clean up dynamically allocated memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}