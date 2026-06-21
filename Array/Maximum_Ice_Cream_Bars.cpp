#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Maximum Ice Cream Bars
Platform: LeetCode (1833)
========================================================

Problem Statement:
Given an array costs where:

costs[i] = price of the i-th ice cream bar

and an integer coins representing the
amount of money available.

Find the maximum number of ice cream
bars that can be purchased.

Example:
Input:
costs = [1,3,2,4,1]
coins = 7

Output:
4

Explanation:
Buy bars costing:

1 + 1 + 2 + 3 = 7

Total bars = 4

========================================================
Approach Used (Greedy + Sorting)

Step 1:
Sort all ice cream costs.

Step 2:
Buy the cheapest ice creams first.

Step 3:
Keep adding costs until coins
are exhausted.

Step 4:
Return the number of purchased bars.

Time Complexity: O(n log n)
Space Complexity: O(1)
(excluding sorting space)

========================================================
*/

class Solution {
public:

    int maxIceCream(vector<int>& costs,
                    int coins) {

        // ------------------------------
        // Sort costs in ascending order
        // ------------------------------
        sort(costs.begin(),
             costs.end());

        int sum = 0;

        int i = 0;

        // ------------------------------
        // Buy ice creams greedily
        // ------------------------------
        for (; i < costs.size(); i++) {

            if (sum + costs[i] <= coins) {

                sum += costs[i];
            }

            else {

                break;
            }
        }

        return i;
    }
};


int main() {

    vector<int> costs =
        {1, 3, 2, 4, 1};

    int coins = 7;

    Solution obj;

    int answer =
        obj.maxIceCream(costs,
                        coins);

    cout << answer << endl;

    return 0;
}