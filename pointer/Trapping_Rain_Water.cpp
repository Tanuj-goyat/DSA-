#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Trapping Rain Water
Platform: LeetCode (42)
========================================================

Problem Statement:
Given an array arr where each element
represents the height of a bar.

Find the total amount of rain water
that can be trapped after raining.

Example:
Input:
arr = [0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6

========================================================
Approach Used (Left Boundary + Right Boundary)

Step 1:
Traverse from left to right and
store the left boundary for each bar.

Step 2:
Traverse from right to left and
store the right boundary for each bar.

Step 3:
For every index,
water trapped is:

min(left, right) - height

if the value is positive.

Step 4:
Sum the trapped water over all indices.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    int trap(vector<int>& arr) {

        int n = arr.size();

        vector<int> left;

        stack<int> st1;

        for (int i = 0; i < n; i++) {

            if (st1.empty()) {

                st1.push(arr[i]);

                left.push_back(-1);
            }

            else if (st1.top() > arr[i]) {

                left.push_back(st1.top());
            }

            else if (st1.top() <= arr[i]) {

                st1.push(arr[i]);

                left.push_back(-1);
            }
        }

        stack<int> st2;

        vector<int> right(n, 0);

        for (int i = n - 1; i >= 0; i--) {

            if (st2.empty()) {

                st2.push(arr[i]);

                right[i] = -1;
            }

            else if (st2.top() > arr[i]) {

                right[i] = st2.top();
            }

            else if (st2.top() <= arr[i]) {

                st2.push(arr[i]);

                right[i] = -1;
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {

            count += max(0, min(left[i], right[i]) - arr[i]);
        }

        return count;
    }
};


int main() {

    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution obj;

    int answer = obj.trap(arr);

    cout << answer << endl;

    return 0;
}