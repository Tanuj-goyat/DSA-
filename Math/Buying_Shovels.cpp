#include <iostream>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Buying Shovels
Platform: Codeforces (1360D)
========================================================

Problem Statement:
Given two integers:

n and k

Split n into the maximum possible number
of equal groups such that:

- Each group size is a divisor of n
- Group size is not greater than k

Print the minimum possible size of a group.

Example:
Input:
n = 8
k = 7

Output:
2

Explanation:
Divisors of 8:

1, 2, 4, 8

Largest divisor not greater than 7 is 4.

Group size = 8 / 4 = 2

========================================================
Approach Used (Divisor Enumeration)

Step 1:
Initialize answer as n.

Step 2:
Traverse all divisors up to √n.

Step 3:
For every divisor pair:

i and n / i

Check whether either divisor
is less than or equal to k.

Step 4:
Update the minimum possible answer.

Time Complexity: O(√n)
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
        int n, k;

        cin >> n >> k;

        int ans = n;

        // ------------------------------
        // Check all divisors
        // ------------------------------
        for (int i = 1;
             1LL * i * i <= n;
             i++)
        {
            if (n % i == 0)
            {
                // Divisor i
                if (i <= k)
                    ans = min(ans,
                              n / i);

                // Divisor n / i
                if (n / i <= k)
                    ans = min(ans,
                              i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}