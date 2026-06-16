#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: IQ Test
Platform: Codeforces (25A)
========================================================

Problem Statement:
Given n integers.

All numbers except one have the same parity
(even or odd).

Find the position (1-based index) of the
number whose parity differs from the others.

Example:
Input:
5

2 4 7 8 10

Output:
3

Explanation:
Only 7 is odd while all others are even.

========================================================
Approach Used (Parity Counting)

Step 1:
Store all numbers.

Step 2:
Count:
- Number of even values
- Number of odd values

Step 3:
Track the last position of:
- Even number
- Odd number

Step 4:
As soon as one parity becomes the minority,
print its position.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

int main()
{
    int n;

    vector<int> v;

    cin >> n;

    // ------------------------------
    // Input array
    // ------------------------------
    for (int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        v.push_back(num);
    }

    int lasteven = -1;

    int lastodd = -1;

    int evencount = 0;

    int oddcount = 0;

    // ------------------------------
    // Count parity
    // ------------------------------
    for (int i = 0; i < n; i++)
    {
        // Even number
        if ((v[i] & 1) == 0)
        {
            lasteven = i + 1;

            evencount++;

            if (evencount > 1 &&
                lastodd != -1)
            {
                cout << lastodd << endl;

                return 0;
            }

            else if (oddcount > 1)
            {
                cout << lasteven << endl;

                return 0;
            }
        }

        // Odd number
        else
        {
            lastodd = i + 1;

            oddcount++;

            if (evencount > 1)
            {
                cout << lastodd << endl;

                return 0;
            }

            else if (oddcount > 1 &&
                     lasteven != -1)
            {
                cout << lasteven << endl;

                return 0;
            }
        }
    }

    return 0;
}