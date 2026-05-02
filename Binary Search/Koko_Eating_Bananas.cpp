#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Koko Eating Bananas
Platform: LeetCode (875)
========================================================

Problem Statement:
Koko loves to eat bananas. There are piles of bananas,
where piles[i] is the number of bananas in the ith pile.

Koko can eat at most k bananas per hour.

Return the minimum integer k such that she can eat all
bananas within h hours.

Example:
Input:
piles = [3,6,7,11], h = 8

Output:
4

========================================================
Approach Used (Binary Search on Answer):

Step 1: Search range:
        min speed = 1
        max speed = max(piles)

Step 2: For each speed (mid):
        calculate total time needed

Step 3: If time ≤ h → valid speed
        else → too slow

Time Complexity: O(n log maxPile)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Check if speed is valid
    // ------------------------------
    bool is_valid(vector<int>& piles, int h, int mid) {

        long long time = 0; // use long long (IMPORTANT)

        for (int i = 0; i < piles.size(); i++) {

            // ceil(piles[i] / mid)
            time += (piles[i] + mid - 1) / mid;

            if (time > h)
                return false;
        }

        return true;
    }


    // ------------------------------
    // Main function
    // ------------------------------
    int minEatingSpeed(vector<int>& piles, int h) {

        int max_speed = 0;

        for (int x : piles)
            max_speed = max(max_speed, x);

        int start = 1;
        int end = max_speed;

        int ans = max_speed;

        // ------------------------------
        // Binary search
        // ------------------------------
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (is_valid(piles, h, mid)) {
                ans = mid;        // possible answer
                end = mid - 1;    // try smaller speed
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};


int main() {

    vector<int> piles = {3,6,7,11};
    int h = 8;

    Solution obj;

    int speed = obj.minEatingSpeed(piles, h);

    cout << "Minimum Speed: " << speed << endl;

    return 0;
}