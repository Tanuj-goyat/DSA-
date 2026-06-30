#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
========================================================
Problem: Sum of Subarray Minimums
Platform: LeetCode (907)
========================================================

Problem Statement:
Given an integer array arr.

For every possible subarray,
find its minimum element.

Return the sum of all subarray
minimums modulo 10^9 + 7.

Example:
Input:
arr = [3,1,2,4]

Output:
17

========================================================
Approach Used (Monotonic Stack)

Step 1:
For every element,
find the Previous Smaller Element (PSE).

Step 2:
Find the Next Smaller Element (NSE).

Step 3:
The current element contributes as the
minimum for:

(i - left[i]) × (right[i] - i)

subarrays.

Step 4:
Contribution:

arr[i] × leftCount × rightCount

Step 5:
Sum all contributions modulo
10^9 + 7.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        stack<int> st1;

        vector<int> left(n, 0);

        // ------------------------------
        // Previous Smaller Element
        // ------------------------------
        for (int i = 0; i < n; i++) {

            if (st1.empty()) {

                st1.push(i);

                left[i] = -1;
            }

            else if (arr[st1.top()] < arr[i]) {

                left[i] = st1.top();

                st1.push(i);
            }

            else {

                while (!st1.empty() && arr[st1.top()] > arr[i]) {

                    st1.pop();
                }

                if (st1.empty()) {

                    left[i] = -1;
                }

                else {

                    left[i] = st1.top();
                }

                st1.push(i);
            }
        }

        stack<int> st2;

        vector<int> right(n, 0);

        // ------------------------------
        // Next Smaller Element
        // ------------------------------
        for (int i = n - 1; i >= 0; i--) {

            if (st2.empty()) {

                st2.push(i);

                right[i] = n;
            }

            else if (arr[st2.top()] < arr[i]) {

                right[i] = st2.top();

                st2.push(i);
            }

            else {

                while (!st2.empty() && arr[st2.top()] >= arr[i]) {

                    st2.pop();
                }

                if (st2.empty()) {

                    right[i] = n;
                }

                else {

                    right[i] = st2.top();
                }

                st2.push(i);
            }
        }

        long long ans = 0;

        long long MOD = 1000000007;

        // ------------------------------
        // Calculate contribution of each
        // element as minimum
        // ------------------------------
        for (int i = 0; i < n; i++) {

            ans =
                (ans + (long long)arr[i] * (right[i] - i) * (i - left[i])) % MOD;
        }

        return ans;
    }
};


int main() {

    vector<int> arr =
        {3, 1, 2, 4};

    Solution obj;

    int answer =
        obj.sumSubarrayMins(arr);

    cout << answer << endl;

    return 0;
}