#include <iostream>
using namespace std;

/*
========================================================
Problem: Partition List
Platform: LeetCode (86)
========================================================

Problem Statement:
Given the head of a linked list and an integer x,
partition the list such that:

- All nodes with value < x come first
- All nodes with value >= x come later

The relative order of nodes in each partition
must remain the same.

Example:
Input:
1 -> 4 -> 3 -> 2 -> 5 -> 2
x = 3

Output:
1 -> 2 -> 2 -> 4 -> 3 -> 5

========================================================
Approach Used (Two Dummy Lists):

Step 1:
Create two lists:
- part1 -> nodes less than x
- part2 -> nodes greater than or equal to x

Step 2:
Traverse original list and place nodes
in appropriate list

Step 3:
Connect both lists

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/


// Linked List Node
struct ListNode {

    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};


class Solution {
public:

    ListNode* partition(ListNode* head,
                        int x) {

        ListNode* temp = head;

        // ------------------------------
        // Dummy nodes
        // ------------------------------
        ListNode* part1 = new ListNode(-1);
        ListNode* part2 = new ListNode(-1);

        ListNode* i = part1;
        ListNode* j = part2;

        // ------------------------------
        // Divide nodes into two lists
        // ------------------------------
        while (temp) {

            if (temp->val < x) {

                i->next = temp;

                i = i->next;
            }

            else {

                j->next = temp;

                j = j->next;
            }

            temp = temp->next;
        }

        // ------------------------------
        // Connect both partitions
        // ------------------------------
        i->next = part2->next;

        j->next = NULL;

        return part1->next;
    }
};


// Helper function
void printList(ListNode* head) {

    while (head) {

        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}


int main() {

    // List:
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2

    ListNode* head =
        new ListNode(1,
        new ListNode(4,
        new ListNode(3,
        new ListNode(2,
        new ListNode(5,
        new ListNode(2))))));

    int x = 3;

    Solution obj;

    head = obj.partition(head, x);

    cout << "Partitioned List:\n";

    printList(head);

    return 0;
}