/**
 * ============================================================================
 * Codeforces 579A: Raising Bacteria
 * ============================================================================
 *
 * Problem Statement:
 * You want to raise exactly 'x' bacteria in a box. Each night, every bacterium
 * in the box splits into two. You can add bacteria into the box during the day.
 * What is the minimum number of bacteria you need to put in the box to get
 * exactly 'x' bacteria?
 *
 * Approach Used: Bit Manipulation (Counting Set Bits)
 * 1. Because bacteria multiply by powers of 2 every night, any bacterium added
 *    manually will grow as 1, 2, 4, 8, 16, etc.
 * 2. To get exactly 'x' bacteria with the minimum manual additions, we must
 *    express 'x' as a sum of powers of 2. This is exactly what the binary
 *    representation of a number does!
 * 3. We iterate through the bits of 'x' using a while loop.
 * 4. We check if the rightmost bit is a 1 using the bitwise AND operator.
 * 5. We then right-shift 'x' by 1 bit to inspect the next bit in the next
 *    iteration, repeating until 'x' becomes 0.
 *
 * Complexity:
 * - Time Complexity: O(log x) -> The loop runs exactly once for each bit
 *   in the binary representation of 'x'.
 * - Space Complexity: O(1) -> Only a couple of integer variables are used.
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;

    // Read the target number of bacteria from the user
    cin >> x;

    int ans = 0; // Variable to keep track of the minimum bacteria added

    // Loop continues as long as there are bits left to process (x > 0)
    while (x)
    {
        // If the least significant bit (rightmost bit) is 1, increment answer
        if (x & 1 == 1)
            ans++;

        // Right shift x by 1 (equivalent to integer division by 2)
        x >>= 1;
    }

    // Output the final count of manually added bacteria
    cout << ans;

    return 0;
}