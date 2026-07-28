#include <iostream>
using namespace std;

/*
========================================================
Problem: Add Two Numbers II
Platform: LeetCode (445)
========================================================

Problem Statement:
You are given two non-empty linked lists
representing two non-negative integers.

The most significant digit comes first,
and each node contains a single digit.

Add the two numbers and return the sum
as a linked list.

The input lists should not be modified
permanently.

Example:
Input:
l1 = [7,2,4,3]
l2 = [5,6,4]

Output:
[7,8,0,7]

========================================================
Approach Used (Reverse Linked Lists)

Step 1:
Reverse both linked lists.

Step 2:
Traverse both lists simultaneously.

Step 3:
Add corresponding digits along with
the carry.

Step 4:
Create the resulting linked list in
reverse order.

Step 5:
Process any remaining nodes from
either list.

Step 6:
If a carry remains,
append it as a new node.

Step 7:
Reverse the resultant list and return
the final answer.

Time Complexity: O(n + m)
Space Complexity: O(max(n, m))

========================================================
*/

/**
 * Definition for singly-linked list.
 */
struct ListNode
{

    int val;

    ListNode *next;

    ListNode()
        : val(0), next(nullptr) {}

    ListNode(int x)
        : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next)
        : val(x), next(next) {}
};

class Solution
{
public:
    // ------------------------------
    // Reverse a linked list
    // ------------------------------
    ListNode *reverse(ListNode *head)
    {

        ListNode *temp = head;

        ListNode *pre = NULL;

        while (temp)
        {

            ListNode *front = temp->next;

            temp->next = pre;

            pre = temp;

            temp = front;
        }

        return pre;
    }

    // ------------------------------
    // Add two linked list numbers
    // ------------------------------
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *h1 = reverse(l1);

        ListNode *h2 = reverse(l2);

        ListNode *result = new ListNode(-1);

        ListNode *temp = result;

        int carry = 0;

        // ------------------------------
        // Add common digits
        // ------------------------------
        while (h1 && h2)
        {

            int a = h1->val;

            int b = h2->val;

            int c = a + b + carry;

            carry = c / 10;

            temp->next = new ListNode(c % 10);

            temp = temp->next;

            h1 = h1->next;

            h2 = h2->next;
        }

        // ------------------------------
        // Process remaining nodes of l1
        // ------------------------------
        while (h1)
        {

            int a = h1->val;

            int c = a + carry;

            carry = c / 10;

            temp->next = new ListNode(c % 10);

            temp = temp->next;

            h1 = h1->next;
        }

        // ------------------------------
        // Process remaining nodes of l2
        // ------------------------------
        while (h2)
        {

            int b = h2->val;

            int c = b + carry;

            carry = c / 10;

            temp->next = new ListNode(c % 10);

            temp = temp->next;

            h2 = h2->next;
        }

        // ------------------------------
        // Append remaining carry
        // ------------------------------
        if (carry)
        {

            temp->next = new ListNode(carry);
        }

        // ------------------------------
        // Reverse final answer
        // ------------------------------
        result = reverse(result->next);

        return result;
    }
};

// ------------------------------
// Print Linked List
// ------------------------------
void printList(ListNode *head)
{

    while (head)
    {

        cout << head->val;

        if (head->next)
        {

            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main()
{

    ListNode *l1 =
        new ListNode(7,
                     new ListNode(2,
                                  new ListNode(4,
                                               new ListNode(3))));

    ListNode *l2 =
        new ListNode(5,
                     new ListNode(6,
                                  new ListNode(4)));

    Solution obj;

    ListNode *answer = obj.addTwoNumbers(l1, l2);

    printList(answer);

    return 0;
}