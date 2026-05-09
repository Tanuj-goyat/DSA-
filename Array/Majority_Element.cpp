#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Majority Element
Platform: LeetCode 169
========================================================

Problem Statement:
Given an array nums of size n,
return the majority element.

The majority element is the element that appears
more than ⌊ n / 2 ⌋ times.

It is guaranteed that the majority element exists.

Example:
Input:
[2,2,1,1,1,2,2]

Output:
2

========================================================
Approach Used (Moore's Voting Algorithm):

Key Idea:
- Majority element frequency > n/2
- Every non-major element can cancel one occurrence
  of majority element

Step 1: Maintain:
        major → current candidate
        count → frequency balance

Step 2:
        if count == 0
            choose new candidate

        if current element == major
            count++

        else
            count--

Step 3:
        Final candidate = majority element

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int majorityElement(vector<int>& nums) {

        int major = 0;
        int count = 0;

        // ------------------------------
        // Moore's Voting Algorithm
        // ------------------------------
        for (int i = 0; i < nums.size(); i++) {

            // Choose new candidate
            if (count == 0) {
                major = nums[i];
                count = 1;
            }

            // Same as candidate
            else if (nums[i] == major) {
                count++;
            }

            // Different element
            else {
                count--;
            }
        }

        // Majority element always exists
        return major;
    }
};


int main() {

    vector<int> nums = {2,2,1,1,1,2,2};

    Solution obj;

    int result = obj.majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    return 0;
}