#include <bits/stdc++.h>
#include <numeric>
using namespace std;

/*
========================================================
Problem: Sum of GCD of Formed Pairs
Platform: LeetCode 3867
========================================================

Problem Statement:
Given an integer array nums.

Step 1:
For every index,
compute the maximum element seen so far.

Step 2:
Compute:

gcd(nums[i], prefixMaximum)

for every position.

Step 3:
Sort all computed GCD values.

Step 4:
Pair the smallest value with the
largest value, the second smallest
with the second largest, and so on.

Return the sum of the GCD of every pair.

========================================================
Approach Used (Prefix Maximum + GCD)

Step 1:
Construct the prefix maximum array.

Step 2:
Compute the GCD of every element with
its corresponding prefix maximum.

Step 3:
Sort the GCD values.

Step 4:
Use two pointers to pair the smallest
and largest values.

Step 5:
Accumulate the GCD of every pair.

Time Complexity: O(n log n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    long long gcdSum(vector<int>& nums) {

        vector<int> mx;

        vector<int> prefixGcd;

        int maxi = 0;

        // ------------------------------
        // Compute prefix maximum and GCD
        // ------------------------------
        for (int i = 0; i < nums.size(); i++) {

            maxi = max(maxi, nums[i]);

            mx.push_back(maxi);

            prefixGcd.push_back(__gcd(nums[i], mx[i]));
        }

        // ------------------------------
        // Sort GCD values
        // ------------------------------
        sort(prefixGcd.begin(), prefixGcd.end());

        int left = 0;

        int right = prefixGcd.size() - 1;

        long long sum = 0;

        // ------------------------------
        // Pair smallest and largest
        // ------------------------------
        while (left < right) {

            sum += __gcd(prefixGcd[left], prefixGcd[right]);

            left++;

            right--;
        }

        return sum;
    }
};


int main() {

    vector<int> nums = {6, 4, 12, 8};

    Solution obj;

    long long answer = obj.gcdSum(nums);

    cout << answer << endl;

    return 0;
}