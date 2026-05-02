#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem Name: 3Sum
Platform: LeetCode
Problem Number: 15
========================================================

Problem Statement:
Given an integer array nums, return all unique triplets
[a, b, c] such that:

a + b + c = 0

The solution set must not contain duplicate triplets.

Example:
Input:
nums = [-1,0,1,2,-1,-4]

Output:
[
 [-1,-1,2],
 [-1,0,1]
]

========================================================
Approach (Sorting + Two Pointers)

Steps:

1️⃣ Sort the array

2️⃣ Fix one element (i)

3️⃣ Use two pointers:
   l → i+1
   r → end

4️⃣ Check:
   sum = nums[i] + nums[l] + nums[r]

   - If sum == 0 → store result
   - If sum < 0 → move left pointer
   - If sum > 0 → move right pointer

5️⃣ Skip duplicates for:
   - i
   - l
   - r

========================================================
Time Complexity: O(n²)
Space Complexity: O(1) (excluding output)

========================================================
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Step 1: Sort array
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        // Step 2: Fix first element
        for(int i = 0; i < nums.size() - 2; i++) {

            // Skip duplicate values of i
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = nums.size() - 1;

            // Step 3: Two pointer approach
            while(l < r) {

                int sum = nums[i] + nums[l] + nums[r];

                if(sum == 0) {

                    // Store valid triplet
                    ans.push_back({nums[i], nums[l], nums[r]});

                    // Skip duplicates for l
                    while(l < r && nums[l] == nums[l + 1])
                        l++;

                    // Skip duplicates for r
                    while(l < r && nums[r] == nums[r - 1])
                        r--;

                    l++;
                    r--;
                }
                else if(sum < 0) {
                    l++;   // need bigger sum
                }
                else {
                    r--;   // need smaller sum
                }
            }
        }

        return ans;
    }
};


int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution obj;

    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Triplets:\n";

    for(auto &vec : result) {
        cout << "[ ";
        for(int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}