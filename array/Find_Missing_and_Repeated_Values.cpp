#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Find Missing and Repeated Values
Platform: LeetCode
Problem Number: 2965
========================================================

Problem Statement:
You are given a n x n grid containing numbers from
1 to n².

One number is missing and one number is repeated.

Return:
[repeated, missing]

Example:
Input:
grid = [[1,3],
        [2,2]]

Output:
[2,4]

========================================================
Approach (Math: Sum & Square Sum)

Let:
x = repeated number
y = missing number

We know:

1️⃣ Sum:
total - sum = y - x  → A

2️⃣ Square Sum:
sqtotal - sqsum = y² - x²
                = (y - x)(y + x)
                = A * (y + x)

So:
(y + x) = B / A

Now solve:
y = ( (B/A) + A ) / 2
x = ( (B/A) - A ) / 2

========================================================
Time Complexity: O(n²)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();

        int sum = 0;        // actual sum
        int total = 0;      // expected sum

        long long sqsum = 0;     // actual square sum
        long long sqtotal = 0;   // expected square sum

        int a = 1;

        // Traverse grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                sum += grid[i][j];
                sqsum += (long long)grid[i][j] * grid[i][j];

                total += a;
                sqtotal += (long long)a * a;

                a++;
            }
        }

        // A = y - x
        int A = total - sum;

        // B = y² - x²
        long long B = sqtotal - sqsum;

        // Solve equations
        int y = (B / A + A) / 2;   // missing
        int x = (B / A - A) / 2;   // repeated

        return {x, y};
    }
};


int main() {

    vector<vector<int>> grid = {
        {1, 3},
        {2, 2}
    };

    Solution obj;

    vector<int> result = obj.findMissingAndRepeatedValues(grid);

    cout << "Repeated: " << result[0] << endl;
    cout << "Missing: " << result[1] << endl;

    return 0;
}