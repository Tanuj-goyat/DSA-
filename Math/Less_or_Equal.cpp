#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Less or Equal
Platform: Codeforces (977C)
========================================================

Problem Statement:
Given an array of n integers and an
integer k.

Find an integer x such that exactly
k elements in the array are less than
or equal to x.

If multiple answers exist, print any.

If no such x exists, print -1.

Example:
Input:
7 4

3 7 5 1 10 3 20

Output:
5

Explanation:
Elements <= 5 are:

1, 3, 3, 5

Exactly 4 elements.

========================================================
Approach Used (Sorting)

Step 1:
Sort the array.

Step 2:
Handle k = 0 separately.

Step 3:
If k = n,
answer is the largest element.

Step 4:
Otherwise choose:

x = v[k - 1]

Step 5:
If v[k] is equal to v[k - 1],
then no valid x exists.

Time Complexity: O(n log n)
Space Complexity: O(n)

========================================================
*/

int main()
{
    int n, k;

    cin >> n >> k;

    vector<int> v;

    // ------------------------------
    // Input array
    // ------------------------------
    for (int i = 0; i < n; i++)
    {
        int val;

        cin >> val;

        v.push_back(val);
    }
    
    sort(v.begin(), v.end());

    if (k == 0)
    {
        if (v[0] > 1)
        {
            cout << 1 << endl;
        }

        else
        {
            cout << -1 << endl;
        }
    }
    else if (k >= n)
    {
        cout << v[n - 1] << endl;
    }
    else
    {
        int x = v[k - 1];

        if (k < n &&
            v[k] == v[k - 1])
        {
            cout << -1 << endl;
        }

        else
        {
            cout << x << endl;
        }
    }

    return 0;
}