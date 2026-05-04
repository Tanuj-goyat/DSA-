#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Find Middle of Linked List
Platform: Custom / LeetCode (876)
========================================================

Problem Statement:
Given a singly linked list, return the middle node.

If there are two middle nodes, return the second one.

Example:
Input:
1 → 2 → 3 → 4 → 5

Output:
3

========================================================
Approach Used (Slow & Fast Pointer):

Step 1: Use two pointers:
        slow moves 1 step
        fast moves 2 steps

Step 2: When fast reaches end,
        slow will be at middle

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

struct Node {
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = NULL;
    }
};


// ------------------------------
// Find middle of linked list
// ------------------------------
Node* middle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


// Helper function
void printList(Node* head) {
    while (head) {
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}


int main() {

    vector<int> arr = {1,2,3,4,5};

    // Create linked list
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    cout << "Linked List:\n";
    printList(head);

    Node* mid = middle(head);

    cout << "Middle Node Value: " << mid->value << endl;

    return 0;
}