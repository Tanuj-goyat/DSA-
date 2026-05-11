#include <iostream>
using namespace std;

/*
========================================================
Problem: Linked List Cycle II
Platform: LeetCode (142)
========================================================

Problem Statement:
Given the head of a linked list,
return the node where the cycle begins.

If there is no cycle, return NULL.

Example:
Input:
3 → 2 → 0 → -4
     ↑       ↓
     ← ← ← ←

Output:
Node with value 2

========================================================
Approach Used (Floyd's Cycle Detection):

Step 1:
Use slow and fast pointers
- slow moves 1 step
- fast moves 2 steps

Step 2:
If they meet → cycle exists

Step 3:
Move slow to head

Step 4:
Move both one step at a time

Step 5:
Point where they meet again
is the start of cycle

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

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

    ListNode* detectCycle(ListNode* head) {

        // ------------------------------
        // Edge cases
        // ------------------------------
        if (!head || !head->next)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // ------------------------------
        // Step 1: Detect cycle
        // ------------------------------
        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast)
                break;
        }

        // ------------------------------
        // No cycle exists
        // ------------------------------
        if (!fast || !fast->next)
            return NULL;

        // ------------------------------
        // Step 2: Find cycle start
        // ------------------------------
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};


// Helper function
void printCycleStart(ListNode* node) {

    if (node)
        cout << "Cycle starts at node: "
             << node->val << endl;
    else
        cout << "No cycle\n";
}


int main() {

    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Create list
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle
    fourth->next = second;

    Solution obj;

    ListNode* ans = obj.detectCycle(head);

    printCycleStart(ans);

    return 0;
}