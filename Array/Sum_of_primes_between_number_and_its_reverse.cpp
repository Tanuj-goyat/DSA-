#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Sum of Primes between Number and its Reverse
Platform: LeetCode (3918)
========================================================

Problem Statement:
Given a number n:
1️⃣ Reverse the number
2️⃣ Find range [min(n, reverse(n)), max(...)]
3️⃣ Return sum of all prime numbers in that range

========================================================
Approach Used (Your Approach: Mark + isPrime):

Step 1: Reverse number

Step 2: Iterate through range [low, high]

Step 3: Use isPrime() to check primality

Step 4: Mark non-primes (optimization)

Time Complexity: ~O(n²) worst (as per your approach)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Check prime (your logic)
    // ------------------------------
    bool isPrime(int n) {

        if (n <= 1) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }


    // ------------------------------
    // Reverse number
    // ------------------------------
    int reverse(int n) {

        int r = 0;

        while (n) {
            int digit = n % 10;
            r = r * 10 + digit;
            n /= 10;
        }

        return r;
    }


    // ------------------------------
    // Main function
    // ------------------------------
    int sumOfPrimesInRange(int n) {

        int r = reverse(n);

        int low = min(n, r);
        int hi  = max(n, r);

        vector<bool> mark(hi - low + 1, true);

        int ans = 0;

        // ------------------------------
        // Traverse range
        // ------------------------------
        for (int i = low; i <= hi; i++) {

            if (i <= 1) continue;

            int index = i - low;

            if (mark[index]) {

                if (isPrime(i)) {
                    ans += i;

                    // mark multiples
                    for (int j = i * 2; j <= hi; j += i) {
                        mark[j - low] = false;
                    }
                }
                else {
                    mark[index] = false;
                }
            }
        }

        return ans;
    }
};


int main() {

    int n = 13;

    Solution obj;

    int result = obj.sumOfPrimesInRange(n);

    cout << "Sum of Primes: " << result << endl;

    return 0;
}