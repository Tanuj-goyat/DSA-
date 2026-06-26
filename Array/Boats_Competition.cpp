#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Boats Competition
Platform: Codeforces 1399C
========================================================

Problem Statement:
For each test case:

Given an array of integers.

Find the maximum number of disjoint pairs   
that can be formed such that every pair
has the same sum.

Print the maximum possible number of
pairs.

========================================================
Approach Used (Sorting + Two Pointers)

Step 1:
Sort the array.

Step 2:
Try every possible target sum from
2 to 100.

Step 3:
For each target sum, use two pointers
to count the maximum number of disjoint
pairs.

Step 4:
Keep the maximum count among all
possible target sums.

Time Complexity: O(100 × n)
Space Complexity: O(1)
(excluding input array)

========================================================
*/


// ------------------------------
// Count disjoint pairs having
// given target sum
// ------------------------------
int twoSum(vector<int>& v,
           int target) {

    if (target < 2)
        return 0;

    int i = 0;

    int j = v.size() - 1;

    int count = 0;

    while (i < j) {

        int sum = v[i] + v[j];

        if (sum == target) {

            count++;

            i++;

            j--;
        }

        else if (sum < target) {

            i++;
        }

        else if (sum > target) {

            j--;
        }
    }

    return count;
}


int main() {

    int t;

    cin >> t;


    for (; t > 0; t--) {

        int n;

        cin >> n;

        vector<int> v;


        for (int i = 0; i < n; i++) {

            int val;

            cin >> val;

            v.push_back(val);
        }

 
        sort(v.begin(), v.end());

        int ans = -1;

        int freq = 0;

        for (int i = 2;
             i <= 100;
             i++) {

            int count =
                twoSum(v, i);

            if (count > freq) {

                freq = count;

                ans = i;
            }
        }

        cout << freq << endl;
    }

    return 0;
}