#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Even Number of Night Moves
Platform: LeetCode 3996
========================================================

Problem Statement:
You are given two coordinates:

- start
- target

Determine whether it is possible to
reach the target based on the parity
of the sum of their coordinates.

Return:

true  -> If both positions have the
         same parity.

false -> Otherwise.

========================================================
Approach Used (Parity Check)

Step 1:
Compute the parity of the sum of the
coordinates for the starting position.

Step 2:
Compute the parity of the sum of the
coordinates for the target position.

Step 3:
If both parities are equal,
return true.

Otherwise,
return false.

Time Complexity: O(1)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    bool canReach(vector<int>& start, vector<int>& target) {

        // ------------------------------
        // Compare parity of coordinates
        // ------------------------------
        if ((start[0] + start[1]) % 2 == (target[0] + target[1]) % 2) {

            return true;
        }

        return false;
    }
};


int main() {

    vector<int> start = {1, 2};

    vector<int> target = {3, 4};

    Solution obj;

    bool answer = obj.canReach(start, target);

    cout << (answer ? "true" : "false") << endl;

    return 0;
}