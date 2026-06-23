#include <iostream>
using namespace std;

/*
========================================================
Problem: Swap Nodes in Pairs
Platform: LeetCode (24)
========================================================

Problem Statement:
Given a linked list, swap every two
adjacent nodes and return its head.

You must modify the links between nodes
and not the node values.

Example:
Input:
1 -> 2 -> 3 -> 4

Output:
2 -> 1 -> 4 -> 3

========================================================
Approach Used (Iterative Link Manipulation)

Step 1:
Handle edge cases:
- Empty list
- Single node

Step 2:
The second node becomes the new head.

Step 3:
For every pair:
- Store second node
- Reverse links of the pair
- Connect previous pair with current pair

Step 4:
Move to the next pair.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/


// ------------------------------------------------
// Definition for singly-linked list
// ------------------------------------------------
struct ListNode {

    int val;

    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x,
             ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};


class Solution {
public:

    ListNode* swapPairs(ListNode* head) {

        ListNode* temp = head;

        // ------------------------------
        // Edge cases
        // ------------------------------
        if (!head || !head->next)
            return head;

        // ------------------------------
        // New head after first swap
        // ------------------------------
        ListNode* newHead =
            head->next;

        ListNode* pre = NULL;

        // ------------------------------
        // Swap nodes pairwise
        // ------------------------------
        while (temp &&
               temp->next) {

            ListNode* front =
                temp->next;

            // Connect previous pair
            if (pre) {

                pre->next = front;
            }

            // Swap current pair
            temp->next =
                (temp->next)->next;

            front->next = temp;

            // Update previous pointer
            pre = temp;

            // Move to next pair
            temp = temp->next;
        }

        return newHead;
    }
};


// ------------------------------------------------
// Helper function
// ------------------------------------------------
void printList(ListNode* head) {

    while (head) {

        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}


int main() {

    // 1 -> 2 -> 3 -> 4

    ListNode* head =
        new ListNode(1,
        new ListNode(2,
        new ListNode(3,
        new ListNode(4))));

    Solution obj;

    head = obj.swapPairs(head);

    cout << "Swapped List:\n";

    printList(head);

    return 0;
}