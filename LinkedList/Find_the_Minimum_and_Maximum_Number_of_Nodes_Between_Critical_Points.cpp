/**
 * ============================================================================
 * LeetCode 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points
 * ============================================================================
 *
 * Problem Statement:
 * A critical point in a linked list is defined as either a local maxima or a
 * local minima.
 * - A node is a local maxima if the current node has a value strictly greater
 *   than the previous node and the next node.
 * - A node is a local minima if the current node has a value strictly smaller
 *   than the previous node and the next node.
 *
 * Given a linked list head, return an array of length 2 containing
 * [minDistance, maxDistance] where minDistance is the minimum distance between
 * any two distinct critical points and maxDistance is the maximum distance
 * between any two distinct critical points. If there are fewer than two critical
 * points, return [-1, -1].
 *
 * Approach Used: One-Pass Iteration with Index Tracking
 * 1. Traverse the linked list starting from the second node (index 1).
 * 2. Keep track of the previous node's value (`last`), the current node (`num`),
 *    and the next node (`nexNum`) to detect local minima and maxima.
 * 3. When a critical point is found:
 *    - If it's the very first one, record its index in `first` and `second`.
 *    - For all subsequent critical points, the maximum distance is always the
 *      current index minus the `first` recorded critical point.
 *    - The minimum distance is calculated by comparing the current minimum
 *      against the distance between the current index and the `second`
 *      (which acts as the previously seen critical point).
 *    - Update `second` to the current index.
 * 4. If fewer than 2 critical points were found, handle the fallback to [-1, -1].
 *
 * Complexity:
 * - Time Complexity: O(N) -> We traverse the linked list exactly once.
 * - Space Complexity: O(1) -> We only use a few integer variables for tracking.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for min(), max()
#include <climits>   // Required for INT_MAX

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *temp = head;
        int index = 1;
        vector<int> ans(2, -1);
        ans[0] = INT_MAX;

        int first = -1;  // Tracks the index of the very first critical point
        int second = -1; // Tracks the index of the most recently seen critical point

        int last = head->val; // Stores the value of the previous node
        temp = temp->next;

        while (temp->next)
        {
            int num = temp->val;
            int nexNum = (temp->next)->val;

            // Check if the current node is a local maxima or local minima
            if ((last > num && num < nexNum) || (last < num && num > nexNum))
            {

                // If this is the first critical point found
                if (first == -1)
                {
                    first = index;
                    second = index;
                }
                else
                {
                    // Update max distance: (current index) - (very first critical point)
                    ans[1] = max(ans[1], index - first);

                    // Update min distance: compare current min vs (current index) - (previous critical point)
                    ans[0] = min(ans[0], index - second);

                    // Update the previous critical point to the current one
                    second = index;
                }
            }

            index++;
            last = num;
            temp = temp->next;
        }

        // If no valid distances were found (less than 2 critical points)
        if (ans[1] == -1)
        {
            ans[0] = -1;
        }

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------

// Helper function to create a linked list from a vector
ListNode *createList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *curr = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to free the linked list memory
void freeList(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Solution solution;

    // Test Case 1: [5, 3, 1, 2, 5, 1, 2]
    // Critical points:
    // - Index 2 (val 1): Local minima (3 > 1 < 2)
    // - Index 4 (val 5): Local maxima (2 < 5 > 1)
    // - Index 5 (val 1): Local minima (5 > 1 < 2)
    // Min distance: index 5 - index 4 = 1
    // Max distance: index 5 - index 2 = 3
    vector<int> vals1 = {5, 3, 1, 2, 5, 1, 2};
    ListNode *head1 = createList(vals1);

    cout << "List: [5, 3, 1, 2, 5, 1, 2]" << endl;
    vector<int> res1 = solution.nodesBetweenCriticalPoints(head1);
    cout << "Distances: [" << res1[0] << ", " << res1[1] << "]" << endl;
    // Expected: [1, 3]

    cout << "-----------------------------------" << endl;

    // Test Case 2: [1, 3, 2, 2, 3, 2, 2, 2, 7]
    // Critical points:
    // - Index 1 (val 3): Local maxima
    // - Index 4 (val 3): Local maxima
    // Min distance = 3, Max distance = 3
    vector<int> vals2 = {1, 3, 2, 2, 3, 2, 2, 2, 7};
    ListNode *head2 = createList(vals2);

    cout << "List: [1, 3, 2, 2, 3, 2, 2, 2, 7]" << endl;
    vector<int> res2 = solution.nodesBetweenCriticalPoints(head2);
    cout << "Distances: [" << res2[0] << ", " << res2[1] << "]" << endl;
    // Expected: [3, 3]

    cout << "-----------------------------------" << endl;

    // Test Case 3: [2, 1]
    // Fewer than 2 critical points.
    vector<int> vals3 = {2, 1};
    ListNode *head3 = createList(vals3);

    cout << "List: [2, 1]" << endl;
    vector<int> res3 = solution.nodesBetweenCriticalPoints(head3);
    cout << "Distances: [" << res3[0] << ", " << res3[1] << "]" << endl;
    // Expected: [-1, -1]

    // Clean up memory
    freeList(head1);
    freeList(head2);
    freeList(head3);

    return 0;
}