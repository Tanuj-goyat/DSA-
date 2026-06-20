#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
========================================================
Problem: BerSU Ball
Platform: Codeforces (489B)
========================================================

Problem Statement:
There are n boys and m girls.

Each boy and girl has a skill level.

A boy and a girl can form a pair if:

|boy skill - girl skill| <= 1

Each boy and each girl can belong to
at most one pair.

Find the maximum number of pairs.

Example:
Input:
4

1 4 6 2

5

5 1 5 7 9

Output:
3

========================================================
Approach Used (Sorting + Two Pointers)

Step 1:
Sort boys' skill levels.

Step 2:
Sort girls' skill levels.

Step 3:
Use two pointers to compare
current boy and girl.

Step 4:
If their skill difference is at most 1,
form a pair and move both pointers.

Step 5:
Otherwise move the pointer of the
smaller skill value.

Time Complexity: O(n log n + m log m)
Space Complexity: O(n + m)

========================================================
*/

int main()
{
    int n;

    cin >> n;

    vector<int> boys;

    // ------------------------------
    // Input boys' skills
    // ------------------------------
    for (int i = 0; i < n; i++)
    {
        int value;

        cin >> value;

        boys.push_back(value);
    }

    int m;

    cin >> m;

    vector<int> girls;

    // ------------------------------
    // Input girls' skills
    // ------------------------------
    for (int i = 0; i < m; i++)
    {
        int value;

        cin >> value;

        girls.push_back(value);
    }

    // ------------------------------
    // Sort both arrays
    // ------------------------------
    sort(boys.begin(), boys.end());

    sort(girls.begin(), girls.end());

    int i = 0;

    int j = 0;

    int count = 0;

    // ------------------------------
    // Two Pointer Matching
    // ------------------------------
    while (i < n && j < m)
    {
        // Valid pair
        if (abs(boys[i] - girls[j]) <= 1)
        {
            count++;

            i++;

            j++;
        }

        else
        {
            if (boys[i] < girls[j])
                i++;
            else
                j++;
        }
    }

    // ------------------------------
    // Print answer
    // ------------------------------
    cout << count << endl;

    return 0;
}