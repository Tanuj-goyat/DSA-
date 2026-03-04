#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Count Subsequences with Given Sum
========================================================

Problem Statement:
Given an array and a number k,
count the number of subsequences whose sum equals k.

Example:
Array = {1,2,1}
k = 2

Valid subsequences:
{1,1}
{2}

Output:
2

========================================================
Approach Used (Recursion + Backtracking)

At each index we have two choices:

1️⃣ Pick the element
   - Add element to sum
   - Move to next index

2️⃣ Do not pick the element
   - Ignore element
   - Move to next index

Base Condition:
When index reaches n:
Check if sum == k
If yes → return 1
Else → return 0

Total subsequences = left branch + right branch

========================================================
Time Complexity: O(2^n)
Space Complexity: O(n) recursion stack
========================================================
*/

int f(int arr[], int n, int index, vector<int> &v, int k, int sum, int &count)
{
    // Base case: reached end of array
    if (index >= n)
    {
        if (sum == k)
        {
            count++;     // increment global count
            return 1;    // valid subsequence found
        }

        return 0;        // not valid
    }

    // --------------------------------
    // 1️⃣ Pick the current element
    // --------------------------------
    sum += arr[index];
    v.push_back(arr[index]);

    int left = f(arr, n, index + 1, v, k, sum, count);

    // --------------------------------
    // Backtrack
    // --------------------------------
    sum -= arr[index];
    v.pop_back();

    // --------------------------------
    // 2️⃣ Do not pick the element
    // --------------------------------
    int right = f(arr, n, index + 1, v, k, sum, count);

    // Total subsequences from both branches
    return left + right;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v;
    int k = 2;
    int count = 0;

    f(arr, n, 0, v, k, 0, count);

    cout << "Total subsequences with sum " << k << " = " << count;

    return 0;
}