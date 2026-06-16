#include <iostream>
using namespace std;

/*
========================================================
Problem: K-th Not Divisible by n
Platform: Codeforces (1352C)
========================================================

Problem Statement:
Given two integers:

n and k

Consider all positive integers that are
NOT divisible by n.

Find the k-th such number.

Example:
Input:
n = 3
k = 7

Numbers not divisible by 3:

1 2 4 5 7 8 10 ...

7th number = 10

Output:
10

========================================================
Approach Used (Math)

Step 1:
For every block of (n - 1) valid numbers,
there is exactly one number divisible by n.

Step 2:
Calculate how many complete blocks exist:

k / (n - 1)

Step 3:
Add the remaining numbers:

k % (n - 1)

Step 4:
Handle the case when k is exactly
divisible by (n - 1).

Time Complexity: O(1)
Space Complexity: O(1)

========================================================
*/

int main() {

    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (int x = 0; x < t; x++) {

        int n, k;

        cin >> n >> k;

        // ------------------------------
        // Calculate answer
        // ------------------------------
        int ans =
            (n * (k / (n - 1))) +
            (k % (n - 1));

        // Exact block case
        if ((k % (n - 1)) == 0)
            ans--;

        cout << ans << endl;
    }

    return 0;
}