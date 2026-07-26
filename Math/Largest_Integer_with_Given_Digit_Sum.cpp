#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem: Largest Integer with Given Digit Sum
Platform: LeetCode 4000
========================================================

Problem Statement:
Given:

- n -> Number of digits.
- s -> Required sum of digits.

Construct the largest possible integer
having exactly n digits such that the
sum of its digits is equal to s.

If no such integer exists,
return -1.

========================================================
Approach Used (Greedy)

Step 1:
Start placing the largest possible
digit at every position.

Step 2:
For each position,
choose the maximum digit that does not
exceed the remaining sum.

Step 3:
Reduce the remaining digit sum and
continue until all positions are filled.

Step 4:
If the constructed number has the
required digit sum,
convert it into an integer.

Otherwise,
return -1.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    int largestInteger(int n, int s) {

        string str;

        int i = 9;

        int sum = 0;

        int dupsum = s;

        // ------------------------------
        // Construct the number greedily
        // ------------------------------
        while (n) {

            while (i > s && i > 0) {

                i--;
            }

            str.push_back(i);

            s -= i;

            sum += i;

            n--;
        }

        int ans = -1;

        // ------------------------------
        // Verify digit sum and build
        // the final integer
        // ------------------------------
        if (dupsum == sum) {

            ans = 0;

            for (int i = 0; i < str.size(); i++) {

                ans = ans * 10 + str[i];
            }
        }

        return ans;
    }
};


int main() {

    int n = 3;

    int s = 20;

    Solution obj;

    int answer = obj.largestInteger(n, s);

    cout << answer << endl;

    return 0;
}