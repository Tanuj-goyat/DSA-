#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Sequential Digits
Platform: LeetCode (1291)
========================================================

Problem Statement:
An integer has sequential digits if
every digit is exactly one greater
than the previous digit.

Given two integers:

low
high

Return all sequential digit numbers
within the range [low, high]
in sorted order.

Example:
Input:
low = 100
high = 300

Output:
[123,234]

========================================================
Approach Used (Generate All Sequential Numbers)

Step 1:
Choose every possible starting digit
from 1 to 9.

Step 2:
Keep appending the next digit to
generate sequential numbers.

Step 3:
If the generated number lies within
the given range,
store it.

Step 4:
Stop generating when the number
exceeds the upper limit.

Step 5:
Sort the generated numbers and
return the result.

Time Complexity: O(1)
(At most 36 sequential numbers exist.)

Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        // ------------------------------
        // Generate sequential numbers
        // ------------------------------
        for (int i = 1; i <= 9; i++) {

            int num = i;

            for (int j = i + 1; j <= 9; j++) {

                num = (num * 10) + j;

                if (num <= high && num >= low) {

                    ans.push_back(num);
                }

                else if (num >= high) {

                    break;
                }
            }
        }

        // ------------------------------
        // Sort the result
        // ------------------------------
        sort(ans.begin(), ans.end());

        return ans;
    }
};


int main() {

    int low = 100;

    int high = 10000;

    Solution obj;

    vector<int> answer = obj.sequentialDigits(low, high);

    for (int x : answer)
        cout << x << " ";

    cout << endl;

    return 0;
}