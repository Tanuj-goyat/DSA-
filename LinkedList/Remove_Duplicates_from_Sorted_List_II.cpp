#include <iostream>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem: Remove Duplicates from Sorted List II
(LeetCode 82)
========================================================

Goal:
Remove ALL duplicate values.
Keep only elements that appear exactly once.

Example:
1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
Output:
1 -> 2 -> 5
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head) return nullptr;

        unordered_map<int, int> freq;

        // Step 1: Count frequency
        ListNode* temp = head;
        while (temp) {
            freq[temp->val]++;
            temp = temp->next;
        }

        // Step 2: Build new list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        temp = head;

        while (temp) {
            if (freq[temp->val] == 1) {
                curr->next = temp;
                curr = curr->next;
            }
            temp = temp->next;
        }

        curr->next = nullptr;

        return dummy->next;
    }
};