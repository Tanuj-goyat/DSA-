#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Delete Node in a Linked List
Platform: LeetCode
Problem Number: 237
========================================================

Problem Statement:
You are given a node in a singly linked list.
Delete that node WITHOUT access to the head.

Constraints:
- The given node is NOT the last node

========================================================
Approach (Copy Next Node Trick)

Since we don't have access to previous node,
we cannot "remove" the current node directly.

So instead:

1️⃣ Copy value of next node into current node
2️⃣ Skip the next node

Effectively:
Current node becomes next node
Next node gets deleted

========================================================
Time Complexity: O(1)
Space Complexity: O(1)
========================================================
*/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {

        // Get next node
        ListNode* second = node->next;

        // Copy value
        node->val = second->val;

        // Skip next node
        node->next = second->next;

        // Optional (good practice)
        delete second;
    }
};