#include <iostream>
using namespace std;

/*
========================================================
Problem: Cheap Travel
Platform: Codeforces (466A)
========================================================

Problem Statement:
A person needs to make n rides.

There are two ticket options:

1. Single ride ticket
   Cost = oneCost

2. Special ticket
   Covers m rides
   Cost = mCost

Find the minimum cost required
to complete all n rides.

Example:
Input:
6 2 1 2

Output:
6

========================================================
Approach Used (Greedy Cost Comparison)

Step 1:
Check whether buying single tickets
for m rides is cheaper than or equal
to a special ticket.

If yes:
Buy all rides individually.

Step 2:
Otherwise:
Buy as many special tickets as possible.

Step 3:
For remaining rides, compare:

- Buying single tickets
- Buying one extra special ticket

Choose the cheaper option.

Time Complexity: O(1)
Space Complexity: O(1)

========================================================
*/

int main() {

    int n, m, oneCost, mCost;

    cin >> n
        >> m
        >> oneCost
        >> mCost;

    // ------------------------------
    // Single tickets are cheaper
    // ------------------------------
    if (m * oneCost <= mCost) {

        cout << n * oneCost << endl;

        return 0;
    }

    else {

        // Cost of complete special tickets
        int cost1 =
            mCost * (n / m);

        // Cost of remaining rides
        int cost2 =
            oneCost * (n % m);

        // ------------------------------
        // Compare:
        // remaining single tickets
        // vs one extra special ticket
        // ------------------------------
        if (cost1 + mCost >=
            cost1 + cost2)

            cout << cost1 + cost2
                 << endl;

        else

            cout << cost1 + mCost;
    }

    return 0;
}