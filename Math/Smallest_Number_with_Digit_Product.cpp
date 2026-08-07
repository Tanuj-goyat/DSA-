#include <iostream>
using namespace std;

/*
========================================================
Problem: Smallest Number with Digit Product
Platform: LeetCode 3345
========================================================

Problem Statement:
Given two integers:
 
- n
- t

Find the smallest integer greater than
or equal to n such that the product of
its digits is divisible by t.

Return that integer.

========================================================
Approach Used (Brute Force)

Step 1:
Create a helper function to compute
the product of digits of a number.

Step 2:
Starting from n,
check every integer one by one.

Step 3:
If the digit product is 0 or divisible
by t,
return the current number.

Otherwise,
continue searching.

Time Complexity: O(k × d)

k = Number of integers checked
d = Number of digits

Space Complexity: O(1)

========================================================
*/

class Solution
{
public:
    // ------------------------------
    // Calculate product of digits
    // ------------------------------
    int f(int n)
    {

        int ans = 1;

        while (n)
        {

            int digit = n % 10;

            n = n / 10;

            ans *= digit;
        }

        return ans;
    }

    int smallestNumber(int n, int t)
    {

        int ans = -1;

        // ------------------------------
        // Search for the required number
        // ------------------------------
        while (ans == -1)
        {

            if (f(n) == 0 || f(n) % t == 0)
            {

                ans = n;
            }

            n++;
        }

        return ans;
    }
};

int main()
{

    int n = 15;

    int t = 6;

    Solution obj;

    int answer = obj.smallestNumber(n, t);

    cout << answer << endl;

    return 0;
}