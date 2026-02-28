#include <iostream>
#include <vector>
#include <cmath>   // For abs()
using namespace std;

/*
========================================================
Problem Name: Find All Duplicates in an Array
Platform: LeetCode
Problem Number: 442
========================================================

Problem Statement:
Given an integer array nums of length n where:
- 1 ≤ nums[i] ≤ n
- Each integer appears once or twice

Return all the integers that appear twice.

Example:
Input:  [4,3,2,7,8,2,3,1]
Output: [2,3]

========================================================
Approach Used (Index Marking / Sign Flipping):

Since values are from 1 to n,
we can use the array itself to track visits.

Idea:
For each number x:
1. Go to index abs(x) - 1
2. If the value at that index is negative,
   it means we have already visited this number → duplicate
3. Otherwise, make it negative to mark visited

This works because:
- First visit → mark negative
- Second visit → already negative → duplicate

Time Complexity: O(n)
Space Complexity: O(1) extra space
(ignoring the output vector)

========================================================
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;  // Stores duplicate elements
        
        // Traverse each number in the array
        for (int x : nums) {
            
            // Get index corresponding to current number
            int index = abs(x) - 1;
            
            // If already negative, number is duplicate
            if (nums[index] < 0) {
                ans.push_back(abs(x));
            }
            else {
                // Mark as visited by making it negative
                nums[index] *= -1;
            }
        }
        
        return ans;
    }
};


int main() {
    
    vector<int> nums = {4,3,2,7,8,2,3,1};
    
    Solution obj;
    vector<int> result = obj.findDuplicates(nums);
    
    cout << "Duplicates are: ";
    for (int x : result) {
        cout << x << " ";
    }
    
    return 0;
}