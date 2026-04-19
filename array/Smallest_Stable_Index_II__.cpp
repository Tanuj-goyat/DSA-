#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Smallest
Platform: LeetCode
Problem Number: 3904
========================================================

Problem Statement:
Given an array nums and an integer k, find the smallest
index i such that:

max(nums[0..i]) - min(nums[i..n-1]) <= k

Return that index, or -1 if no such index exists.

========================================================
Approach (Hash Map)

1️⃣ Build suffix minimum array:
   m[i] = min element from i → n-1

2️⃣ Traverse from left:
   keep track of prefix maximum

3️⃣ For each i:
   check:
   prefix_max - suffix_min <= k

4️⃣ First valid i → answer

========================================================
Time Complexity: O(n)
Space Complexity: O(n)
========================================================
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        // Edge case
        if (n == 1) {
            return (0 <= k) ? 0 : -1;
        }

        // Step 1: Build suffix minimum array
        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        // Step 2: Traverse and maintain prefix max
        int prefixMax = nums[0];

        for (int i = 0; i < n; i++) {

            prefixMax = max(prefixMax, nums[i]);

            // Step 3: Check condition
            if (prefixMax - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};


int main() {

    vector<int> nums = {5, 3, 6, 2, 4};
    int k = 2;

    Solution obj;

    cout << "First Stable Index: "
         << obj.firstStableIndex(nums, k);

    return 0;
}