#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Find Missing Elements
Platform: LeetCode 3731
========================================================

Problem Statement:
Given an integer array nums.

Return all missing integers lying
between the minimum and maximum
elements of the array.

Example:
Input:
nums = [4, 2, 7, 5]

Output:
[3, 6]

========================================================
Approach Used (Sorting)

Step 1:
Sort the array.

Step 2:
Traverse every integer from the
smallest element to the largest
element.

Step 3:
Maintain an index pointing to the
current element in the sorted array.

Step 4:
If the current integer exists in the
array, move the index forward.

Otherwise,
store it as a missing element.

Step 5:
Return the list of missing integers.

Time Complexity: O(n log n)
Space Complexity: O(1)
(excluding the output array)

========================================================
*/

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {

        // ------------------------------
        // Sort the array
        // ------------------------------
        sort(nums.begin(), nums.end());

        vector<int> ans;

        int index = 0;

        // ------------------------------
        // Find missing numbers
        // ------------------------------
        for (int i = nums[0]; i < nums[nums.size() - 1]; i++)
        {

            if (i >= nums[index])
            {

                index++;
            }

            else
            {

                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{

    vector<int> nums = {4, 2, 7, 5};

    Solution obj;

    vector<int> answer = obj.findMissingElements(nums);

    for (int x : answer)
    {

        cout << x << " ";
    }

    cout << endl;

    return 0;
}