#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Palindromic Substrings
Platform: LeetCode (647)
========================================================

Problem Statement:
Given a string s.

Return the total number of
palindromic substrings.

A substring is considered a palindrome
if it reads the same forward and
backward.

Example:
Input:
s = "abc"

Output:
3

Explanation:
Palindromic substrings:
"a", "b", "c"

Example:
Input:
s = "aaa"

Output:
6

Explanation:
"a", "a", "a", "aa", "aa", "aaa"

========================================================
Approach Used (Brute Force)

Step 1:
Generate every possible substring.

Step 2:
For each substring,
check whether it is a palindrome.

Step 3:
If it is a palindrome,
increase the count.

Step 4:
Return the total count.

Time Complexity: O(n³)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Check whether substring
    // s[start...end] is a palindrome
    // ------------------------------
    bool isPalindrome(int start,
                      int end,
                      string& s) {

        while (start < end) {

            if (s[start] != s[end])
                return false;

            start++;

            end--;
        }

        return true;
    }

    int countSubstrings(string s) {

        int n = s.size();

        int count = 0;

        // ------------------------------
        // Generate all substrings
        // ------------------------------
        for (int i = 0;
             i < n;
             i++) {

            for (int j = i;
                 j < n;
                 j++) {

                if (isPalindrome(i, j, s))
                    count++;
            }
        }

        return count;
    }
};


int main() {

    string s = "aaa";

    Solution obj;

    int answer =
        obj.countSubstrings(s);

    cout << answer << endl;

    return 0;
}