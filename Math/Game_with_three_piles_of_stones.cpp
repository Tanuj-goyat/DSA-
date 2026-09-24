/**
 * ============================================================================
 * Codeforces 2266B: Game with three piles of stones
 * ============================================================================
 *
 * Problem Statement:
 * Alice has 'a' stones, Bob has 'b' stones. A third pile has 'c' stones.
 * Alice and Bob take turns taking any amount from 'c' to add to their pile.
 * Alice wants to MAXIMIZE the absolute difference |A - B|.
 * Bob wants to MINIMIZE the absolute difference |A - B|.
 *
 * Approach Used: Game Theory / Greedy Strategy
 * 1. Alice goes first and controls the flow.
 * 2. Case 1 (a >= b): Alice is already winning. To maximize the difference,
 *    she greedily takes ALL 'c' stones on turn 1. Bob gets 0.
 *    Final score: (a + c) - b.
 * 3. Case 2 (a < b): Alice is currently losing. She has two options:
 *    - Option A (Take all): She takes all 'c' stones. Bob gets 0.
 *      The difference becomes |(a + c) - b|.
 *    - Option B (Take none): She takes 0. Since Bob wants to minimize the
 *      difference and is already ahead, taking any stones would only INCREASE
 *      his lead. So Bob also takes 0. The game ends. The difference is (b - a).
 * 4. Alice simply picks the maximum between Option A and Option B.
 *    The formula max((a+c)-b, b-a) elegantly handles the absolute value
 *    because if (a+c) is still less than b, the left side is negative and
 *    the positive (b-a) automatically wins the max check.
 *
 * Complexity:
 * - Time Complexity: O(1) per test case -> Only basic arithmetic and a single
 *   comparison are performed.
 * - Space Complexity: O(1) -> Only 64-bit integer variables are allocated.
 * ============================================================================
 */

#include <iostream>
#include <algorithm> // Required for max()

using namespace std;

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
            long long a, b, c;
            long long result = 0;
            cin >> a >> b >> c;

            // If Alice starts with fewer stones than Bob
            if (a < b)
            {
                // Compare taking ALL stones vs taking NO stones
                result = max((a + c) - b, b - a);
            }
            // If Alice starts with more or equal stones
            else if (a >= b)
            {
                // Take ALL stones to maximize the lead
                result = (a + c) - b;
            }

            // Output using '\n' for speed
            cout << result << "\n";
        }
    }
    return 0;
}