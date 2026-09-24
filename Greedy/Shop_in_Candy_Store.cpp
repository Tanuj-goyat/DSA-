/**
 * ============================================================================
 * GeeksforGeeks: Shop in Candy Store
 * ============================================================================
 *
 * Problem Statement:
 * In a candy store, there are N different types of candies available and the
 * prices of all the N different types of candies are provided. There is also
 * an attractive offer: you can buy a single candy from the store and get at
 * most K other candies (all are different types) for free.
 * Find the minimum amount of money you have to spend to buy all the N candies,
 * and the maximum amount of money you have to spend to buy all the N candies.
 *
 * Approach Used: Greedy + Sorting (Single Pass)
 * 1. Step 1 (Sort): Sort the candy prices in ascending order.
 * 2. Step 2 (Mathematical Grouping): Every time you buy 1 candy, you get K
 *    for free. This means you acquire (K + 1) candies per transaction.
 *    Therefore, you only need to make exactly ceil(N / (K + 1)) purchases.
 * 3. Step 3 (Simultaneous Min/Max):
 *    - To get the Minimum Cost, we greedily buy the cheapest candies
 *      (starting from index i = 0) and use our "free" picks to eliminate the
 *      most expensive ones.
 *    - To get the Maximum Cost, we greedily buy the most expensive candies
 *      (starting from index n - i - 1) and use our "free" picks to eliminate
 *      the cheapest ones.
 * 4. We track the `total` candies acquired (bought + free). Once `total >= n`,
 *    we have acquired all candies and can break the loop.
 *
 * Complexity:
 * - Time Complexity: O(N log N) -> Bottleneck is the sorting operation. The
 *   single while loop runs in O(N / K) time.
 * - Space Complexity: O(1) auxiliary space -> Only primitive variables are used.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

class Solution
{
public:
    vector<int> minMaxCandy(vector<int> &prices, int k)
    {
        int n = prices.size();

        // Sort the prices in ascending order
        sort(prices.begin(), prices.end());

        int minCost = 0;
        int maxCost = 0;

        // 'total' tracks the number of candies acquired (bought + free)
        int total = 0;

        // 'i' represents the number of actual purchases made
        int i = 0;

        while (total < n)
        {
            // For minCost: buy the i-th cheapest candy
            minCost += prices[i];

            // For maxCost: buy the i-th most expensive candy
            maxCost += prices[n - i - 1];

            // Move to the next purchase
            i++;

            // We acquire 1 bought candy + k free candies
            total += k + 1;
        }

        return {minCost, maxCost};
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // GFG Test Case 1
    // N = 4, K = 2, prices = [3, 2, 1, 4]
    // Sorted: [1, 2, 3, 4]
    // Min Cost: Buy 1 (get 4,3 free) -> Buy 2. Total = 3
    // Max Cost: Buy 4 (get 1,2 free) -> Buy 3. Total = 7
    vector<int> prices1 = {3, 2, 1, 4};
    int k1 = 2;

    cout << "Test Case 1:" << endl;
    cout << "Prices: [3, 2, 1, 4], K = 2" << endl;
    vector<int> result1 = solution.minMaxCandy(prices1, k1);
    cout << "Output: " << result1[0] << " " << result1[1] << endl;
    // Expected: 3 7

    cout << "-----------------------------------" << endl;

    // GFG Test Case 2
    // N = 5, K = 4, prices = [3, 2, 1, 4, 5]
    // Sorted: [1, 2, 3, 4, 5]
    // Buy 1 get 4 free. Only 1 purchase needed.
    // Min Cost: Buy 1
    // Max Cost: Buy 5
    vector<int> prices2 = {3, 2, 1, 4, 5};
    int k2 = 4;

    cout << "Test Case 2:" << endl;
    cout << "Prices: [3, 2, 1, 4, 5], K = 4" << endl;
    vector<int> result2 = solution.minMaxCandy(prices2, k2);
    cout << "Output: " << result2[0] << " " << result2[1] << endl;
    // Expected: 1 5

    return 0;
}