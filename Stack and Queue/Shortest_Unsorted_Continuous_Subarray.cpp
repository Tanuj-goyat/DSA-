#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Shortest Unsorted Continuous Subarray
Platform: LeetCode (581)
========================================================

Problem Statement:
Given an integer array nums.

Find the shortest continuous subarray
such that if only this subarray is
sorted, the whole array becomes sorted.

Return the length of that subarray.

Example:
Input:
nums = [2,6,4,8,10,9,15]

Output:
5

========================================================
Approach 1 (Brute Force - Sorting)

Step 1:
Create a copy of the original array.

Step 2:
Sort the copied array.

Step 3:
Find the first index from the left
where the original and sorted arrays differ.

Step 4:
Find the first index from the right
where the original and sorted arrays differ.

Step 5:
Answer = (right - left + 1)

Time Complexity: O(n log n)
Space Complexity: O(n)

========================================================
Approach 2 (Optimal - One Pass)

Idea:
1. Traverse from left to right while keeping track of
   the maximum element seen so far.
   Whenever current element is smaller than maximum,
   it must belong to the unsorted subarray.
   Update the right boundary.

2. Traverse from right to left while keeping track of
   the minimum element seen so far.
   Whenever current element is greater than minimum,
   it must belong to the unsorted subarray.
   Update the left boundary.

3. If no violation is found, the array is already sorted.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution
{
public:
    // ====================================================
    // Approach 1 : Brute Force (Sorting)
    // Uncomment this function if you want to use it.
    // ====================================================

    /*
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> demo = nums;

        sort(demo.begin(), demo.end());

        int left = 0;
        int right = nums.size() - 1;

        while (left < nums.size() && demo[left] == nums[left])
        {
            left++;
        }

        while (right > left && demo[right] == nums[right])
        {
            right--;
        }

        return (right - left + 1);
    }
    */

    // ====================================================
    // Approach 2 : Optimal (Linear Scan)
    // ====================================================

    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();

        int left = -1;
        int right = -1;

        int maxIndex = 0;
        int minIndex = n - 1;

        // Find right boundary
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < nums[maxIndex])
            {
                right = i;
            }
            else
            {
                maxIndex = i;
            }
        }

        // Find left boundary
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[minIndex])
            {
                left = i;
            }
            else
            {
                minIndex = i;
            }
        }

        if (left == -1)
        {
            return 0;
        }

        return (right - left + 1);
    }
};

int main()
{
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};

    Solution obj;

    int answer = obj.findUnsortedSubarray(nums);

    cout << answer << endl;

    return 0;
}