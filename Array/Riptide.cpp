#include <iostream>
using namespace std;

/*
========================================================
Problem: Riptide
Platform: Codeforces 2254
========================================================

Problem Statement:
For each test case,
three integers a, b, and c are given.

In one operation:

- Decrease the largest number by 1.
- Increase the smallest of the other
  two numbers by 1.

Continue performing operations until
at least two numbers become equal.

Print the minimum number of operations
performed.

========================================================
Approach Used (Simulation)

Step 1:
Repeat until any two numbers become
equal.

Step 2:
Identify the largest number.

Step 3:
Decrease the largest number by 1.

Step 4:
Increase the smaller of the remaining
two numbers by 1.

Step 5:
Count every operation and print the
final count.

Time Complexity: O(answer)
Space Complexity: O(1)

========================================================
*/

int main()
{
    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (; t > 0; t--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        int count = 0;

        // ------------------------------
        // Perform operations until
        // two numbers become equal
        // ------------------------------
        while (!(a == b ||
                 b == c ||
                 a == c))
        {
            count++;

            if (a > b &&
                a > c)
            {
                if (b < c)
                {
                    b++;
                }

                else
                {
                    c++;
                }

                a--;
            }

            else if (b > a &&
                     b > c)
            {
                if (a < c)
                {
                    a++;
                }

                else
                {
                    c++;
                }

                b--;
            }

            else if (c > a &&
                     c > b)
            {
                if (a < b)
                {
                    a++;
                }

                else
                {
                    b++;
                }

                c--;
            }
        }

        // ------------------------------
        // Print answer
        // ------------------------------
        cout << count << endl;
    }

    return 0;
}