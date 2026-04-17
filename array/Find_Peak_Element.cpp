#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Find Peak Element
Platform: LeetCode
Problem Number: 162
========================================================

Problem Statement:
A peak element is an element that is strictly greater
than its neighbors.

Return the index of ANY peak element.

You may assume:
nums[-1] = nums[n] = -∞

========================================================
Approach (Binary Search)

Key Idea:
If nums[mid] < nums[mid+1]
→ peak lies on right side

Else
→ peak lies on left side (including mid)

========================================================
Time Complexity: O(log n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Peak is on right
                start = mid + 1;
            } else {
                // Peak is on left (including mid)
                end = mid;
            }
        }

        return start; // or end
    }
};


int main() {

    vector<int> nums = {1, 2, 3, 1};

    Solution obj;

    cout << "Peak Index: "
         << obj.findPeakElement(nums);

    return 0;
}