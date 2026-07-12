#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Seconds Between Two Times
Platform: LeetCode 3986
========================================================

Problem Statement:
Given two time strings:

startTime
endTime

Both are in the format:

HH:MM:SS

Return the number of seconds between
endTime and startTime.

Example:
Input:
startTime = "10:15:20"
endTime   = "10:16:35"

Output:
75

========================================================
Approach Used (String Parsing)

Step 1:
Extract hours, minutes, and seconds
from each time string.

Step 2:
Convert each time into total seconds.

Step 3:
Return:

endTimeSeconds - startTimeSeconds

Time Complexity: O(1)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Convert time string into
    // total seconds
    // ------------------------------
    int tellSec(string& s) {

        int hour = stoi(s.substr(0, 2));

        int min = stoi(s.substr(3, 2));

        int sec = stoi(s.substr(6, 2));

        int ans = (hour * 3600) + (min * 60) + sec;

        return ans;
    }

    // ------------------------------
    // Find difference in seconds
    // ------------------------------
    int secondsBetweenTimes(string startTime, string endTime) {

        return tellSec(endTime) - tellSec(startTime);
    }
};


int main() {

    string startTime = "10:15:20";

    string endTime = "10:16:35";

    Solution obj;

    int answer = obj.secondsBetweenTimes(startTime, endTime);

    cout << answer << endl;

    return 0;
}