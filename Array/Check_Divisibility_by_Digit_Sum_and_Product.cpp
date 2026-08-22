/**
 * ============================================================================
 * LeetCode 3622: Check Divisibility by Digit Sum and Product
 * ============================================================================
 *
 * Problem Statement:
 * You are given a positive integer `n`. Determine whether `n` is divisible by
 * the sum of its digit sum (sum of its digits) and its digit product (product
 * of its digits). Return `true` if `n` is divisible by this sum, otherwise
 * return `false`.
 *
 * Approach Used: Math / Digit Extraction Simulation
 * 1. Store a copy of `n` in `num` so we can extract its digits without losing
 *    the original value of `n` (which we need for the final modulo check).
 * 2. Initialize `sum` to 0 and `prod` to 1.
 * 3. Use a `while` loop to iteratively extract the last digit of `num` using
 *    `num % 10`.
 * 4. Add the extracted digit to `sum` and multiply it into `prod`.
 * 5. Remove the last digit from `num` using `num / 10`.
 * 6. Finally, check if `n % (sum + prod) == 0`. If the remainder is 0, it is
 *    divisible!
 *
 * Complexity:
 * - Time Complexity: O(log n) -> The number of digits in an integer `n` is
 *   proportional to log(n) base 10. We process each digit exactly once.
 * - Space Complexity: O(1) -> Only a few integer variables are used, taking
 *   constant extra space.
 * ============================================================================
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int sum = 0;  // To store the sum of the digits
        int prod = 1; // To store the product of the digits
        int num = n;  // Copy of n to safely extract digits without mutating n

        // Extract digits one by one until the number becomes 0
        while (num)
        {
            int digit = num % 10; // Get the rightmost digit
            num /= 10;            // Remove the rightmost digit

            sum += digit;  // Add to the running sum
            prod *= digit; // Multiply to the running product
        }

        // Check if the original number is divisible by (sum + prod)
        if (n % (sum + prod) == 0)
            return true;

        return false;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: n = 99
    // sum = 9 + 9 = 18. prod = 9 * 9 = 81.
    // sum + prod = 18 + 81 = 99.
    // 99 % 99 == 0 -> true.
    int n1 = 99;
    cout << "Input: " << n1 << endl;
    cout << "Is Divisible: " << (solution.checkDivisibility(n1) ? "true" : "false") << endl;

    cout << "-----------------------------------" << endl;

    // Test Case 2: n = 23
    // sum = 2 + 3 = 5. prod = 2 * 3 = 6.
    // sum + prod = 5 + 6 = 11.
    // 23 % 11 != 0 -> false.
    int n2 = 23;
    cout << "Input: " << n2 << endl;
    cout << "Is Divisible: " << (solution.checkDivisibility(n2) ? "true" : "false") << endl;

    return 0;
}