#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem Name: Next Permutation
Platform: LeetCode
Problem Number: 31
========================================================

Problem Statement:
Implement next permutation, which rearranges numbers
into the lexicographically next greater permutation.

If such arrangement is not possible,
it must rearrange it to the lowest possible order.

Example:

Input:  [1,2,3]
Output: [1,3,2]

Input:  [3,2,1]
Output: [1,2,3]

========================================================
Approach (Optimal)

Steps:

1️⃣ Find the first decreasing element from right
   (index i such that nums[i] < nums[i+1])

2️⃣ If found:
   - Find just greater element on right side (index j)
   - Swap nums[i] and nums[j]

3️⃣ Reverse the part after i

Why reverse?
Because right side is in descending order → make it smallest

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find pivot (first decreasing element from right)
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If pivot found, find next greater element
        if (i >= 0) {
            int j = n - 1;

            while (j > i && nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};


int main() {

    vector<int> nums = {1, 2, 3};

    Solution obj;

    obj.nextPermutation(nums);

    cout << "Next Permutation: ";

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}