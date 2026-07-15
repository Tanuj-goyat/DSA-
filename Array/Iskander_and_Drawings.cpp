#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Iskander and Drawings
Platform: Codeforces 2244A
========================================================

Problem Statement:
For each test case,
you are given a string consisting of
'.' and '#'.

Find the longest consecutive sequence
of '#' characters.

The required answer is:

(longest_length + 1) / 2

Print the result for every test case.

========================================================
Approach Used (Linear Traversal)

Step 1:
Traverse the string.

Step 2:
Count the length of every consecutive
block of '#'.

Step 3:
Maintain the maximum block length.

Step 4:
Compute the answer using:

(maxLen + 1) / 2

Print the result.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

int main()
{
    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (; t > 0; t--)
    {
        int n;

        cin >> n;

        string s;

        cin >> s;

        int maxLen = 0;

        int len = 0;

        // ------------------------------
        // Find longest consecutive '#'
        // ------------------------------
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '#')
            {
                len++;
            }

            else
            {
                maxLen = max(maxLen, len);

                len = 0;
            }
        }

        // Check the last segment
        maxLen = max(maxLen, len);

        len = 0;

        // ------------------------------
        // Calculate answer
        // ------------------------------
        int ans = (maxLen + 1) / 2;

        cout << ans << endl;
    }

    return 0;
}