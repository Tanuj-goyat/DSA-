#include <iostream>
using namespace std;

/*
========================================================
Problem: Reorder List
Platform: LeetCode (143)
========================================================

Problem Statement:
Given a singly linked list:

L0 -> L1 -> ... -> Ln

Reorder it to:

L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 ...

You must modify the list in-place.

Example:
Input:
1 -> 2 -> 3 -> 4

Output:
1 -> 4 -> 2 -> 3

========================================================
Approach Used (Middle + Reverse + Merge)

Step 1:
Find middle of linked list

Step 2:
Reverse second half

Step 3:
Merge both halves alternately

Time Complexity: O(n)
Space Complexity: O(1)
(ignoring dummy node)

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
    // Reverse linked list
    // ------------------------------
    ListNode* reverse(ListNode* head) {

        ListNode* pre = NULL;

        ListNode* temp = head;

        while (temp) {

            ListNode* front = temp->next;

            temp->next = pre;

            pre = temp;

            temp = front;
        }

        return pre;
    }


    // ------------------------------
    // Find middle node
    // ------------------------------
    ListNode* mid(ListNode* head) {

        ListNode* slow = head;

        ListNode* fast = head;

        while (fast->next &&
              (fast->next)->next) {

            slow = slow->next;

            fast = (fast->next)->next;
        }

        if ((fast->next) == NULL)
            return slow;

        return slow->next;
    }


    // ------------------------------
    // Reorder list
    // ------------------------------
    void reorderList(ListNode* head) {

        if (!head || !head->next)
            return;

        ListNode* h1 = head;

        // Find middle
        ListNode* medium = mid(head);

        // Reverse second half
        ListNode* h2 =
            reverse(medium->next);

        // Split list
        medium->next = NULL;

        // Dummy node
        ListNode* newHead =
            new ListNode(-1);

        ListNode* temp = newHead;

        bool check = true;

        // ------------------------------
        // Merge alternately
        // ------------------------------
        while (h1 && h2) {

            if (check) {

                temp->next = h1;

                h1 = h1->next;
            }

            else {

                temp->next = h2;

                h2 = h2->next;
            }

            temp = temp->next;

            check = !check;
        }

        // Remaining nodes
        if (h1)
            temp->next = h1;

        if (h2)
            temp->next = h2;

        head = newHead->next;
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

    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head =
        new ListNode(1,
        new ListNode(2,
        new ListNode(3,
        new ListNode(4,
        new ListNode(5)))));

    Solution obj;

    obj.reorderList(head);

    cout << "Reordered List:\n";

    printList(head);

    return 0;
}