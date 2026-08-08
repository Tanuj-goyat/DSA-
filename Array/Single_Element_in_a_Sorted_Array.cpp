#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Single Element in a Sorted Array
Platform: LeetCode (540)
========================================================

Problem Statement:
Given a sorted array where every element
appears exactly twice except for one
element, find the element that appears
only once.

========================================================
Approach Used (XOR)

Step 1:
Initialize ans with the first element.

Step 2:
XOR ans with every remaining element.

XOR has these properties:

x ^ x = 0
x ^ 0 = x

Therefore, all duplicate elements cancel
each other and only the single element
remains.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {

        int ans = nums[0];

        // ------------------------------
        // XOR all elements
        // ------------------------------
        for (int i = 1; i < nums.size(); i++)
        {

            ans = ans ^ nums[i];
        }

        return ans;
    }
};

int main()
{

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4};

    Solution obj;

    int answer = obj.singleNonDuplicate(nums);

    cout << answer << endl;

    return 0;
}