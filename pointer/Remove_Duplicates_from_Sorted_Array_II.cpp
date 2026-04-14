#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem Name: Remove Duplicates from Sorted Array II
Platform: LeetCode
Problem Number: 80
========================================================

Problem Statement:
Given a sorted array nums, remove duplicates in-place
such that each element appears at most twice.

Return the new length.

Example:
Input:
[1,1,1,2,2,3]

Output:
Length = 5
Array = [1,1,2,2,3]

========================================================
Your Approach (Mark + Sort)

1️⃣ Allow at most 2 occurrences

2️⃣ If more than 2:
   → replace with large value (maxi)

3️⃣ Count duplicates removed

4️⃣ Sort array again to push invalid values to end

========================================================
Time Complexity: O(n log n) (due to sorting)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        int maxi = nums[n - 1] + 1; // value greater than all elements

        int current_element = nums[0];
        int count = 0;
        int duplicate_count = 0;

        // Step 1: Mark extra duplicates
        for (int i = 0; i < n; i++) {

            if (nums[i] == current_element) {

                if (count < 2) {
                    count++;
                } else {
                    nums[i] = maxi;     // mark invalid
                    duplicate_count++;
                }
            }
            else {
                current_element = nums[i];
                count = 1;
            }
        }

        // Step 2: Move invalid values to end
        sort(nums.begin(), nums.end());

        return n - duplicate_count;
    }
};


int main() {

    vector<int> nums = {1,1,1,2,2,3};

    Solution obj;

    int newLength = obj.removeDuplicates(nums);

    cout << "New Length: " << newLength << endl;

    cout << "Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}