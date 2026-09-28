/**
 * ============================================================================
 * Problem: Vending Machine Placement (Interval Covering)
 * ============================================================================
 *
 * Problem Statement:
 * You have a straight corridor and 'n' doors at given positions. You need to
 * place vending machines such that every door is at most 'd' distance away
 * from at least one vending machine. Find the minimum number of machines needed.
 *
 * Approach Used: Greedy Strategy
 * 1. The doors are already given in sorted order.
 * 2. We iterate through the doors. When we find the first uncovered door at
 *    position `a[index]`, we MUST cover it.
 * 3. Greedy Choice: To maximize the coverage of future doors, we should place
 *    the vending machine as far right as possible while still covering `a[index]`.
 *    The optimal placement is exactly at `a[index] + d`.
 * 4. From this position, the machine can reach another `d` meters to the right.
 *    Therefore, this single machine covers all doors up to `a[index] + 2 * d`.
 * 5. We use an inner `while` loop to fast-forward our pointer `i` past all
 *    doors that fall within this `2 * d` coverage range.
 * 6. We repeat this until all doors are covered.
 *
 * Complexity:
 * - Time Complexity: O(N) per test case -> Even with a nested while loop, the
 *   pointer `i` only moves forward, meaning each door is evaluated exactly once.
 * - Space Complexity: O(N) -> To store the door positions.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Process continuous test cases until n == 0 and d == 0
    while (true)
    {
        int n, d;

        // Safely read input and check for the termination condition (0 0)
        if (!(cin >> n >> d) || (n == 0 && d == 0))
        {
            break;
        }

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int i = 0;
        int ans = 0;

        // Single pass greedy check
        while (i < n)
        {
            ans++;         // Place a new vending machine
            int index = i; // This is the first currently uncovered door

            // The machine is conceptually placed at a[index] + d.
            // It covers everything up to (a[index] + d) + d = a[index] + 2*d.
            // Fast-forward 'i' past all doors covered by this machine.
            while (i < n && a[i] <= a[index] + 2 * d)
            {
                i++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}