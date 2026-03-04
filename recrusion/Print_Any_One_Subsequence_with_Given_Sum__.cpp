#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Print Any One Subsequence with Given Sum
========================================================

Problem Statement:
Given an array and a number k,
print ANY ONE subsequence whose sum equals k.

Example:
Array = {1,2,1}
k = 2

Possible subsequences with sum = 2:
1 1
2

But this program prints ONLY ONE of them.

========================================================
Approach Used (Recursion + Backtracking + Early Return)

At each index we have two choices:

1️⃣ Pick the element
2️⃣ Do not pick the element

If a valid subsequence is found:
→ Immediately return true
→ Stop exploring further recursion

This is done using boolean return type.

========================================================
Time Complexity: O(2^n) worst case
Space Complexity: O(n) recursion stack
========================================================
*/

bool f(int arr[], int n, int index, vector<int> &v, int k, int sum)
{
    // Base case
    if (index >= n)
    {
        if (sum == k)
        {
            // Print subsequence
            for (auto x : v)
            {
                cout << x << " ";
            }

            if (v.size() == 0)
            {
                cout << "{}";
            }

            cout << endl;

            return true;   // subsequence found
        }

        return false;
    }

    // --------------------------------
    // 1️⃣ Pick the current element
    // --------------------------------
    sum += arr[index];
    v.push_back(arr[index]);

    if (f(arr, n, index + 1, v, k, sum))
        return true;

    // --------------------------------
    // Backtrack
    // --------------------------------
    sum -= arr[index];
    v.pop_back();

    // --------------------------------
    // 2️⃣ Do not pick the element
    // --------------------------------
    if (f(arr, n, index + 1, v, k, sum))
        return true;

    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v;
    int k = 2;

    f(arr, n, 0, v, k, 0);

    return 0;
}