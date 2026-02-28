#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Single Number
Platform: LeetCode
Problem Number: 136
========================================================

Problem Statement:
Given a non-empty array of integers nums,
every element appears twice except for one.
Find that single one.

You must implement a solution with:
- Linear runtime complexity O(n)
- Constant extra space O(1)

Example:
Input:  [2, 2, 1]
Output: 1

Input:  [4, 1, 2, 1, 2]
Output: 4

========================================================
Approach Used (Bit Manipulation - XOR):

We use XOR (^) operator.

Important XOR properties:
1. a ^ a = 0
2. a ^ 0 = a
3. XOR is commutative and associative

So:
If every number appears twice except one,
all duplicate numbers cancel out.

Example:
4 ^ 1 ^ 2 ^ 1 ^ 2
= (1 ^ 1) ^ (2 ^ 2) ^ 4
= 0 ^ 0 ^ 4
= 4

Thus the remaining value is the single number.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;   // This will store the final single number
        
        // Traverse through all elements
        for (int i = 0; i < nums.size(); i++) {
            
            // XOR current number with ans
            ans = ans ^ nums[i];
            
            // Duplicate numbers cancel out
        }
        
        return ans;    // Remaining number is the single number
    }
};


int main() {
    
    vector<int> nums = {4, 1, 2, 1, 2};
    
    Solution obj;
    int result = obj.singleNumber(nums);
    
    cout << "Single Number is: " << result << endl;
    
    return 0;
}