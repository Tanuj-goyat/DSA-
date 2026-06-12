#include <iostream>
#include <climits>
using namespace std;

/*
========================================================
Problem: Games on the Train
Platform: Codeforces
========================================================

Problem Statement:
For each test case:

Given an array of n integers.

Find:

(maximum element - minimum element + 1)

Example:
Input:
5

4 2 7 1 5

Output:
7

Explanation:
Maximum = 7
Minimum = 1

Answer =
7 - 1 + 1 = 7

========================================================
Approach Used (Single Traversal)

Step 1:
Initialize minimum and maximum.

Step 2:
Traverse the array.

Step 3:
Update minimum and maximum values.

Step 4:
Print:

maximum - minimum + 1

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

int main()
{
    int testCases;

    cin >> testCases;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (int test = 0;
         test < testCases;
         test++)
    {
        int arraySize;

        cin >> arraySize;

        int maximumValue = INT_MIN;

        int minimumValue = INT_MAX;

        // ------------------------------
        // Read array elements
        // ------------------------------
        for (int index = 0;
             index < arraySize;
             index++)
        {
            int currentNumber;

            cin >> currentNumber;

            minimumValue =
                min(minimumValue,
                    currentNumber);

            maximumValue =
                max(maximumValue,
                    currentNumber);
        }

        // ------------------------------
        // Print answer
        // ------------------------------
        cout
            << (maximumValue -
                minimumValue + 1)
            << endl;
    }

    return 0;
}