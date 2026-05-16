#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Merge K Sorted Linked Lists
Platform: LeetCode (23)
========================================================

Problem Statement:
Given an array of k sorted linked lists,
merge all linked lists into one sorted list.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]

Output:
1->1->2->3->4->4->5->6

========================================================
Approach Used (Sequential Merging):

Step 1:
Maintain one merged list

Step 2:
Merge current merged list
with next linked list

Step 3:
Repeat for all lists

Time Complexity: O(k * n)
(where n = total nodes)

Space Complexity: O(1)
(excluding recursion/extra nodes)

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

                l1 = l1->next;

                temp = temp->next;
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
    // Merge K lists
    // ------------------------------
    ListNode* mergeKLists(vector<ListNode*>& arr) {

        ListNode* head = NULL;

        // Merge one by one
        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] != NULL)

                head = merge(head, arr[i]);
        }

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

    // List 1: 1 -> 4 -> 5
    ListNode* l1 =
        new ListNode(1,
        new ListNode(4,
        new ListNode(5)));

    // List 2: 1 -> 3 -> 4
    ListNode* l2 =
        new ListNode(1,
        new ListNode(3,
        new ListNode(4)));

    // List 3: 2 -> 6
    ListNode* l3 =
        new ListNode(2,
        new ListNode(6));

    vector<ListNode*> lists = {l1, l2, l3};

    Solution obj;

    ListNode* result =
        obj.mergeKLists(lists);

    cout << "Merged List:\n";

    printList(result);

    return 0;
}