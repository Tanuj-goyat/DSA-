/*
========================================================
Problem Name: Spiral Matrix
Platform: LeetCode
Problem Number: 54
========================================================

Problem Statement:
Given an m x n matrix, return all elements of the matrix 
in spiral order (clockwise).

Example:
Input:
[
 [1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]
]

Output:
[1, 2, 3, 6, 9, 8, 7, 4, 5]

========================================================
Approach Used (Layer by Layer Traversal):

We traverse the matrix in layers (like peeling an onion).

For each layer:
1. Traverse left → right  (top row)
2. Traverse top → bottom  (right column)
3. Traverse right → left  (bottom row)
4. Traverse bottom → top  (left column)

We maintain:
- i → row pointer
- j → column pointer
- x → current layer number

We stop when all elements (m * n) are added.
If one element remains in the center (odd dimension case),
we add it at the end.

Time Complexity: O(m × n)
Space Complexity: O(m × n)  (for result vector)

========================================================
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> v;                 // Stores final spiral order
        
        int m = 0;                     // Number of rows
        int n = 0;                     // Number of columns
        
        // If matrix is empty, return empty vector
        if (!matrix.empty()) {
            m = matrix.size();
            n = matrix[0].size();
        } else {
            return v;
        }

        bool done = false;             // Flag to stop when all elements are added
        
        int i = 0;                     // Row pointer
        int j = 0;                     // Column pointer
        
        // Loop through each spiral layer
        for (int x = 0; x < n; x++) {
            
            if (done) break;           // Stop if traversal completed

            // -------------------------------------------------
            // 1️⃣ Move Left → Right (Top Row of current layer)
            // -------------------------------------------------
            while (j < (n - x - 1)) {
                
                if (v.size() < m * n)
                    v.push_back(matrix[i][j]);
                else {
                    done = true;
                    break;
                }
                
                j++;                   // Move right
            }

            // -------------------------------------------------
            // 2️⃣ Move Top → Bottom (Right Column)
            // -------------------------------------------------
            while (i < (m - x - 1)) {
                
                if (v.size() < m * n)
                    v.push_back(matrix[i][j]);
                else {
                    done = true;
                    break;
                }
                
                i++;                   // Move down
            }

            // -------------------------------------------------
            // 3️⃣ Move Right → Left (Bottom Row)
            // -------------------------------------------------
            while (j > x) {
                
                if (v.size() < m * n)
                    v.push_back(matrix[i][j]);
                else {
                    done = true;
                    break;
                }
                
                j--;                   // Move left
            }

            // -------------------------------------------------
            // 4️⃣ Move Bottom → Top (Left Column)
            // -------------------------------------------------
            while (i > x + 1) {
                
                if (v.size() < m * n)
                    v.push_back(matrix[i][j]);
                else {
                    done = true;
                    break;
                }
                
                i--;                   // Move up
            }
        }

        // If one element remains (center of odd dimension matrix)
        if (v.size() < m * n) {
            v.push_back(matrix[i][j]);
        }

        return v;                      // Return spiral traversal
    }
};