#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Combination Sum
Platform: LeetCode
Problem Number: 39
========================================================

Problem Statement:
Given an array of distinct integers candidates and a
target integer target, return all unique combinations
of candidates where the chosen numbers sum to target.

You may use the same number from candidates
unlimited times.

Example:

Input:
candidates = [2,3,6,7]
target = 7

Output:
[
 [2,2,3],
 [7]
]

========================================================
Approach (Recursion + Backtracking)

At every index we have two choices:

1️⃣ Pick the current number
   - Add it to current combination
   - Reduce target
   - Stay at same index (because we can reuse elements)

2️⃣ Do not pick the number
   - Move to next index

Base Case:
If target becomes 0 → valid combination
If target < 0 or index reaches end → stop recursion

========================================================
Time Complexity: Exponential
Space Complexity: O(target) recursion stack
========================================================
*/

class Solution {
private:

    // Recursive helper function
    void f(vector<int> arr, int target, vector<int>& v, int index, int n,
           vector<vector<int>>& ans)
    {
        // Base condition
        if (target <= 0 || index >= n)
        {
            if (target == 0)
            {
                ans.push_back(v);   // store valid combination
            }

            return;
        }

        // --------------------------------
        // 1️⃣ Pick the current element
        // --------------------------------
        v.push_back(arr[index]);

        // stay at same index because element can be reused
        f(arr, target - arr[index], v, index, n, ans);

        // --------------------------------
        // Backtrack
        // --------------------------------
        v.pop_back();

        // --------------------------------
        // 2️⃣ Do not pick the element
        // --------------------------------
        f(arr, target, v, index + 1, n, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> v;
        vector<vector<int>> ans;

        int n = candidates.size();

        f(candidates, target, v, 0, n, ans);

        return ans;
    }
};


int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution obj;

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "Combinations:\n";

    for (auto &vec : result)
    {
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}