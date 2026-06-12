#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Tatar TV Show
Platform: Codeforces
========================================================

Problem Statement:
For each test case:

Given:
- A binary string s of length n
- An integer k

Operation:
If s[i] = '1', then:

1. Set s[i] = '0'
2. Toggle s[i + k]

Determine whether it is possible
to make the entire string equal to 0.

Print:
"yes" if possible
"no" otherwise

========================================================
Approach Used (Greedy Simulation)

Step 1:
Traverse from left to right.

Step 2:
Whenever a '1' is found,
apply the operation immediately.

Step 3:
Toggle the character at position i + k.

Step 4:
After processing all possible positions,
check the remaining suffix.

Step 5:
If any '1' remains,
answer is "no".

Otherwise answer is "yes".

Time Complexity: O(n)
Space Complexity: O(1)
(excluding input string)

========================================================
*/

int main()
{
    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (int x = 0; x < t; x++)
    {
        int n, k;

        cin >> n >> k;

        string s;

        // ------------------------------
        // Read binary string
        // ------------------------------
        for (int i = 0; i < n; i++)
        {
            char num;

            cin >> num;

            s.push_back(num);
        }

        int i = 0;

        bool ans = true;

        // ------------------------------
        // Greedy Simulation
        // ------------------------------
        while (i <= n - k - 1)
        {
            if (s[i] == '1')
            {
                // Remove current 1
                s[i] = '0';

                // Toggle position i + k
                if (s[i + k] == '0')
                {
                    s[i + k] = '1';
                }
                else
                {
                    s[i + k] = '0';
                }
            }

            i++;
        }

        // ------------------------------
        // Check remaining positions
        // ------------------------------
        while (i < n)
        {
            if (s[i] == '1')
            {
                ans = false;

                break;
            }

            i++;
        }

        // ------------------------------
        // Print answer
        // ------------------------------
        if (ans)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}