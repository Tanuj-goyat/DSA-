/**
 * ============================================================================
 * LeetCode 860: Lemonade Change
 * ============================================================================
 *
 * Problem Statement:
 * At a lemonade stand, each lemonade costs $5. Customers are standing in a
 * queue to buy from you and order one at a time. Each customer will only buy
 * one lemonade and pay with either a $5, $10, or $20 bill.
 * You must provide the correct change to each customer so that the net
 * transaction is that the customer pays $5. You start with no change in hand.
 * Return true if and only if you can provide every customer with correct change.
 *
 * Approach Used: Greedy Algorithm
 * 1. We keep a running count of our $5 and $10 bills. (Tracking $20s isn't
 *    strictly necessary for making change, but harmless to include).
 * 2. If a customer pays with $5: We take it and give no change.
 * 3. If a customer pays with $10: We must give one $5 in change. If we don't
 *    have any, we fail and return false.
 * 4. If a customer pays with $20: We need to give $15 in change. We have two
 *    choices, and we apply a GREEDY choice here:
 *    - Priority 1: Give one $10 and one $5. This is optimal because $5 bills
 *      are highly versatile (needed for $10 customers). We want to hoard them.
 *    - Priority 2: Give three $5 bills. We only do this if we have no $10s.
 *    - If neither is possible, we return false.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We iterate through the bills array exactly once.
 * - Space Complexity: O(1) -> Only primitive integer variables are used.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        int twenty = 0; // Note: Tracking 20s isn't needed for change, but perfectly fine

        for (int i = 0; i < n; i++)
        {
            // Case 1: Customer gives $5. No change needed.
            if (bills[i] == 5)
            {
                five++;
            }
            // Case 2: Customer gives $10. Need to return $5.
            else if (bills[i] == 10)
            {
                ten++;
                five--;
                if (five < 0)
                    return false; // Cannot make change
            }
            // Case 3: Customer gives $20. Need to return $15.
            else if (bills[i] == 20)
            {
                twenty++;

                // Greedy choice: Always try to use a $10 bill first to save $5 bills
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                // Fallback: Use three $5 bills if we have no $10 bills
                else if (five >= 3)
                {
                    five -= 3;
                }
                // Cannot make change
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Perfect change scenario
    // Collect $5s, then use them for the $10 and $20.
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << "Test Case 1:" << endl;
    cout << "Bills: [5, 5, 5, 10, 20]" << endl;
    cout << "Can provide change? " << (solution.lemonadeChange(bills1) ? "true" : "false") << endl;
    // Expected: true

    cout << "-----------------------------------" << endl;

    // Test Case 2: Run out of $5 bills
    // Customer 1: Gives $5 (We have one $5)
    // Customer 2: Gives $5 (We have two $5)
    // Customer 3: Gives $10 (We have one $5, one $10)
    // Customer 4: Gives $10 (We have zero $5, two $10)
    // Customer 5: Gives $20 (We need $15 change, but have no $5 bills. Fails!)
    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << "Test Case 2:" << endl;
    cout << "Bills: [5, 5, 10, 10, 20]" << endl;
    cout << "Can provide change? " << (solution.lemonadeChange(bills2) ? "true" : "false") << endl;
    // Expected: false

    cout << "-----------------------------------" << endl;

    // Test Case 3: Exact change using three $5 bills
    vector<int> bills3 = {5, 5, 5, 20};
    cout << "Test Case 3:" << endl;
    cout << "Bills: [5, 5, 5, 20]" << endl;
    cout << "Can provide change? " << (solution.lemonadeChange(bills3) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}