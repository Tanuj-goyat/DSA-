#include <iostream>
using namespace std;

/*
========================================================
Problem: Add One to Number Represented by Linked List
Platform: Custom / GFG-style
========================================================

Problem Statement:
Given a linked list representing a non-negative number,
add 1 to the number and return the updated list.

Example:
Input:
9 → 9 → 9

Output:
1 → 0 → 0 → 0

========================================================
Approach Used (Recursion + Carry):

Step 1: Traverse till last node using recursion

Step 2: Add carry (initially 1) at last node

Step 3: While returning, propagate carry backward

Step 4: If carry still remains → add new node at front

Time Complexity: O(n)
Space Complexity: O(n) (recursion stack)

========================================================
*/

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    // ------------------------------
    // Step 1: Recursive helper
    // ------------------------------
    void addOneUtil(ListNode* head, int &carry) {

        if (head == NULL)
            return;

        // Go to last node
        addOneUtil(head->next, carry);

        // Add carry while backtracking
        if (carry) {
            int sum = head->val + carry;
            head->val = sum % 10;
            carry = sum / 10;
        }
    }


    // ------------------------------
    // Step 2: Main function
    // ------------------------------
    ListNode* addOne(ListNode* head) {

        int carry = 1;

        addOneUtil(head, carry);

        // If carry remains, add new node at front
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};


// Helper function
void printList(ListNode *head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}


int main() {

    // Example: 9 → 9 → 9
    ListNode *head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    Solution obj;

    head = obj.addOne(head);

    cout << "Result:\n";
    printList(head);

    return 0;
}