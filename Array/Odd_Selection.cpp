#include <iostream>
using namespace std;

/*
========================================================
Problem: Array with Odd Sum
Platform: Codeforces (1296A)
========================================================

Problem Statement:
Given an array of n integers.

Determine whether it is possible to
select exactly x elements such that
their sum is odd.

Print:

YES  -> If possible
NO   -> Otherwise

========================================================
Approach Used (Counting Odds and Evens)

Step 1:
Count the number of odd and even
elements in the array.

Step 2:
To obtain an odd sum,
the number of selected odd elements
must be odd.

Step 3:
Try every possible odd count of
selected odd numbers.

Step 4:
If enough odd and even elements are
available to select exactly x elements,
the answer is YES.

Otherwise,
print NO.

Time Complexity: O(n)
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

        int n, x;

        cin >> n >> x;

        int oddCount = 0;

        int evenCount = 0;

        // ------------------------------
        // Count odd and even numbers
        // ------------------------------
        for (int i = 0; i < n; i++) {

            int num;

            cin >> num;

            if (num % 2 == 0)
                evenCount++;

            else
                oddCount++;
        }

        bool ans = false;

        // ------------------------------
        // Try every possible odd count
        // ------------------------------
        for (int i = 1; i <= x; i = i + 2) {

            if (i <= oddCount && (x - i) <= evenCount) {

                ans = true;

                break;
            }

            else if (i > oddCount) {

                break;
            }
        }

        // ------------------------------
        // Print answer
        // ------------------------------
        if (ans) {

            cout << "YES" << endl;
        }

        else {

            cout << "No" << endl;
        }
    }

    return 0;
}