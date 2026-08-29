/**
 * ============================================================================
 * Codeforces 2258A (or equivalent): Maximum GCD after operations
 * ============================================================================
 *
 * Problem Statement:
 * Given an array of n integers, you can choose any odd number of indices
 * (2k + 1) and remove the exact median/middle element of that chosen
 * subsequence. You can repeat this any number of times.
 * What is the maximum possible greatest common divisor (GCD) of the
 * remaining array?
 *
 * Approach Used: Mathematical Deduction / Greedy
 * 1. Let's analyze the removal operation: to remove an element, you need to
 *    pick 'k' elements before it and 'k' elements after it.
 * 2. Because of this rule, the very first element (a1) has no elements
 *    before it (so k=0 before it), meaning it can never act as the median
 *    of a sequence of size 3 or more. It can NEVER be removed.
 * 3. Similarly, the very last element (an) has no elements after it, so it
 *    can NEVER be removed either.
 * 4. We can successfully remove every single other element in the array
 *    except the first and the last ones.
 * 5. Since the first (a) and last (b) elements must always remain, the
 *    maximum possible GCD of the remaining array is simply bounded by them.
 *    Thus, the answer is just __gcd(a, b)!
 * 6. We process the input stream on the fly, capturing only the first and
 *    last elements to save space.
 *
 * Complexity:
 * - Time Complexity: O(N) per testcase -> We read the N integers exactly once.
 * - Space Complexity: O(1) -> We only store a few variables (a, b, and x)
 *   instead of allocating an entire array, which is highly memory efficient.
 * ============================================================================
 */

#include <iostream>
#include <algorithm> // Required for __gcd

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    // Check if input exists (helps when running locally in VS Code)
    if (cin >> t)
    {
        // Loop through all test cases
        for (; t > 0; t--)
        {
            int n;
            cin >> n;

            int a = 0, b = 0;

            // Read elements one by one without storing them all in a vector
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;

                // Capture the very first element
                if (i == 0)
                    a = x;

                // Capture the very last element
                if (i == n - 1)
                    b = x;
            }

            // The answer is just the GCD of the first and last elements
            int ans = __gcd(a, b);

            // Output the answer
            cout << ans << "\n";
        }
    }

    return 0;
}