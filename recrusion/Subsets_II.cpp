#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem Name: Subsets II
Platform: LeetCode
Problem Number: 90
========================================================

Problem Statement:
Given an integer array nums that may contain duplicates,
return all possible subsets (the power set).

The solution set must NOT contain duplicate subsets.

Example:

Input:
nums = [1,2,2]

Output:
[
 [],
 [1],
 [1,2],
 [1,2,2],
 [2],
 [2,2]
]

========================================================
Approach (Backtracking + Duplicate Handling)

Key Ideas:

1️⃣ Sort the array
   → Groups duplicates together

2️⃣ Generate subsets using recursion

3️⃣ Skip duplicates:
   If current element is same as previous
   and not at starting index → skip it

Condition:
if(i != index && nums[i] == nums[i-1]) continue;

4️⃣ Add subset at every step
   → Because every state is a valid subset

========================================================
Time Complexity: O(2^n)
Space Complexity: O(n)

========================================================
*/

class Solution {
private:

    void f(vector<vector<int>>& ans,
           vector<int>& v,
           vector<int>& nums,
           int index)
    {
        // Store current subset
        ans.push_back(v);

        for(int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if(i != index && nums[i] == nums[i - 1])
                continue;

            // Pick element
            v.push_back(nums[i]);

            // Recurse for next index
            f(ans, v, nums, i + 1);

            // Backtrack
            v.pop_back();
        }
    }

public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Step 1: Sort array
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        // Start recursion
        f(ans, v, nums, 0);

        return ans;
    }
};


int main()
{
    vector<int> nums = {1,2,2};

    Solution obj;

    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "Subsets:\n";

    for(auto &subset : result) {
        cout << "[ ";
        for(int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}