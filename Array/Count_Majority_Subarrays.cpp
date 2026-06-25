#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Count Majority Subarrays
Platform: LeetCode 3737
========================================================

Problem Statement:
Given:

- An integer array nums
- An integer target

Count the number of subarrays in which
target is the majority element.

A target is considered a majority if:

2 × frequency(target) >
length of subarray

Return the total number of such
subarrays.

Example:
Input:
nums = [1, 2, 2]
target = 2

Output:
4

Explanation:
Valid subarrays are:

[2]
[2]
[2,2]
[1,2,2]

========================================================
Approach Used (Brute Force)

Step 1:
Generate every possible subarray.

Step 2:
Maintain the frequency of target
inside the current subarray.

Step 3:
Check whether:

2 × frequency >
subarray length

Step 4:
If true, increase the answer.

Time Complexity: O(n²)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int countMajoritySubarrays(
        vector<int>& nums,
        int target) {

        int count = 0;

        // ------------------------------
        // Generate all subarrays
        // ------------------------------
        for (int i = 0;
             i < nums.size();
             i++) {

            int freq = 0;

            for (int j = i;
                 j < nums.size();
                 j++) {

                // Count target frequency
                if (nums[j] == target)
                    freq++;

                // Check majority condition
                if (2 * freq >
                    j - i + 1)

                    count++;
            }
        }

        return count;
    }
};


int main() {

    vector<int> nums =
        {1, 2, 2};

    int target = 2;

    Solution obj;

    int answer =
        obj.countMajoritySubarrays(
            nums,
            target);

    cout << answer << endl;

    return 0;
}