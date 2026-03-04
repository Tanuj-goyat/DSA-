#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Print Subsequences with Given Sum
========================================================

Problem Statement:
Given an array and a number k,
print all subsequences whose sum equals k.

Example:
Array = {1,2,1}
k = 2

Output:
1 1
2

Explanation:
Possible subsequences:
{1}
{2}
{1}
{1,2}
{1,1}
{2,1}
{1,2,1}

Only subsequences with sum = 2 are printed.

========================================================
Approach Used (Recursion + Backtracking):

At each index we have two choices:

1️⃣ Pick the element
   - Add it to subsequence
   - Increase current sum

2️⃣ Do not pick the element
   - Move to next element

Base Condition:
When index reaches n:
Check if sum == k
If yes → print subsequence

Time Complexity: O(2^n)
Space Complexity: O(n) recursion stack

========================================================
*/

void f(int arr[], int n, int index, vector<int> &v, int k, int sum)
{
    // Base case: reached end of array
    if (index >= n)
    {
        if (sum == k)
        {
            // Print the subsequence
            for (auto x : v)
            {
                cout << x << " ";
            }

            if (v.size() == 0)
            {
                cout << "{}";
            }

            cout << endl;
        }

        return;
    }

    // ------------------------------------------------
    // 1️⃣ Pick the current element
    // ------------------------------------------------
    sum += arr[index];
    v.push_back(arr[index]);

    f(arr, n, index + 1, v, k, sum);

    // ------------------------------------------------
    // Backtrack
    // ------------------------------------------------
    sum -= arr[index];
    v.pop_back();

    // ------------------------------------------------
    // 2️⃣ Do not pick the current element
    // ------------------------------------------------
    f(arr, n, index + 1, v, k, sum);
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