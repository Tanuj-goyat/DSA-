#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Worms
Platform: Codeforces (474B)
========================================================

Problem Statement:
There are n piles of worms.

Each pile contains a certain number
of worms.

Queries are given, where each query
represents the position of a worm.

For every query, determine the pile
to which that worm belongs.

Example:
Input:
5

2 7 3 4 9

3

1
25
11

Output:
1
5
3

========================================================
Approach Used (Prefix Sum + Binary Search)

Step 1:
Construct the prefix sum array.

Step 2:
For each query,
use binary search to find the first
prefix sum greater than or equal to
the query.

Step 3:
Its index (1-based) is the required
pile number.

Time Complexity:
Building Prefix Sum : O(n)
Each Query          : O(log n)

Space Complexity: O(n)

========================================================
*/


// ------------------------------
// Binary Search
// Find first prefix sum
// greater than or equal to target
// ------------------------------
int search(int target,
           vector<int>& v) {

    int n = v.size();

    int start = 0;

    int end = n - 1;

    int ans = 1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (v[mid] >= target) {

            ans = mid + 1;

            end = mid - 1;
        }

        else if (v[mid] < target) {

            start = mid + 1;
        }
    }

    return ans;
}


int main() {

    int n;

    cin >> n;

    vector<int> vSum;

    int sum = 0;

    // ------------------------------
    // Build prefix sum array
    // ------------------------------
    for (int i = 0; i < n; i++) {

        int num;

        cin >> num;

        sum += num;

        vSum.push_back(sum);
    }

    int m;

    cin >> m;

    // ------------------------------
    // Answer all queries
    // ------------------------------
    for (int i = 0; i < m; i++) {

        int num;

        cin >> num;

        cout << search(num, vSum) << endl;
    }

    return 0;
}