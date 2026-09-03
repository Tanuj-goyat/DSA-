/**
 * ============================================================================
 * Problem: Top View of Binary Tree (GFG)
 * ============================================================================
 *
 * Problem Statement:
 * Given a binary tree, print the top view of it. The top view of a binary
 * tree is the set of nodes visible when the tree is viewed from the top.
 * The output nodes should be printed from left to right.
 *
 * Approach Used: Breadth-First Search (BFS) with a Map
 * 1. We use a queue to perform a level-order traversal (BFS). We store pairs
 *    of `(Node*, horizontal_distance)`. The root is at horizontal distance 0.
 * 2. We use a `map<int, int>` to store the first node we see at each
 *    horizontal distance.
 *    - Because we are doing BFS, the first node we encounter at any horizontal
 *      distance is guaranteed to be the highest one (the one visible from the top).
 * 3. Moving to the left child decreases the horizontal distance by 1.
 * 4. Moving to the right child increases the horizontal distance by 1.
 * 5. Because we use a `std::map`, the horizontal distances (keys) are
 *    automatically sorted from smallest (leftmost) to largest (rightmost).
 * 6. Finally, we iterate through the map and extract the values into our result.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> Where N is the number of nodes. We visit
 *   every node once, and inserting into a `map` takes O(log N) time.
 * - Space Complexity: O(N) -> The queue and map will take O(N) space in the
 *   worst-case scenario.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
        vector<int> ans;

        // Base case: If the tree is empty, return an empty result
        if (!root)
            return ans;

        // Map stores horizontal distance -> node data
        map<int, int> view;

        // Queue stores pairs of (node, horizontal distance)
        queue<pair<Node *, int>> q;

        // Start with the root at horizontal distance 0
        q.push({root, 0});

        while (!q.empty())
        {

            auto box = q.front();
            q.pop();

            Node *node = box.first;
            int level = box.second; // Represents horizontal distance

            // If this horizontal distance hasn't been seen yet, save the node's data.
            // Since it's BFS, the first node seen at this distance is the top-most.
            if (view.find(level) == view.end())
                view[level] = node->data;

            // Go left: horizontal distance decreases by 1
            if (node->left)
            {
                q.push({node->left, level - 1});
            }

            // Go right: horizontal distance increases by 1
            if (node->right)
            {
                q.push({node->right, level + 1});
            }
        }

        // Extract values from the map (automatically sorted left to right)
        for (auto x : view)
        {
            ans.push_back(x.second);
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
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
    //
    // Horizontal distances:
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