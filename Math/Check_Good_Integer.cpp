#include <iostream>
using namespace std;

/*
========================================================
Problem: Check Good Integer
Platform: LeetCode (3959)
========================================================

Problem Statement:
Given an integer n.

Calculate:

1. Sum of digits
2. Sum of squares of digits

An integer is considered "Good" if:

(sum of squares of digits) -
(sum of digits) >= 50

Return:
true  -> if integer is good
false -> otherwise

Example:
Input:
n = 99

Output:
true

Explanation:
Sum of digits = 9 + 9 = 18

Sum of squares =
81 + 81 = 162

162 - 18 = 144

144 >= 50

========================================================
Approach Used (Digit Extraction)

Step 1:
Extract digits one by one.

Step 2:
Maintain:
- sum of digits
- sum of squared digits

Step 3:
Check whether:

square - sum >= 50

Time Complexity: O(number of digits)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    bool checkGoodInteger(int n) {

        long long sum = 0;

        long long square = 0;

        // ------------------------------
        // Process all digits
        // ------------------------------
        while (n) {

            int bit = n % 10;

            n = n / 10;

            sum += bit;

            square += bit * bit;
        }

        // ------------------------------
        // Check condition
        // ------------------------------
        if (square - sum >= 50)
            return true;

        return false;
    }
};


int main() {

    int n = 99;

    Solution obj;

    bool result =
        obj.checkGoodInteger(n);

    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}