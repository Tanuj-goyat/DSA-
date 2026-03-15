#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Squares of a Sorted Array
Platform: LeetCode
Problem Number: 977
========================================================

Problem Statement:
Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in
non-decreasing order.

Example:

Input:
nums = [-4, -1, 0, 3, 10]

Output:
[0, 1, 9, 16, 100]

Explanation:
After squaring:
[16, 1, 0, 9, 100]

After sorting:
[0, 1, 9, 16, 100]

========================================================
Approach (Merge Two Sorted Parts)

Observation:
Negative numbers when squared may become large.

Example:
[-7, -3, -1, 4, 8]

Squares:
[49, 9, 1, 16, 64]

Left part → negatives (in decreasing absolute value)
Right part → positives (already increasing)

Steps:

1️⃣ Find first non-negative number.
2️⃣ Use two pointers:
      i → last negative number
      j → first non-negative number
3️⃣ Compare absolute values and push smaller square.
4️⃣ Merge like merge-sort.

========================================================
Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> v;

        // Edge case: single element
        if (nums.size() < 2) {
            v.push_back(nums[0] * nums[0]);
            return v;
        }

        int i = 0;
        int j = 0;

        // Find first non-negative number
        while (i < nums.size() && nums[i] <= 0) {
            i++;
        }

        j = i;   // first non-negative
        i--;     // last negative

        // Merge squares like merge-sort
        while (i >= 0 && j < nums.size()) {

            if (nums[i] * (-1) < nums[j]) {
                v.push_back(nums[i] * nums[i]);
                i--;
            } 
            else {
                v.push_back(nums[j] * nums[j]);
                j++;
            }
        }

        // Add remaining negative numbers
        while (i >= 0) {
            v.push_back(nums[i] * nums[i]);
            i--;
        }

        // Add remaining positive numbers
        while (j < nums.size()) {
            v.push_back(nums[j] * nums[j]);
            j++;
        }

        return v;
    }
};


int main() {

    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution obj;

    vector<int> result = obj.sortedSquares(nums);

    cout << "Sorted Squares: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}