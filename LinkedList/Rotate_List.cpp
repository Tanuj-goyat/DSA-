#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Rotate List
Platform: LeetCode
Problem Number: 61
========================================================

Problem Statement:
Given the head of a linked list, rotate the list to the
right by k places.

Example:
Input:
1 → 2 → 3 → 4 → 5, k = 2

Output:
4 → 5 → 1 → 2 → 3

========================================================
Approach (Circular Linked List)

1️⃣ Find length of list

2️⃣ Connect last node to head → make circular

3️⃣ Reduce k:
   k = k % n

4️⃣ Find new tail:
   position = n - k

5️⃣ Break the circle

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
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge cases
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Find length
        ListNode* temp = head;
        int n = 1;

        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Step 2: Make circular
        temp->next = head;

        // Step 3: Reduce k
        k = k % n;

        // If no rotation needed
        if (k == 0) {
            temp->next = NULL;
            return head;
        }

        int steps = n - k;

        // Step 4: Find new tail
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
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

    int k = 2;

    Solution obj;

    head = obj.rotateRight(head, k);

    cout << "Rotated List:\n";
    printList(head);

    return 0;
}