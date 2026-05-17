#include <iostream>
using namespace std;

/*
========================================================
Problem: Copy List with Random Pointer
Platform: LeetCode (138)
========================================================

Problem Statement:
Given a linked list where each node contains:
- next pointer
- random pointer

Create a deep copy of the list.

Return the copied linked list.

========================================================
Approach Used (Interleaving Nodes Technique):

Step 1:
Insert copied node after every original node

Original:
A -> B -> C

Becomes:
A -> A' -> B -> B' -> C -> C'

Step 2:
Assign random pointers

Copied node random:
original->random->next

Step 3:
Separate original and copied lists

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/


// Definition for Node
class Node {
public:

    int val;

    Node* next;
    Node* random;

    Node(int _val) {

        val = _val;

        next = NULL;
        random = NULL;
    }
};


class Solution {
public:

    Node* copyRandomList(Node* head) {

        // Empty list
        if (!head)
            return head;

        Node* temp = head;

        // ------------------------------
        // Step 1:
        // Insert copied nodes
        // ------------------------------
        while (temp) {

            Node* node =
                new Node(temp->val);

            node->next = temp->next;

            temp->next = node;

            temp = node->next;
        }

        temp = head;

        // ------------------------------
        // Step 2:
        // Connect random pointers
        // ------------------------------
        while (temp) {

            Node* node = temp->next;

            if (temp->random != NULL)

                node->random =
                    (temp->random)->next;

            else
                node->random = NULL;

            temp = node->next;
        }

        temp = head;

        // Head of copied list
        Node* newHead = head->next;

        // ------------------------------
        // Step 3:
        // Separate both lists
        // ------------------------------
        while (temp) {

            Node* node = temp->next;

            // Restore original list
            temp->next = node->next;

            temp = temp->next;

            // Connect copied list
            if (temp && temp->next)

                node->next = temp->next;

            else {

                node->next = NULL;

                break;
            }
        }

        return newHead;
    }
};


// Helper function
void printList(Node* head) {

    while (head) {

        cout << "Value: "
             << head->val;

        if (head->random)
            cout << " Random: "
                 << head->random->val;

        else
            cout << " Random: NULL";

        cout << endl;

        head = head->next;
    }
}


int main() {

    // Create nodes
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);

    // Next pointers
    n1->next = n2;
    n2->next = n3;

    // Random pointers
    n1->random = NULL;
    n2->random = n1;
    n3->random = n1;

    Solution obj;

    Node* copied =
        obj.copyRandomList(n1);

    cout << "Copied List:\n";

    printList(copied);

    return 0;
}