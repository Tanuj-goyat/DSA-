#include <iostream>
using namespace std;

/*
========================================================
Problem: Random Teams
Platform: Codeforces (478B)
========================================================
 
Problem Statement:
There are n people to be divided into
m groups.

A pair is formed by any two people
belonging to the same group.

Find:

1. The minimum possible number of pairs.
2. The maximum possible number of pairs.

Print both values.

Example:
Input:
5 3

Output:
2 6

========================================================
Approach Used (Mathematical Observation)

Step 1:
For the maximum number of pairs,
place as many people as possible into
one group and keep one person in each
remaining group.

Step 2:
Compute the number of pairs in that
largest group.

Step 3:
For the minimum number of pairs,
distribute people as evenly as possible
among all groups.

Step 4:
Groups will have either:

- n / m people
- n / m + 1 people

Compute the pairs contributed by each
type of group and add them.

Time Complexity: O(1)
Space Complexity: O(1)

========================================================
*/

int main()
{
    long long n, m;

    cin >> n >> m;

    long long qutenet = n / m;

    long long modulo = n % m;

    long long kMax = 0;

    // ------------------------------
    // Calculate maximum pairs
    // ------------------------------
    long long num = (n - m) + 1;

    kMax += (num * (num - 1)) / 2;

    long long kMin = 0;

    // ------------------------------
    // Calculate minimum pairs
    // ------------------------------
    if (qutenet > 1)
    {
        kMin += (m - modulo) * (qutenet * (qutenet - 1)) / 2;
    }

    if (modulo > 0)
    {
        kMin += (modulo) * (qutenet * (qutenet + 1)) / 2;
    }

    // ------------------------------
    // Print answer
    // ------------------------------
    cout << kMin << " " << kMax << endl;

    return 0;
}