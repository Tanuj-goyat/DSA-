#include <iostream>
using namespace std;

/*
========================================================
Problem: Same Parity Summands
Platform: Codeforces (1352B)
========================================================

Problem Statement:
Given two integers:

n
k
 
Determine whether n can be represented
as the sum of exactly k positive integers
having the same parity.

If possible, print:

YES
followed by the k integers.

Otherwise, print:

NO.

========================================================
Approach Used (Greedy Construction)

Step 1:
Try constructing the answer using:

(k - 1) ones.

Let the last number be:

n - (k - 1)

If the last number is positive and odd,
a valid solution exists.

Step 2:
Otherwise, try using:

(k - 1) twos.

Let the last number be:

n - 2 × (k - 1)

If the last number is positive and even,
a valid solution exists.

Step 3:
If neither construction works,
print NO.

Time Complexity: O(k)
Space Complexity: O(1)

========================================================
*/

int main() {

    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (; t > 0; t--) {

        int n, k;

        cin >> n >> k;

        int a = (k - 1);

        int b = n - a;

        // ------------------------------
        // Try using ones
        // ------------------------------
        if (b > 0 && (b % 2 == 1)) {

            cout << "YES" << endl;

            for (int i = 0; i < k - 1; i++) {

                cout << 1 << " ";
            }

            cout << b << endl;

            continue;
        }

        // ------------------------------
        // Try using twos
        // ------------------------------
        a *= 2;

        b = n - a;

        if (b > 0 &&
            (b % 2 == 0)) {

            cout << "YES" << endl;

            for (int i = 0; i < k - 1; i++) {

                cout << 2 << " ";
            }

            cout << b << endl;

            continue;
        }

        // ------------------------------
        // No valid construction
        // ------------------------------
        cout << "NO" << endl;
    }

    return 0;
}