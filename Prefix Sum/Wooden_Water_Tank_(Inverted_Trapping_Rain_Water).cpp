/**
 * ============================================================================
 * Problem: Wooden Water Tank (Inverted Trapping Rain Water)
 * ============================================================================
 *
 * Problem Statement:
 * A rectangular wooden water tank has varying bottom depths. The boards at
 * both ends fall off, causing water to spill out. Given the depth of each
 * section from the top, calculate the total amount of water that remains
 * trapped in the deeper sections of the tank.
 *
 * Approach Used: Prefix and Suffix Extrema
 * 1. This is an inverted version of "Trapping Rain Water". Instead of heights
 *    from the bottom, we are given depths from the top.
 * 2. Step 1 (Left Barriers): We compute a `prefmin` array. `prefmin[i]` stores
 *    the minimum depth (which corresponds to the highest physical floor) from
 *    the left end up to section i.
 * 3. Step 2 (Right Barriers): We compute a `suffmin` array. `suffmin[i]` stores
 *    the minimum depth from the right end down to section i.
 * 4. Step 3 (Water Level): For any section `i`, the water is trapped by the
 *    barriers on its left and right. Water spills over the barrier that is
 *    physically lower. A physically lower barrier means a GREATER depth from
 *    the top. Thus, the depth of the water surface is `max(prefmin[i], suffmin[i])`.
 * 5. Step 4 (Accumulate): If this water surface depth `mini` is less than the
 *    actual depth of the section `a[i]`, water is trapped! The amount is exactly
 *    `a[i] - mini`.
 *
 * Complexity:
 * - Time Complexity: O(N) per test case -> We do three distinct linear passes
 *   (one for prefmin, one for suffmin, one to calculate the answer).
 * - Space Complexity: O(N) -> We allocate arrays for prefix and suffix minimums.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for min() and max()

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Process continuous test cases until n == 0
    while (true)
    {
        int n;

        // Safely read input and check for the termination condition
        if (!(cin >> n) || n == 0)
        {
            break;
        }

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Edge case: A tank with less than 3 sections cannot trap any water
        // because both ends are exposed. The loops below handle this safely,
        // but it's good to note conceptually.
        if (n < 3)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<int> prefmin(n), suffmin(n);

        // Build the prefix minimums (highest bottom to the left)
        prefmin[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            prefmin[i] = min(prefmin[i - 1], a[i]);
        }

        // Build the suffix minimums (highest bottom to the right)
        suffmin[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffmin[i] = min(suffmin[i + 1], a[i]);
        }

        int ans = 0;

        // We only check from 1 to n-2 because sections 0 and n-1 are the
        // open ends where water completely spills out.
        for (int i = 1; i < n - 1; i++)
        {
            // The water level depth is dictated by the lowest barrier
            // (which translates to the maximum depth value of the two barriers)
            int mini = max(prefmin[i], suffmin[i]);

            // If the barrier depth is greater than the bottom depth, water
            // just flows away (no water trapped).
            if (mini > a[i])
            {
                continue;
            }
            // Otherwise, water is trapped up to the barrier line
            else
            {
                ans += a[i] - mini;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}