#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Longest Subarray with Difference ≤ 1
Platform: HackerRank (Longest Subarray problem)
========================================================

Problem Statement:
Given an array of integers, find the length of the
longest subarray where the absolute difference between
any two elements is at most 1.

Example:
Input:
arr = [1,2,2,3,1,2]

Output:
5

Explanation:
Subarray: [1,2,2,1,2]
Difference between max and min ≤ 1

========================================================
Approach (Frequency Map)

1️⃣ Count frequency of each number
2️⃣ For each number x:
    - Check frequency of x and x+1
    - Combine them → freq[x] + freq[x+1]
3️⃣ Take maximum of all such combinations

Why this works:
Valid subarray can only contain:
✔ same numbers OR
✔ numbers differing by 1

========================================================
Time Complexity: O(n)
Space Complexity: O(n)
========================================================
*/

int longestSubarray(vector<int> arr) {

    unordered_map<int, int> freq;
    int ans = 0;

    // Step 1: Count frequency
    for (int x : arr) {
        freq[x]++;
    }

    // Step 2: Check pairs (x, x+1)
    for (auto it : freq) {

        int x = it.first;

        int curr = freq[x] + freq[x + 1];

        ans = max(ans, curr);
    }

    return ans;
}


int main() {

    vector<int> arr = {1, 2, 2, 3, 1, 2};

    cout << "Longest Subarray Length: "
         << longestSubarray(arr);

    return 0;
}