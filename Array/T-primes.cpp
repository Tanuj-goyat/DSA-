#include <iostream>
#include <cmath>
using namespace std;

/*
========================================================
Problem: T-Primes
Platform: Codeforces (230B)
========================================================

Problem Statement:
A T-prime is a number that has exactly
three positive divisors.

Given several numbers, determine whether
each number is a T-prime.

Print:
"YES" if the number is a T-prime
"NO" otherwise.

Example:
Input:
3

4
5
9

Output:
YES
NO
YES

Explanation:
4 = 2² and 2 is prime

9 = 3² and 3 is prime

Both are T-primes.

========================================================
Approach Used (Square Root + Prime Check)

Observation:

A number has exactly 3 divisors iff:

number = p²

where p is a prime number.

Step 1:
Find square root of n.

Step 2:
Check whether:
root × root == n

Step 3:
Check whether root is prime.

Step 4:
If both conditions are true,
print "YES".

Otherwise print "NO".

Time Complexity:
O(√n) per query

Space Complexity:
O(1)

========================================================
*/


// ------------------------------
// Check whether a number
// is prime
// ------------------------------
bool isPrime(long long n) {

    if (n < 2)
        return false;

    for (long long i = 2;
         i * i <= n;
         i++) {

        if (n % i == 0)
            return false;
    }

    return true;
}


int main() {

    int x;

    cin >> x;

    // ------------------------------
    // Process all test cases
    // ------------------------------
    for (; x > 0; x--) {

        long long n;

        cin >> n;

        long long root = sqrt(n);

        // Perfect square and
        // square root is prime
        if ((long long)root * root ==
                (long long)n &&
            isPrime(root)) {

            cout << "YES" << endl;
        }

        else {

            cout << "NO" << endl;
        }
    }

    return 0;
}