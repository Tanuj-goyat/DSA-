#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Lucky Division
Platform: Codeforces (122A)
========================================================

Problem Statement:
A number is called lucky if it contains
only digits 4 and 7.

Examples:
4, 7, 44, 47, 74, 77 ...

Given an integer n.

Determine whether n is divisible by
at least one lucky number.

Print:
"YES" if divisible
"NO" otherwise.

Example:
Input:
47

Output:
YES

Example:
Input:
16

Output:
YES

Explanation:
16 is divisible by 4.

========================================================
Approach Used (Precomputed Lucky Numbers)

Step 1:
Store all lucky numbers up to 3 digits.

Step 2:
Traverse the lucky numbers.

Step 3:
If any lucky number divides n,
print "YES".

Step 4:
Otherwise print "NO".

Time Complexity: O(14)
Space Complexity: O(1)

========================================================
*/

int main() {

    int n;

    cin >> n;

    // ------------------------------
    // Precomputed lucky numbers
    // ------------------------------
    vector<int> v = {
        4, 7,
        44, 47,
        74, 77,
        444, 447,
        474, 477,
        744, 747,
        774, 777
    };

    // ------------------------------
    // Check divisibility
    // ------------------------------
    for (int i = 0; i < 14; i++) {

        if (v[i] > n)
            break;

        if (n % v[i] == 0) {

            cout << "YES" << endl;

            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}