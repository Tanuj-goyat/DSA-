#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================================================
Problem: Alternating Subsequence
Platform: Codeforces (1343C)
========================================================

Problem Statement:
For each test case:

Given an array containing positive and
negative integers.

Choose a subsequence such that signs
alternate between positive and negative.

From every consecutive segment having
the same sign, choose the maximum element.

Find the maximum possible sum.

Example:
Input:
6

1 2 3 -1 -2 -3

Output:
2

Explanation:
Choose:
3 + (-1) = 2

========================================================
Approach Used (Two Simulations)

Step 1:
Start assuming first selected segment
is positive.

Step 2:
For every sign block, keep the maximum
value from that block.

Step 3:
Calculate:
- Number of selected blocks
- Sum of selected values

Step 4:
Repeat the same process assuming
the first segment is negative.

Step 5:
Compare both results and print answer.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

int main() {

    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (int x = 0; x < t; x++) {

        int n;

        cin >> n;

        vector<int> v;

        // ------------------------------
        // Input array
        // ------------------------------
        for (int i = 0; i < n; i++) {

            int val;

            cin >> val;

            v.push_back(val);
        }

        // ------------------------------
        // First Simulation
        // Start with positive sign
        // ------------------------------
        bool b = true;

        int maxVal = INT_MIN;

        int i = 0;

        int size = 0;

        long long sum = 0;

        while (i < n) {

            if ((v[i] > 0 && b) ||
                (v[i] < 0 && !b)) {

                maxVal = max(maxVal,
                             v[i]);
            }

            else if (maxVal != INT_MIN) {

                size++;

                sum += maxVal;

                maxVal = v[i];

                b = !b;
            }

            i++;
        }

        size++;

        sum += maxVal;

        int size1 = size;

        long long sum1 = sum;

        // ------------------------------
        // Second Simulation
        // Start with negative sign
        // ------------------------------
        size = 0;

        maxVal = INT_MIN;

        i = 0;

        sum = 0;

        b = false;

        while (i < n) {

            if ((v[i] > 0 && b) ||
                (v[i] < 0 && !b)) {

                maxVal = max(maxVal,
                             v[i]);
            }

            else if (maxVal != INT_MIN) {

                size++;

                sum += maxVal;

                maxVal = v[i];

                b = !b;
            }

            i++;
        }

        size++;

        sum += maxVal;

        int size2 = size;

        long long sum2 = sum;

        // ------------------------------
        // Compare both simulations
        // ------------------------------
        if (size1 > size2) {

            cout << sum1 << endl;
        }

        else if (size1 == size2) {

            cout << max(sum1,
                        sum2)
                 << endl;
        }

        else {

            cout << sum2 << endl;
        }
    }

    return 0;
}