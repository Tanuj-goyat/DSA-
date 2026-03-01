#include <iostream>
#include <vector>
#include <algorithm>   // For sort()
using namespace std;

/*
========================================================
Problem Name: Contains Duplicate
Platform: LeetCode
Problem Number: 217
========================================================

Problem Statement:
Given an integer array nums,
return true if any value appears at least twice,
and return false if every element is distinct.

Example:
Input:  [1,2,3,1]
Output: true

Input:  [1,2,3,4]
Output: false

========================================================
Approach Used (Sorting Method):

1️⃣ Sort the array.
2️⃣ After sorting, duplicate elements will be adjacent.
3️⃣ Traverse once and check:
     if v[i] == v[i+1] → duplicate found.

Time Complexity: O(n log n)  (because of sorting)
Space Complexity: O(1) extra space (ignoring sort stack)

========================================================
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        
        // Step 1: Sort the array
        sort(v.begin(), v.end());
        
        // Step 2: Check adjacent elements
        for (int i = 0; i < v.size() - 1; i++) {
            
            if (v[i] == v[i + 1]) 
                return true;   // Duplicate found
        }
        
        return false;   // No duplicates found
    }
};


int main() {
    
    vector<int> nums = {1, 2, 3, 1};
    
    Solution obj;
    bool result = obj.containsDuplicate(nums);
    
    if (result)
        cout << "Contains Duplicate: Yes" << endl;
    else
        cout << "Contains Duplicate: No" << endl;
    
    return 0;
}