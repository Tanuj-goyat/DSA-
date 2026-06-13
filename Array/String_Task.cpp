#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: String Task
Platform: Codeforces (118A)
========================================================

Problem Statement:
Given a string.

Perform the following operations:

1. Remove all vowels:
   A, O, Y, E, U, I
   (both uppercase and lowercase)

2. Insert a '.' before each
   remaining character.

3. Convert all remaining
   characters to lowercase.

Example:
Input:
tour

Output:
.t.r

Example:
Input:
Codeforces

Output:
.c.d.f.r.c.s

========================================================
Approach Used (String Processing)

Step 1:
Traverse the string.

Step 2:
Ignore vowels.

Step 3:
For every consonant:
- Add '.'
- Convert to lowercase if needed
- Append to answer string

Step 4:
Print final string.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/


// ------------------------------
// Check whether character
// is a vowel
// ------------------------------
bool vovl(char ch)
{
    if (ch == 'A' || ch == 'a' ||
        ch == 'E' || ch == 'e' ||
        ch == 'I' || ch == 'i' ||
        ch == 'O' || ch == 'o' ||
        ch == 'U' || ch == 'u' ||
        ch == 'Y' || ch == 'y')

        return true;

    return false;
}


int main()
{
    string s;

    getline(cin, s);

    string ans = "";

    // ------------------------------
    // Process every character
    // ------------------------------
    for (int i = 0; i < s.size(); i++)
    {
        // Lowercase consonant
        if (!(vovl(s[i])) &&
            s[i] > 'a' &&
            s[i] <= 'z')
        {
            ans.push_back('.');

            ans.push_back(s[i]);
        }

        // Uppercase consonant
        else if (!(vovl(s[i])) &&
                 s[i] > 'A' &&
                 s[i] <= 'Z')
        {
            ans.push_back('.');

            char ch =
                s[i] - 'A' + 'a';

            ans.push_back(ch);
        }
    }

    // ------------------------------
    // Print answer
    // ------------------------------
    cout << ans << endl;

    return 0;
}