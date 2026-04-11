#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Best Time to Buy and Sell Stock II
Platform: LeetCode
Problem Number: 122
========================================================

Problem Statement:
You are given an array prices where prices[i] is the
price of a given stock on the i-th day.

You may complete as many transactions as you like
(buy one and sell one share multiple times).

Goal:
Maximize total profit.

========================================================
Approach (Greedy)

Key Idea:
✔ Take every profitable opportunity

If today's price > yesterday's price:
→ add profit

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int maxProfit(vector<int>& nums) {

        int profit = 0;

        // Traverse prices
        for (int i = 1; i < nums.size(); i++) {

            // If price increases → take profit
            if (nums[i] > nums[i - 1]) {
                profit += nums[i] - nums[i - 1];
            }
        }

        return profit;
    }
};


int main() {

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution obj;

    cout << "Maximum Profit: "
         << obj.maxProfit(prices);

    return 0;
}