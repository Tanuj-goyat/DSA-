#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Evanescent String
Platform: Codeforces 2254B
========================================================

Problem Statement:
For each test case,
a binary string s is given.

Determine the minimum possible number
of contiguous character segments after
performing the allowed modification.

Print the minimum number of segments.

========================================================
Approach Used (Counting Segments)

Step 1:
Count the number of contiguous
segments in the string.

Step 2:
Traverse the string and identify
positions where changing one character
can reduce the number of segments.

Step 3:
If changing a character merges two
adjacent segments,
the number of segments decreases by 2.

Otherwise,
it may decrease by 1.

Step 4:
Print:

segments - maximum reduction

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
    while (t--)
    {

        int n;

        cin >> n;

        string s;

        cin >> s;

        int ans = 1;

        int x = 0;

        // ------------------------------
        // Count segments and find the
        // best possible reduction
        // ------------------------------
        for (int i = 1; i < n; i++)
        {

            if (s[i] != s[i - 1])
            {

                ans++;
            }

            if (i == n - 1)
            {

                break;
            }

            if (s[i] != s[i - 1] && s[i] != s[i + 1])
            {

                if (s[i + 1] == s[i - 1])
                {

                    x = 2;
                }

                else
                {

                    x = max(x, 1);
                }
            }
        }

        // ------------------------------
        // Print answer
        // ------------------------------
        cout << ans - x << endl;
    }

    return 0;
}