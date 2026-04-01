#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
========================================================
Problem Name: 3Sum Closest
Platform: LeetCode
Problem Number: 16
========================================================

Problem Statement:
Given an integer array nums of length n and an integer
target, find three integers in nums such that the sum
is closest to target.

Return the sum of the three integers.

Example:
Input:
nums = [-1,2,1,-4], target = 1

Output:
2

Explanation:
(-1 + 2 + 1 = 2) → closest to 1

========================================================
Approach (Sorting + Two Pointers)

1️⃣ Sort the array

2️⃣ Fix one element (i)

3️⃣ Use two pointers:
   j → i+1
   k → end

4️⃣ Calculate sum:
   - Update closest value (near)
   - Move pointers based on comparison

========================================================
Time Complexity: O(n²)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // Step 1: Sort array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initialize closest sum
        int near = nums[0] + nums[1] + nums[2];

        // Step 2: Fix first element
        for (int i = 0; i < n - 2; i++) {

            int j = i + 1;
            int k = n - 1;

            // Step 3: Two pointer approach
            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                // Update closest sum
                if (abs(target - near) > abs(target - sum)) {
                    near = sum;
                }

                // If exact match found
                if (sum == target) {
                    return target;
                }
                else if (sum < target) {
                    j++;   // increase sum
                }
                else {
                    k--;   // decrease sum
                }
            }
        }

        return near;
    }
};


int main() {

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    Solution obj;

    cout << "Closest Sum: "
         << obj.threeSumClosest(nums, target);

    return 0;
}