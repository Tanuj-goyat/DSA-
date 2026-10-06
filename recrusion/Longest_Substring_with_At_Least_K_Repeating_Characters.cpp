/**
 * ============================================================================
 * LeetCode 395: Longest Substring with At Least K Repeating Characters
 * ============================================================================
 *
 * Problem Statement:
 * Given a string `s` and an integer `k`, return the length of the longest
 * substring of `s` such that the frequency of each character in this substring
 * is greater than or equal to `k`.
 *
 * Approach Used: Divide and Conquer
 * 1. Base Case: If the window length `b - a` is less than `k`, it's impossible
 *    to have a valid substring, so return 0.
 * 2. Step 1 (Frequency Map): Count the occurrences of each character in the
 *    current substring window `[a, b)`.
 * 3. Step 2 (Find the Split Point): Scan the window from left to right. Find
 *    the first character `s[x]` that has a frequency strictly less than `k`.
 *    Because this character can NEVER be part of a valid substring, any valid
 *    substring must exist entirely to its left or entirely to its right.
 * 4. Step 3 (Conquer):
 *    - If no such invalid character is found (`x == b`), the entire current
 *      window is valid! Return its length `b - a`.
 *    - Otherwise, recursively call the function on the left side `[a, x)`
 *      and the right side `[x + 1, b)`.
 * 5. Return the maximum of the valid substrings found in the left and right halves.
 *
 * Complexity:
 * - Time Complexity: O(N^2) in the absolute worst case (e.g., if we split the
 *   string one character at a time). However, since there are only 26 unique
 *   alphabet characters, the recursion depth is bounded by 26, making it
 *   O(N) or O(N log N) in practice.
 * - Space Complexity: O(N) -> Due to the recursion stack depth.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm> // Required for max()

using namespace std;

class Solution
{
public:
    int f(string &s, int k, int a, int b)
    {
        // Base case: window is too small to satisfy condition
        if (b - a < k)
            return 0;

        unordered_map<char, int> m;
        // Count frequencies of characters in the current window
        for (int i = a; i < b; i++)
        {
            m[s[i]]++;
        }

        int x = a;
        // Find the first character that appears fewer than 'k' times
        while (x < b && m[s[x]] >= k)
        {
            x++;
        }

        // If all characters in the window appear at least k times, the whole window is valid
        if (x == b)
        {
            return b - a;
        }

        m.clear(); // Optional: Clear memory (handled by scope destruction anyway)

        // Divide: Split the string at the invalid character 'x' and search both halves
        int r = f(s, k, a, x);
        int l = f(s, k, x + 1, b);

        // Conquer: Return the maximum valid substring length from both halves
        return max(r, l);
    }

    int longestSubstring(string s, int k)
    {
        // Call the helper function with the full string boundaries [0, size)
        return f(s, k, 0, s.size());
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard valid case
    // String: "aaabb", k = 3
    // 'a' appears 3 times, 'b' appears 2 times.
    // Invalid character is 'b'. Splitting at 'b' leaves "aaa" (length 3).
    string s1 = "aaabb";
    int k1 = 3;
    cout << "Test Case 1:" << endl;
    cout << "Input: s = \"aaabb\", k = 3" << endl;
    cout << "Longest Substring Length: " << solution.longestSubstring(s1, k1) << endl;
    // Expected: 3 ("aaa")

    cout << "-----------------------------------" << endl;

    // Test Case 2: Multiple splits required
    // String: "ababbc", k = 2
    // 'c' is invalid. Split into "ababb".
    // In "ababb", 'a' appears 2 times, 'b' appears 3 times. Valid!
    string s2 = "ababbc";
    int k2 = 2;
    cout << "Test Case 2:" << endl;
    cout << "Input: s = \"ababbc\", k = 2" << endl;
    cout << "Longest Substring Length: " << solution.longestSubstring(s2, k2) << endl;
    // Expected: 5 ("ababb")

    cout << "-----------------------------------" << endl;

    // Test Case 3: No valid substring
    // String: "abcd", k = 2
    // No character appears at least 2 times.
    string s3 = "abcd";
    int k3 = 2;
    cout << "Test Case 3:" << endl;
    cout << "Input: s = \"abcd\", k = 2" << endl;
    cout << "Longest Substring Length: " << solution.longestSubstring(s3, k3) << endl;
    // Expected: 0

    return 0;
}