#include <iostream>
using namespace std;

/*
========================================================
Problem: Reverse Linked List II
Platform: LeetCode (92)
========================================================

Problem Statement:
Given the head of a linked list and two integers
left and right,

reverse the nodes from position left to right.

Example:
Input:
1 -> 2 -> 3 -> 4 -> 5

left = 2
right = 4

Output:
1 -> 4 -> 3 -> 2 -> 5

========================================================
Approach Used (Partial Reversal):

Step 1:
Move to node just before position left

Step 2:
Reverse nodes from left to right

Step 3:
Reconnect reversed portion with
remaining linked list

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

    // ------------------------------
    // Reverse 'diff + 1' nodes
    // ------------------------------
    ListNode* reverse(ListNode* head,
                      int diff) {

        ListNode* pre = head;

        if (!head || !head->next)
            return head;

        ListNode* temp = head->next;

        int i = 1;

        while (i <= diff) {

            ListNode* front = temp->next;

            temp->next = pre;

            pre = temp;

            temp = front;

            i++;
        }

        // Connect remaining list
        head->next = temp;

        return pre;
    }


    // ------------------------------
    // Reverse between left and right
    // ------------------------------
    ListNode* reverseBetween(ListNode* head,
                             int left,
                             int right) {

        ListNode* temp = head;

        int i = 1;

        // Move before left position
        while (i < left - 1) {

            temp = temp->next;

            i++;
        }

        // Reverse from middle
        if (left != 1)

            temp->next =
                reverse(temp->next,
                        right - left);

        // Reverse starting from head
        else

            return reverse(temp,
                           right - left);

        return head;
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
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head =
        new ListNode(1,
        new ListNode(2,
        new ListNode(3,
        new ListNode(4,
        new ListNode(5)))));

    int left = 2;
    int right = 4;

    Solution obj;

    head = obj.reverseBetween(head,
                              left,
                              right);

    cout << "Reversed List:\n";

    printList(head);

    return 0;
}