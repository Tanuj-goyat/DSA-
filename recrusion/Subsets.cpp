#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Subsets
Platform: LeetCode (78)
========================================================

Problem Statement:
Given an integer array nums.

Return all possible subsets
(the power set).

The solution set must not contain
duplicate subsets.

The subsets can be returned in
any order.

Example:
Input:
nums = [1,2,3]

Output:
[
  [],
  [1],
  [2],
  [3],
  [1,2],
  [1,3],
  [2,3],
  [1,2,3]
]

========================================================
Approach Used (Recursion / Backtracking)

Step 1:
Start from index 0.

Step 2:
For every element,
make two recursive calls:

- Include the current element.
- Exclude the current element.

Step 3:
When all elements have been processed,
store the current subset.

Step 4:
Return all generated subsets.

Time Complexity: O(2ⁿ × n)
Space Complexity: O(n)

========================================================
*/

class Solution
{
public:
    // ------------------------------
    // Generate all subsets
    // ------------------------------
    void f(vector<vector<int>> &ans, vector<int> &nums, int index, vector<int> &v)
    {

        if (index >= nums.size())
        {

            ans.push_back(v);

            return;
        }

        // ------------------------------
        // Include current element
        // ------------------------------
        v.push_back(nums[index]);

        f(ans, nums, index + 1, v);

        v.pop_back();

        // ------------------------------
        // Exclude current element
        // ------------------------------
        f(ans, nums, index + 1, v);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<int> v;

        vector<vector<int>> ans;

        // ------------------------------
        // Generate all subsets
        // ------------------------------
        f(ans, nums, 0, v);

        return ans;
    }
};

int main()
{

    vector<int> nums = {1, 2, 3};

    Solution obj;

    vector<vector<int>> answer = obj.subsets(nums);

    for (auto &subset : answer)
    {

        cout << "[ ";

        for (int x : subset)
        {

            cout << x << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}