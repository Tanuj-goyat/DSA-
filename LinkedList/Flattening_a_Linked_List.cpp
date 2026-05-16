#include <iostream>
using namespace std;

/*
========================================================
Problem: Flattening a Linked List
Platform: GFG
========================================================

Problem Statement:
Given a linked list where:
- next pointer points to next list
- bottom pointer points to sorted linked list

Flatten the list into a single sorted list
using bottom pointers only.

Example:
Input:

5 -> 10 -> 19 -> 28
|     |      |      |
7     20     22     35
|            |      |
8            50     40
|                   |
30                  45

Output:
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22
-> 28 -> 30 -> 35 -> 40 -> 45 -> 50

========================================================
Approach Used (Sequential Merge):

Step 1:
Merge first two bottom lists

Step 2:
Merge result with next list

Step 3:
Repeat until all lists merged

Time Complexity: O(N * K)
Space Complexity: O(1)

========================================================
*/


// Linked List Node
class Node {
public:

    int data;

    Node* next;
    Node* bottom;

    Node(int x) {

        data = x;

        next = nullptr;
        bottom = nullptr;
    }
};


class Solution {
public:

    // ------------------------------
    // Merge two bottom linked lists
    // ------------------------------
    Node* merge(Node* l1,
                Node* l2) {

        Node* head = new Node(-1);

        Node* temp = head;

        // ------------------------------
        // Merge both lists
        // ------------------------------
        while (l1 && l2) {

            if (l1->data < l2->data) {

                temp->bottom = l1;

                temp = temp->bottom;

                l1 = l1->bottom;
            }

            else {

                temp->bottom = l2;

                temp = temp->bottom;

                l2 = l2->bottom;
            }
        }

        // Remaining nodes of l1
        while (l1) {

            temp->bottom = l1;

            temp = temp->bottom;

            l1 = l1->bottom;
        }

        // Remaining nodes of l2
        while (l2) {

            temp->bottom = l2;

            temp = temp->bottom;

            l2 = l2->bottom;
        }

        return head->bottom;
    }


    // ------------------------------
    // Flatten linked list
    // ------------------------------
    Node* flatten(Node* root) {

        // Base case
        if (!root || !(root->next))
            return root;

        Node* x = root->next;

        Node* head = root;

        // ------------------------------
        // Sequential merging
        // ------------------------------
        while (x) {

            head = merge(head, x);

            x = x->next;
        }

        return head;
    }
};


// Helper function
void printBottomList(Node* head) {

    while (head) {

        cout << head->data;

        if (head->bottom)
            cout << " -> ";

        head = head->bottom;
    }

    cout << endl;
}


int main() {

    // Create example structure

    Node* head = new Node(5);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom =
        new Node(45);

    Solution obj;

    Node* result = obj.flatten(head);

    cout << "Flattened List:\n";

    printBottomList(result);

    return 0;
}