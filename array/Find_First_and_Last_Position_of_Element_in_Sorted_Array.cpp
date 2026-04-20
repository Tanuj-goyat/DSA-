#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Find First and Last Position of Element
Platform: LeetCode
Problem Number: 34
========================================================

Problem Statement:
Given a sorted array nums, find the starting and ending
position of a given target value.

If target is not found, return [-1, -1].

Example:
Input:  nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

========================================================
Approach Used (Binary Search Twice):

Since array is sorted:

Step 1: Find FIRST occurrence
        → when found, move LEFT (end = mid - 1)

Step 2: Find LAST occurrence
        → when found, move RIGHT (start = mid + 1)

Step 3: Store answers separately

Time Complexity: O(log n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Step 1: Find FIRST occurrence
    // ------------------------------
    int findFirst(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        int ans = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // If target found
            if (nums[mid] == target) {

                ans = mid;          // store index
                end = mid - 1;      // move LEFT to find earlier occurrence
            }
            else if (nums[mid] < target) {

                start = mid + 1;    // move RIGHT
            }
            else {

                end = mid - 1;      // move LEFT
            }
        }

        return ans;
    }


    // ------------------------------
    // Step 2: Find LAST occurrence
    // ------------------------------
    int findLast(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        int ans = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // If target found
            if (nums[mid] == target) {

                ans = mid;          // store index
                start = mid + 1;    // move RIGHT to find later occurrence
            }
            else if (nums[mid] < target) {

                start = mid + 1;
            }
            else {

                end = mid - 1;
            }
        }

        return ans;
    }


    // ------------------------------
    // Step 3: Combine results
    // ------------------------------
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> result(2, -1);

        result[0] = findFirst(nums, target);
        result[1] = findLast(nums, target);

        return result;
    }
};


int main() {

    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    Solution obj;

    vector<int> result = obj.searchRange(nums, target);

    cout << "Range is: ";
    cout << result[0] << " " << result[1];

    return 0;
}