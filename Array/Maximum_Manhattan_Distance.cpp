#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
========================================================
Problem: Maximum Manhattan Distance
Platform: LeetCode 3968
========================================================

Problem Statement:
Given a string moves containing:

'U' -> Up
'D' -> Down
'L' -> Left
'R' -> Right
'_' -> Flexible move

Calculate the maximum possible
Manhattan distance from the origin.

Manhattan Distance:

|x| + |y|

Example:
Input:
moves = "U_R"

Output:
3

Explanation:
'U'  -> (0, 1)
'R'  -> (1, 1)

The '_' move can be used to increase
the distance by 1.

Distance =
|1| + |1| + 1 = 3

========================================================
Approach Used (Coordinate Tracking)

Step 1:
Track final x-coordinate.

Step 2:
Track final y-coordinate.

Step 3:
Count the number of '_' moves.

Step 4:
Each '_' can be used to increase the
Manhattan distance by 1.

Step 5:
Answer:

|x| + |y| + count

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int maxDistance(string moves) {

        int n = moves.size();

        int x = 0;

        int y = 0;

        int count = 0;

        for (int i = 0; i < n; i++) {

            char ch = moves[i];

            if (ch == 'U')
                y++;

            if (ch == 'D')
                y--;

            if (ch == 'L')
                x--;

            if (ch == 'R')
                x++;

            if (ch == '_')
                count++;
        }


        return (abs(x) + abs(y) + count);
    }
};


int main() {

    string moves = "U_R";

    Solution obj;

    int answer =
        obj.maxDistance(moves);

    cout << answer << endl;

    return 0;
}