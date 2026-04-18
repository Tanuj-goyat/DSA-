#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Remove Nth Node From End of List
Platform: LeetCode
Problem Number: 19
========================================================

Problem Statement:
Given the head of a linked list, remove the nth node
from the end of the list and return its head.

Example:
Input:
1 → 2 → 3 → 4 → 5, n = 2

Output:
1 → 2 → 3 → 5

========================================================
Your Approach (Two Pass)

1️⃣ Find size of list

2️⃣ Find (size - n)th node from start

3️⃣ Remove next node

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

    // Step 1: Calculate size
    int tell_size(ListNode* head) {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        return count;
    }

    // Step 2: Remove k-th node from start (k = size - n)
    void removeNode(ListNode* head, int k) {

        ListNode* temp = head;
        int index = 1;

        while (temp && index < k) {
            temp = temp->next;
            index++;
        }

        // Node to delete
        ListNode* del = temp->next;

        temp->next = del->next;

        delete del; // good practice
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int size = tell_size(head);

        // If head needs to be removed
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Remove (size - n)th node
        removeNode(head, size - n);

        return head;
    }
};


// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}


int main() {

    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5)))));

    int n = 2;

    Solution obj;

    head = obj.removeNthFromEnd(head, n);

    printList(head);

    return 0;
}