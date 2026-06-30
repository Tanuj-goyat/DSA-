#include <iostream>
#include <cmath>
using namespace std;

/*
========================================================
Problem: Product of Three Numbers
Platform: Codeforces (1294C)
========================================================

Problem Statement:
Given an integer n.

Determine whether it can be represented
as the product of three distinct integers
greater than 1.

If possible, print:

YES
a b c

Otherwise print:

NO

Example:
Input:
64

Output:
YES
2 4 8

========================================================
Approach Used (Factor Enumeration)

Step 1:
Find the first divisor i of n.

Step 2:
Let:

x = n / i

Step 3:
Find another divisor j of x.

Step 4:
Compute:

c = x / j

Step 5:
Check whether:

- a, b and c are distinct.
- a × b × c = n.

If all conditions hold,
print the three numbers.

Otherwise print NO.

Time Complexity: O(√n × √n)
Space Complexity: O(1)

========================================================
*/

int main() {

    int t;

    cin >> t;

    for (; t > 0; t--) {

        int n;

        cin >> n;

        int a = 0;

        int b = 0;

        int c = 0;

        bool found = false;

        for (int i = 2; i <= sqrt(n); i++) {

            int x = n / i;

            if (x * i == n) {

                for (int j = i; j <= sqrt(x); j++) {

                    if ((x / j) * j == x && (i != j && j != x / j && i != x / j)) {

                        a = i;

                        b = j;

                        c = x / j;

                        found = true;

                        break;
                    }
                }
            }

            if (found)
                break;
        }

        if (a && b && c && (a * b * c == n)) {

            cout << "YES" << endl;

            cout << a << " " << b << " " << c << endl;
        }

        else {

            cout << "NO" << endl;
        }
    }

    return 0;
}