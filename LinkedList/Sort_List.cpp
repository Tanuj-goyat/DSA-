#include <iostream>
using namespace std;

/*
========================================================
Problem: Sort List
Platform: LeetCode (148)
========================================================

Problem Statement:
Given the head of a linked list,
sort the list in ascending order.

Example:
Input:
4 -> 2 -> 1 -> 3

Output:
1 -> 2 -> 3 -> 4

========================================================
Approach Used (Merge Sort on Linked List):

Step 1:
Find middle of linked list

Step 2:
Split list into two halves

Step 3:
Recursively sort both halves

Step 4:
Merge sorted halves

Time Complexity: O(n log n)
Space Complexity: O(log n)
(recursion stack)

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
    // Merge two sorted lists
    // ------------------------------
    ListNode* merge(ListNode* l1,
                    ListNode* l2) {

        ListNode* head = new ListNode(-1);

        ListNode* temp = head;

        // ------------------------------
        // Merge while both exist
        // ------------------------------
        while (l1 && l2) {

            if (l1->val < l2->val) {

                temp->next = l1;

                temp = temp->next;

                l1 = l1->next;
            }

            else {

                temp->next = l2;

                temp = temp->next;

                l2 = l2->next;
            }
        }

        // Remaining nodes of l1
        while (l1) {

            temp->next = l1;

            temp = temp->next;

            l1 = l1->next;
        }

        // Remaining nodes of l2
        while (l2) {

            temp->next = l2;

            temp = temp->next;

            l2 = l2->next;
        }

        return head->next;
    }


    // ------------------------------
    // Find middle node
    // ------------------------------
    ListNode* medium(ListNode* head) {

        if (!head)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next &&
              (fast->next)->next) {

            slow = slow->next;

            fast = (fast->next)->next;
        }

        return slow;
    }


    // ------------------------------
    // Merge Sort recursion
    // ------------------------------
    ListNode* f(ListNode* head) {

        // Base case
        if (!head || !(head->next))
            return head;

        // Find middle
        ListNode* mid = medium(head);

        // Split list
        ListNode* left = head;

        ListNode* right = mid->next;

        mid->next = NULL;

        // Sort left half
        left = f(left);

        // Sort right half
        right = f(right);

        // Merge sorted halves
        return merge(left, right);
    }


    // ------------------------------
    // Main function
    // ------------------------------
    ListNode* sortList(ListNode* head) {

        return f(head);
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
    // 4 -> 2 -> 1 -> 3

    ListNode* head =
        new ListNode(4,
        new ListNode(2,
        new ListNode(1,
        new ListNode(3))));

    Solution obj;

    head = obj.sortList(head);

    cout << "Sorted List:\n";

    printList(head);

    return 0;
}