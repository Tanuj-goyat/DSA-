#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Combination Sum II
Platform: LeetCode (40)
========================================================

Problem Statement:
Given a collection of candidate numbers
(candidates) and a target value.

Find all unique combinations where the
chosen numbers sum to the target.

Each number may be used at most once.

The solution set must not contain
duplicate combinations.

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
Approach Used (Backtracking)

Step 1:
Sort the input array to make duplicate
elements adjacent.

Step 2:
Use recursion to generate all possible
combinations.

Step 3:
Skip duplicate elements at the same
recursion level.

Step 4:
If the current element exceeds the
remaining target, stop exploring
further.

Step 5:
Whenever the target becomes zero,
store the current combination.

Time Complexity: O(2ⁿ)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Generate all valid combinations
    // ------------------------------
    void f(vector<int>& db, vector<vector<int>>& ans, int index, int target, vector<int>& v) {

        if (index >= v.size() ||
            target <= 0) {

            if (target == 0) {

                ans.push_back(db);
            }

            return;
        }

        for (int i = index; i < v.size(); i++) {

            // ------------------------------
            // Skip duplicate elements
            // ------------------------------
            if (i != index && (v[i] == v[i - 1])) {

                continue;
            }

            // ------------------------------
            // No need to continue further
            // ------------------------------
            if (v[i] > target) {

                break;
            }

            // ------------------------------
            // Choose current element
            // ------------------------------
            db.push_back(v[i]);

            f(db, ans, i + 1, target - v[i], v);

            // ------------------------------
            // Backtrack
            // ------------------------------
            db.pop_back();
        }
    }

    vector<vector<int>> combinationSum2( vector<int>& candidates, int target) {

        // ------------------------------
        // Sort the candidates
        // ------------------------------
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;

        vector<int> db;

        // ------------------------------
        // Generate combinations
        // ------------------------------
        f(db, ans, 0, target, candidates);

        return ans;
    }
};


int main() {

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

    int target = 8;

    Solution obj;

    vector<vector<int>> answer = obj.combinationSum2(candidates, target);

    for (auto &v : answer) {

        cout << "[ ";

        for (int x : v) {

            cout << x << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}