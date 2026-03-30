#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem Name: 4Sum
Platform: LeetCode
Problem Number: 18
========================================================

Problem Statement:
Given an array nums of n integers, return all unique
quadruplets [a, b, c, d] such that:

a + b + c + d = target

The solution set must not contain duplicate quadruplets.

Example:
Input:
nums = [1,0,-1,0,-2,2], target = 0

Output:
[
 [-2,-1,1,2],
 [-2,0,0,2],
 [-1,0,0,1]
]

========================================================
Approach (Backtracking)

1️⃣ Sort the array → helps skip duplicates

2️⃣ Use recursion to generate combinations of size 4

3️⃣ At each step:
   - Pick element
   - Recurse
   - Backtrack

4️⃣ When size == 4:
   - Check if sum == target

5️⃣ Skip duplicates using:
   if(i != index && nums[i] == nums[i-1]) continue;

========================================================
Time Complexity: O(n⁴)
Space Complexity: O(4) recursion stack
========================================================
*/

class Solution {
public:

    void f(vector<int>& nums,
           vector<vector<int>>& ans,
           vector<int>& v,
           int index,
           int target,
           long sum)
    {
        // Base case
        if (index >= nums.size() || v.size() == 4) {

            if (v.size() == 4 && sum == target) {
                ans.push_back(v);
            }
            return;
        }

        // Try all elements starting from index
        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if (i != index && nums[i] == nums[i - 1])
                continue;

            // Choose element
            v.push_back(nums[i]);

            // Recurse
            f(nums, ans, v, i + 1, target, sum + nums[i]);

            // Backtrack
            v.pop_back();
        }
    }


    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        f(nums, ans, v, 0, target, 0);

        return ans;
    }
};


int main() {

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution obj;

    vector<vector<int>> result = obj.fourSum(nums, target);

    cout << "Quadruplets:\n";

    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}