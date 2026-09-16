/**
 * ============================================================================
 * LeetCode 2396: Strictly Palindromic Number
 * ============================================================================
 *
 * Problem Statement:
 * An integer n is strictly palindromic if, for every base b between 2 and n - 2
 * (inclusive), the string representation of the integer n in base b is
 * palindromic. Return true if n is strictly palindromic and false otherwise.
 *
 * Approach Used: Base Conversion & Two-Pointer Palindrome Check
 * 1. We iterate through every base from `2` up to `n - 2`.
 * 2. For each base, we extract the digits of `n` in that base using modulo (`%`)
 *    and division (`/`), pushing them into a vector `v`.
 * 3. We pass this vector to `isPalindrome()`, which uses a two-pointer approach
 *    (`i` at the start, `j` at the end) to verify if the digits mirror each other.
 * 4. If any base representation is NOT a palindrome, we immediately return false.
 * 5. If we successfully check all bases, we return true.
 *
 * Complexity:
 * - Time Complexity: O(N * log_base N) -> We check N-3 different bases.
 *   Converting the number to each base takes logarithmic time.
 * - Space Complexity: O(log N) -> The vector stores the digits of the number
 *   in the current base.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Helper function to check if a vector of digits is a palindrome
    bool isPalindrome(const vector<int> &s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;

            // FIX: Increment and decrement the pointers to avoid an infinite loop!
            i++;
            j--;
        }
        return true;
    }

    bool isStrictlyPalindromic(int n)
    {
        // FIX: Check all bases from 2 up to n - 2
        for (int base = 2; base <= n - 2; base++)
        {

            vector<int> v;
            int temp = n; // Use a temporary variable so we don't destroy 'n'

            // Extract the digits in the current base
            while (temp > 0)
            {
                v.push_back(temp % base);
                temp /= base;
            }

            // If the representation in this base is not a palindrome, it fails
            if (!isPalindrome(v))
            {
                return false;
            }
        }

        return true;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: n = 9
    // Base 2: 1001 (Palindrome)
    // Base 3: 100 (Not a palindrome) -> Should return false immediately.
    int n1 = 9;
    cout << "Test Case 1 (n = 9):" << endl;
    cout << "Is Strictly Palindromic? "
         << (solution.isStrictlyPalindromic(n1) ? "true" : "false") << endl;
    // Expected: false

    cout << "-----------------------------------" << endl;

    // Test Case 2: n = 4
    // Base 2: 100 (Not a palindrome)
    int n2 = 4;
    cout << "Test Case 2 (n = 4):" << endl;
    cout << "Is Strictly Palindromic? "
         << (solution.isStrictlyPalindromic(n2) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}