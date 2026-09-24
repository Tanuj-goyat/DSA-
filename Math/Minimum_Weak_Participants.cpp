/**
 * ============================================================================
 * Codeforces 2266A: Minimum Weak Participants
 * ============================================================================
 *
 * Problem Statement:
 * There are 'n' participants and 3 problems. We know how many people solved
 * each problem: a1, a2, and a3. A participant is "weak" if they did not solve
 * all 3 problems. Find the minimum possible number of weak participants.
 *
 * Approach Used: Mathematical Bottleneck / Intersection Maximization
 * 1. To MINIMIZE the number of weak participants, we must MAXIMIZE the
 *    number of "strong" participants (those who solved all 3 problems).
 * 2. The maximum number of people who could possibly solve all 3 problems
 *    is completely bottlenecked by the hardest problem—the one solved by
 *    the fewest people.
 * 3. Therefore, max_strong = min(a1, min(a2, a3)).
 * 4. The minimum weak participants is simply the total participants 'n'
 *    minus this maximum strong count.
 *
 * Complexity:
 * - Time Complexity: O(1) per test case -> Only basic arithmetic and min()
 *   operations are performed.
 * - Space Complexity: O(1) -> Only primitive integer variables are allocated.
 * ============================================================================
 */

#include <iostream>
#include <algorithm> // Required for min()

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
            int n, a1, a2, a3;
            cin >> n >> a1 >> a2 >> a3;

            // The maximum possible people who solved all three is bottlenecked
            // by the problem with the lowest solve count.
            int ans = min(min(a1, a2), a3);

            // The minimum weak participants are simply the total participants
            // minus the maximum possible strong participants.
            cout << (n - ans) << "\n";
        }
    }

    return 0;
}