#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Odd Even Linked List
Platform: LeetCode
Problem Number: 328
========================================================

Problem Statement:
Given the head of a singly linked list, group all the
nodes with odd indices together followed by the nodes
with even indices.

Note:
- Indexing starts from 1 (NOT 0)

Example:
Input:
1 → 2 → 3 → 4 → 5

Output:
1 → 3 → 5 → 2 → 4

========================================================
Approach Used (In-place Re-linking):

Step 1: Maintain two pointers:
        odd  → for odd indexed nodes
        even → for even indexed nodes

Step 2: Store head of even list (first_even)

Step 3: Rearrange links:
        odd connects to next odd
        even connects to next even

Step 4: Attach even list after odd list

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* oddEvenList(ListNode* head) {

        // Edge case
        if (head == NULL || head->next == NULL)
            return head;

        // ------------------------------
        // Step 1: Initialize pointers
        // ------------------------------
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* first_even = even;  // store start of even list

        // ------------------------------
        // Step 2: Rearrange links
        // ------------------------------
        while (even != NULL && even->next != NULL) {

            // Connect odd nodes
            odd->next = even->next;
            odd = odd->next;

            // Connect even nodes
            even->next = odd->next;
            even = even->next;
        }

        // ------------------------------
        // Step 3: Attach even list
        // ------------------------------
        odd->next = first_even;

        return head;
    }
};


// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}


int main() {

    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5)))));

    Solution obj;

    head = obj.oddEvenList(head);

    cout << "Rearranged List:\n";
    printList(head);

    return 0;
}