#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================================================
Problem: Leaders in an Array
Platform: GFG
========================================================

Problem Statement:
An element is called a leader if it is
greater than or equal to all elements
to its right side.

The rightmost element is always a leader.

Return all leaders in same order.

Example:
Input:
[16,17,4,3,5,2]

Output:
[17,5,2]

========================================================
Approach Used (Reverse Traversal):

Step 1:
Traverse array from right to left

Step 2:
Maintain maximum seen so far

Step 3:
If current element >= maximum,
it is a leader

Step 4:
Insert leader at beginning
to maintain order

Time Complexity: O(n²)
(because insert at begin shifts elements)

Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    vector<int> leaders(vector<int>& arr) {

        int maxi = INT_MIN;

        vector<int> v;

        // ------------------------------
        // Traverse from right
        // ------------------------------
        for (int i = arr.size() - 1; i >= 0; i--) {

            // Leader found
            if (arr[i] >= maxi) {

                v.insert(v.begin(), arr[i]);

                maxi = arr[i];
            }
        }

        return v;
    }
};


int main() {

    vector<int> arr = {16,17,4,3,5,2};

    Solution obj;

    vector<int> result = obj.leaders(arr);

    cout << "Leaders:\n";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}