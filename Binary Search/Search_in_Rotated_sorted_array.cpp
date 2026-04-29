#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Search in Rotated Sorted Array
Platform: LeetCode (33)
========================================================

Problem Statement:
Given a rotated sorted array nums (no duplicates),
search for a target value.

Return its index if found, else return -1.

Example:
Input:
nums = [4,5,6,7,0,1,2], target = 0

Output:
4

========================================================
Approach Used (Binary Search with Pivot Logic):

Key Idea:
Array is divided into TWO sorted parts:
1️⃣ Left sorted part
2️⃣ Right sorted part

We use last element to identify which part we are in.

Step 1: Use binary search

Step 2: Compare nums[mid] with last element
        → identify which side is sorted

Step 3: Decide direction based on target

Time Complexity: O(log n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int last = nums[n - 1];

        int start = 0;
        int end = n - 1;

        // ------------------------------
        // Binary Search
        // ------------------------------
        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // ------------------------------
            // Case 1: target < nums[mid]
            // ------------------------------
            if (target < nums[mid]) {

                // mid in LEFT part, target in RIGHT part
                if (nums[mid] > last && target <= last)
                    start = mid + 1;
                else
                    end = mid - 1;
            }

            // ------------------------------
            // Case 2: target > nums[mid]
            // ------------------------------
            else {

                // target in LEFT part, mid in RIGHT part
                if (target > last && nums[mid] <= last)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }

        return -1;
    }
};


int main() {

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution obj;

    int index = obj.search(nums, target);

    cout << "Index: " << index << endl;

    return 0;
}