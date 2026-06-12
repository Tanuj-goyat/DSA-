#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Notelock
Platform: Codeforces 2154A
========================================================

Problem Statement:
Given a binary string s of length n
and an integer k.

Count the minimum number of protected
positions required according to the
problem's conditions.

Example:
Input:
n = 5
k = 2

s = "10101"

Output:
2

========================================================
Approach Used (Greedy)

Step 1:
Traverse the string from left to right.

Step 2:
Whenever a '1' is found,
check the distance from the last
selected/protected position.

Step 3:
If the distance is at least k,
select the current position.

Step 4:
Update the last selected position.

Step 5:
Count total selected positions.

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
        int length;
        int distanceLimit;

        cin >> length >> distanceLimit;

        string binaryString;

        // ------------------------------
        // Read binary string
        // ------------------------------
        for (int index = 0;
             index < length;
             index++)
        {
            char currentCharacter;

            cin >> currentCharacter;

            binaryString.push_back(
                currentCharacter);
        }

        // Last selected position
        int lastSelected =
            -distanceLimit;

        int protectedCount = 0;

        // ------------------------------
        // Greedy Traversal
        // ------------------------------
        for (int index = 0;
             index < length;
             index++)
        {
            // Ignore zeros
            if (binaryString[index] == '0')
                continue;

            // Valid position
            if (index - lastSelected >=
                distanceLimit)
            {
                protectedCount++;
            }

            // Update last seen 1
            lastSelected = index;
        }

        cout << protectedCount
             << endl;
    }

    return 0;
}