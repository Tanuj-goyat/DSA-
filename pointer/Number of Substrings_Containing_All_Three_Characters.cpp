#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem: Number of Substrings Containing All Three Characters
Platform: LeetCode (1358)
========================================================

Problem Statement:
Given a string s consisting only of:
'a', 'b', and 'c',

return the number of substrings
containing at least one occurrence of:
- 'a'
- 'b'
- 'c'

Example:
Input:
"abcabc"

Output:
10

========================================================
Approach Used (Sliding Window):

Step 1:
Maintain frequency of:
- a
- b
- c

Step 2:
Expand window using j

Step 3:
Whenever window contains all 3 characters:
all substrings from current j to end are valid

count += n - j

Step 4:
Shrink window from left

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Check if all characters exist
    // ------------------------------
    bool isValid(vector<int>& v) {

        if (v[0] == 0 ||
            v[1] == 0 ||
            v[2] == 0)

            return false;

        return true;
    }


    int numberOfSubstrings(string s) {

        int n = s.size();

        // Frequency array
        vector<int> v(3, 0);

        int count = 0;

        // Sliding window pointers
        int i = 0;
        int j = 0;

        // First character
        int index = s[0] - 'a';

        v[index]++;

        // ------------------------------
        // Sliding window traversal
        // ------------------------------
        while (j < n) {

            // Valid window found
            if (isValid(v)) {

                // All substrings after j valid
                count += n - j;

                // Remove left character
                index = s[i] - 'a';

                v[index]--;

                i++;
            }

            // Expand window
            else {

                j++;

                if (j < n) {

                    index = s[j] - 'a';

                    v[index]++;
                }
            }
        }

        return count;
    }
};


int main() {

    string s = "abcabc";

    Solution obj;

    int result =
        obj.numberOfSubstrings(s);

    cout << "Total Substrings: "
         << result << endl;

    return 0;
}