#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem Name: Two Sum
Platform: LeetCode
Problem Number: 1
========================================================

Problem Statement:
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up
to target.

You may assume that each input has exactly one solution,
and you may not use the same element twice.

Example:
Input:
nums = [2, 7, 11, 15], target = 9

Output:
[0, 1]

Because:
nums[0] + nums[1] = 2 + 7 = 9

========================================================
Approach (Hash Map)

We use an unordered_map to store:
value -> index

Step 1:
Store every number with its index in the map.

Step 2:
For each element nums[i], calculate:
remaining = target - nums[i]

If remaining exists in map and its index is not same as i,
then we found the answer.

========================================================
Time Complexity: O(n)
Space Complexity: O(n)
========================================================
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;   // stores value -> index
        vector<int> v;               // stores answer indices

        // Store all numbers with their indices
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        // Check for the required pair
        for (int i = 0; i < nums.size(); i++) {
            int nwtarget = target - nums[i];

            // If required number exists and is not same index
            if (m.find(nwtarget) != m.end() && m[nwtarget] != i) {
                v.push_back(i);
                v.push_back(m[nwtarget]);
                break;
            }
        }

        return v;
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> result = obj.twoSum(nums, target);

    cout << "Indices: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}