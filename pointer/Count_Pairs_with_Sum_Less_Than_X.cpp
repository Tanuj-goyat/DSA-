#include <bits/stdc++.h>
using namespace std;

/*
========================================================
Problem: Count Pairs with Sum Less Than X
Platform: codechef
========================================================

Problem Statement:
Given an array and an integer X, count the number of
pairs (i, j) such that:

i < j AND arr[i] + arr[j] < X

========================================================
Approach (Two Pointer Technique)

1️⃣ Sort the array

2️⃣ Use two pointers:
   i → start
   j → end

3️⃣ If arr[i] + arr[j] < X:
   → All elements between i and j form valid pairs
   → count += (j - i)
   → move i forward

4️⃣ Else:
   → decrease j

========================================================
Time Complexity: O(n log n) (sorting)
Space Complexity: O(1)
========================================================
*/

long long countPairsLessThanX(vector<int>& arr, int x, int n) {

    // Step 1: Sort array (VERY IMPORTANT)
    sort(arr.begin(), arr.end());

    long long count = 0;

    int i = 0;
    int j = n - 1;

    // Step 2: Two pointer traversal
    while (i < j) {

        if (arr[i] + arr[j] < x) {

            // All pairs (i, i+1 ... j-1) are valid
            count += (j - i);

            i++;
        }
        else {
            j--;
        }
    }

    return count;
}


int main() {

    int n, x;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    cout << countPairsLessThanX(arr, x, n) << endl;

    return 0;
}