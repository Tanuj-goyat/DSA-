#include <iostream>
using namespace std;

/*
========================================================
Problem: Delete the Middle Node of a Linked List
Platform: LeetCode (2095)
========================================================

Problem Statement:
Given the head of a linked list, delete the middle node
and return the modified list.

If there are two middle nodes,
delete the second middle node.

Example:
Input:
1 → 2 → 3 → 4 → 5

Output:
1 → 2 → 4 → 5

========================================================
Approach Used (Slow & Fast Pointer):

Step 1: Use slow and fast pointers
        slow moves 1 step
        fast moves 2 steps

Step 2: Maintain previous pointer (pre)

Step 3: When slow reaches middle,
        remove it using:
        pre->next = slow->next

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:

    ListNode* deleteMiddle(ListNode* head) {

        // ------------------------------
        // Edge case: single node
        // ------------------------------
        if (head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre  = head;

        // ------------------------------
        // Find middle node
        // ------------------------------
        while (fast && fast->next) {

            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // ------------------------------
        // Delete middle node
        // ------------------------------
        pre->next = slow->next;

        return head;
    }
};


// Helper function
void printList(ListNode* head) {

    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}


int main() {

    // Create list:
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    head = obj.deleteMiddle(head);

    cout << "After deleting middle:\n";

    printList(head);

    return 0;
}