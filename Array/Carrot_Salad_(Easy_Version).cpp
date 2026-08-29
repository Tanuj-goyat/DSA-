/**
 * ============================================================================
 * Codeforces 2258B1: Carrot Salad (Easy Version)
 * ============================================================================
 *
 * Problem Statement:
 * You have an array of 'n' carrots with sizes up to 'm'. You can use a cutting
 * machine exactly once (k=1). The machine takes a subset of carrots and an
 * integer 'x'. Any chosen carrot of length l > x is cut into two pieces of
 * sizes 'x' and 'l - x'. What is the maximum number of carrots of the exact
 * same length you can obtain?
 *
 * Approach Used: Frequency Array & Greedy Counting
 * 1. Let the target carrot size be 'i'.
 * 2. With exactly 1 operation, if we choose the cutting parameter x = i:
 *    - Any carrot of size l < i is useless.
 *    - Any carrot of size l == i is already the right size (yields 1 piece).
 *    - Any carrot of size l > i is cut into 'i' and 'l - i' (yields 1 piece).
 *    - EXCEPTION: If a carrot is exactly l == 2i, it gets cut into 'i' and 'i'.
 *      This yields exactly 2 pieces!
 * 3. Therefore, the maximum number of carrots of size 'i' we can get is:
 *    (Total carrots of size >= i) + (Total carrots of size exactly 2i)
 * 4. We can compute this in O(M) time per test case by maintaining a running
 *    suffix sum (`biger`) of carrot frequencies from 'm' down to 1.
 *
 * Complexity:
 * - Time Complexity: O(N + M) per testcase -> We iterate over the array of size N
 *   to build frequencies, and then loop from M down to 1.
 * - Space Complexity: O(M) -> We use a frequency array of size M + 2.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        for (; t > 0; t--)
        {
            int n, m;
            cin >> n >> m;

            // Frequency array to store counts of each carrot size
            vector<int> freq(m + 2, 0);
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                freq[x]++;
            }

            int ans = 0;
            int biger = 0; // Tracks the count of carrots >= i

            // Check every possible target size 'i' from 'm' down to 1
            for (int i = m; i >= 1; i--)
            {
                // Add the current frequency to the running sum of elements >= i
                biger += freq[i];

                // Base count: every carrot >= i yields at least one piece of size i
                int curr = biger;

                // Bonus count: carrots of exactly size 2i split perfectly into TWO pieces of size i
                if (2 * i <= m)
                {
                    curr += freq[2 * i];
                }

                // Update the maximum possible pieces found
                ans = max(ans, curr);
            }

            // Output the answer using '\n' instead of endl for faster execution
            cout << ans << "\n";
        }
    }
    return 0;
}