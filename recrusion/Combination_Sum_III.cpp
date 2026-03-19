#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Combination Sum III
Platform: LeetCode
Problem Number: 216
========================================================

Problem Statement:
Find all valid combinations of k numbers that sum up to n
such that:

1. Only numbers from 1 to 9 are used
2. Each number is used at most once
3. The combination should contain exactly k numbers

Return all possible valid combinations.

Example:
Input: k = 3, n = 7
Output: [[1,2,4]]

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]

========================================================
Approach (Recursion + Backtracking)

At each number from 1 to 9, we have two choices:

1️⃣ Pick the current number
   - Add it to current combination
   - Increase sum
   - Move to next number

2️⃣ Do not pick the current number
   - Simply move to next number

Base Case:
- If index goes beyond 9
- Or current combination size becomes k

Then check:
If size == k and sum == target,
store the combination.

========================================================
Time Complexity: Exponential
Space Complexity: O(k) recursion stack
========================================================
*/

class Solution {
private:
    void f(vector<vector<int>>& ans,
           vector<int>& v,
           int target,
           int k,
           int index,
           int sum) {
        
        // Base case:
        // Stop if number goes beyond 9
        // or combination size already reached/exceeded k
        if (index > 9 || v.size() >= k) {
            if (v.size() == k && sum == target) {
                ans.push_back(v);
            }
            return;
        }

        // --------------------------------
        // 1️⃣ Pick current number
        // --------------------------------
        v.push_back(index);
        f(ans, v, target, k, index + 1, sum + index);

        // --------------------------------
        // Backtrack
        // --------------------------------
        v.pop_back();

        // --------------------------------
        // 2️⃣ Do not pick current number
        // --------------------------------
        f(ans, v, target, k, index + 1, sum);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;

        // Start from number 1 with sum 0
        f(ans, v, n, k, 1, 0);

        return ans;
    }
};

int main() {
    int k = 3;
    int n = 9;

    Solution obj;
    vector<vector<int>> result = obj.combinationSum3(k, n);

    cout << "Combinations:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}