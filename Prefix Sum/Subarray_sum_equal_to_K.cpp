#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem: Subarray Sum Equals K
Platform: LeetCode 560
========================================================

Problem Statement:
Given an array nums and an integer k,
return the total number of subarrays
whose sum equals k.

Example:
Input:
nums = [1,1,1], k = 2

Output:
2

Explanation:
Subarrays:
[1,1] at index (0,1)
[1,1] at index (1,2)

========================================================
Approach Used (Prefix Sum + Hash Map):

Key Idea:
If:

prefixSum[j] - prefixSum[i] = k

Then:
prefixSum[i] = prefixSum[j] - k

So for every current sum,
check whether (sum - k) already existed.

Step 1: Maintain running prefix sum

Step 2: Store frequency of prefix sums in map

Step 3: If (sum - k) exists,
        add its frequency to answer

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {

        int count = 0;

        // prefixSum -> frequency
        unordered_map<int, int> m;

        int sum = 0;

        // ------------------------------
        // Traverse array
        // ------------------------------
        for (int i = 0; i < nums.size(); i++) {

            // Current prefix sum
            sum += nums[i];

            // ------------------------------
            // Check if subarray exists
            // ------------------------------
            if (m.find(sum - k) != m.end()) {
                count += m[sum - k];
            }

            // If prefix sum itself equals k
            if (sum == k)
                count++;

            // Store current prefix sum
            m[sum]++;
        }

        return count;
    }
};


int main() {

    vector<int> nums = {1,1,1};
    int k = 2;

    Solution obj;

    int result = obj.subarraySum(nums, k);

    cout << "Total Subarrays: " << result << endl;

    return 0;
}