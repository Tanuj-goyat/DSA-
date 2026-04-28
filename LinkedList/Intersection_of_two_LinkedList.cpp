#include <iostream>
using namespace std;

/*
========================================================
Problem: Intersection of Two Linked Lists
Platform: LeetCode (160)
========================================================

Problem Statement:
Given the heads of two singly linked lists, return the
node at which the two lists intersect.

If the two linked lists have no intersection, return NULL.

Example:
List A: 1 → 2 → 3 → 4 → 5
List B:       9 → 4 → 5

Output:
Node with value 4

========================================================
Approach Used (Two Pointer Switching):

Step 1: Use two pointers (temp1, temp2)

Step 2: Traverse both lists:
        When pointer reaches end → switch to other list

Step 3: Eventually both pointers will meet at intersection
        OR both become NULL (no intersection)

Time Complexity: O(n + m)
Space Complexity: O(1)

========================================================
*/

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // ------------------------------
    // Core logic: find intersection
    // ------------------------------
    ListNode* intersection(ListNode* h1, ListNode* h2) {

        ListNode* temp1 = h1;
        ListNode* temp2 = h2;

        // Traverse until both pointers meet
        while (temp1 != temp2) {

            // Move pointers
            temp1 = (temp1 == NULL) ? h2 : temp1->next;
            temp2 = (temp2 == NULL) ? h1 : temp2->next;
        }

        // Either intersection node OR NULL
        return temp1;
    }


    // ------------------------------
    // Main function
    // ------------------------------
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        if (!headA || !headB)
            return NULL;

        return intersection(headA, headB);
    }
};


// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}


int main() {

    // Create intersecting lists
    // Common part: 4 -> 5
    ListNode* common = new ListNode(4);
    common->next = new ListNode(5);

    // List A: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    // List B: 9 -> 4 -> 5
    ListNode* headB = new ListNode(9);
    headB->next = common;

    Solution obj;

    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if (ans)
        cout << "Intersection at node with value: " << ans->val << endl;
    else
        cout << "No intersection\n";

    return 0;
}