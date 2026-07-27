#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Power Set
Platform: GeeksforGeeks
========================================================

Problem Statement:
Given a string s,
generate all possible subsequences
(power set) of the string.

Return the subsequences in
lexicographical order.

Example:
Input:
s = "abc"

Output:
"", "a", "ab", "abc", "ac",
"b", "bc", "c"

========================================================
Approach Used (Recursion / Backtracking)

Step 1:
Start from index 0.

Step 2:
For every character,
make two recursive calls:

- Include the current character.
- Exclude the current character.

Step 3:
When the index reaches the end of the
string, store the generated subsequence.

Step 4:
Sort all generated subsequences and
return them.

Time Complexity: O(2ⁿ × n)
Space Complexity: O(2ⁿ × n)

========================================================
*/

class Solution
{
public:
    // ------------------------------
    // Generate all subsequences
    // ------------------------------
    void f(vector<string> &ans, string &s, string &db, int index)
    {

        if (index >= s.length())
        {

            ans.push_back(db);

            return;
        }

        // ------------------------------
        // Include current character
        // ------------------------------
        db.push_back(s[index]);

        f(ans, s, db, index + 1);

        db.pop_back();

        // ------------------------------
        // Exclude current character
        // ------------------------------
        f(ans, s, db, index + 1);
    }

    vector<string> powerSet(string &s)
    {

        string db = "";

        vector<string> ans;

        // ------------------------------
        // Generate all subsequences
        // ------------------------------
        f(ans, s, db, 0);

        // ------------------------------
        // Sort the result
        // ------------------------------
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    string s = "abc";

    Solution obj;

    vector<string> answer =
        obj.powerSet(s);

    for (string x : answer)
    {

        cout << "\"" << x << "\"" << endl;
    }

    return 0;
}