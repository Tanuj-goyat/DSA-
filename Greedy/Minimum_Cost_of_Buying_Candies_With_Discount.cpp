/**
 * ============================================================================
 * LeetCode 2144: Minimum Cost of Buying Candies With Discount
 * ============================================================================
 *
 * Problem Statement:
 * A shop is selling candies. For every two candies sold, the shop gives a
 * third candy for free. The cost of the free candy must be less than or equal
 * to the minimum cost of the two candies bought.
 * Given an integer array `cost` where `cost[i]` is the cost of the ith candy,
 * return the minimum cost of buying all the candies.
 *
 * Approach Used: Greedy + Sorting
 * 1. Step 1 (Sort): Sort the array in ascending order.
 * 2. Step 2 (Greedy Grouping): Iterate through the array starting from the
 *    back (the most expensive candies).
 * 3. We group the items into chunks of 3. We pay for the two most expensive
 *    candies in the chunk (`cost[n] + cost[n - 1]`) and receive the third one
 *    (`cost[n - 2]`) for free.
 * 4. We jump our pointer back by 3 (`n -= 3`) and repeat.
 * 5. Edge Cases: If fewer than 3 candies remain (e.g., `n < 2`), we simply
 *    pay for whatever is left since we cannot form a pair to get a free candy.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> The bottleneck is sorting the array. The
 *   subsequent loop processes the array in a single O(N) pass.
 * - Space Complexity: O(1) auxiliary space -> Depending on the C++ sorting
 *   implementation it may use O(log N) stack space, but no extra data
 *   structures are allocated.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int n = cost.size() - 1;

        // Sort in ascending order to easily access the most expensive items at the end
        sort(cost.begin(), cost.end());

        int ans = 0;

        while (n >= 0)
        {
            // If we have at least 3 candies left (or exactly 3 when n == 2)
            if (n >= 2)
            {
                // Buy the two most expensive candies
                ans += (cost[n] + cost[n - 1]);

                // If we exactly processed the last chunk of 3 (indices 2, 1, 0),
                // cost[0] is free and we are completely done.
                if (n == 2)
                    break;

                // Skip the third candy (we get it for free!) and move to the next chunk
                n -= 3;
            }
            // If we have 1 or 2 candies left, we must pay for them
            else
            {
                ans += cost[n]; // Buy the first remaining
                if (n - 1 >= 0)
                    ans += cost[n - 1]; // Buy the second remaining if it exists
                break;
            }
        }

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard case with a multiple of 3
    // Candies: [1, 2, 3]
    // Sorted: [1, 2, 3] -> Buy 3 and 2, get 1 for free.
    vector<int> cost1 = {1, 2, 3};
    cout << "Test Case 1:" << endl;
    cout << "Costs: [1, 2, 3]" << endl;
    cout << "Minimum Cost: " << solution.minimumCost(cost1) << endl;
    // Expected: 5

    cout << "-----------------------------------" << endl;

    // Test Case 2: Array size not a multiple of 3
    // Candies: [6, 5, 7, 9, 2, 2]
    // Sorted: [2, 2, 5, 6, 7, 9]
    // Chunk 1: Buy 9 and 7, get 6 free. (Cost = 16)
    // Chunk 2: Buy 5 and 2, get 2 free. (Cost = 7)
    // Total = 16 + 7 = 23
    vector<int> cost2 = {6, 5, 7, 9, 2, 2};
    cout << "Test Case 2:" << endl;
    cout << "Costs: [6, 5, 7, 9, 2, 2]" << endl;
    cout << "Minimum Cost: " << solution.minimumCost(cost2) << endl;
    // Expected: 23

    cout << "-----------------------------------" << endl;

    // Test Case 3: Less than 3 candies
    // Candies: [5, 5]
    // Cannot get any free candies, must buy both.
    vector<int> cost3 = {5, 5};
    cout << "Test Case 3:" << endl;
    cout << "Costs: [5, 5]" << endl;
    cout << "Minimum Cost: " << solution.minimumCost(cost3) << endl;
    // Expected: 10

    return 0;
}