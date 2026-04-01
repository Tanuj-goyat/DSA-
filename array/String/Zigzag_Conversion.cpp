#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem Name: Zigzag Conversion
Platform: LeetCode
Problem Number: 6
========================================================

Problem Statement:
Given a string s and an integer numRows,
write the string in a zigzag pattern and then
read line by line.

Example:

Input:
s = "PAYPALISHIRING", numRows = 3

Zigzag:
P   A   H   N
A P L S I I G
Y   I   R

Output:
"PAHNAPLSIIGYIR"

========================================================
Approach (Row-wise Traversal)

Instead of building the zigzag matrix,
we simulate row-by-row traversal.

Key Idea:
Each row has a pattern of jumps:

For row i:
down jump = 2 * (numRows - i - 1)
up jump   = 2 * i

Middle rows:
→ alternate between down and up

First row:
→ only down jumps

Last row:
→ only up jumps

========================================================
Time Complexity: O(n)
Space Complexity: O(n)
========================================================
*/

class Solution {
public:
    string convert(string s, int row) {

        // Edge case
        if (row == 1) return s;

        int n = s.size();
        string result = "";

        // Traverse each row
        for (int i = 0; i < row; i++) {

            int j = i;

            int down = 2 * (row - i - 1);
            int up   = 2 * i;

            bool flag = true; // alternate jumps

            while (j < n) {

                // Add current character
                result.push_back(s[j]);

                if (i == 0) {
                    // First row → only downward jump
                    j += down;
                }
                else if (i == row - 1) {
                    // Last row → only upward jump
                    j += up;
                }
                else {
                    // Middle rows → alternate jumps
                    if (flag) {
                        j += down;
                    } else {
                        j += up;
                    }
                    flag = !flag;
                }
            }
        }

        return result;
    }
};


int main() {

    string s = "PAYPALISHIRING";
    int numRows = 3;

    Solution obj;

    string result = obj.convert(s, numRows);

    cout << "Zigzag Conversion: " << result;

    return 0;
}