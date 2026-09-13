/**
 * ============================================================================
 * LeetCode 1721: Swapping Nodes in a Linked List
 * ============================================================================
 *
 * Problem Statement:
 * You are given the head of a linked list, and an integer k.
 * Return the head of the linked list after swapping the values of the kth node
 * from the beginning and the kth node from the end (the list is 1-indexed).
 *
 * Approach Used: Two-Pass Value Swap
 * 1. Step 1 (Calculate Size): Traverse the linked list once to find its total
 *    length using the helper function `tellSize()`.
 * 2. Step 2 (Identify Targets): The first node is at index `k`. The second node
 *    from the end is mathematically at index `size - k + 1` (which we call `k2`).
 * 3. Step 3 (Locate Nodes): Traverse the list a second time. When our `index`
 *    matches `k`, we save the pointer to `node1`. When it matches `k2`, we
 *    save the pointer to `node2`.
 * 4. Step 4 (Early Exit): As a great optimization, once our index reaches the
 *    maximum of `k` and `k2`, we have found both nodes and can safely `break`
 *    out of the loop early.
 * 5. Step 5 (Swap Values): Instead of tangling with next pointers, simply
 *    swap the `val` properties of `node1` and `node2`.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We traverse the list completely once to find the
 *   size, and at most once again to find the nodes.
 * - Space Complexity: O(1) -> We only use a few pointer variables.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for max()

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
    // Helper function to find the total length of the linked list
    int tellSize(ListNode *head)
    {
        ListNode *temp = head;
        int ans = 0;
        while (temp)
        {
            temp = temp->next;
            ans++;
        }
        return ans;
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        // Base case: If the list is empty or has only one node, no swap needed
        if (!head || !head->next)
            return head;

        int size = tellSize(head);
        int k2 = size - k + 1; // 1-based index of the kth node from the end

        ListNode *node1 = nullptr;
        ListNode *node2 = nullptr;
        ListNode *temp = head;
        int index = 0;

        while (temp)
        {
            index++;

            // Capture the first target node
            if (index == k)
                node1 = temp;

            // Capture the second target node
            if (index == k2)
                node2 = temp;

            // Optimization: Stop traversing once both nodes have been found
            if (index >= max(k, k2))
                break;

            temp = temp->next;
        }

        // Swap the values instead of the node pointers
        int data = node1->val;
        node1->val = node2->val;
        node2->val = data;

        return head;
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

// Helper function to print the linked list
void printList(ListNode *head)
{
    ListNode *curr = head;
    cout << "[ ";
    while (curr)
    {
        cout << curr->val << (curr->next ? ", " : " ");
        curr = curr->next;
    }
    cout << "]" << endl;
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

    // Test Case 1: Standard Swap
    // List: [1, 2, 3, 4, 5], k = 2
    // 2nd node is 2. 2nd from end is 4. Swap them.
    vector<int> vals1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    ListNode *head1 = createList(vals1);

    cout << "Original List: ";
    printList(head1);
    cout << "k = " << k1 << endl;

    head1 = solution.swapNodes(head1, k1);
    cout << "Swapped List:  ";
    printList(head1);
    // Expected: [ 1, 4, 3, 2, 5 ]

    cout << "-----------------------------------" << endl;

    // Test Case 2: Swapping the exact same node (middle)
    // List: [7, 9, 6, 6, 7, 8, 3, 0, 9, 5], k = 5
    vector<int> vals2 = {7, 9, 6, 6, 7, 8, 3, 0, 9, 5};
    int k2 = 5;
    ListNode *head2 = createList(vals2);

    cout << "Original List: ";
    printList(head2);
    cout << "k = " << k2 << endl;

    head2 = solution.swapNodes(head2, k2);
    cout << "Swapped List:  ";
    printList(head2);
    // Expected: [ 7, 9, 6, 6, 8, 7, 3, 0, 9, 5 ]

    cout << "-----------------------------------" << endl;

    // Test Case 3: Swapping head and tail
    // List: [1, 2], k = 1
    vector<int> vals3 = {1, 2};
    int k3 = 1;
    ListNode *head3 = createList(vals3);

    cout << "Original List: ";
    printList(head3);
    cout << "k = " << k3 << endl;

    head3 = solution.swapNodes(head3, k3);
    cout << "Swapped List:  ";
    printList(head3);
    // Expected: [ 2, 1 ]

    // Clean up memory
    freeList(head1);
    freeList(head2);
    freeList(head3);

    return 0;
}