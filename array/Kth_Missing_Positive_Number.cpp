#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Kth Missing Positive Number
Platform: LeetCode
Problem Number: 1539
========================================================

Problem Statement:
Given an array arr of positive integers sorted in strictly
increasing order, and an integer k.

Return the k-th positive integer that is missing from this array.

Example:
Input:
arr = [2,3,4,7,11], k = 5

Missing numbers:
1,5,6,8,9,...

5th missing → 9

Output: 9

========================================================
Approach (Brute Force Simulation)

We simulate natural numbers starting from 0:

- Compare current number n with array elements
- If n exists in array → skip
- Else → it's a missing number → increment count

When count == k → return that number

========================================================
Time Complexity: O(n + k)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int count = 0;   // count of missing numbers
        int ans = 0;

        // i → pointer for array
        // n → natural numbers starting from 0
        for(int i = 0, n = 0; count <= k + 1; n++) {

            // If we found k missing numbers
            if(count == k) {
                ans = n;
                break;
            }

            // If n is present in array → skip
            if(i < arr.size() && n == arr[i]) {
                i++;
            }
            else {
                // n is missing
                count++;
            }
        }

        return ans;
    }
};


int main() {

    vector<int> arr = {2,3,4,7,11};
    int k = 5;

    Solution obj;

    cout << "Kth missing number: "
         << obj.findKthPositive(arr, k);

    return 0;
}