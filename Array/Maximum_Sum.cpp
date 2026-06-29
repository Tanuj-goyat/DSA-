#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Maximum Sum
Platform: LeetCode 3974
========================================================

Problem Statement:
Given:

- An integer array nums
- An integer k
- An integer mul

Select exactly k elements to maximize
the total sum.

The largest selected elements receive
multipliers in decreasing order:

mul, mul-1, ...

Once the multiplier becomes less than 1,
remaining selected elements contribute
their original value.

Return the maximum possible sum.

========================================================
Approach Used (Sorting + Greedy)

Step 1:
Sort the array in ascending order.

Step 2:
Start selecting elements from the end
(largest values).

Step 3:
While multiplier is at least 1,
multiply the current largest element.

Step 4:
When multiplier becomes less than 1,
add the remaining selected elements
without multiplication.

Step 5:
Return the total sum.

Time Complexity: O(n log n)
Space Complexity: O(1)
(excluding sorting space)

========================================================
*/

class Solution {
public:

    long long maxSum(vector<int>& nums, int k, int mul) {

        sort(nums.begin(), nums.end());

        int j = nums.size() - 1;

        long long ans = 0;

        for (int x = 0;
             x < k;
             x++) {

            if (mul >= 1) {

                ans +=
                    (long long)nums[j] * mul;

                j--;

                mul--;
            }

            else {

                ans += nums[j];

                j--;
            }
        }

        return ans;
    }
};


int main() {

    vector<int> nums =
        {2, 5, 3, 8, 1};

    int k = 3;

    int mul = 2;

    Solution obj;

    long long answer =
        obj.maxSum(nums,
                   k,
                   mul);

    cout << answer << endl;

    return 0;
}