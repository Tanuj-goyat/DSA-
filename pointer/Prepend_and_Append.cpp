#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Prepend and Append
Platform: Codeforces (1791C)
========================================================

Problem Statement:
For each test case:

Given a binary string of length n.

Remove characters from both ends while
the two end characters are different.

Stop when:
- both end characters become equal, or
- the string becomes empty.

Print the length of the remaining string.

========================================================
Approach Used (Two Pointers)

Step 1:
Place one pointer at the beginning
and one at the end.

Step 2:
If end characters are different,
move both pointers inward.

Step 3:
If end characters become equal,
print remaining length.

Step 4:
If pointers cross or meet,
print remaining length.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

int main()
{
    int testCases;

    cin >> testCases;

    for (int tc = 0; tc < testCases; tc++)
    {
        int length;

        cin >> length;

        string binaryString;

        if (length == 0)
            continue;

        // ------------------------------
        // Read binary string
        // ------------------------------
        for (int i = 0; i < length; i++)
        {
            char currentChar;

            cin >> currentChar;

            binaryString.push_back(currentChar);
        }

        int leftPointer = 0;

        int rightPointer = length - 1;

        // ------------------------------
        // Two Pointer Traversal
        // ------------------------------
        while (leftPointer < rightPointer)
        {
            int leftDigit =
                binaryString[leftPointer] - '0';

            int rightDigit =
                binaryString[rightPointer] - '0';

            // Ends are equal
            if (leftDigit ^ rightDigit == 0)
            {
                cout
                    << rightPointer - leftPointer + 1
                    << endl;

                break;
            }

            rightPointer--;

            leftPointer++;
        }

        // ------------------------------
        // Remaining length is
        // either 0 or 1
        // ------------------------------
        if ((rightPointer - leftPointer + 1) == 1 ||
            (rightPointer - leftPointer + 1) == 0)
        {
            cout
                << rightPointer - leftPointer + 1
                << endl;
        }
    }

    return 0;
}