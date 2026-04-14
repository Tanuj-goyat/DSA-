#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Two Sum II - Input Array Is Sorted
Platform: LeetCode
Problem Number: 167
========================================================

Problem Statement:
Given a 1-indexed array of integers that is sorted in
non-decreasing order, find two numbers such that they
add up to a specific target number.

Return:
Indices (1-based) of the two numbers.

========================================================
Approach (Two Pointer)

1️⃣ Use two pointers:
   - left → start
   - right → end

2️⃣ If sum == target → return answer

3️⃣ If sum < target → move left forward

4️⃣ If sum > target → move right backward

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        int left = 0;
        int right = n - 1;

        while (left < right) {

            int sum = nums[left] + nums[right];

            if (sum == target) {
                return {left + 1, right + 1}; // 1-based index
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {}; // should not happen (guaranteed solution)
    }
};


int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution obj;

    vector<int> ans = obj.twoSum(nums, target);

    cout << "Indices: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}