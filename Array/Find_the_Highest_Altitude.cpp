#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Find the Highest Altitude
Platform: LeetCode (1732)
========================================================

Problem Statement:
There is a biker going on a road trip.

The biker starts at altitude 0.

gain[i] represents the net gain in
altitude between point i and i + 1.

Return the highest altitude reached.

Example:
Input:
gain = {-5, 1, 5, 0, -7}

Output:
1

Explanation:
Altitudes:

0
-5
-4
1
1
-6

Highest altitude = 1

========================================================
Approach Used (Prefix Sum)

Step 1:
Start with altitude 0.

Step 2:
Keep adding each gain value to
the current altitude.

Step 3:
Track the maximum altitude reached.

Step 4:
Return the maximum altitude.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int largestAltitude(vector<int>& gain) {

        // Highest altitude reached
        int ans = 0;

        // Current altitude
        int sum = 0;

        // ------------------------------
        // Calculate altitudes
        // ------------------------------
        for (int i = 0; i < gain.size(); i++) {

            sum += gain[i];

            ans = max(ans, sum);
        }

        return ans;
    }
};


int main() {

    vector<int> gain =
        {-5, 1, 5, 0, -7};

    Solution obj;

    int answer =
        obj.largestAltitude(gain);

    cout << answer << endl;

    return 0;
}