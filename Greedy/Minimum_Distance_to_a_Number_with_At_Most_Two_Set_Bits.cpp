/**
 * ============================================================================
 * Problem: Minimum Distance to a Number with At Most Two Set Bits
 * ============================================================================
 *
 * Approach Used: Bit Manipulation & Greedy Candidates
 * 1. Step 1 (Fast Exponentiation): The custom `Pow` function calculates base^exp
 *    in O(log exp) time using binary exponentiation, preventing TLE.
 * 2. Step 2 (Power of 2 Check): The expression `(x & (x - 1)) == 0` checks if
 *    `x` is already a perfect power of 2 (has exactly one set bit). If it is,
 *    the distance is 0.
 * 3. Step 3 (Find Bounds): The helper function `f(x)` finds the smallest power
 *    `i` such that 2^i > x.
 *    - `a` represents the first power of 2 strictly greater than `x`.
 *    - `b` represents the first power of 2 strictly greater than the remainder
 *      `(x - 2^(a-1))`.
 * 4. Step 4 (Candidate Evaluation): The closest number with at most 2 set bits
 *    must be one of three candidates:
 *    - ans1: Overshooting with 2^a + 1.
 *    - ans2: Taking the lower bound of the first bit (2^(a-1)) and overshooting
 *            the remainder with the upper bound of the second bit (2^b).
 *    - ans3: Taking the lower bound of both bits (2^(a-1) + 2^(b-1)).
 * 5. We simply output the minimum of these three absolute differences.
 *
 * Complexity:
 * - Time Complexity: O(log X) -> The `f(x)` function runs in logarithmic time
 *   relative to X. `Pow` also runs in O(log(exp)).
 * - Space Complexity: O(1) -> Only primitive integer variables are allocated.
 * ============================================================================
 */

#include <iostream>
#include <cmath>
#include <algorithm> // Required for min()

using namespace std;

// Fast binary exponentiation: O(log exp)
long long Pow(long long base, int exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

// Finds the smallest exponent 'i' such that 2^i > x
long long f(long long x)
{
    long long i = 0;
    while (Pow(2, i) <= x)
        i++;
    return i;
}

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    // Check if input exists to avoid hanging when running locally
    if (cin >> t)
    {
        for (; t > 0; t--)
        {
            long long x;
            cin >> x;

            // If x is a power of 2 (has exactly 1 set bit), the distance is 0.
            // Note: x != 1 handles the edge case for 1.
            if (x != 1 && (x & (x - 1)) == 0)
            {
                cout << "0\n";
                continue;
            }

            // a: The exponent where 2^a is the first power of 2 greater than x
            long long a = f(x);

            // b: The exponent where 2^b is the first power of 2 greater than the remainder
            long long b = f(x - Pow(2, a - 1));

            // Candidate 1: 2^a + 1
            long long ans1 = abs((Pow(2, a) + 1) - x);

            // Candidate 2: 2^(a-1) + 2^b
            long long ans2 = abs((Pow(2, a - 1) + Pow(2, b)) - x);

            // Candidate 3: 2^(a-1) + 2^(b-1)
            long long ans3 = abs(x - (Pow(2, a - 1) + Pow(2, b - 1)));

            // Output the minimum absolute distance using \n for speed
            cout << min(ans1, min(ans2, ans3)) << "\n";
        }
    }

    return 0;
}