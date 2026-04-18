#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Spiral Matrix II
Platform: LeetCode
Problem Number: 59
========================================================

Problem Statement:
Given an integer n, generate an n x n matrix filled
with elements from 1 to n² in spiral order.

Example:
Input: n = 3

Output:
1 2 3
8 9 4
7 6 5

========================================================
Approach (Layer by Layer Spiral Filling)

1️⃣ Fill matrix in layers (outer → inner)

2️⃣ For each layer:
   - Top row
   - Right column
   - Bottom row
   - Left column

3️⃣ Continue until center

========================================================
Time Complexity: O(n²)
Space Complexity: O(n²)
========================================================
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int num = 1;

        while (top <= bottom && left <= right) {

            // Top row
            for (int j = left; j <= right; j++) {
                matrix[top][j] = num++;
            }
            top++;

            // Right column
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;

            // Bottom row
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    matrix[bottom][j] = num++;
                }
                bottom--;
            }

            // Left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};


int main() {

    int n = 3;

    Solution obj;

    vector<vector<int>> result = obj.generateMatrix(n);

    cout << "Spiral Matrix:\n";

    for (auto &row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}