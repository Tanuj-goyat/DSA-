/**
 * ============================================================================
 * Codeforces 2266C: Binary String Sorting with Bitwise Prefix Operations
 * ============================================================================
 *
 * Problem Statement:
 * You have a binary string `s`. You can replace `s[i]` with the bitwise AND
 * or OR of the prefix `s[1...i]`. Find the minimum operations to sort `s`
 * in non-decreasing order (e.g., 000111).
 *
 * Approach Used: Prefix/Suffix Boundary Optimization
 * 1. Step 1 (Immutability of s[0]): The first character `s[0]` can never change
 *    because the AND/OR of a single element is just itself.
 * 2. Step 2 (Edge Case - Starts with 1): If `s[0] == '1'`, the only valid sorted
 *    array is all 1s. We must change every '0' in the string to a '1' using a
 *    bitwise OR. The cost is exactly the total number of '0's.
 * 3. Step 3 (Finding the Pivot): If `s[0] == '0'`, the final string will be
 *    formatted as `00..0011..11`. We iterate through the string considering
 *    each index `i` as the boundary (pivot).
 *    - `one`: Tracks the number of '1's in the left prefix that we must
 *      convert to '0's (using AND with s[0]).
 *    - `zero`: Tracks the number of '0's in the right suffix that we must
 *      convert to '1's (using OR).
 * 4. As we sweep from left to right, if we see a '1', we increment the prefix
 *    `one` count. If we see a '0', we decrement the suffix `zero` count.
 * 5. The minimum operations needed is the minimum value of `one + zero` at
 *    any pivot point!
 *
 * Complexity:
 * - Time Complexity: O(N) per test case -> We count total 0s in one pass,
 *   then find the optimal pivot in a second pass.
 * - Space Complexity: O(1) auxiliary space -> Only primitive integer variables
 *   are used to track the counts.
 * ============================================================================
 */

#include <iostream>
#include <string>
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
            int n;
            cin >> n;
            string s;
            cin >> s;

            int one = 0;
            int zero = 0;
            int ans = n;

            // First pass: Count the total number of '0's in the string
            for (char x : s)
            {
                if (x == '0')
                    zero++;
            }

            // Edge Case: If the string starts with '1', we can only sort it
            // by making everything '1'.
            if (s[0] == '1')
            {
                cout << zero << "\n";
                continue;
            }

            // Second pass: Find the optimal boundary to split 0s and 1s
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    // This '1' is on the left side, we will need to change it to '0'
                    one++;
                }
                else
                {
                    // This '0' has passed to the left side, we no longer need
                    // to change it to a '1', so remove it from the suffix count
                    zero--;
                }

                // Track the minimum total changes required across all possible splits
                ans = min(ans, one + zero);
            }

            // Output using '\n' for speed
            cout << ans << "\n";
        }
    }

    return 0;
}