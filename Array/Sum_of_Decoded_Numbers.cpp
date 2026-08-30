/**
 * ============================================================================
 * Problem: Sum of Decoded Numbers(4039)
 * ============================================================================
 * 
 * Problem Statement:
 * You are given an array of integers `nums`. Each integer is encoded such that:
 * 1. The very last digit represents the `width` (length) of the base.
 * 2. The first `width` digits form the `base`.
 * 3. The remaining digits (between the base and the last digit) form the `exp`.
 * 
 * For each number, calculate (base ^ exp) % (10^9 + 7).
 * Return the sum of all these decoded power values, modulo 10^9 + 7.
 * 
 * Approach Used: Math & String/Digit Parsing
 * 1. `power`: Uses Fast Modular Exponentiation to calculate (base^exp) % MOD 
 *    in O(log exp) time.
 * 2. `f`: Extracts digits of the number into a vector. It reads the last digit 
 *    to find the `width`. It then reconstructs the base `x` and the exponent 
 *    `y` by iterating through the appropriate bounds of the vector.
 * 3. `sumDecoded`: Iterates over the array, sums up the results from `f`, 
 *    and ensures the final sum is also kept within modulo 10^9 + 7.
 * 
 * Complexity:
 * - Time Complexity: O(N * D) -> Where N is the number of elements and D is 
 *   the maximum number of digits in an element. The `power` function runs in 
 *   O(log(exp)) which is bounded by the number of digits.
 * - Space Complexity: O(D) -> We store the digits of each number in a temporary 
 *   vector `v` inside the helper function `f`.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for reverse()

using namespace std;

class Solution {
public:
    // Fast modular exponentiation to calculate (base^exp) % MOD in O(log exp) time
    long long power(long long base, long long exp) {
        long long MOD = 1e9 + 7;
        long long res = 1;
        base %= MOD;
        
        while (exp > 0) {
            // If the current exponent bit is odd, multiply the base with the result
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            
            // Square the base and halve the exponent for the next bit
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper function to decode a number and calculate its power
    long long f(long long num) {
        vector<int> v;
        
        // Extract digits in reverse order
        while (num) {
            v.push_back(num % 10);
            num = num / 10;
        }
        // Reverse to get digits from left to right
        reverse(v.begin(), v.end());
        
        int n = v.size();
        
        // The last digit tells us how many digits belong to the base
        int width = v[n - 1];
        
        // Reconstruct the base 'x' using the first 'width' digits
        int x = 0;
        for (int i = 0; i < width; i++) {
            x = (x * 10) + v[i];
        }
        
        // Reconstruct the exponent 'y' using the remaining middle digits
        int y = 0;
        for (int i = width; i < n - 1; i++) {
            y = (y * 10) + v[i];
        }
        
        // Return (x ^ y) % MOD
        return power(x, y);
    }

    int sumDecoded(vector<long long>& nums) {
        long long result = 0;
        int MOD = 1e9 + 7;
        
        // Accumulate the decoded power for every number in the array
        for (auto num : nums) {
            result = (result + f(num)) % MOD;
        }
        
        int ans = result % MOD;
        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main() {
    Solution solution;

    // Test Case 1
    // num = 25332
    // - Last digit = 2 (width of base)
    // - Base 'x' = first 2 digits = 25
    // - Exp 'y' = remaining digits = 33
    // -> Calculates 25^33 % (10^9 + 7)
    vector<long long> nums1 = {25332};
    cout << "Array: [25332]" << endl;
    cout << "Sum Decoded: " << solution.sumDecoded(nums1) << endl; 

    cout << "-----------------------------------" << endl;

    // Test Case 2
    // num1 = 23 (Width=3, meaning out of bounds if not careful, assuming valid inputs like 231)
    // Let's use 231:
    // - Last digit = 1 (width of base)
    // - Base = 2
    // - Exp = 3
    // -> Calculates 2^3 = 8
    // num2 = 52
    // - Last digit = 2 (width of base = 2 -> Wait, base is 5. Need input to match bounds).
    // Let's use 521: 
    // - Last digit = 1
    // - Base = 5
    // - Exp = 2
    // -> Calculates 5^2 = 25
    // Total sum = 8 + 25 = 33
    vector<long long> nums2 = {231, 521};
    cout << "Array: [231, 521]" << endl;
    cout << "Sum Decoded: " << solution.sumDecoded(nums2) << endl; 
    // Expected: 33

    return 0;
}