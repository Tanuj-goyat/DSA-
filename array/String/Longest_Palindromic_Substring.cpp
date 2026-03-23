#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem Name: Longest Palindromic Substring
Platform: LeetCode
Problem Number: 5
========================================================

Problem Statement:
Given a string s, return the longest palindromic substring.

A palindrome is a string that reads the same forward
and backward.

Example:
Input:  "babad"
Output: "bab" or "aba"

Input:  "cbbd"
Output: "bb"

========================================================
Approach (Brute Force + Palindrome Check)

Steps:

1️⃣ Count frequency of characters (used as optimization)
2️⃣ Try every possible substring:
   - Fix start index i
   - Fix end index j
3️⃣ Check if substring is palindrome
4️⃣ Keep track of longest valid substring

Palindrome check:
Compare characters from both ends moving inward.

========================================================
Time Complexity: O(n³)
(2 loops + palindrome check)

Space Complexity: O(n)

========================================================
*/

class Solution {
public:
    string longestPalindrome(string s) {

        unordered_map<char, int> mp;   // frequency map
        string ans = "";

        // Step 1: Count frequency
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        // Step 2: Try all substrings
        for (int i = 0; i < s.size(); i++) {

            // Small optimization:
            // skip if character appears only once
            if (mp[s[i]] == 1)
                continue;

            for (int j = s.size() - 1; j > i; j--) {

                // If end character doesn't match start → skip
                if (s[j] != s[i])
                    continue;

                bool valid = true;

                // Step 3: Check palindrome
                for (int l = i, r = j; l < r; l++, r--) {
                    if (s[l] != s[r]) {
                        valid = false;
                        break;
                    }
                }

                // Step 4: Update answer
                if (valid && ans.size() < j - i + 1) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }

        // If no palindrome found, return first character
        if (ans.size() == 0 && s.size() > 0) {
            ans.push_back(s[0]);
        }

        return ans;
    }
};


int main() {

    string s = "babad";

    Solution obj;

    string result = obj.longestPalindrome(s);

    cout << "Longest Palindromic Substring: " << result;

    return 0;
}