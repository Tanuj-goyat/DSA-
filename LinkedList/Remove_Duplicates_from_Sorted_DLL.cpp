#include <iostream>
using namespace std;

/*
========================================================
Problem: Remove Duplicates from Sorted DLL
Platform: GFG
========================================================

Problem Statement:
Given a sorted doubly linked list,
remove duplicate nodes such that
each element appears only once.

Example:
Input:
1 <-> 1 <-> 2 <-> 2 <-> 3

Output:
1 <-> 2 <-> 3

========================================================
Approach Used (In-place Link Adjustment):

Step 1:
Maintain two pointers:
- i    → last unique node
- temp → traversal pointer

Step 2:
If current node is different,
connect it after i

Step 3:
Break extra links at end

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/


// Doubly Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


class Solution {
public:

    Node* removeDuplicates(Node* head) {

        // ------------------------------
        // Empty list
        // ------------------------------
        if (head == NULL)
            return head;

        Node* temp = head;
        Node* i = head;

        // Single node
        if (temp->next == NULL)
            return head;

        else
            temp = temp->next;

        // ------------------------------
        // Traverse list
        // ------------------------------
        while (temp) {

            // Unique element found
            if (temp->data != i->data) {

                i->next = temp;

                temp->prev = i;

                i = i->next;
            }

            temp = temp->next;
        }

        // Remove extra duplicate links
        i->next = NULL;

        return head;
    }
};


// Helper function
void printList(Node* head) {

    while (head) {

        cout << head->data;

        if (head->next)
            cout << " <-> ";

        head = head->next;
    }

    cout << endl;
}


int main() {

    // Create DLL:
    // 1 <-> 1 <-> 2 <-> 2 <-> 3

    Node* head = new Node(1);

    Node* n2 = new Node(1);
    Node* n3 = new Node(2);
    Node* n4 = new Node(2);
    Node* n5 = new Node(3);

    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    Solution obj;

    head = obj.removeDuplicates(head);

    cout << "DLL after removing duplicates:\n";

    printList(head);

    return 0;
}