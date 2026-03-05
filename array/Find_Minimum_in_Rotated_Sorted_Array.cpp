#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Find Minimum in Rotated Sorted Array
Platform: LeetCode
Problem Number: 153
========================================================

Problem Statement:
Suppose an array sorted in ascending order is rotated
at some pivot unknown to you beforehand.

Example:

Original Sorted Array:
[0,1,2,4,5,6,7]

After Rotation:
[4,5,6,7,0,1,2]

Find the minimum element.

Constraints:
- All elements are unique.
- Must run in O(log n) time.

========================================================
Approach Used (Binary Search)

Observation:
The rotated array consists of two sorted parts.

Example:
[4,5,6,7 | 0,1,2]

The minimum element is the start of the second part.

Key Idea:
Compare middle element with the last element.

Case 1:
nums[mid] > nums[n-1]
→ Minimum is on the RIGHT side.

Case 2:
nums[mid] <= nums[n-1]
→ Minimum is on the LEFT side (including mid).

========================================================
Time Complexity: O(log n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        // If array is already sorted (not rotated)
        if (nums[0] < nums[n - 1]) {
            return nums[0];
        }

        int s = 0;
        int e = n - 1;
        int mid = 0;

        // Binary search
        while (s < e) {

            mid = s + (e - s) / 2;

            // Minimum lies on right side
            if (nums[mid] > nums[n - 1]) {
                s = mid + 1;
            }
            // Minimum lies on left side (including mid)
            else {
                e = mid;
            }
        }

        return nums[s];   // s points to minimum element
    }
};


int main() {

    vector<int> nums = {4,5,6,7,0,1,2};

    Solution obj;

    int result = obj.findMin(nums);

    cout << "Minimum element: " << result << endl;

    return 0;
}