#include <iostream>
#include <vector>
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
Approach Used (Cyclic Sort Technique):

Since numbers are from 1 to n,
each number ideally should be at index (number - 1).

Step 1: Place each element at its correct position:
        nums[i] should be at index nums[i] - 1

        If it's not in correct position,
        swap it with the element at its correct index.

Step 2: After rearrangement,
        if nums[i] != i + 1,
        then nums[i] is a duplicate.

Time Complexity: O(n)
Space Complexity: O(1) extra space
(ignoring output vector)

========================================================
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int i = 0;
        int n = nums.size();
        
        // ------------------------------
        // Step 1: Cyclic Sort Placement
        // ------------------------------
        while (i < n) {
            
            // If current number is not at correct position
            // and not equal to the number already there
            if (nums[i] != nums[nums[i] - 1]) {
                
                // Swap it to its correct index
                swap(nums[i], nums[nums[i] - 1]);
            }
            else {
                // Move forward if already correct
                i++;
            }
        }
        
        // ------------------------------
        // Step 2: Collect Duplicates
        // ------------------------------
        vector<int> v;
        
        for (int i = 0; i < n; i++) {
            
            // If number is not at correct index,
            // it means this number is duplicate
            if (nums[i] - 1 != i) {
                v.push_back(nums[i]);
            }
        }
        
        return v;
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