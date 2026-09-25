/**
 * ============================================================================
 * LeetCode 134: Gas Station
 * ============================================================================
 *
 * Problem Statement:
 * There are n gas stations along a circular route, where the amount of gas at
 * the ith station is gas[i]. You have a car with an unlimited gas tank and it
 * costs cost[i] of gas to travel from the ith station to its next (i + 1)th
 * station. You begin the journey with an empty tank at one of the gas stations.
 * Given two integer arrays gas and cost, return the starting gas station's
 * index if you can travel around the circuit once in the clockwise direction,
 * otherwise return -1.
 *
 * Approach Used: Single-Pass Greedy
 * 1. We maintain two running sums:
 *    - `sum`: Tracks the total net gas over the entire journey.
 *    - `currSum`: Tracks the current tank balance from our proposed `start` point.
 * 2. As we iterate, we add the net gas of the current station (`gas[i] - cost[i]`).
 * 3. If `currSum` drops below 0, it means our car stalled. Furthermore, no station
 *    between our current `start` and `i` could have successfully reached `i + 1`
 *    either.
 * 4. We reset `currSum` to 0 and designate the next station (`i + 1`) as our
 *    new potential `start`.
 * 5. Finally, if the total `sum` across all stations is negative, it is
 *    mathematically impossible to complete the circuit, so we return -1.
 *    Otherwise, our last designated `start` is guaranteed to be the unique solution.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We traverse the gas and cost arrays exactly once.
 * - Space Complexity: O(1) -> We only use a few integer variables.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        int sum = 0;
        int currSum = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            // Calculate the net gas gained/lost at the current station
            int x = (gas[i] - cost[i]);

            sum += x;     // Track total gas balance globally
            currSum += x; // Track gas balance for the current attempted route

            // If we run out of gas, the current starting point (and any point
            // before i) is invalid.
            if (currSum < 0)
            {
                // Set the next station as the new starting candidate
                start = i + 1;
                // Reset the current tank balance
                currSum = 0;
            }
        }

        // If the total gas available is less than the total cost, it's impossible
        if (sum < 0)
            return -1;

        // Otherwise, the last valid starting point is our answer
        return start;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard successful circuit
    // gas  = [1, 2, 3, 4, 5]
    // cost = [3, 4, 5, 1, 2]
    // Start at index 3 (gas=4, cost=1).
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Test Case 1:" << endl;
    cout << "Starting Station Index: " << solution.canCompleteCircuit(gas1, cost1) << endl;
    // Expected: 3

    cout << "-----------------------------------" << endl;

    // Test Case 2: Impossible circuit
    // gas  = [2, 3, 4]
    // cost = [3, 4, 3]
    // Total gas = 9, Total cost = 10. Impossible.
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Test Case 2:" << endl;
    cout << "Starting Station Index: " << solution.canCompleteCircuit(gas2, cost2) << endl;
    // Expected: -1

    cout << "-----------------------------------" << endl;

    // Test Case 3: Exactly enough gas
    // gas  = [5, 1, 2, 3, 4]
    // cost = [4, 4, 1, 5, 1]
    // Total gas = 15, Total cost = 15. Start at index 4.
    vector<int> gas3 = {5, 1, 2, 3, 4};
    vector<int> cost3 = {4, 4, 1, 5, 1};
    cout << "Test Case 3:" << endl;
    cout << "Starting Station Index: " << solution.canCompleteCircuit(gas3, cost3) << endl;
    // Expected: 4

    return 0;
}