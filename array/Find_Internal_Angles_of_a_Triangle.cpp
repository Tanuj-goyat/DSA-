#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Find Internal Angles of a Triangle
Platform: LeetCode
Problem Number: 3899
========================================================

Problem Statement:
Given three side lengths of a triangle, return all
three internal angles (in degrees), sorted in ascending order.

If the sides do not form a valid triangle,
return an empty vector.

========================================================
Approach (Cosine Rule)

For triangle sides a, b, c:

Angle A:
cos(A) = (b² + c² - a²) / (2bc)

Similarly for other angles.

Convert radians → degrees:
angle = (180 / π) * acos(value)

========================================================
Time Complexity: O(1)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        double l1 = sides[0];
        double l2 = sides[1];
        double l3 = sides[2];

        vector<double> ans;

        // Step 1: Check triangle validity
        if ((l1 + l2 <= l3) ||
            (l1 + l3 <= l2) ||
            (l2 + l3 <= l1))
            return ans;

        // Step 2: Apply cosine rule
        double a1 = (180.0 / M_PI) *
            acos((l2*l2 + l3*l3 - l1*l1) / (2*l2*l3));

        double a2 = (180.0 / M_PI) *
            acos((l1*l1 + l3*l3 - l2*l2) / (2*l1*l3));

        double a3 = (180.0 / M_PI) *
            acos((l1*l1 + l2*l2 - l3*l3) / (2*l1*l2));

        ans.push_back(a1);
        ans.push_back(a2);
        ans.push_back(a3);

        // Step 3: Sort angles
        sort(ans.begin(), ans.end());

        return ans;
    }
};


int main() {

    vector<int> sides = {3, 4, 5};

    Solution obj;

    vector<double> angles = obj.internalAngles(sides);

    if (angles.empty()) {
        cout << "Invalid triangle\n";
    } else {
        cout << "Angles:\n";
        for (double x : angles) {
            cout << x << " ";
        }
    }

    return 0;
}