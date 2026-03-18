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
 [3,2,1],
 [3,1,2]
]

========================================================
Approach (Backtracking using Swapping)

Instead of using an extra frequency array,
we fix one position at a time.

Idea:
- At index 0, try placing every element there
- At index 1, try placing every remaining element there
- Continue until the whole array is fixed

Steps:
1. Swap current index with every possible index
2. Recur for next index
3. Backtrack by swapping again

Base Case:
When index reaches nums.size(),
one full permutation is formed.

========================================================
Time Complexity: O(n * n!)
Space Complexity: O(n) recursion stack
========================================================
*/

class Solution {
private:
    void f(vector<vector<int>>& ans, int index, vector<int>& nums) {
        
        // Base case: one permutation is formed
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try every element at current index
        for (int i = index; i < nums.size(); i++) {
            
            // Place nums[i] at current position
            swap(nums[index], nums[i]);

            // Recur for next position
            f(ans, index + 1, nums);

            // Backtrack to restore original array
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f(ans, 0, nums);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution obj;
    vector<vector<int>> result = obj.permute(nums);

    cout << "Permutations:\n";
    for (auto &perm : result) {
        cout << "[ ";
        for (int x : perm) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}