#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Find the Duplicate Number
Platform: LeetCode
Problem Number: 287
========================================================

Problem Statement:
Given an array of n + 1 integers where each integer is
in the range [1, n], there is exactly one duplicate number.

Return that duplicate number.

Constraints:
✔ Cannot modify array
✔ Must use O(1) extra space

========================================================
Approach (Floyd’s Cycle Detection - Tortoise & Hare)

Treat array like a linked list:
index → node
value → next pointer

Since duplicate exists → cycle will form

Steps:

1️⃣ Find intersection point
   slow = nums[slow]
   fast = nums[nums[fast]]

2️⃣ Reset fast to start

3️⃣ Move both one step
   → where they meet = duplicate

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Step 1: Find intersection point
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];           // move 1 step
            fast = nums[nums[fast]];     // move 2 steps
        } while (slow != fast);

        // Step 2: Find entrance of cycle
        fast = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // duplicate number
    }
};


int main() {

    vector<int> nums = {1, 3, 4, 2, 2};

    Solution obj;

    cout << "Duplicate Number: "
         << obj.findDuplicate(nums);

    return 0;
}