#include <iostream>
using namespace std;

/*
========================================================
Problem: Watermelon
Platform: Codeforces (4A)
========================================================

Problem Statement:
Pete and Billy bought a watermelon
weighing w kilograms.

Determine whether it is possible
to divide the watermelon into
two parts such that:

1. Both parts have positive weight.
2. Both parts have even weight.

Print:
"YES" if possible
"NO" otherwise.

Example:
Input:
8

Output:
YES

Explanation:
8 = 4 + 4

Example:
Input:
5

Output:
NO

========================================================
Approach Used (Observation)

Step 1:
The watermelon weight must be even.

Step 2:
Weight must be greater than 2.

Reason:
2 can only be split as:

1 + 1

which are not even.

Therefore:

w > 2
and
w is even

=> YES

Otherwise => NO

Time Complexity: O(1)
Space Complexity: O(1)

========================================================
*/

int main() {

    int w;

    cin >> w;

    // ------------------------------
    // Check if watermelon can be
    // split into two even parts
    // ------------------------------
    if ((w > 2) &&
        ((w & 1) == 0))

        cout << "YES" << endl;

    else

        cout << "NO" << endl;

    return 0;
}