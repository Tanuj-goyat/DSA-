#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
========================================================
Problem Name: Maximum Nesting Depth of the Parentheses
Platform: LeetCode
Problem Number: 1614
========================================================

Problem Statement:
Given a valid parentheses string s, return the maximum
nesting depth of the parentheses.

The nesting depth is the maximum number of nested
parentheses at any point.

Example:
Input:  "(1+(2*3)+((8)/4))+1"
Output: 3

Explanation:
The deepest nested parentheses is "((8)/4)" → depth = 3

========================================================
Approach (Counter Method)

We use a simple counter:

1️⃣ Traverse the string
2️⃣ If '(' → increase count
3️⃣ If ')' → update depth and decrease count

depth = maximum value of count during traversal

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int maxDepth(string s) {

        int count = 0;   // current depth
        int depth = 0;   // maximum depth

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                count++;   // entering a deeper level
            }
            else if(s[i] == ')') {
                depth = max(depth, count);  // update max depth
                count--;   // leaving a level
            }
        }

        return depth;
    }
};


int main() {

    string s = "(1+(2*3)+((8)/4))+1";

    Solution obj;

    int result = obj.maxDepth(s);

    cout << "Maximum Depth: " << result;

    return 0;
}