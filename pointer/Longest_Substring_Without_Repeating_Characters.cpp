#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
========================================================
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode (3)
========================================================

Problem Statement:
Given a string s,
find the length of the longest substring
without repeating characters.

Example:
Input:
"abcabcbb"

Output:
3

Explanation:
"abc" is the longest substring
without repeating characters.

========================================================
Approach Used (Sliding Window + Hash Map):

Step 1:
Use two pointers:
- i = window start
- j = window end

Step 2:
Store latest index of characters

Step 3:
If duplicate found,
move i after previous occurrence

Step 4:
Update maximum window length

Time Complexity: O(n)
Space Complexity: O(1)
(at most 256 characters)

========================================================
*/

class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        // Character -> latest index
        unordered_map<char, int> m;

        // Sliding window pointers
        int i = 0;
        int j = 0;

        int len = 0;

        int maxLen = 0;

        // ------------------------------
        // Sliding window traversal
        // ------------------------------
        while (j < n) {

            // Character not seen before
            if (m.find(s[j]) == m.end()) {

                m[s[j]] = j;
            }

            // Duplicate character found
            else {

                // Move left pointer safely
                i = max(i, m[s[j]] + 1);

                // Update latest index
                m[s[j]] = j;
            }

            // Current window length
            len = j - i + 1;

            // Maximum length
            maxLen = max(len, maxLen);

            j++;
        }

        return maxLen;
    }
};


int main() {

    string s = "abcabcbb";

    Solution obj;

    int result =
        obj.lengthOfLongestSubstring(s);

    cout << "Longest Length: "
         << result << endl;

    return 0;
}