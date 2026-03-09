#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Largest Odd Number in String
Platform: LeetCode 1903
========================================================

Problem Statement:
Given a numeric string `num`, return the largest-valued
odd integer (as a string) that is a substring of `num`.

If no odd number exists, return an empty string "".

Example:
Input:  num = "35427"
Output: "35427"

Input:  num = "4206"
Output: ""

========================================================
Approach (Greedy from Right)

Key Observation:
A number is odd if its LAST digit is odd.

Odd digits:
1, 3, 5, 7, 9

Steps:
1. Traverse the string from the END.
2. Find the first odd digit.
3. Return substring from start to that index.

Why?
Because that substring will be the largest possible odd number.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

string largestOddNumber(string num)
{
    // Traverse from the end of the string
    for(int i = num.size() - 1; i >= 0; i--)
    {
        // Convert character to integer and check if odd
        if((num[i] - '0') % 2 == 1)
        {
            // Return substring from start to this index
            return num.substr(0, i + 1);
        }
    }

    // If no odd digit found
    return "";
}

int main()
{
    string num = "35427";

    cout << "Largest Odd Number: " << largestOddNumber(num);

    return 0;
}