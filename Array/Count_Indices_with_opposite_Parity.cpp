#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Count Indices with Opposite Parity
Platform: LeetCode (3917)
========================================================

Problem Statement:
Given an array nums, for each element:
- If it is even → count how many odd numbers remain
- If it is odd  → count how many even numbers remain

Return the result array.

Example:
Input:
nums = [1,2,3,4]

Output:
[2,2,1,1]

Explanation:
For each index:
1 → even count = 2 (2,4)
2 → odd count  = 2 (1,3)
3 → even count = 1 (4)
4 → odd count  = 1 (3)

========================================================
Approach Used (Counting + Traversal):

Step 1: Count total odd and even numbers

Step 2: Traverse array:
        - If current is even → answer = totalOdd
        - If current is odd  → answer = totalEven

Step 3: Reduce count after processing

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    vector<int> countOppositeParity(vector<int>& nums) {

        int totalOdd = 0;
        int totalEven = 0;

        // ------------------------------
        // Step 1: Count odds and evens
        // ------------------------------
        for (int x : nums) {
            if (x % 2 == 0)
                totalEven++;
            else
                totalOdd++;
        }

        vector<int> ans;

        // ------------------------------
        // Step 2: Build answer
        // ------------------------------
        for (int x : nums) {

            if (x % 2 == 0) {
                ans.push_back(totalOdd);
                totalEven--;   // reduce current even
            }
            else {
                ans.push_back(totalEven);
                totalOdd--;    // reduce current odd
            }
        }

        return ans;
    }
};


int main() {

    vector<int> nums = {1,2,3,4};

    Solution obj;

    vector<int> result = obj.countOppositeParity(nums);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}