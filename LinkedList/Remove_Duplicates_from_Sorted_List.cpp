#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Remove Duplicates from Sorted List
Platform: LeetCode
Problem Number: 83
========================================================

Problem Statement:
Given the head of a sorted linked list, delete all
duplicates such that each element appears only once.

Return the linked list sorted as well.

Example:
Input:
1 → 1 → 2 → 3 → 3

Output:
1 → 2 → 3

========================================================
Approach (Iterative Traversal)

1️⃣ Since list is sorted:
   → Duplicates will always be adjacent

2️⃣ Traverse the list using a pointer

3️⃣ If current value == next value:
   → skip next node

4️⃣ Else:
   → move forward

========================================================
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
    ListNode* deleteDuplicates(ListNode* head) {

        // Edge case: empty list or single node
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;

        // Traverse list
        while (temp != NULL && temp->next != NULL) {

            // If duplicate found
            if (temp->val == temp->next->val) {

                // Skip duplicate node
                temp->next = temp->next->next;
            }
            else {
                // Move forward
                temp = temp->next;
            }
        }

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

    // Create list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1,
                        new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(3)))));

    Solution obj;

    head = obj.deleteDuplicates(head);

    cout << "After removing duplicates:\n";
    printList(head);

    return 0;
}