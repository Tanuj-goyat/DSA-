#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Reverse Linked List
Platform: LeetCode
Problem Number: 206
========================================================

Problem Statement:
Given the head of a singly linked list, reverse the list,
and return the reversed list.

Example:
Input:
1 → 2 → 3 → 4 → 5

Output:
5 → 4 → 3 → 2 → 1

========================================================
Approach (Iterative - 3 Pointers)

We maintain three pointers:

1️⃣ prev   → previous node
2️⃣ curr   → current node
3️⃣ next   → next node

Steps:
- Reverse link (curr → prev)
- Move all pointers forward

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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* next = curr->next; // store next

            curr->next = prev;           // reverse link

            prev = curr;                 // move prev
            curr = next;                 // move curr
        }

        return prev;
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

    head = obj.reverseList(head);

    cout << "Reversed List:\n";
    printList(head);

    return 0;
}