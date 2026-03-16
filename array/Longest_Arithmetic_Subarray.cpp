#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Longest Arithmetic Subarray
========================================================

Problem Statement:
Given an array of integers, find the length of the
longest contiguous arithmetic subarray.

An arithmetic subarray means the difference between
consecutive elements is constant.

Example:
Input:
[3, 6, 9, 12]

Output:
4

Explanation:
Differences:
6-3 = 3
9-6 = 3
12-9 = 3

So the entire array is arithmetic.

--------------------------------------------------------

Example:
Input:
[9,4,7,2,10]

Output:
3

Arithmetic subarray:
[4,7,10]

========================================================
Approach

We traverse the array and maintain:

diff → current arithmetic difference
i    → start index of current arithmetic segment
j    → current position

If difference continues → extend subarray

If difference breaks → start a new arithmetic segment.

The function is called twice:
1️⃣ Original array
2️⃣ Reversed array

This helps catch arithmetic sequences that extend
in the opposite direction.

========================================================
Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {

    // Function to find longest arithmetic subarray
    int f(vector<int>& arr) {

        int n = arr.size();

        int ans = 2;                         // Minimum arithmetic length
        int diff = arr[1] - arr[0];          // Initial difference

        for (int i = 0, j = 2; j < n; j++) {

            int curr_diff = arr[j] - arr[j - 1];

            // If difference continues
            if (curr_diff == diff) {

                ans = max(ans, j - i + 1);
                continue;
            }

            // Difference changed
            int index = j;

            int value = arr[j - 1] + diff;

            // Try extending arithmetic pattern
            while (index + 1 < n && arr[index + 1] - value == diff) {

                value = arr[index + 1];
                index++;
            }

            ans = max(ans, index - i + 1);

            // Reset window
            i = j - 1;
            diff = curr_diff;
        }

        return ans;
    }

public:

    int longestArithmetic(vector<int>& nums) {

        int ans = f(nums);

        // Check in reverse direction
        reverse(nums.begin(), nums.end());

        ans = max(ans, f(nums));

        return ans;
    }
};


int main() {

    vector<int> nums = {3, 6, 9, 12};

    Solution obj;

    cout << "Longest Arithmetic Subarray Length: "
         << obj.longestArithmetic(nums);

    return 0;
}