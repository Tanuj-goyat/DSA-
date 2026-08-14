/**
 * ============================================================================
 * LeetCode 3090: Maximum Length Substring With Two Occurrences
 * ============================================================================
 *
 * Problem Statement:
 * Given a string s, return the maximum length of a substring such that it
 * contains at most two occurrences of each character.
 *
 * Approach Used: Sliding Window (Two Pointers)
 * 1. We use a frequency vector of size 26 to keep track of character counts
 *    within our current window.
 * 2. Two pointers, `i` (left) and `j` (right), define the window boundaries.
 * 3. Expand the window by moving `j` to the right and incrementing the
 *    frequency of the character `s[j]`.
 * 4. If the frequency of the current character reaches 3, the window becomes
 *    invalid. We must shrink it from the left by moving `i` forward and
 *    decrementing character frequencies until the window is valid again.
 * 5. Update the maximum length (`ans`) at each valid step using `j - i + 1`.
 *
 * Complexity:
 * - Time Complexity: O(N) -> N is the length of the string. Both pointers `i`
 *   and `j` traverse the string at most once, making it a linear time solution.
 * - Space Complexity: O(1) -> We use a fixed-size array of 26 integers, which
 *   takes constant extra space regardless of the input string size.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for max()

using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size();
        vector<int> freq(26, 0); // Array to track frequencies of lowercase letters
        int ans = 0;             // Stores the maximum substring length found
        int i = 0;               // Left pointer of the sliding window
        int j = 0;               // Right pointer of the sliding window

        while (j < n)
        {
            // Map the character to an index from 0 to 25
            int index = s[j] - 'a';
            freq[index]++;

            // If the character count exceeds 2, the window is invalid
            while (freq[index] >= 3)
            {
                // Shrink the window from the left
                int index2 = s[i] - 'a';
                freq[index2]--;
                i++;
            }

            // Record the maximum length of a valid window
            ans = max(j - i + 1, ans);

            // Expand the window by moving the right pointer
            j++;
        }

        return ans;
    }
};


int main()
{
    Solution solution;

    // Test Case 1
    string s1 = "bcbbbcba";
    int result1 = solution.maximumLengthSubstring(s1);
    cout << "String: \"" << s1 << "\"" << endl;
    cout << "Maximum Length Substring: " << result1 << endl; // Expected: 4 ("bcba")

    cout << "-----------------------------------" << endl;

    // Test Case 2
    string s2 = "aaaa";
    int result2 = solution.maximumLengthSubstring(s2);
    cout << "String: \"" << s2 << "\"" << endl;
    cout << "Maximum Length Substring: " << result2 << endl; // Expected: 2 ("aa")

    return 0;
}