#include <iostream>
using namespace std;

/*
========================================================
Problem: Delete All Occurrences of a Key in DLL
Platform: GFG
========================================================

Problem Statement:
Given the head of a doubly linked list and an integer key,
delete all nodes having value = key.

Return the modified head.

Example:
Input:
1 ⇄ 2 ⇄ 3 ⇄ 2 ⇄ 4
key = 2

Output:
1 ⇄ 3 ⇄ 4

========================================================
Approach Used (Your Approach: Rebuild Links):

Step 1: Create dummy node

Step 2: Traverse original list

Step 3:
        If current node != key,
        attach it to new list

Step 4:
        Fix prev and next pointers

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

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};


class Solution {
public:

    // ------------------------------
    // Delete all occurrences of key
    // ------------------------------
    Node* deleteAllOccurOfX(Node* head, int key) {

        // Empty list
        if (!head)
            return NULL;

        // Dummy node
        Node* newHead = new Node(-1);

        Node* list = newHead;
        Node* temp = head;

        // ------------------------------
        // Build filtered list
        // ------------------------------
        while (temp) {

            // Keep node if not equal to key
            if (temp->data != key) {

                list->next = temp;

                temp->prev = list;

                list = list->next;
            }

            temp = temp->next;
        }

        // End list properly
        list->next = NULL;

        // ------------------------------
        // Remove dummy connection
        // ------------------------------
        if (newHead->next)
            newHead->next->prev = NULL;

        return newHead->next;
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
    // 1 <-> 2 <-> 3 <-> 2 <-> 4
    Node* head = new Node(1);

    Node* second = new Node(2);
    Node* third  = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth  = new Node(4);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    Solution obj;

    head = obj.deleteAllOccurOfX(head, 2);

    cout << "Updated DLL:\n";

    printList(head);

    return 0;
}