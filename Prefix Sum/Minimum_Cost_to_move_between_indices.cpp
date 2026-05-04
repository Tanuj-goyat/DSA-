#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: minimum cost to move between indices
Platform: LeetCode (3919)
========================================================

Problem Statement:
Given an array nums and queries [a, b]:

- If a < b → move forward
- If a > b → move backward

Cost rule:
Based on difference comparison between neighbors.

Return cost for each query.

========================================================
Approach Used (Prefix Cost Arrays):

Step 1: Build two arrays:
        upper → forward cost prefix
        lower → backward cost prefix

Step 2: For query:
        if a < b → use upper
        if a > b → use lower

Step 3: Answer using prefix subtraction

Time Complexity: O(n + q)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Step 1: Build prefix arrays
    // ------------------------------
    void store(vector<int>& upper, vector<int>& lower, vector<int>& nums) {

        int n = nums.size();

        // ------------------------------
        // Forward prefix (upper)
        // ------------------------------
        upper.push_back(0);
        upper.push_back(1);

        int cost = 1;

        for (int i = 1; i < n - 1; i++) {

            if (nums[i + 1] - nums[i] < nums[i] - nums[i - 1])
                cost += 1;
            else
                cost += nums[i + 1] - nums[i];

            upper.push_back(cost);
        }

        // ------------------------------
        // Backward prefix (lower)
        // ------------------------------
        lower.push_back(0);
        lower.push_back(1);

        cost = 1;

        for (int i = n - 2; i > 0; i--) {

            if (nums[i + 1] - nums[i] < nums[i] - nums[i - 1])
                cost += nums[i] - nums[i - 1];
            else
                cost += 1;

            lower.push_back(cost);
        }
    }


    // ------------------------------
    // Step 2: Answer queries
    // ------------------------------
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& matrix) {

        int n = nums.size();

        vector<int> upper;
        vector<int> lower;

        store(upper, lower, nums);

        vector<int> ans;

        for (int i = 0; i < matrix.size(); i++) {

            int a = matrix[i][0];
            int b = matrix[i][1];

            if (a == b) {
                ans.push_back(0);
            }

            else if (a < b) {
                int cost = upper[b] - upper[a];
                ans.push_back(cost);
            }

            else {
                int cost = lower[n - 1 - b] - lower[n - 1 - a];
                ans.push_back(cost);
            }
        }

        return ans;
    }
};


int main() {

    vector<int> nums = {1, 3, 6, 10};

    vector<vector<int>> queries = {
        {0, 2},
        {2, 0},
        {1, 3}
    };

    Solution obj;

    vector<int> result = obj.minCost(nums, queries);

    cout << "Results:\n";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}