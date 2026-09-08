/**
 * ============================================================================
 * Problem: Total Commas in Numbers from 1 to N
 * ============================================================================
 *
 * Problem Statement:
 * Given an integer `n`, calculate the total number of commas used when writing
 * all the integers from 1 to `n` inclusive in standard Western number format
 * (where commas separate thousands, e.g., 1,000 or 1,000,000).
 *
 * Approach Used: Mathematical Grouping by Digit Length
 * 1. Convert the number `n` to a string to easily find its total digit `size`.
 * 2. Numbers with 1 to 3 digits have 0 commas. We only care about sizes >= 4.
 * 3. We loop through completely filled digit lengths `i` from 4 up to `size - 1`:
 *    - The number of commas for any `i`-digit number is exactly `(i - 1) / 3`.
 *    - The total count of `i`-digit numbers is `9 * 10^(i-1)`.
 *      (e.g., there are 9000 4-digit numbers: 1000 to 9999).
 *    - We multiply these together and add them to our total `ans`.
 * 4. Finally, for the last group (numbers with exactly `size` digits up to `n`):
 *    - We calculate how many commas each of these numbers has: `(size - 1) / 3`.
 *    - We find how many such numbers exist: `(n + 1) - 10^(size - 1)`.
 *    - We multiply and add this to `ans`.
 *
 * Complexity:
 * - Time Complexity: O(log_10 N) -> The loop runs once for each digit length
 *   of N. Since the maximum integer fits in 10 digits, this is effectively O(1).
 * - Space Complexity: O(1) -> Only a few integer variables and a small string
 *   allocation are used.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <cmath> // Required for pow()

using namespace std;

class Solution
{
public:
    int countCommas(int n)
    {
        // Convert to string to easily find the number of digits
        string s = to_string(n);
        int size = s.length();
        int ans = 0;

        // Calculate commas for all fully completed digit lengths (from 4 up to size - 1)
        for (int i = 4; i < size; i++)
        {
            // Number of commas present in a number of length 'i'
            int comma = (i - 1) / 3;

            // Total amount of numbers that have exactly 'i' digits
            int count = 9 * (int)pow(10, i - 1);

            ans += comma * count;
        }

        // Calculate commas for the final, partially completed digit length up to 'n'
        if (size >= 4)
        {
            ans += ((size - 1) / 3) * ((n + 1) - ((int)pow(10, size - 1)));
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

    // Test Case 1: n = 999
    // Numbers 1 to 999 have no commas.
    int n1 = 999;
    cout << "N = " << n1 << endl;
    cout << "Total Commas: " << solution.countCommas(n1) << endl;
    // Expected: 0

    cout << "-----------------------------------" << endl;

    // Test Case 2: n = 1000
    // Only the number 1,000 has a comma.
    int n2 = 1000;
    cout << "N = " << n2 << endl;
    cout << "Total Commas: " << solution.countCommas(n2) << endl;
    // Expected: 1

    cout << "-----------------------------------" << endl;

    // Test Case 3: n = 1010
    // Numbers 1,000 through 1,010 inclusive (11 numbers), each has 1 comma.
    int n3 = 1010;
    cout << "N = " << n3 << endl;
    cout << "Total Commas: " << solution.countCommas(n3) << endl;
    // Expected: 11

    cout << "-----------------------------------" << endl;

    // Test Case 4: n = 1000000
    // 9000 numbers have 1 comma (1,000-9,999) = 9,000 commas
    // 90000 numbers have 1 comma (10,000-99,999) = 90,000 commas
    // 900000 numbers have 1 comma (100,000-999,999) = 900,000 commas
    // The number 1,000,000 has 2 commas.
    // Total = 999,000 + 2 = 999,002
    int n4 = 1000000;
    cout << "N = " << n4 << endl;
    cout << "Total Commas: " << solution.countCommas(n4) << endl;
    // Expected: 999002

    return 0;
}