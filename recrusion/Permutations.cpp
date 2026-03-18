#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Permutations
Platform: LeetCode
Problem Number: 46
========================================================

Problem Statement:
Given an array nums of distinct integers,
return all possible permutations.

Example:
Input:
nums = [1, 2, 3]

Output:
[
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
]

========================================================
Approach (Backtracking using Frequency Array)

We build permutations step by step.

At each step:
1. Try every element
2. If it is not already used, pick it
3. Mark it as used in freq array
4. Recur for next position
5. Backtrack:
   - unmark it
   - remove it from current permutation

Base Case:
When current permutation size becomes equal to nums.size(),
store it in answer.

========================================================
Time Complexity: O(n * n!)
Space Complexity: O(n) recursion stack + freq array
========================================================
*/

class Solution {
    void f(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums,
           vector<int>& freq) {
        
        // Base case: one full permutation is formed
        if (v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }

        // Try placing each number at current position
        for (int i = 0; i < nums.size(); i++) {
            if (freq[i] == 0) {
                freq[i] = 1;           // mark as used
                v.push_back(nums[i]);  // include current number

                f(ans, v, nums, freq); // recurse

                freq[i] = 0;           // backtrack: unmark
                v.pop_back();          // backtrack: remove number
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> freq(nums.size(), 0); // keeps track of used elements

        f(ans, v, nums, freq);

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution obj;
    vector<vector<int>> result = obj.permute(nums);

    cout << "Permutations:\n";
    for (auto& perm : result) {
        cout << "[ ";
        for (int x : perm) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}