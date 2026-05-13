#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Find Pairs With Given Sum in DLL
Platform: GFG
========================================================

Problem Statement:
Given a sorted doubly linked list and a target,
find all pairs whose sum equals target.

Example:
Input:
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7

Output:
(1,6)
(2,5)

========================================================
Approach Used (Two Pointer Technique):

Step 1:
Place one pointer at beginning

Step 2:
Place second pointer at end

Step 3:
- If sum == target → store pair
- If sum < target  → move left pointer
- If sum > target  → move right pointer

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

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};


class Solution {
public:

    vector<pair<int, int>> findPairsWithGivenSum(Node *head,
                                                 int target) {

        // ------------------------------
        // Result vector
        // ------------------------------
        vector<pair<int, int>> ans;

        // Empty list
        if (head == NULL)
            return ans;

        // ------------------------------
        // Left pointer
        // ------------------------------
        Node* left = head;

        // ------------------------------
        // Move to last node
        // ------------------------------
        Node* temp = head;

        while (temp->next) {
            temp = temp->next;
        }

        // Right pointer
        Node* right = temp;

        // ------------------------------
        // Two pointer traversal
        // ------------------------------
        while (left->data < right->data) {

            int sum = left->data + right->data;

            // Pair found
            if (sum == target) {

                ans.push_back({left->data,
                               right->data});

                left = left->next;
            }

            // Need smaller sum
            else if (sum > target) {

                right = right->prev;
            }

            // Need larger sum
            else if (sum < target) {

                left = left->next;
            }
        }

        return ans;
    }
};


// Helper function
void printPairs(vector<pair<int,int>>& v) {

    for (auto p : v) {

        cout << "("
             << p.first
             << ", "
             << p.second
             << ")" << endl;
    }
}


int main() {

    // Create DLL:
    // 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9

    Node* head = new Node(1);

    Node* n2 = new Node(2);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);
    Node* n6 = new Node(8);
    Node* n7 = new Node(9);

    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    n5->next = n6;
    n6->prev = n5;

    n6->next = n7;
    n7->prev = n6;

    int target = 7;

    Solution obj;

    vector<pair<int,int>> result =
        obj.findPairsWithGivenSum(head, target);

    cout << "Pairs:\n";

    printPairs(result);

    return 0;
}