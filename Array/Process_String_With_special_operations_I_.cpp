#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Process String with Special Operations
Platform: LeetCode (3612)
========================================================

Problem Statement:
Given a string s, process it according
to the following rules:

1. Lowercase letter ('a' to 'z')
   -> Append it to result.

2. '*'
   -> Remove the last character
      from result (if present).

3. '#'
   -> Duplicate the current result.

4. Any other character
   -> Reverse the current result.

Return the final processed string.

Example:
Input:
"ab#*c"

Processing:
"a"   -> a
"b"   -> ab
"#"   -> abab
"*"   -> aba
"c"   -> abac

Output:
"abac"

========================================================
Approach Used (String Simulation)

Step 1:
Traverse the input string.

Step 2:
Apply operation based on current
character.

Step 3:
Maintain a result string throughout
the process.

Step 4:
Return the final result.

Time Complexity: O(n²)
(Reverse and duplication may take O(n))

Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Reverse a string
    // ------------------------------
    void reverse(string &s) {

        int n = s.size();

        int i = 0;

        int j = n - 1;

        while (i < j) {

            swap(s[i], s[j]);

            i++;

            j--;
        }
    }

    // ------------------------------
    // Process input string
    // ------------------------------
    string processStr(string s) {

        string result = "";

        for (int i = 0; i < s.size(); i++) {

            // Append lowercase letter
            if (s[i] >= 'a' &&
                s[i] <= 'z') {

                result.push_back(s[i]);
            }

            // Remove last character
            else if (s[i] == '*') {

                if (result.size() > 0)
                    result.pop_back();
            }

            // Duplicate string
            else if (s[i] == '#') {

                result += result;
            }

            // Reverse string
            else {

                reverse(result);
            }
        }

        return result;
    }
};


int main() {

    string s = "ab#*c";

    Solution obj;

    string ans =
        obj.processStr(s);

    cout << "Processed String: "
         << ans << endl;

    return 0;
}