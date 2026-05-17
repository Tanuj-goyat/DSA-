#include <iostream>
#include <cmath>
using namespace std;

/*
========================================================
Problem: Count K-th Roots in Range
Platform: LeetCode(3932)
========================================================

Problem Statement:
Given:
- l = lower bound
- r = upper bound
- k = power

Count how many integers x satisfy:

l <= x^k <= r

Example:
Input:
l = 1
r = 27
k = 3

Output:
3

Explanation:
1^3 = 1
2^3 = 8
3^3 = 27

========================================================
Approach Used (Binary Search):

Step 1:
Find largest x such that:
x^k <= r

Step 2:
Find smallest x such that:
x^k >= l

Step 3:
Count numbers between them

Time Complexity: O(log r)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int countKthRoots(int l, int r, int k) {

        // ------------------------------
        // Binary search for upper limit
        // ------------------------------
        int start = 0;
        int end = r;

        int mid;

        int a = 0;
        int b = 0;

        while (start <= end) {

            mid = start + (end - start) / 2;

            double y = pow(mid, k);

            // Too large
            if (y > r) {

                end = mid - 1;
            }

            // Valid candidate
            else {

                b = mid;

                start = mid + 1;
            }
        }

        // ------------------------------
        // Binary search for lower limit
        // ------------------------------
        start = 0;
        end = l;

        while (start <= end) {

            mid = start + (end - start) / 2;

            double y = pow(mid, k);

            // Too small
            if (y < l) {

                start = mid + 1;
            }

            // Valid candidate
            else {

                a = mid;

                end = mid - 1;
            }
        }

        // ------------------------------
        // Count valid roots
        // ------------------------------
        return b - a + 1;
    }
};


int main() {

    int l = 1;
    int r = 27;
    int k = 3;

    Solution obj;

    int result =
        obj.countKthRoots(l, r, k);

    cout << "Count of K-th Roots: "
         << result << endl;

    return 0;
}