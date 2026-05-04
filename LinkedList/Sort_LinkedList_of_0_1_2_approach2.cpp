#include <iostream>
using namespace std;

/*
========================================================
Problem: Sort Linked List of 0s, 1s and 2s
Platform: GFG
========================================================

Approach Used (Your Approach: Pointer + Value Swapping):

Idea:
Maintain two pointers:
- first1 → first occurrence where 1 should go
- first2 → first occurrence where 2 should go

Traverse list and adjust values dynamically.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:

    Node* segregate(Node* head) {

        if (!head) return NULL;

        Node* temp = head;
        Node* first1 = NULL; // first misplaced 1
        Node* first2 = NULL; // first misplaced 2

        while (temp) {

            // ------------------------------
            // Case: current = 0
            // ------------------------------
            if (temp->data == 0) {

                if (first1 && first2) {
                    temp->data = 2;
                    first2->data = 1;
                    first1->data = 0;

                    first1 = first1->next;
                    first2 = first2->next;
                }
                else if (first2) {
                    temp->data = 2;
                    first2->data = 0;

                    first2 = first2->next;
                }
                else if (first1) {
                    temp->data = 1;
                    first1->data = 0;

                    first1 = first1->next;
                }
            }

            // ------------------------------
            // Case: current = 1
            // ------------------------------
            else if (temp->data == 1) {

                if (first2) {
                    temp->data = 2;
                    first2->data = 1;

                    if (!first1)
                        first1 = first2;

                    first2 = first2->next;
                }

                if (!first1)
                    first1 = temp;
            }

            // ------------------------------
            // Case: current = 2
            // ------------------------------
            else {
                if (!first2)
                    first2 = temp;
            }

            temp = temp->next;
        }

        return head;
    }
};