#include <iostream>
#include <climits>
using namespace std;

/*
========================================================
Problem:  Pashmak and Flowers
Platform: Codeforces (459B)
========================================================

Problem Statement:
Given n integers.

Find:

1. The difference between the maximum
   and minimum value.

2. The number of pairs having this
   maximum difference.

Example:
Input:
5

1 2 3 4 5

Output:
4 1

Explanation:
Maximum = 5
Minimum = 1

Difference = 4

Only one pair:
(1, 5)

========================================================
Approach Used (Single Traversal)

Step 1:
Track:
- Minimum value
- Maximum value

Step 2:
Track frequency of:
- Minimum value
- Maximum value

Step 3:
Calculate:

difference = maxi - mini

pairs = maxCount × minCount

Step 4:
Special Case:
If all values are equal:

pairs =
n × (n - 1) / 2

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

int main() {

    int n;

    cin >> n;

    int maxi = INT_MIN;

    int mini = INT_MAX;

    int minCount = 0;

    int maxCount = 0;

 
    for (int i = 0; i < n; i++) {

        int val;

        cin >> val;

        // Update minimum
        if (val == mini) {

            minCount++;
        }

        else if (val < mini) {

            mini = val;

            minCount = 1;
        }

        // Update maximum
        if (val == maxi) {

            maxCount++;
        }

        else if (val > maxi) {

            maxi = val;

            maxCount = 1;
        }
    }


    long long pair =
        (long long)maxCount *
        minCount;


    if (maxi == mini) {

        pair =
            (long long)maxCount *
            (maxCount - 1) / 2;
    }

    cout << maxi - mini<< " "<< pair<< endl;

    return 0;
}