/**
 * ============================================================================
 * Problem: Minimum Swaps to Make First and Last Problems Easy
 * ============================================================================
 *
 * Problem Statement:
 * Monocarp has 'n' problems, each either easy (0) or hard (1). He wants the
 * first and last problems of the contest to be easy (0). In one operation,
 * he can swap ANY two problems. Find the minimum operations required, or
 * return -1 if impossible.
 *
 * Approach Used: Greedy Observation & Stream Processing
 * 1. We process the input array on the fly without storing it in memory.
 *    We only need three crucial pieces of information:
 *    - `p`: The very first problem's difficulty.
 *    - `q`: The very last problem's difficulty.
 *    - `a`: The total frequency of easy problems (0s) in the entire array.
 * 2. If the array contains fewer than two easy problems (`a < 2`), we can't
 *    possibly place an easy problem at both the start and the end. Return -1.
 * 3. If there are at least two easy problems, we just check the boundaries:
 *    - If both boundaries are already 0 (`p == 0` and `q == 0`), 0 swaps needed.
 *    - If both boundaries are 1 (`p == 1` and `q == 1`), we need to swap two
 *      different 0s from the middle to the ends, requiring 2 swaps.
 *    - If the boundaries are mixed (one is 1, the other is 0), we only need
 *      to swap one 0 from the middle to the end that currently has a 1,
 *      requiring 1 swap.
 *
 * Complexity:
 * - Time Complexity: O(N) per testcase -> We read the N integers exactly once.
 * - Space Complexity: O(1) -> We only store a few variables (a, p, q, and x)
 *   instead of allocating an entire array, which is highly memory efficient!
 * ============================================================================
 */

#include <iostream>

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

            int n;
            cin >> n;

            int a = 0;  // Frequency count of easy problems (0s)
            int p = -1; // First problem's difficulty
            int q = -1; // Last problem's difficulty

            // Process the array elements on the fly
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;

                // Capture the first problem
                if (i == 0)
                    p = x;

                // Capture the last problem
                if (i == n - 1)
                    q = x;

                // Count the number of easy problems
                if (x == 0)
                    a++;
            }

            int ans = -1;

            // Apply the boundary logic if we have enough easy problems
            if (a >= 2)
            {
                if (p == q && p == 0)
                {
                    ans = 0; // Both already easy
                }
                else if (p == q && p == 1)
                {
                    ans = 2; // Both are hard, need 2 swaps
                }
                else
                {
                    ans = 1; // One is hard, one is easy, need 1 swap
                }
            }

            // Output the answer using '\n' instead of endl for faster execution
            cout << ans << "\n";
        }
    }

    return 0;
}