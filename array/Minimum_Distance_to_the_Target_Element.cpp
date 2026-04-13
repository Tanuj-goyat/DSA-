#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================================================
Problem Name: Minimum Distance to the Target Element
Platform: LeetCode
Problem Number: 1848
========================================================

Problem Statement:
Given an array nums, a target value, and a starting index,
find the minimum distance between start and any index i
such that nums[i] == target.

Return:
min |i - start|

========================================================
Approach (Linear Scan)

1️⃣ Traverse the array

2️⃣ If nums[i] == target:
   → compute distance |i - start|

3️⃣ Keep track of minimum distance

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {

        int ans = INT_MAX;

        // Traverse array
        for (int i = 0; i < nums.size(); i++) {

            // Check target
            if (nums[i] == target) {

                // Update minimum distance
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};


int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    int start = 3;

    Solution obj;

    cout << "Minimum Distance: "
         << obj.getMinDistance(nums, target, start);

    return 0;
}