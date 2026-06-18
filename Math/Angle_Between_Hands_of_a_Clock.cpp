#include <iostream>
#include <cmath>
using namespace std;

/*
========================================================
Problem: Angle Between Hands of a Clock
Platform: LeetCode (1344)
========================================================

Problem Statement:
Given the hour and minutes of a clock,
return the smaller angle (in degrees)
between the hour hand and minute hand.

Example:
Input:
hour = 3
minutes = 30

Output:
75

Explanation:
Minute hand = 180°
Hour hand = 105°

Angle = 75°

========================================================
Approach Used (Clock Mathematics)

Step 1:
Calculate minute hand angle:

6 × minutes

because each minute represents 6°.

Step 2:
Calculate hour hand angle:

30 × hour + minutes / 2

because:
- each hour = 30°
- each minute moves the hour hand by 0.5°

Step 3:
Find absolute difference.

Step 4:
Return the smaller angle between:

angle
and
360 - angle

Time Complexity: O(1)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    double angleClock(int hour,
                      int minutes) {

        // ------------------------------
        // Minute hand angle
        // ------------------------------
        double m_angle =
            6 * minutes;

        // ------------------------------
        // Hour hand angle
        // ------------------------------
        double h_angle =
            (30 * hour) +
            (minutes / 2.0);

        // ------------------------------
        // Difference between hands
        // ------------------------------
        double angle =
            abs(m_angle - h_angle);

        // ------------------------------
        // Return smaller angle
        // ------------------------------
        return min(angle,
                   360 - angle);
    }
};


int main() {

    int hour = 3;

    int minutes = 30;

    Solution obj;

    double answer =
        obj.angleClock(hour,
                       minutes);

    cout << answer << endl;

    return 0;
}