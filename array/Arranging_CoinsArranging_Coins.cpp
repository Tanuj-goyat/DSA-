#include <iostream>
using namespace std;

/*
========================================================
Problem Name: Arranging Coins
Platform: LeetCode
Problem Number: 441
========================================================

Problem Statement:
You have n coins and you want to build a staircase.

- 1st row → 1 coin
- 2nd row → 2 coins
- 3rd row → 3 coins
...

Return the total number of COMPLETE rows.

Example:
Input:  n = 5
Output: 2

Explanation:
1 + 2 = 3 coins used → 2 full rows
Remaining coins = 2 (not enough for next row)

========================================================
Approach Used (Greedy / Simulation):

Step 1: Start placing rows one by one

Step 2: For each row i:
        subtract i coins from n

Step 3: Stop when n < i

Step 4: Answer = number of full rows

Time Complexity: O(√n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:
    int arrangeCoins(int n) {

        int i = 1; // current row number

        // ------------------------------
        // Step 1: Build rows
        // ------------------------------
        while (i <= n) {

            n = n - i; // use coins for current row
            i++;       // move to next row
        }

        // ------------------------------
        // Step 2: Return completed rows
        // ------------------------------
        return i - 1;
    }
};


int main() {

    int n = 5;

    Solution obj;

    cout << "Complete Rows: "
         << obj.arrangeCoins(n);

    return 0;
}