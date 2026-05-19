#include <iostream>
using namespace std;

/*
========================================================
Problem: Reverse Nodes in K-Group
Platform: LeetCode (25)
========================================================

Problem Statement:
Given the head of a linked list,
reverse nodes of the list k at a time.

If remaining nodes are fewer than k,
leave them unchanged.

Example:
Input:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Output:
2 -> 1 -> 4 -> 3 -> 5

========================================================
Approach Used (Iterative Group Reversal):

Step 1:
Find total size of linked list

Step 2:
Count how many complete groups exist

Step 3:
Reverse each group of size k

Step 4:
Connect reversed groups properly

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
    // Find linked list size
    // ------------------------------
    int tell_size(ListNode* head) {

        ListNode* temp = head;

        int i = 0;

        while (temp) {

            temp = temp->next;

            i++;
        }

        return i;
    }


    // ------------------------------
    // Reverse nodes in K groups
    // ------------------------------
    ListNode* reverseKGroup(ListNode* head,
                            int k) {

        if (!head || k == 1)
            return head;

        // ------------------------------
        // Find new head
        // ------------------------------
        ListNode* newHead = head;

        int i = 1;

        while (newHead && i != k) {

            newHead = newHead->next;

            i++;
        }

        // Total size
        int size = tell_size(head);

        // Number of complete groups
        int loop = size / k;

        ListNode* temp = head;

        ListNode* end = NULL;

        // ------------------------------
        // Reverse each group
        // ------------------------------
        while (loop) {

            ListNode* pre = NULL;

            int i = k;

            // Start node of current group
            ListNode* start = temp;

            // Reverse k nodes
            while (temp && i) {

                ListNode* front = temp->next;

                temp->next = pre;

                pre = temp;

                temp = front;

                i--;
            }

            loop--;

            // Connect previous group
            if (end) {

                end->next = pre;
            }

            // Last group handling
            if (loop == 0) {

                start->next = temp;

                break;
            }

            // Update end pointer
            end = start;
        }

        return newHead;
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

    // Create list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head =
        new ListNode(1,
        new ListNode(2,
        new ListNode(3,
        new ListNode(4,
        new ListNode(5)))));

    int k = 2;

    Solution obj;

    head = obj.reverseKGroup(head, k);

    cout << "Reversed in K-Groups:\n";

    printList(head);

    return 0;
}