#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem: Longest Substring with Exactly K Unique Characters
Platform: GFG
========================================================

Problem Statement:
Given a string s and an integer k,
find the length of the longest substring
containing exactly k distinct characters.

If no such substring exists,
return -1.

Example:
Input:
s = "aabacbebebe"
k = 3

Output:
7

Explanation:
"cbebebe" has exactly 3 unique characters.

========================================================
Approach Used (Sliding Window):

Step 1:
Use two pointers:
- i = window start
- j = window end

Step 2:
Maintain frequency array

Step 3:
Track distinct character count

Step 4:
If distinct count > k,
shrink window

Step 5:
Update maximum length
when distinct count == k

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int longestKSubstr(string &s,
                       int k) {

        // Frequency array
        vector<int> m(26, 0);

        // Sliding window pointers
        int i = 0;
        int j = 0;

        // Distinct character count
        int letter = 0;

        // Answer
        int len = -1;

        // ------------------------------
        // Sliding window traversal
        // ------------------------------
        while (j < s.size()) {

            int index = s[j] - 'a';

            // New character enters window
            if (m[index] == 0)
                letter++;

            m[index]++;

            // ------------------------------
            // Too many distinct characters
            // ------------------------------
            if (letter > k) {

                index = s[i] - 'a';

                m[index]--;

                // Character removed completely
                if (m[index] == 0) {

                    letter--;
                }

                i++;
            }

            // ------------------------------
            // Valid window
            // ------------------------------
            if (letter == k)

                len = max(len,
                          j - i + 1);

            j++;
        }

        return len;
    }
};


int main() {

    string s = "aabacbebebe";

    int k = 3;

    Solution obj;

    int result =
        obj.longestKSubstr(s, k);

    cout << "Longest Length: "
         << result << endl;

    return 0;
}