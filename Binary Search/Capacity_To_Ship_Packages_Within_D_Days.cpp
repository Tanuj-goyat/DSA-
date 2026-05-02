#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Capacity To Ship Packages Within D Days
Platform: LeetCode (1011)
========================================================

Problem Statement:
Given an array weights where weights[i] is the weight
of the ith package, and an integer days.

You must ship all packages within given days.

Each day:
- Load packages in order
- Total weight ≤ ship capacity

Return the minimum capacity required.

Example:
Input:
weights = [1,2,3,4,5,6,7,8,9,10], days = 5

Output:
15

========================================================
Approach Used (Binary Search on Answer):

Step 1: Capacity range:
        min = max(weights)
        max = sum(weights)

Step 2: For each mid capacity:
        check if possible within 'days'

Step 3: If possible → try smaller capacity
        else → increase capacity

Time Complexity: O(n log sum)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Check if capacity works
    // ------------------------------
    bool valid_day(int maxLoad, int days, vector<int>& weights) {

        int today = 1;   // current day
        int load = 0;    // current load

        for (int i = 0; i < weights.size(); i++) {

            // If single package exceeds capacity → impossible
            if (weights[i] > maxLoad)
                return false;

            // If adding exceeds capacity → next day
            if (load + weights[i] > maxLoad) {
                today++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }

            // If days exceeded
            if (today > days)
                return false;
        }

        return true;
    }


    // ------------------------------
    // Main function
    // ------------------------------
    int shipWithinDays(vector<int>& weights, int days) {

        int totalLoad = 0;

        for (int w : weights) {
            totalLoad += w;
        }

        // Binary search range
        int start = 0;   // IMPORTANT FIX
        int end = totalLoad;

        int ans = end;

        // ------------------------------
        // Binary search
        // ------------------------------
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (valid_day(mid, days, weights)) {
                ans = mid;        // possible answer
                end = mid - 1;    // try smaller
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};


int main() {

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    Solution obj;

    int result = obj.shipWithinDays(weights, days);

    cout << "Minimum Capacity: " << result << endl;

    return 0;
}