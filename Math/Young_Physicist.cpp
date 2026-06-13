#include <iostream>
using namespace std;

/*
========================================================
Problem: Young Physicist
Platform: Codeforces (69A)
========================================================

Problem Statement:
A body is in equilibrium if the sum of
all forces acting on it is zero.

Given n force vectors:

(x, y, z)

Determine whether the body is in
equilibrium.

Print:
"YES" if equilibrium exists
"NO" otherwise.

Example:
Input:
3

4 1 7
-2 4 -1
-2 -5 -6

Output:
YES

Explanation:
Sum of x-components = 0
Sum of y-components = 0
Sum of z-components = 0

========================================================
Approach Used (Vector Summation)

Step 1:
Maintain sums for:
- x direction
- y direction
- z direction

Step 2:
Add every vector component.

Step 3:
If all three sums become zero,
the body is in equilibrium.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

int main()
{
    int n;

    cin >> n;

    // ------------------------------
    // Sum of x, y and z components
    // ------------------------------
    int a = 0;
    int b = 0;
    int c = 0;

    // ------------------------------
    // Read all vectors
    // ------------------------------
    for (int i = 0; i < n; i++)
    {
        int x, y, z;

        cin >> x >> y >> z;

        a += x;

        b += y;

        c += z;
    }

    // ------------------------------
    // Check equilibrium condition
    // ------------------------------
    if (a == 0 &&
        b == 0 &&
        c == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}