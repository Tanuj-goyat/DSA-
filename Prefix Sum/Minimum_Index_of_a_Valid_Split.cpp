#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem: Minimum Index of a Valid Split
Platform: LeetCode (2780)
========================================================

Problem Statement:
An element x is dominant in an array if:
frequency(x) * 2 > size of array

Return the minimum index i such that:
- nums[0...i] and nums[i+1...n-1]
both have the same dominant element.

If no valid split exists, return -1.

Example:
Input:
[1,2,2,2]

Output:
2

========================================================
Approach Used (Moore Voting + Prefix Check):

Step 1: Build prefix dominant array
        prefix[i] = dominant element in left part

Step 2: Build suffix dominant array
        back_prefix[i] = dominant element in right part

Step 3: Find first index where:
        prefix[i] == suffix[i+1]

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Build suffix dominant array
    // ------------------------------
    void back(vector<int>& nums,
              vector<int>& back_prefix) {

        int major = 0;
        int count = 0;

        unordered_map<int, int> m;

        for (int i = nums.size() - 1; i > 0; i--) {

            m[nums[i]]++;

            // Moore Voting
            if (count == 0) {
                major = nums[i];
                count = 1;
            }
            else if (nums[i] == major) {
                count++;
            }
            else {
                count--;
            }

            // Store dominant element
            if (count == 0) {
                back_prefix.push_back(-1);
            }
            else {

                // Check dominance
                if (m[major] > (nums.size() - i) / 2)
                    back_prefix.push_back(major);
                else
                    back_prefix.push_back(-1);
            }
        }
    }


    // ------------------------------
    // Build prefix dominant array
    // ------------------------------
    void front(vector<int>& nums,
               vector<int>& prefix) {

        int major = 0;
        int count = 0;

        unordered_map<int, int> m;

        for (int i = 0; i < nums.size() - 1; i++) {

            m[nums[i]]++;

            // Moore Voting
            if (count == 0) {
                major = nums[i];
                count = 1;
            }
            else if (nums[i] == major) {
                count++;
            }
            else {
                count--;
            }

            // Store dominant element
            if (count == 0) {
                prefix.push_back(-1);
            }
            else {

                // Check dominance
                if (m[major] > (i + 1) / 2)
                    prefix.push_back(major);
                else
                    prefix.push_back(-1);
            }
        }
    }


    // ------------------------------
    // Main function
    // ------------------------------
    int minimumIndex(vector<int>& nums) {

        vector<int> prefix;
        vector<int> back_prefix;

        // Build prefix and suffix info
        front(nums, prefix);
        back(nums, back_prefix);

        int n = prefix.size();

        // ------------------------------
        // Find valid split
        // ------------------------------
        for (int i = 0; i < n; i++) {

            if (prefix[i] == back_prefix[n - i - 1]
                && prefix[i] != -1)
                return i;
        }

        return -1;
    }
};


int main() {

    vector<int> nums = {1,2,2,2};

    Solution obj;

    int result = obj.minimumIndex(nums);

    cout << "Minimum Valid Index: "
         << result << endl;

    return 0;
}