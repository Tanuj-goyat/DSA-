#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
========================================================
Problem: Assembly via Minimums
Platform: Codeforces (1857C)
========================================================

Problem Statement:
You are given the array containing all
pairwise minimums of an unknown array.

Reconstruct one possible original array.

Example:
Input:
n = 3

Pairwise minimums:
1 1 2

Output:
1 2 1000000000

(Any valid reconstruction is accepted.)

========================================================
Approach Used (Frequency Counting)

Step 1:
Store the frequency of every pairwise
minimum in a map.

Step 2:
Traverse the map in increasing order.

Step 3:
Each selected value must appear
(elements_left) times in the remaining
pairwise minimums.

Reduce its frequency accordingly and
append it to the answer.

Step 4:
Decrease elements_left after selecting
each element.

Step 5:
Append a very large value as the last
element because it never appears as a
minimum in any pair.

Time Complexity: O(n² log n)
Space Complexity: O(n²)

========================================================
*/

int main() {

    int t;

    cin >> t;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    while (t--) {

        int n;

        cin >> n;

        map<int, int> m;

        int bSize = (n * (n - 1)) / 2;

        // ------------------------------
        // Read pairwise minimums
        // ------------------------------
        for (int i = 0; i < bSize; i++) {

            int num;

            cin >> num;

            m[num]++;
        }

        vector<int> ans;

        int elements_left = n - 1;

        // ------------------------------
        // Reconstruct the array
        // ------------------------------
        for (auto x : m) {

            while (x.second > 0) {

                ans.push_back(x.first);

                x.second -= elements_left;

                elements_left--;
            }
        }

        // ------------------------------
        // Last element can be any
        // sufficiently large value
        // ------------------------------
        ans.push_back(1e9);

        // ------------------------------
        // Print reconstructed array
        // ------------------------------
        for (int i = 0; i < n; i++) {

            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}