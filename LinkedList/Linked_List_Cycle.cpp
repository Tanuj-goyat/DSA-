#include <iostream>
using namespace std;

/*
========================================================
Problem: Linked List Cycle
Platform: LeetCode (141)
========================================================

Problem Statement:
Given the head of a linked list,
determine whether the linked list
contains a cycle.

Return true if cycle exists,
otherwise return false.

Example:
Input:
3 -> 2 -> 0 -> -4
     ↑       ↓
     ← ← ← ←

Output:
true

========================================================
Approach Used (Floyd's Cycle Detection):

Step 1:
Use two pointers:
- slow moves 1 step
- fast moves 2 steps

Step 2:
If cycle exists,
both pointers will meet

Step 3:
If fast reaches NULL,
cycle does not exist

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/


// Linked List Node
struct ListNode {

    int val;
    ListNode* next;

    ListNode(int x) {

        val = x;

        next = NULL;
    }
};


class Solution {
public:

    bool hasCycle(ListNode* head) {

        // Slow pointer
        ListNode* slow = head;

        // Fast pointer
        ListNode* fast = head;

        // ------------------------------
        // Floyd's Cycle Detection
        // ------------------------------
        while (fast && fast->next) {

            // Move slow by 1
            slow = slow->next;

            // Move fast by 2
            fast = (fast->next)->next;

            // Cycle detected
            if (slow == fast)
                return true;
        }

        // No cycle
        return false;
    }
};


// Helper function
void printResult(bool ans) {

    if (ans)
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle\n";
}


int main() {

    // Create nodes
    ListNode* head = new ListNode(3);

    ListNode* second = new ListNode(2);
    ListNode* third  = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Connect list
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle
    fourth->next = second;

    Solution obj;

    bool result = obj.hasCycle(head);

    printResult(result);

    return 0;
}