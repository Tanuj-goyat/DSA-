#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Rearrange Array Elements by Sign
Platform: LeetCode (2149)
========================================================

Problem Statement:
Given an array nums containing equal number of
positive and negative integers.

Rearrange the array such that:
- Positive and negative numbers alternate
- Positive number appears first
- Relative order is preserved

Example:
Input:
[3,1,-2,-5,2,-4]

Output:
[3,-2,1,-5,2,-4]

========================================================
Approach Used (Two Index Placement):

Step 1: Create answer array

Step 2: Maintain:
        pindex → next even index for positive
        nindex → next odd index for negative

Step 3: Traverse nums:
        positive → place at pindex
        negative → place at nindex

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    vector<int> rearrangeArray(vector<int>& nums) {

        int pindex = 0; // even index
        int nindex = 1; // odd index

        vector<int> ans(nums.size(), 0);

        // ------------------------------
        // Place elements alternatively
        // ------------------------------
        for (int i = 0; i < nums.size(); i++) {

            // Negative number
            if (nums[i] < 0) {
                ans[nindex] = nums[i];
                nindex += 2;
            }

            // Positive number
            else {
                ans[pindex] = nums[i];
                pindex += 2;
            }
        }

        return ans;
    }
};


int main() {

    vector<int> nums = {3,1,-2,-5,2,-4};

    Solution obj;

    vector<int> result = obj.rearrangeArray(nums);

    cout << "Rearranged Array:\n";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}