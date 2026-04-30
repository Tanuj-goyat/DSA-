#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Search in Rotated Sorted Array II
Platform: LeetCode (81)
========================================================

Problem Statement:
Given a rotated sorted array nums (may contain duplicates),
return true if target exists in array, otherwise false.

Example:
Input:
nums = [2,5,6,0,0,1,2], target = 0

Output:
true

========================================================
Approach Used (Modified Binary Search):

Challenge:
Duplicates make it difficult to identify sorted half.

Step 1: Use binary search

Step 2: If nums[mid] == target → return true

Step 3: If duplicates:
        nums[start] == nums[mid] == nums[end]
        → shrink range (start++, end--)

Step 4: Identify sorted half:
        Left sorted → nums[start] <= nums[mid]
        Right sorted → nums[mid] <= nums[end]

Step 5: Check where target lies

Time Complexity:
Best: O(log n)
Worst: O(n) (due to duplicates)

Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int start = 0;
        int end = n - 1;

        // ------------------------------
        // Binary Search
        // ------------------------------
        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target)
                return true;

            // ------------------------------
            // Case 1: Duplicates
            // ------------------------------
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
            }

            // ------------------------------
            // Case 2: Left half sorted
            // ------------------------------
            else if (nums[start] <= nums[mid]) {

                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }

            // ------------------------------
            // Case 3: Right half sorted
            // ------------------------------
            else {

                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};


int main() {

    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    Solution obj;

    bool found = obj.search(nums, target);

    cout << "Found: " << (found ? "true" : "false") << endl;

    return 0;
}