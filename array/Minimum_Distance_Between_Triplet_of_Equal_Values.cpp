#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

/*
========================================================
Problem: Minimum Distance Between Triplet of Equal Values
Platform: LeetCode
Problem Number: 3740
========================================================

Problem Statement:
Given an array, find three indices i, j, k such that:
nums[i] == nums[j] == nums[k]

Minimize:
|i - j| + |j - k| + |k - i|

Return the minimum value, or -1 if no such triplet exists.

========================================================
Approach (Brute + Optimization)

1️⃣ Count frequency of each number

2️⃣ Only process elements having freq ≥ 3

3️⃣ For each such value:
   - Track last two occurrences
   - When third occurrence found → compute distance

4️⃣ Keep minimum answer

========================================================
Time Complexity: O(n²)
Space Complexity: O(n)
========================================================
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        if (nums.size() < 3)
            return -1;

        unordered_map<int, int> freq;

        // Step 1: Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        int ans = INT_MAX;
        bool found = false;

        // Step 2: Try each starting index
        for (int i = 0; i < nums.size(); i++) {

            if (freq[nums[i]] < 3)
                continue;

            int first = i;
            int second = -1;

            // Step 3: Find next occurrences
            for (int j = i + 1; j < nums.size(); j++) {

                if (nums[j] == nums[i]) {

                    if (second == -1) {
                        second = j;
                    } else {
                        int third = j;

                        // Calculate distance
                        int sum = abs(first - second)
                                + abs(second - third)
                                + abs(third - first);

                        ans = min(ans, sum);
                        found = true;

                        // shift window
                        second = third;
                    }
                }
            }
        }

        return found ? ans : -1;
    }
};


int main() {

    vector<int> nums = {1, 2, 1, 1, 3, 1};

    Solution obj;

    cout << "Minimum Distance: "
         << obj.minimumDistance(nums);

    return 0;
}