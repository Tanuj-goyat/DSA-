/**
 * ============================================================================
 * Problem: Total Commas in Numbers from 1 to N (64-bit Optimized)
 * ============================================================================
 *
 * Problem Statement:
 * Given a large integer `n`, calculate the total number of commas used when
 * writing all the integers from 1 to `n` inclusive in standard Western number
 * format (e.g., 1,000 or 1,000,000).
 *
 * Approach Used: Mathematical Grouping by Digit Length
 * 1. Convert the number `n` to a string to easily find its total digit `size`.
 * 2. Numbers with 1 to 3 digits have 0 commas. We only care about sizes >= 4.
 * 3. We loop through completely filled digit lengths `i` from 4 up to `size - 1`:
 *    - The number of commas for any `i`-digit number is exactly `(i - 1) / 3`.
 *    - The total count of `i`-digit numbers is `9 * 10^(i-1)`.
 *    - We multiply these together and add them to our total `ans`.
 * 4. Finally, for the last group (numbers with exactly `size` digits up to `n`):
 *    - We calculate how many commas each of these numbers has: `(size - 1) / 3`.
 *    - We find how many such numbers exist: `(n + 1) - 10^(size - 1)`.
 *    - We multiply and add this to `ans`.
 *
 * Note on Data Types:
 * All calculations use `long long` to prevent integer overflow, allowing this
 * algorithm to easily process inputs up to ~10^15 safely.
 *
 * Complexity:
 * - Time Complexity: O(log_10 N) -> The loop runs once for each digit length
 *   of N. For a 64-bit integer, this loops at most 18 times, making it O(1).
 * - Space Complexity: O(1) -> Only a few variables and a small string are used.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <cmath> // Required for pow()

using namespace std;

class Solution
{
public:
    long long countCommas(long long n)
    {
        // Convert to string to easily find the number of digits
        string s = to_string(n);
        long long size = s.length();
        long long ans = 0;

        // Calculate commas for all fully completed digit lengths (from 4 up to size - 1)
        for (int i = 4; i < size; i++)
        {
            long long comma = (i - 1) / 3;
            long long count = 9 * (long long)pow(10, i - 1);
            ans += comma * count;
        }

        // Calculate commas for the final, partially completed digit length up to 'n'
        if (size >= 4)
        {
            ans += ((size - 1) / 3) * ((n + 1) - ((long long)pow(10, size - 1)));
        }

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard bounds testing
    long long n1 = 1000000;
    cout << "N = " << n1 << endl;
    cout << "Total Commas: " << solution.countCommas(n1) << endl;
    // Expected: 999002

    cout << "-----------------------------------" << endl;

    // Test Case 2: Pushing past 32-bit integer limits (~2.14 x 10^9)
    // Using a 10-digit number (3 billion)
    long long n2 = 3000000000LL;
    cout << "N = " << n2 << endl;
    cout << "Total Commas: " << solution.countCommas(n2) << endl;
    // Expected: 4999000002

    cout << "-----------------------------------" << endl;

    // Test Case 3: Massive scale (1 trillion)
    long long n3 = 1000000000000LL;
    cout << "N = " << n3 << endl;
    cout << "Total Commas: " << solution.countCommas(n3) << endl;
    // Expected: 2999999000003

    return 0;
}