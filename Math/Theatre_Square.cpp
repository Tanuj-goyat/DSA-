#include <iostream>
using namespace std;

/*
========================================================
Problem: Theatre Square
Platform: Codeforces (1A)
========================================================

Problem Statement:
Theatre Square is a rectangle of size:

n × m

You need to cover it completely using
square flagstones of size:

a × a

Flagstones cannot be broken.

Find the minimum number of flagstones
required to cover the entire square.

Example:
Input:
6 6 4

Output:
4

Explanation:
Along length:
ceil(6 / 4) = 2

Along width:
ceil(6 / 4) = 2

Total:
2 × 2 = 4

========================================================
Approach Used (Math)

Step 1:
Find how many flagstones are needed
along length.

Step 2:
Find how many flagstones are needed
along width.

Step 3:
Multiply both values.

Time Complexity: O(1)
Space Complexity: O(1)

========================================================
*/

int main() {

    int n, m, a;

    cin >> n >> m >> a;

    // ------------------------------
    // Flagstones needed along length
    // ------------------------------
    int x = n / a;

    if (n % a != 0)
        x++;

    // ------------------------------
    // Flagstones needed along width
    // ------------------------------
    int y = m / a;

    if (m % a != 0)
        y++;

    // ------------------------------
    // Total flagstones required
    // ------------------------------
    cout << (long long)x * y << endl;

    return 0;
}