/**
 * ============================================================================
 * LeetCode 1780: Check if Number is a Sum of Powers of Three
 * ============================================================================
 *
 * Problem Statement: 
 * Given an integer n, return true if it is possible to represent n as the sum
 * of distinct powers of three. Otherwise, return false.
 * An integer y is a power of three if there exists an integer x such that y == 3^x.
 *
 * Approach Used: Base-3 (Ternary) Representation
 * 1. Any integer can be uniquely represented in base-3 using the digits 0, 1, and 2.
 * 2. If a number is the sum of DISTINCT powers of 3, its base-3 representation
 *    can only contain the digits 0 and 1 (meaning a power of 3 is either omitted
 *    or used exactly once).
 * 3. If the base-3 representation contains a digit '2', it means we would need
 *    to use a specific power of 3 twice, which violates the "distinct" rule.
 * 4. We extract the base-3 digits from right to left using `num % 3`. If we
 *    ever see a 2, we immediately return false.
 * 5. We then shift to the next base-3 digit by dividing `num` by 3.
 *
 * Complexity:
 * - Time Complexity: O(log_3 N) -> We divide the number by 3 in each iteration,
 *   making this extremely fast (at most ~15 iterations for N = 10^7).
 * - Space Complexity: O(1) -> Only a single integer variable is used.
 * ============================================================================
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int num = n;

        // Loop to extract base-3 digits until the number is reduced to 1 or 0
        while (num > 1)
        {

            // If the current base-3 digit is 2, it requires using the same
            // power of 3 twice. This violates the "distinct powers" condition.
            if (num % 3 == 2)
            {
                return false;
            }

            // Move to the next most significant base-3 digit
            num /= 3;
        }

        // If we processed all digits without finding a '2', it is valid
        return true;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: n = 12
    // 12 = 3^1 + 3^2 = 3 + 9
    // Base 3 of 12 is 110 (valid)
    int n1 = 12;
    cout << "N = " << n1 << endl;
    cout << "Can be represented: "
         << (solution.checkPowersOfThree(n1) ? "true" : "false") << endl;
    // Expected: true

    cout << "-----------------------------------" << endl;

    // Test Case 2: n = 91
    // 91 = 3^0 + 3^2 + 3^4 = 1 + 9 + 81
    // Base 3 of 91 is 10101 (valid)
    int n2 = 91;
    cout << "N = " << n2 << endl;
    cout << "Can be represented: "
         << (solution.checkPowersOfThree(n2) ? "true" : "false") << endl;
    // Expected: true

    cout << "-----------------------------------" << endl;

    // Test Case 3: n = 21
    // Base 3 of 21 is 210 (contains a 2 -> invalid)
    int n3 = 21;
    cout << "N = " << n3 << endl;
    cout << "Can be represented: "
         << (solution.checkPowersOfThree(n3) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}