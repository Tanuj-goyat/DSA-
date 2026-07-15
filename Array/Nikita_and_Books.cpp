#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Nikita and Books
Platform: Codeforces 2244B
========================================================

Problem Statement:
For each test case,
determine whether it is possible to
modify the given array according to
the required operation so that every
element becomes strictly greater than
its previous element.

Print:

YES  -> If possible
NO   -> Otherwise

========================================================
Approach Used (Greedy)

Step 1:
Traverse the array from left to right.

Step 2:
Maintain:

- pre  -> Previous adjusted value.
- add  -> Total increment already used.

Step 3:
Update the current element using the
previous accumulated increment.

Step 4:
If the current value is greater than
the previous value,
minimize it while keeping it strictly
greater than the previous element.

Step 5:
If any element cannot become greater
than the previous one,
the answer is NO.

Otherwise,
print YES.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

int main()
{
    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (; t > 0; t--) {

        int n;

        cin >> n;

        vector<long long> v;

        // ------------------------------
        // Read array
        // ------------------------------
        for (int i = 0; i < n; i++) {

            long long num;

            cin >> num;

            v.push_back(num);
        }

        long long pre = 0;

        long long add = 0;

        bool found = true;

        // ------------------------------
        // Greedy adjustment
        // ------------------------------
        for (int i = 0; i < n; i++) {

            v[i] += add;

            if (v[i] > pre) {

                add = v[i] - pre - 1;

                v[i] -= add;

                pre = v[i];
            }

            else {

                found = false;

                break;
            }
        }

        // ------------------------------
        // Print answer
        // ------------------------------
        if (found) {

            cout << "YES" << endl;
        }

        else {

            cout << "NO" << endl;
        }
    }

    return 0;
}