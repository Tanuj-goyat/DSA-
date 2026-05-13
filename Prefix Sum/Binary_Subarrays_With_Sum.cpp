#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem: Binary Subarrays With Sum
Platform: LeetCode (930)
========================================================

Problem Statement:
Given a binary array nums and an integer goal,
return the number of non-empty subarrays
with sum equal to goal.

Example:
Input:
nums = [1,0,1,0,1]
goal = 2

Output:
4

Explanation:
Subarrays are:
[1,0,1]
[1,0,1,0]
[0,1,0,1]
[1,0,1]

========================================================
Approach Used (Prefix Sum + Hash Map):

Key Idea:
If:

currentSum - previousSum = goal

Then:
previousSum = currentSum - goal

So for every prefix sum,
check whether (sum - goal) already existed.

Step 1: Maintain running sum

Step 2: Store frequency of prefix sums

Step 3: Add frequency of (sum - goal)

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int, int> m;

        int n = nums.size();

        int sum = 0;
        int count = 0;

        // ------------------------------
        // Traverse array
        // ------------------------------
        for (int i = 0; i < n; i++) {

            // Current prefix sum
            sum += nums[i];

            // If prefix sum itself equals goal
            if (sum == goal) {
                count++;
            }

            // ------------------------------
            // Check previous prefix sums
            // ------------------------------
            if (m.find(sum - goal) != m.end()) {

                count += m[sum - goal];
            }

            // Store current prefix sum
            m[sum]++;
        }

        return count;
    }
};


int main() {

    vector<int> nums = {1,0,1,0,1};

    int goal = 2;

    Solution obj;

    int result =
        obj.numSubarraysWithSum(nums, goal);

    cout << "Total Subarrays: "
         << result << endl;

    return 0;
}