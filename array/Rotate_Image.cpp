#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Rotate Image
Platform: LeetCode
Problem Number: 48
========================================================

Problem Statement:
Given an n x n 2D matrix, rotate the image by 90 degrees
(clockwise) in-place.

========================================================
Approach (Layer by Layer Rotation)

1️⃣ Process matrix layer by layer

2️⃣ For each layer:
   rotate 4 elements at a time

   top → right → bottom → left

3️⃣ Perform cyclic swaps

========================================================
Time Complexity: O(n²)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int last = n - 1;

        // Traverse layers
        for (int i = 0; i < n / 2; i++) {

            // Traverse elements in layer
            for (int j = i; j < last - i; j++) {

                // Perform 4-way swap

                // Save top
                int temp = matrix[i][j];

                // left → top
                matrix[i][j] = matrix[last - j][i];

                // bottom → left
                matrix[last - j][i] = matrix[last - i][last - j];

                // right → bottom
                matrix[last - i][last - j] = matrix[j][last - i];

                // top → right
                matrix[j][last - i] = temp;
            }
        }
    }
};


int main() {

    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Solution obj;

    obj.rotate(matrix);

    cout << "Rotated Matrix:\n";

    for (auto &row : matrix) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}