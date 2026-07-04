#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Largest Rectangle in Histogram
Platform: LeetCode (84)
========================================================

Problem Statement:
Given an array v where each element
represents the height of a histogram bar.

Find the area of the largest rectangle
that can be formed in the histogram.

Example:
Input:
v = [2,1,5,6,2,3]

Output:
10

Explanation:
The largest rectangle has height 5
and width 2.

Area = 10

========================================================
Approach Used (Monotonic Stack)

Step 1:
Find the Previous Smaller Element (PSE)
for every bar.

Step 2:
Find the Next Smaller Element (NSE)
for every bar.

Step 3:
For every bar:

Width =
right[i] - left[i] - 1

Area =
height × width

Step 4:
Return the maximum area.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    int largestRectangleArea(vector<int>& v) {

        int n = v.size();

        stack<int> st1;

        vector<int> left;

        // ------------------------------
        // Previous Smaller Element
        // ------------------------------
        for (int i = 0; i < n; i++) {

            if (st1.empty()) {

                left.push_back(-1);

                st1.push(i);
            }

            else if (v[st1.top()] <= v[i]) {

                left.push_back(st1.top());

                st1.push(i);
            }

            else {

                while (!st1.empty() && v[st1.top()] > v[i]) {

                    st1.pop();
                }

                if (st1.empty()) {

                    left.push_back(-1);
                }

                else {

                    left.push_back(st1.top());
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

                right[i] = n;

                st2.push(i);
            }

            else if (v[st2.top()] < v[i]) {

                right[i] = st2.top();

                st2.push(i);
            }

            else {

                while (!st2.empty() && v[st2.top()] >= v[i]) {

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

        int area = 0;

        // ------------------------------
        // Calculate maximum rectangle
        // ------------------------------
        for (int i = 0; i < n; i++) {

            area = max(area, v[i] * (right[i] - left[i] - 1));
        }

        return area;
    }
};


int main() {

    vector<int> v = {2, 1, 5, 6, 2, 3};

    Solution obj;

    int answer = obj.largestRectangleArea(v);

    cout << answer << endl;

    return 0;
}