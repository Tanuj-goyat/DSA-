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
Approach Used (Sorting)

Step 1:
Create a copy of the original array.

Step 2:
Sort the copied array.

Step 3:
Find the first index from the left
where the original and sorted arrays
differ.

Step 4:
Find the first index from the right
where the original and sorted arrays
differ.

Step 5:
The required length is:

(right - left + 1)

If the array is already sorted,
the result becomes 0.

Time Complexity: O(n log n)
Space Complexity: O(n)

========================================================
*/

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {

        vector<int> demo = nums;

        // ------------------------------
        // Sort the copied array
        // ------------------------------
        sort(demo.begin(), demo.end());

        int i = 0;

        int j = nums.size() - 1;

        // ------------------------------
        // Find left boundary
        // ------------------------------
        while (i < nums.size() && demo[i] == nums[i])
        {

            i++;
        }

        // ------------------------------
        // Find right boundary
        // ------------------------------
        while (j > i && demo[j] == nums[j])
        {

            j--;
        }

        return (j - i + 1);
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