#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem Name: Combination Sum II
Platform: LeetCode
Problem Number: 40
========================================================

Problem Statement:
Given a collection of candidate numbers (candidates)
and a target number (target), find all unique combinations
where the candidate numbers sum to target.

Each number may be used ONLY ONCE.

Note:
The solution set must not contain duplicate combinations.

Example:

Input:
candidates = [10,1,2,7,6,1,5]
target = 8

Output:
[
 [1,1,6],
 [1,2,5],
 [1,7],
 [2,6]
]

========================================================
Approach (Backtracking + Sorting)

Key Differences from Combination Sum I:
❌ Cannot reuse elements
✅ Must avoid duplicate combinations

Steps:

1️⃣ Sort the array
   → Helps skip duplicates
   → Helps early stopping

2️⃣ Use recursion:
   - Loop from current index
   - Pick element
   - Move to next index (i+1)

3️⃣ Skip duplicates:
   if (i > index && candidates[i] == candidates[i-1])
       continue;

4️⃣ Stop early:
   if element > target → break

========================================================
Time Complexity: Exponential
Space Complexity: O(target)

========================================================
*/

class Solution {
private:

    void f(vector<vector<int>>& ans,
           vector<int>& v,
           int index,
           int target,
           vector<int>& candidates)
    {
        // Base case
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Stop if element exceeds target
            if (candidates[i] > target)
                break;

            // Pick element
            v.push_back(candidates[i]);

            // Move to next index (no reuse allowed)
            f(ans, v, i + 1, target - candidates[i], candidates);

            // Backtrack
            v.pop_back();
        }
    }

public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> v;

        f(ans, v, 0, target, candidates);

        return ans;
    }
};


int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    Solution obj;

    vector<vector<int>> result = obj.combinationSum2(candidates, target);

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