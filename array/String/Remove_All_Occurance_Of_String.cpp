#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Remove All Occurrences of a Substring
Platform: LeetCode
Problem Number: 1910
========================================================

Problem Statement:
Given two strings s and part, repeatedly remove the
leftmost occurrence of substring "part" from s until
no more occurrences exist.

Return the final string.

Example:
Input:
s = "daabcbaabcbc"
part = "abc"

Steps:
daabcbaabcbc
dbaabcbc      (remove first "abc")
dbabcbc       (remove next "abc")
dab           (remove last "abc")

Output:
"dab"

========================================================
Approach Used

1️⃣ Use string.find() to locate the first occurrence
   of substring "part".

2️⃣ If found:
      remove it using string.erase()

3️⃣ Repeat the process until find() returns npos
   (meaning substring no longer exists).

========================================================
Time Complexity:
Worst Case → O(n²)
because each erase shifts the string.

Space Complexity:
O(1) extra space.

========================================================
*/


// Function to remove all occurrences of "part"
string f(string s, string part)
{
    // Find first occurrence of substring
    size_t x = s.find(part);

    // Continue while substring exists
    while (x != string::npos)
    {
        // Remove substring
        s.erase(x, part.size());

        // Search again
        x = s.find(part);
    }

    return s;
}


int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";

    cout << "Result: " << f(s, part);

    return 0;
}