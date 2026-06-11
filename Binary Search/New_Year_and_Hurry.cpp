#include <iostream>
using namespace std;

/*
========================================================
Problem: New Year and Hurry
Platform: Codeforces (750A)
========================================================

Problem Statement:
There are n problems in a contest.

Time required for solving:
Problem 1 -> 5 minutes
Problem 2 -> 10 minutes
Problem 3 -> 15 minutes
...
Problem i -> 5 * i minutes

The contestant must leave after k minutes,
so only (240 - k) minutes are available.

Find the maximum number of problems
that can be solved.

Example:
Input:
n = 10
k = 30

Output:
8

========================================================
Approach Used (Binary Search)

Step 1:
Calculate available time:
240 - k

Step 2:
For any mid problems,
time required is:

5 * (mid * (mid + 1)) / 2

Step 3:
Use binary search to find the
maximum valid number of problems.

Time Complexity: O(log n)
Space Complexity: O(1)

========================================================
*/

int main() {

    int n, k;

    cin >> n >> k;

    // ------------------------------
    // Available contest time
    // ------------------------------
    int available = 240 - k;

    int start = 0;
    int end = n;

    int ans = 0;

    // ------------------------------
    // Binary Search
    // ------------------------------
    while (start <= end) {

        int mid =
            start + (end - start) / 2;

        // Time needed to solve
        // first 'mid' problems
        int timeNeeded =
            5 * mid * (mid + 1) / 2;

        // Valid answer
        if (timeNeeded <= available) {

            ans = mid;

            start = mid + 1;
        }

        // Too much time required
        else {

            end = mid - 1;
        }
    }

    cout << ans;

    return 0;
}