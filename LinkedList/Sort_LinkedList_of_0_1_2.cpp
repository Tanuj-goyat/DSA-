#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Sort Linked List of 0s, 1s and 2s
Platform: GFG-style
========================================================

Problem Statement:
Given a linked list containing only 0s, 1s and 2s,
sort the list.

Example:
Input:
1 → 2 → 0 → 1 → 2

Output:
0 → 1 → 1 → 2 → 2

========================================================
Approach Used (Three Dummy Lists):

Step 1: Create 3 lists:
        zero → for 0s
        one  → for 1s
        two  → for 2s

Step 2: Traverse original list and attach nodes

Step 3: Connect lists properly

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

ListNode* sort_list(ListNode* head) {

    // ------------------------------
    // Step 1: Create dummy nodes
    // ------------------------------
    ListNode* zero = new ListNode(-1);
    ListNode* one  = new ListNode(-1);
    ListNode* two  = new ListNode(-1);

    ListNode* z = zero;
    ListNode* o = one;
    ListNode* t = two;

    ListNode* temp = head;

    // ------------------------------
    // Step 2: Distribute nodes
    // ------------------------------
    while (temp) {

        if (temp->val == 0) {
            z->next = temp;
            z = z->next;
        }
        else if (temp->val == 1) {
            o->next = temp;
            o = o->next;
        }
        else {
            t->next = temp;
            t = t->next;
        }

        temp = temp->next;
    }

    // ------------------------------
    // Step 3: Connect lists safely
    // ------------------------------

    // Connect 0 → 1 OR 2
    if (one->next != NULL)
        z->next = one->next;
    else
        z->next = two->next;

    // Connect 1 → 2
    o->next = two->next;

    // End list
    t->next = NULL;

    return zero->next;
}


// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {

    vector<int> v = {1,2,0,1,2};

    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;

    for (int i = 1; i < v.size(); i++) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }

    head = sort_list(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}