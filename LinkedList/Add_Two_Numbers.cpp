#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Add Two Numbers
Platform: LeetCode
Problem Number: 2
========================================================

Problem Statement:
You are given two non-empty linked lists representing
two non-negative integers.

Digits are stored in reverse order.

Add the two numbers and return the result as a linked list.

Example:
Input:
l1 = 2 → 4 → 3   (342)
l2 = 5 → 6 → 4   (465)

Output:
7 → 0 → 8        (807)

========================================================
Approach (Simulation with Carry)

1️⃣ Traverse both lists

2️⃣ Add digits + carry

3️⃣ Create new node with (sum % 10)

4️⃣ Update carry = sum / 10

5️⃣ Continue until both lists AND carry are done

========================================================
Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))
========================================================
*/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify result building
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        // Traverse both lists
        while (l1 || l2 || carry) {

            int sum = carry;

            // Add l1 value
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add l2 value
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Compute carry
            carry = sum / 10;

            // Create new node
            curr->next = new ListNode(sum % 10);

            curr = curr->next;
        }

        return dummy->next;
    }
};


// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}


int main() {

    // l1: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2,
                     new ListNode(4,
                     new ListNode(3)));

    // l2: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5,
                     new ListNode(6,
                     new ListNode(4)));

    Solution obj;

    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result:\n";
    printList(result);

    return 0;
}