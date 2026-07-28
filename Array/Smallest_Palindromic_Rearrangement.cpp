#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Smallest Palindromic Rearrangement
Platform: LeetCode 3517
========================================================

Problem Statement:
Given a string s,
rearrange its characters to form the
lexicographically smallest palindrome.

If a character has an odd frequency,
place one occurrence in the middle.

Return the constructed palindrome.

========================================================
Approach Used (Frequency Counting)

Step 1:
Count the frequency of every character.

Step 2:
For each character:

- Add half of its occurrences to the
  first half of the palindrome.
- If its frequency is odd,
  place one occurrence in the middle.

Step 3:
Sort the first half to ensure the
lexicographically smallest result.

Step 4:
Append the middle character(s).

Step 5:
Reverse the first half and append it
to complete the palindrome.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        string partA = "";

        string partB = "";

        // ------------------------------
        // Count character frequencies
        // ------------------------------
        for (int i = 0; i < s.length(); i++) {

            int index = s[i] - 'a';

            freq[index]++;
        }

        // ------------------------------
        // Build first half and middle
        // ------------------------------
        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2 == 0) {

                for (int j = 0; j < freq[i] / 2; j++) {

                    partA += 'a' + i;
                }
            }

            else {

                for (int j = 0; j < freq[i] / 2; j++) {

                    partA += 'a' + i;
                }

                partB += 'a' + i;
            }
        }

        // ------------------------------
        // Construct palindrome
        // ------------------------------
        sort(partA.begin(), partA.end());

        string ans = partA;

        ans += partB;

        reverse(partA.begin(), partA.end());

        ans += partA;

        return ans;
    }
};


int main() {

    string s = "aabbc";

    Solution obj;

    string answer = obj.smallestPalindrome(s);

    cout << answer << endl;

    return 0;
}