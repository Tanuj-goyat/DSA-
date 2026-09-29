/**
 * ============================================================================
 * Problem: TOPC Crit (Arithmetic Progression Check)
 * ============================================================================
 *
 * Problem Statement:
 * Given three damage values a, b, and c, determine if they form an arithmetic
 * progression. They form an arithmetic progression if the difference between
 * consecutive values is the same (b - a == c - b).
 * If they do, output "secret x" where x is this common difference.
 * Otherwise, output "not secret".
 *
 * Approach Used: O(1) Mathematical Check
 * 1. Read the three integers.
 * 2. Calculate the difference between the second and first (b - a).
 * 3. Calculate the difference between the third and second (c - b).
 * 4. If they are equal, the sequence is an arithmetic progression. Output
 *    "secret " followed by the common difference.
 * 5. If they are not equal, output "not secret".
 *
 * Complexity:
 * - Time Complexity: O(1) -> A single constant-time arithmetic check.
 * - Space Complexity: O(1) -> Only primitive integer variables are allocated.
 * ============================================================================
 */

#include <iostream>

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Using long long to safely prevent any overflow during subtraction,
    // since values can range from -10^9 to 10^9.
    long long a, b, c;

    // Check if input exists to avoid hanging when running locally
    if (cin >> a >> b >> c)
    {
        // Check if the common differences match
        if (b - a == c - b)
        {
            cout << "secret " << (b - a) << "\n";
        }
        else
        {
            cout << "not secret\n";
        }
    }

    return 0;
}