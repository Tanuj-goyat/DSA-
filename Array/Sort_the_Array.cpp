#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Sort the Array
Platform: Codeforces (451B)
========================================================

Problem Statement:
Given an array.

Determine whether the array can be
sorted in non-decreasing order by
reversing exactly one continuous segment.

If possible:
Print:
yes

and the segment boundaries.

Otherwise print:
no

Example:
Input:
3 2 1

Output:
yes
1 3

========================================================
Approach Used (Reverse One Segment)

Step 1:
Find the first position where the
array starts decreasing.

Step 2:
Extend that decreasing segment.

Step 3:
Reverse the segment.

Step 4:
Check whether the entire array
becomes sorted.

Step 5:
Print the segment if valid.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/


// ------------------------------------------------
// Check whether subarray is sorted
// ------------------------------------------------
bool check(int start,
           int end,
           vector<int>& v)
{
    for (int i = start;
         i < end - 1;
         i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }

    return true;
}


int main()
{
    int n;

    cin >> n;

    vector<int> v;

    // ------------------------------
    // Input array
    // ------------------------------
    for (int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        v.push_back(num);
    }

    int start = -1;

    int end = -1;

    // ------------------------------
    // Find decreasing segment
    // ------------------------------
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] < v[i] &&
            start == -1)
        {
            start = i;

            while (i < n - 1 &&
                   v[i + 1] < v[i])
            {
                i++;
            }

            end = i;

            break;
        }
    }

    // ------------------------------
    // Reverse identified segment
    // ------------------------------
    if (end != -1 &&
        start != -1)
    {
        reverse(v.begin() + start,
                v.begin() + end + 1);
    }

    else if (start != -1 &&
             end == -1)
    {
        end = n - 1;

        reverse(v.begin() + start,
                v.begin() + end + 1);
    }

    // Already sorted case
    if (end == -1 &&
        start == -1)
    {
        end = 0;

        start = 0;
    }

    // ------------------------------
    // Verify final array
    // ------------------------------
    if (check(0, n, v))
    {
        cout << "yes" << endl
             << start + 1
             << "  "
             << end + 1
             << endl;
    }

    else
    {
        cout << "no" << endl;
    }

    return 0;
}