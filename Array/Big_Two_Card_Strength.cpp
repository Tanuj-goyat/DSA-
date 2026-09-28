/**
 * ============================================================================
 * Problem: Big Two Card Strength
 * ============================================================================
 *
 * Problem Statement:
 * In the "Big Two" card game, the standard strength of cards is modified.
 * Instead of Ace being the highest, the order is:
 * 2 (Strongest) > 1 (Ace) > 13 (King) > 12 (Queen) > ... > 3 (Weakest).
 * Given 'n' cards, find the rank of the strongest card among them.
 *
 * Approach Used: Linear Scan with Special Case Override
 * 1. The problem requires finding the maximum value in a custom hierarchy.
 * 2. Notice that for all cards between 3 and 13, their numerical value
 *    perfectly matches their strength order (13 > 12 > 11...).
 * 3. Therefore, we can just find the standard numerical maximum (`maxi`) of
 *    the array to handle cards 3-13.
 * 4. The only exceptions are 1 and 2. We can simply use flags (`one` and `two`)
 *    to track if we ever encounter them during our single pass.
 * 5. Output Logic:
 *    - If we saw a 2, it overrides everything. Output 2.
 *    - Else if we saw a 1, it overrides 3-13. Output 1.
 *    - Else, output the standard maximum value we tracked.
 *
 * Complexity:
 * - Time Complexity: O(N) per test case -> We process the array in exactly
 *   one pass.
 * - Space Complexity: O(N) -> To store the cards in the vector (though this
 *   could easily be optimized to O(1) by calculating on the fly without a vector).
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> // Required for max()

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

        // Read n. If input fails (EOF) or n is 0, break the loop.
        if (!(cin >> n) || n == 0)
        {
            break;
        }

        vector<int> a(n);
        int two = -1;
        int one = -1;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            // Flag the special high-value cards
            if (a[i] == 2)
            {
                two = 1;
            }
            else if (a[i] == 1)
            {
                one = 1;
            }

            // Track the standard maximum for cards 3-13
            maxi = max(maxi, a[i]);
        }

        // Output the strongest card based on the Big Two hierarchy
        if (two == 1)
        {
            cout << "2\n";
        }
        else if (one == 1)
        {
            cout << "1\n";
        }
        else
        {
            cout << maxi << "\n";
        }
    }

    return 0;
}