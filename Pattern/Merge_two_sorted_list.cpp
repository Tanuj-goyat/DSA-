#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Merge Two Sorted Lists
Platform: LeetCode
Problem Number: 21
========================================================

Problem Statement:
Merge two sorted linked lists and return it as a new
sorted list.

The new list should be made by splicing together the
nodes of the first two lists.

Example:
Input:
list1 = 1→2→4
list2 = 1→3→4

Output:
1→1→2→3→4→4

========================================================
Approach (Create New List)

1️⃣ Compare nodes from both lists
2️⃣ Insert smaller value into new list
3️⃣ Move pointer forward
4️⃣ When one list ends → append remaining nodes

========================================================
Time Complexity: O(n + m)
Space Complexity: O(n + m) (new list created)
========================================================
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


// Helper function to merge remaining nodes
void merge(ListNode* h1, ListNode* h2, ListNode* h3) {

    // Merge both lists
    while (h1 != NULL && h2 != NULL) {

        if (h1->val < h2->val) {
            h3->next = new ListNode(h1->val);
            h1 = h1->next;
        } else {
            h3->next = new ListNode(h2->val);
            h2 = h2->next;
        }

        h3 = h3->next;
    }

    // If list1 remains
    while (h1) {
        h3->next = new ListNode(h1->val);
        h1 = h1->next;
        h3 = h3->next;
    }

    // If list2 remains
    while (h2) {
        h3->next = new ListNode(h2->val);
        h2 = h2->next;
        h3 = h3->next;
    }
}


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Edge cases
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* h1 = list1;
        ListNode* h2 = list2;

        ListNode* list3;

        // Initialize head of new list
        if (h1->val < h2->val) {
            list3 = new ListNode(h1->val);
            h1 = h1->next;
        } else {
            list3 = new ListNode(h2->val);
            h2 = h2->next;
        }

        ListNode* h3 = list3;

        // Merge remaining nodes
        merge(h1, h2, h3);

        return list3;
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

    // Create list1: 1->2->4
    ListNode* list1 = new ListNode(1,
                         new ListNode(2,
                         new ListNode(4)));

    // Create list2: 1->3->4
    ListNode* list2 = new ListNode(1,
                         new ListNode(3,
                         new ListNode(4)));

    Solution obj;

    ListNode* result = obj.mergeTwoLists(list1, list2);

    cout << "Merged List:\n";
    printList(result);

    return 0;
}