#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
========================================================
Problem: Next Greater Element III
Platform: LeetCode (556)
========================================================

Problem Statement:
Given a positive integer n.

Find the smallest integer that is
greater than n and contains exactly
the same digits.

If no such integer exists or the answer
does not fit in a 32-bit signed integer,
return -1.

Example:
Input:
n = 12

Output:
21

Example:
Input:
n = 21

Output:
-1

========================================================
Approach Used (Next Permutation)

Step 1:
Convert the integer into a string.

Step 2:
Traverse from right to left and find
the first index where:

nums[i] < nums[i + 1]

Step 3:
Find the smallest digit on the right
that is greater than nums[i].

Step 4:
Swap both digits.

Step 5:
Reverse the suffix to obtain the
smallest possible greater number.

Step 6:
Convert the string back to integer.
If it exceeds INT_MAX,
return -1.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    int nextGreaterElement(int n) {

        string nums = to_string(n);

        int i = nums.size() - 2;

        int j = i + 1;

        while (i >= 0 &&
               nums[i + 1] <= nums[i]) {

            i--;
        }

        if (i < 0) {

            return -1;
        }

        while (j > i &&
               nums[j] <= nums[i]) {

            j--;
        }

        swap(nums[i], nums[j]);


        reverse(nums.begin() + i + 1, nums.end());

        long long ans = stoll(nums);

        if (ans > INT_MAX) {

            return -1;
        }

        return (int)ans;
    }
};


int main() {

    int n = 12443322;

    Solution obj;

    int answer = obj.nextGreaterElement(n);

    cout << answer << endl;

    return 0;
}