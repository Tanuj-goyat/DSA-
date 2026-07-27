#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Range Sum Query 2D - Immutable
Platform: LeetCode (304)
========================================================

Problem Statement:
Given a 2D matrix,
process multiple queries to find the
sum of elements inside a rectangular
region.

Each query is defined by:

(row1, col1) -> Top-left corner
(row2, col2) -> Bottom-right corner

Return the sum of all elements inside
the specified rectangle.

========================================================
Approach Used (2D Prefix Sum)

Step 1:
Construct a 2D prefix sum matrix.

Step 2:
Each cell stores the sum of all
elements from (0,0) to the current
cell.

Step 3:
For every query, use the inclusion-
exclusion principle to calculate the
required rectangle sum in O(1).

Time Complexity:
Constructor : O(rows × cols)
Query       : O(1)

Space Complexity: O(rows × cols)

========================================================
*/

class NumMatrix {
public:

    vector<vector<int>> box;

    // ------------------------------
    // Build 2D Prefix Sum Matrix
    // ------------------------------
    NumMatrix(vector<vector<int>>& matrix) {

        for (int row = 0; row < matrix.size(); row++) {

            int preSum = 0;

            vector<int> v;

            for (int col = 0; col < matrix[0].size(); col++) {

                preSum += matrix[row][col];

                int sum = preSum;

                if (row > 0) {

                    sum += box[row - 1][col];
                }

                v.push_back(sum);
            }

            box.push_back(v);
        }
    }

    // ------------------------------
    // Return sum of given rectangle
    // ------------------------------
    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = box[row2][col2];

        if (row1 > 0) {

            sum -= box[row1 - 1][col2];
        }

        if (col1 > 0) {

            sum -= box[row2][col1 - 1];
        }

        if (row1 > 0 &&
            col1 > 0) {

            sum += box[row1 - 1][col1 - 1];
        }

        return sum;
    }
};


int main() {

    vector<vector<int>> matrix =
    {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix obj(matrix);

    cout << obj.sumRegion(2, 1, 4, 3) << endl;
    cout << obj.sumRegion(1, 1, 2, 2) << endl;
    cout << obj.sumRegion(1, 2, 2, 4) << endl;

    return 0;
}

/*
Your NumMatrix object will be instantiated
and called as such:

NumMatrix* obj = new NumMatrix(matrix);
int param_1 = obj->sumRegion(row1,
                             col1,
                             row2,
                             col2);
*/