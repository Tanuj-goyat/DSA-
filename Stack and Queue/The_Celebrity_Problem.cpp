#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: The Celebrity Problem
Platform: GeeksforGeeks
========================================================

Problem Statement:
There are n people at a party.

A celebrity is a person who:

1. Knows nobody.
2. Is known by everyone else.

Given the acquaintance matrix mat:

mat[i][j] = 1
Person i knows person j.

mat[i][j] = 0
Person i does not know person j.

Return the index of the celebrity.
If no celebrity exists,
return -1.

========================================================
Approach Used (Two Pointers)

Step 1:
Initialize two pointers:

- i = 0
- j = n - 1

Step 2:
Compare persons i and j.

If i knows j,
i cannot be the celebrity.

If j knows i,
j cannot be the celebrity.

Eliminate one candidate in each step.

Step 3:
After the loop,
only one candidate remains.

Step 4:
Verify that the candidate:

- Knows nobody.
- Is known by everyone.

Return the candidate if valid,
otherwise return -1.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int celebrity(vector<vector<int>>& mat) {

        int n = mat.size();

        int i = 0;

        int j = n - 1;

        int ans = -1;

        // ------------------------------
        // Find potential celebrity
        // ------------------------------
        while (i < j) {

            if (mat[i][j] == 0 && mat[j][i] == 1) {

                j--;
            }

            else if (mat[i][j] == 1 && mat[j][i] == 0) {

                i++;
            }

            else {

                i++;

                j--;
            }
        }

        // ------------------------------
        // Verify candidate
        // ------------------------------
        for (int x = 0; x < n; x++) {

            if ((mat[i][x] == 1 && i != x) || (mat[x][i] == 0 && i != x))

                return -1;
        }

        return i;
    }
};


int main() {

    vector<vector<int>> mat =
    {
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 0}
    };

    Solution obj;

    int answer = obj.celebrity(mat);

    cout << answer << endl;

    return 0;
}