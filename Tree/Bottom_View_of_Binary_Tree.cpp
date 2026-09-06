/**
 * ============================================================================
 * Problem: Bottom View of Binary Tree (Optimized O(N) Version) GFG
 * ============================================================================
 *
 * Problem Statement:
 * Given a binary tree, print the bottom view of it. The bottom view of a binary
 * tree is the set of nodes visible when the tree is viewed from the bottom.
 * The output nodes should be printed from left to right. If there are multiple
 * nodes at the same horizontal distance and same level, the one that comes
 * later in the level-order traversal is selected.
 *
 * Approach Used: Breadth-First Search (BFS) with Unordered Map & Min/Max Tracking
 * 1. We use a queue to perform a level-order traversal (BFS), storing pairs
 *    of `(Node*, column_index)`. The root is at column 0.
 * 2. We use an `unordered_map` to store the nodes for each column.
 * 3. Crucial Difference from Top View: We UNCONDITIONALLY overwrite the value
 *    in the map (`m[col] = node->data`). Because BFS traverses level by level,
 *    the last node we process for any given column will naturally be the
 *    bottom-most node!
 * 4. We manually track the leftmost (`maxleft`) and rightmost (`maxright`)
 *    column indices to avoid the O(log N) overhead of a sorted `std::map`.
 * 5. Finally, we iterate from `maxleft` to `maxright` to extract the bottom
 *    view from left to right.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We visit every node exactly once. Hash map
 *   insertions/updates take O(1) average time.
 * - Space Complexity: O(N) -> The queue and hash map take O(N) space.
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
    vector<int> bottomView(Node *root)
    {

        // key : col, value : data
        unordered_map<int, int> m;

        // Track the extreme left and right columns to reconstruct the array later
        int maxleft = 0;
        int maxright = 0;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            Node *node = p.first;
            int col = p.second;

            // Unconditionally overwrite the map. The last node processed
            // at this column will be the one visible from the bottom.
            m[col] = node->data;

            // Dynamically update the minimum and maximum column bounds
            maxleft = min(maxleft, col);
            maxright = max(maxright, col);

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
        for (int i = maxleft; i <= maxright; i++)
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
    //        20
    //      /    \
    //     8      22
    //    / \    /  \
    //   5   3  4    25
    //      / \      
    //     10 14
    //
    // Columns:
    // -2: [5]
    // -1: [8, 10]    -> bottom is 10
    //  0: [20, 3, 4] -> bottom is 4 (or 3, but 4 is processed later in BFS)
    //  1: [22, 14]   -> bottom is 14
    //  2: [25]
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    cout << "Test Case 1 (Bottom View):" << endl;
    vector<int> result1 = solution.bottomView(root);

    cout << "Bottom View: [ ";
    for (int val : result1)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
    // Expected Output: [ 5 10 4 14 25 ]

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