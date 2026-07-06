#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

/*
========================================================
Problem: Maximum Digit Range
Platform: LeetCode (3982)
========================================================

Problem Statement:
Given an integer array nums.

For every number:

Digit Range =
largest digit - smallest digit

Group numbers having the same
digit range.

Return the sum of numbers belonging
to the group having the maximum
digit range.

========================================================
Approach Used (Hash Map)

Step 1:
For every number,
calculate its digit range.

Step 2:
Store the total sum of numbers
having the same digit range.

Step 3:
Find the maximum digit range
present in the map.

Step 4:
Return the corresponding sum.

Time Complexity: O(n × d log d)
where d is the number of digits.

Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Calculate digit range
    // ------------------------------
    int f(int n) {

        string s = to_string(n);

        sort(s.begin(), s.end());

        int ans = s[s.size() - 1] - s[0];

        return ans;
    }

    int maxDigitRange(vector<int>& nums) {

        unordered_map<int, int> m;

        // ------------------------------
        // Group numbers by digit range
        // ------------------------------
        for (int i = 0; i < nums.size(); i++) {

            int sum = f(nums[i]);

            m[sum] += nums[i];
        }

        int maxi = 0;

        // ------------------------------
        // Find maximum digit range
        // ------------------------------
        for (auto x : m) {

            maxi = max(maxi, x.first);
        }

        return m[maxi];
    }
};


int main() {

    vector<int> nums = {123, 456, 909, 808};

    Solution obj;

    int answer = obj.maxDigitRange(nums);

    cout << answer << endl;

    return 0;
}