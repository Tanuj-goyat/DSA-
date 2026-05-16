#include <iostream>
#include <unordered_map>
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

Each new node should contain:
- same value
- correct next pointer
- correct random pointer

========================================================
Approach Used (Hash Map Mapping):

Step 1:
Create copy nodes using next pointers

Step 2:
Store mapping:
original node -> copied node

Step 3:
Traverse again and connect random pointers

Time Complexity: O(n)
Space Complexity: O(n)

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

        // ------------------------------
        // Empty list
        // ------------------------------
        if (!head)
            return NULL;

        Node* temp = head;

        // Dummy node
        Node* l1 = new Node(-1);

        Node* dmy = l1;

        // Original -> Copy mapping
        unordered_map<Node*, Node*> m;

        // ------------------------------
        // Create copied nodes
        // ------------------------------
        while (temp) {

            dmy->next = new Node(temp->val);

            dmy = dmy->next;

            // Store mapping
            m[temp] = dmy;

            temp = temp->next;
        }

        temp = head;

        dmy = l1->next;

        // ------------------------------
        // Connect random pointers
        // ------------------------------
        while (temp) {

            Node* ran = m[temp->random];

            dmy->random = ran;

            dmy = dmy->next;

            temp = temp->next;
        }

        return l1->next;
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