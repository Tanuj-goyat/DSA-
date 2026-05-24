#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
========================================================
Problem: Password Strength
Platform: LeetCode (3941)
========================================================

Problem Statement:
Given a string password,
calculate its strength based on
unique characters.

Scoring Rules:
- Lowercase letter  -> +1
- Uppercase letter  -> +2
- Digit             -> +3
- Special character -> +5

A character contributes only once,
even if repeated multiple times.

Example:
Input:
"aA1@aA"

Output:
11

Explanation:
'a' -> 1
'A' -> 2
'1' -> 3
'@' -> 5

Total = 11

========================================================
Approach Used (HashMap + Character Classification):

Step 1:
Traverse string

Step 2:
If character appears first time,
calculate score using helper function

Step 3:
Add corresponding value

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Character scoring function
    // ------------------------------
    int f(char ch) {

        // Lowercase letter
        if (ch >= 'a' && ch <= 'z')
            return 1;

        // Uppercase letter
        if (ch >= 'A' && ch <= 'Z')
            return 2;

        // Digit
        if (ch >= '0' && ch <= '9')
            return 3;

        // Special character
        return 5;
    }


    int passwordStrength(string s) {

        unordered_map<char, int> m;

        int ans = 0;

        // ------------------------------
        // Traverse string
        // ------------------------------
        for (int i = 0; i < s.size(); i++) {

            // First occurrence only
            if (m.find(s[i]) == m.end()) {

                ans += f(s[i]);
            }

            m[s[i]]++;
        }

        return ans;
    }
};


int main() {

    string s = "aA1@aA";

    Solution obj;

    int result =
        obj.passwordStrength(s);

    cout << "Password Strength: "
         << result << endl;

    return 0;
}