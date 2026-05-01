#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Minimum Number of Days to Make m Bouquets
Platform: LeetCode (1482)
========================================================

Problem Statement:
You are given an array bloomDay where bloomDay[i]
is the day the ith flower blooms.

You need to make m bouquets.
Each bouquet requires k adjacent flowers.

Return the minimum number of days needed to make m bouquets.
If impossible → return -1.

Example:
Input:
bloomDay = [1,10,3,10,2], m = 3, k = 1

Output:
3

========================================================
Approach Used (Binary Search on Answer):

Step 1: Search on days (range: 0 → max bloom day)

Step 2: For each mid (day):
        check if we can make m bouquets

Step 3: If possible → try smaller day
        else → increase day

Time Complexity: O(n log maxDay)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Check if possible on given day
    // ------------------------------
    bool isValid(vector<int>& v, int m, int k, int mid) {

        int count = 0;     // consecutive flowers
        int bouquet = 0;   // total bouquets

        for (int i = 0; i < v.size(); i++) {

            // Flower bloomed by 'mid' day
            if (v[i] <= mid)
                count++;
            else
                count = 0;

            // If k consecutive flowers found
            if (count == k) {
                bouquet++;
                count = 0; // reset for next bouquet
            }

            // Enough bouquets formed
            if (bouquet >= m)
                return true;
        }

        return false;
    }


    // ------------------------------
    // Main function
    // ------------------------------
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        // ------------------------------
        // Edge case: not enough flowers
        // ------------------------------
        if ((long long)m * k > n)
            return -1;

        // Find maximum day
        int maxDay = 0;
        for (int x : bloomDay)
            maxDay = max(maxDay, x);

        int start = 1;
        int end = maxDay;
        int ans = -1;

        // ------------------------------
        // Binary search on days
        // ------------------------------
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (isValid(bloomDay, m, k, mid)) {
                ans = mid;      // possible answer
                end = mid - 1;  // try smaller day
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};


int main() {

    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;

    Solution obj;

    int result = obj.minDays(bloomDay, m, k);

    cout << "Minimum Days: " << result << endl;

    return 0;
}