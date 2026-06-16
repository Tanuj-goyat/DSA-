#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/*
========================================================
Problem: Vanya and Lanterns
Platform: Codeforces (492B)
========================================================

Problem Statement:
There are n lanterns placed on a street
of length l.

Each lantern illuminates an equal distance
to its left and right.

Find the minimum light radius required so
that the entire street is illuminated.

Example:
Input:
7 15

15 5 3 7 9 14 0

Output:
2.5000000000

========================================================
Approach Used (Sorting)

Step 1:
Store all lantern positions.

Step 2:
Sort the positions.

Step 3:
Find the maximum gap between
adjacent lanterns.

Step 4:
The required radius must cover:
- Half of the maximum gap
- Distance from start of street
- Distance from end of street

Step 5:
Take the maximum among them.

Time Complexity: O(n log n)
Space Complexity: O(n)

========================================================
*/

int main() {

    int n, l;

    cin >> n >> l;

    vector<int> v;

    // ------------------------------
    // Input lantern positions
    // ------------------------------
    for (int i = 0; i < n; i++) {

        int num;

        cin >> num;

        v.push_back(num);
    }

    // ------------------------------
    // Sort positions
    // ------------------------------
    sort(v.begin(), v.end());

    int d = 0;

    // ------------------------------
    // Find maximum adjacent gap
    // ------------------------------
    for (int i = 0; i < n - 1; i++) {

        d = max(d,
                v[i + 1] - v[i]);
    }

    // Half of largest gap
    double ans = d / 2.0;

    // Distance from street start
    ans = max(ans,
              (double)v[0]);

    // Distance from street end
    ans = max(ans,
              (double)l - v[n - 1]);

    // ------------------------------
    // Print answer
    // ------------------------------
    cout << fixed
         << setprecision(10)
         << ans
         << endl;

    return 0;
}