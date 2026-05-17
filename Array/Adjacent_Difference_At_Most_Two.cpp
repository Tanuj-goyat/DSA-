#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
========================================================
Problem: Adjacent Difference At Most Two
Platform: LeetCode(3931)
========================================================

Problem Statement:
Given a numeric string s,
check whether the absolute difference
between every pair of adjacent digits
is at most 2.

Return true if valid,
otherwise return false.

Example:
Input:
"123454"

Output:
true

Example:
Input:
"195"

Output:
false

========================================================
Approach Used (Linear Traversal):

Step 1:
Traverse string from index 1

Step 2:
Convert adjacent characters into digits

Step 3:
Find absolute difference

Step 4:
If difference > 2,
return false

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    bool isAdjacentDiffAtMostTwo(string s) {

        // ------------------------------
        // Traverse adjacent digits
        // ------------------------------
        for (int i = 1; i < s.size(); i++) {

            // Previous digit
            int a = s[i - 1] - '0';

            // Current digit
            int b = s[i] - '0';

            // Absolute difference
            int diff = abs(a - b);

            // Invalid difference
            if (diff > 2)
                return false;
        }

        return true;
    }
};


int main() {

    string s = "123454";

    Solution obj;

    bool result =
        obj.isAdjacentDiffAtMostTwo(s);

    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}