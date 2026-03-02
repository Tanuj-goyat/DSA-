#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Generate All Subsequences (Power Set)
========================================================

Problem Statement:
Given an array of integers, print all possible
subsequences (subsets) of the array.

Example:
Input:  {3, 1, 2}

Output:
3 1 2
3 1
3 2
3
1 2
1
2
{}

Explanation:
Each element has two choices:
1️⃣ Include it
2️⃣ Exclude it

Total subsequences = 2^n

========================================================
Approach Used (Recursion - Pick / Not Pick):

At each index:
- Pick the element and move forward.
- Do not pick the element and move forward.

Base Case:
When index == n,
print the current subsequence.

Time Complexity: O(2^n)
Space Complexity: O(n) recursion stack

========================================================
*/

void f(int n, int arr[], vector<int> &ds, int index)
{
    // Base case: If we have processed all elements
    if (index == n)
    {
        // Print current subsequence
        for (auto it : ds)
        {
            cout << it << " ";
        }

        // If subsequence is empty, print {}
        if (ds.size() == 0)
        {
            cout << "{}";
        }

        cout << endl;
        return;
    }

    // -------------------------
    // 1️⃣ Pick the element
    // -------------------------
    ds.push_back(arr[index]);              // Include current element
    f(n, arr, ds, index + 1);              // Recur for next index

    // -------------------------
    // 2️⃣ Not Pick the element
    // -------------------------
    ds.pop_back();                         // Backtrack (remove last element)
    f(n, arr, ds, index + 1);              // Recur without including element
}


int main()
{
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ds;   // Stores current subsequence

    f(n, arr, ds, 0);

    return 0;
}