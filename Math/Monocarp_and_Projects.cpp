/**
 * ============================================================================
 * Problem: Monocarp's Company Projects
 * ============================================================================
 *
 * Problem Statement:
 * In month 1, the company has 'x' employees and 'y' projects. Each subsequent
 * month, both increase by 1. Monocarp completes (y % x) projects himself.
 * Find the total projects Monocarp completes over 'k' months.
 *
 * Approach Used: Mathematical Simulation & Constant Modulo Optimization
 * 1. Let D = (y - x) be the difference between projects and employees. Because
 *    both x and y increase by 1 each month, this difference D is CONSTANT.
 * 2. In any month, Monocarp takes (y % x) projects. This is equivalent to
 *    (x + D) % x.
 * 3. As long as x <= D, the modulo fluctuates, so we calculate these early
 *    months iteratively in a while loop.
 * 4. CRITICAL INSIGHT: Once x > D (or x > y - x), the modulo (x + D) % x
 *    will simply equal D. It stops fluctuating and remains perfectly constant!
 * 5. Instead of iterating up to k (which is up to 10^12), we break the loop
 *    early and calculate the total for all remaining months using multiplication
 *    in O(1) time: (y - x) * (remaining_months).
 *
 * Complexity:
 * - Time Complexity: O(y - x) per testcase. Since the sum of y over all test
 *   cases is bounded by 10^6, the while loop will run at most 10^6 times
 *   overall. This easily passes within the time limit.
 * - Space Complexity: O(1) -> Only primitive integer variables are used.
 * ============================================================================
 */

#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Check if input exists to prevent hanging
    if (cin >> t)
    {
        for (; t > 0; t--)
        {
            long long x, y, k;
            cin >> x >> y >> k;

            long long ans = 0;
            int i = 1;

            // Phase 1: Simulate month-by-month as long as x <= (y - x)
            // We also cap this at k months in case k is very small
            while (i <= k && x <= (y - x))
            {
                ans += y % x;
                x++;
                y++;
                i++;
            }

            // Adjust 'i' to represent the number of months actually simulated
            i--;

            // Phase 2: O(1) calculation for all remaining months
            // For all remaining months, (y % x) is exactly equal to (y - x)
            ans += ((y - x) * (k - i));

            // Output using '\n' for speed
            cout << ans << "\n";
        }
    }

    return 0;
}