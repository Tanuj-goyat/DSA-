#include <iostream>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem: Same Differences
Platform: Codeforces (1520D) 
========================================================

Problem Statement:
Given an array of n integers.

Count the number of pairs:

(i, j)

such that:

i < j

and

a[j] - a[i] = j - i

Example:
Input:
5

1 2 3 4 5

Output:
10

Explanation:
Every pair satisfies the condition.

========================================================
Approach Used (Hash Map)

Observation:

a[j] - a[i] = j - i

Rearranging:

a[j] - j = a[i] - i

So for every index i,
compute:

value = a[i] - i

If two indices have the same value,
they form a valid pair.

Step 1:
Traverse the array.

Step 2:
Compute:

value = num - i

Step 3:
Count how many times the same value
has appeared before.

Step 4:
Add that frequency to answer.

Step 5:
Store current value in map.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

int main()
{
    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    while (t > 0)
    {
        int n;

        cin >> n;

        unordered_map<int, int> m;

        long long ans = 0;

        // ------------------------------
        // Read array and count pairs
        // ------------------------------
        for (int i = 0; i < n; i++)
        {
            int num;

            cin >> num;

            int value = num - i;

            // Add previously seen matches
            ans += m[value];

            // Store current value
            m[value]++;
        }

        cout << ans << endl;

        t--;
    }

    return 0;
}