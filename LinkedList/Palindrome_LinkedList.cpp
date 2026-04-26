#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Palindrome Linked List
Platform: LeetCode (234)
========================================================

Problem Statement:
Given the head of a singly linked list, return true if
it is a palindrome.

Example:
Input:
1 → 2 → 2 → 1

Output:
true

========================================================
Approach Used (Middle + Reverse + Compare):

Step 1: Find middle using slow & fast pointers

Step 2: Reverse second half of list

Step 3: Compare first half and second half

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

// ------------------------------
// Step 2: Reverse linked list
// ------------------------------
ListNode* reverse(ListNode* head) {

    ListNode* back = NULL;
    ListNode* temp = head;

    while (temp != NULL) {
        ListNode* front = temp->next;
        temp->next = back;
        back = temp;
        temp = front;
    }

    return back;
}


// ------------------------------
// Main palindrome function
// ------------------------------
bool isPalindrome(ListNode* head) {

    if (head == NULL || head->next == NULL)
        return true;

    ListNode* slow = head;
    ListNode* fast = head;

    // ------------------------------
    // Step 1: Find middle
    // ------------------------------
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // ------------------------------
    // Step 2: Reverse second half
    // ------------------------------
    ListNode* h2 = reverse(slow->next);

    // ------------------------------
    // Step 3: Compare both halves
    // ------------------------------
    ListNode* temp1 = head;
    ListNode* temp2 = h2;

    while (temp2 != NULL) {
        if (temp1->val != temp2->val)
            return false;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}


// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {

    vector<int> v = {1,2,2,1};

    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;

    for (int i = 1; i < v.size(); i++) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }

    cout << "Linked List:\n";
    printList(head);

    if (isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}