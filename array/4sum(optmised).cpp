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

========================================================
Approach (Optimal: Sorting + Two Pointers)

Steps:

1️⃣ Sort the array

2️⃣ Fix first element (a)

3️⃣ Fix second element (b)

4️⃣ Use two pointers:
   c → b+1
   d → end

5️⃣ Check:
   nums[a] + nums[b] + nums[c] + nums[d]

6️⃣ Skip duplicates for:
   a, b, c, d

========================================================
Time Complexity: O(n³)
Space Complexity: O(1) (excluding output)
========================================================
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        // Edge case
        if (nums.size() < 4) return {};

        // Fix first element
        for (int a = 0; a < nums.size() - 3; a++) {

            // Skip duplicates for a
            if (a > 0 && nums[a] == nums[a - 1])
                continue;

            // Fix second element
            for (int b = a + 1; b < nums.size() - 2; b++) {

                // Skip duplicates for b
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;

                int c = b + 1;
                int d = nums.size() - 1;

                // Remaining sum to find
                long long sum = (long long)target - nums[a] - nums[b];

                // Two pointer search
                while (c < d) {

                    long long curr = (long long)nums[c] + nums[d];

                    if (curr == sum) {

                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});

                        // Skip duplicates for c
                        while (c < d && nums[c] == nums[c + 1])
                            c++;

                        // Skip duplicates for d
                        while (c < d && nums[d] == nums[d - 1])
                            d--;

                        c++;
                        d--;
                    }
                    else if (curr < sum) {
                        c++;
                    }
                    else {
                        d--;
                    }
                }
            }
        }

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