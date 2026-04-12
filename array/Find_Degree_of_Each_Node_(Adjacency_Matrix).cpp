#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Find Degree of Each Node (Adjacency Matrix)
Platform: LeetCode
Problem Number: 3898
========================================================

Problem Statement:
Given an adjacency matrix of a graph, return the degree
of each node.

Degree of a node:
→ Number of edges connected to it

For adjacency matrix:
- matrix[i][j] == 1 → edge exists

========================================================
Approach

1️⃣ For each row i:
   → count number of 1's

2️⃣ Skip self-loop (i == j)

3️⃣ Store count in result

========================================================
Time Complexity: O(n²)
Space Complexity: O(n)
========================================================
*/

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {

        vector<int> ans;

        int n = matrix.size();

        // Traverse each node
        for(int i = 0; i < n; i++) {

            int count = 0;

            // Check connections
            for(int j = 0; j < matrix[0].size(); j++) {

                // Skip self-loop
                if(j != i && matrix[i][j] == 1)
                    count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};


int main() {

    vector<vector<int>> matrix = {
        {0,1,1},
        {1,0,1},
        {1,1,0}
    };

    Solution obj;

    vector<int> result = obj.findDegrees(matrix);

    cout << "Degrees:\n";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}