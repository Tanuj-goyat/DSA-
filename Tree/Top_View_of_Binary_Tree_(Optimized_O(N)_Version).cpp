/**
 * ============================================================================
 * Problem: Top View of Binary Tree (Optimized O(N) Version)
 * ============================================================================
 *
 * Problem Statement:
 * Given a binary tree, print the top view of it. The top view of a binary
 * tree is the set of nodes visible when the tree is viewed from the top.
 * The output nodes should be printed from left to right.
 *
 * Approach Used: Breadth-First Search (BFS) with Unordered Map & Min/Max Tracking
 * 1. We use a queue to perform a level-order traversal (BFS), storing pairs
 *    of `(Node*, column_index)`. The root is at column 0.
 * 2. We use an `unordered_map` to store the first node seen at each column.
 *    Because we are doing BFS, the first node encountered at any column is
 *    guaranteed to be the highest one (visible from the top).
 * 3. Instead of relying on a self-sorting `std::map` (which costs O(log N) per
 *    insertion), we manually track the leftmost (`start`) and rightmost (`end`)
 *    column indices as we traverse the tree.
 * 4. Finally, we iterate from `start` to `end` and extract the values from our
 *    hash map in perfect left-to-right order.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node exactly once, and insertions
 *   into an `unordered_map` take O(1) average time. Extracting the results
 *   takes O(width_of_tree) time.
 * - Space Complexity: O(N) -> The queue and hash map will take O(N) space in
 *   the worst-case scenario.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm> // Required for min() and max()

using namespace std;

// Definition for a binary tree node.
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> topView(Node *root)
    {

        // key : col, value : data
        unordered_map<int, int> m;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        // Track the extreme left and right columns to reconstruct the array later
        int start = 0;
        int end = 0;

        while (!q.empty())
        {
            auto box = q.front();
            q.pop();

            Node *node = box.first;
            int col = box.second;

            // Dynamically update the minimum and maximum column bounds
            start = min(start, col);
            end = max(end, col);

            // If this column hasn't been recorded yet, store the top-most node's data
            if (m.find(col) == m.end())
            {
                m[col] = node->data;
            }

            // Move left: column decreases by 1
            if (node->left)
            {
                q.push({node->left, col - 1});
            }
            // Move right: column increases by 1
            if (node->right)
            {
                q.push({node->right, col + 1});
            }
        }

        vector<int> result;

        // Loop from the leftmost column to the rightmost column to maintain order
        for (int i = start; i <= end; i++)
        {
            result.push_back(m[i]);
        }

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
    //    / \   / \
    //   4   5 6   7
    //
    // Columns:
    // -2: [4]
    // -1: [2]
    //  0: [1]  (5 and 6 are hidden below 1)
    //  1: [3]
    //  2: [7]
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Test Case 1 (Standard Tree):" << endl;
    vector<int> result1 = solution.topView(root);

    cout << "Top View: [ ";
    for (int val : result1)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
    // Expected Output: [ 4 2 1 3 7 ]

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}