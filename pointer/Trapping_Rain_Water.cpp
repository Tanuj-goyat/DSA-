#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Trapping Rain Water
Platform: LeetCode (42)
========================================================

Problem Statement:
Given an array arr where each element
represents the height of a bar.

Find the total amount of rain water
that can be trapped after raining.

Example:
Input:
arr = [0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6

========================================================
Approach Used (Two Pointers)

Step 1:
Initialize two pointers:

- Left pointer (i)
- Right pointer (j)

Step 2:
Maintain:

- imax -> Maximum height seen from left
- jmax -> Maximum height seen from right

Step 3:
Move the pointer whose maximum height
is smaller.

Step 4:
If the current height is smaller than
the corresponding maximum,
water trapped is:

maximum - current height

Otherwise,
update the maximum.

Step 5:
Continue until both pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int trap(vector<int>& arr) {

        int imax = 0;

        int jmax = 0;

        int i = 0;

        int j = arr.size() - 1;

        int count = 0;

        while (i <= j) {

            if (imax <= jmax) {

                if (arr[i] >= imax) {

                    imax = arr[i];
                }

                else {

                    count += imax - arr[i];
                }

                i++;
            }

            else {

                if (arr[j] >= jmax) {

                    jmax = arr[j];
                }

                else {
                    count += jmax - arr[j];
                }

                j--;
            }
        }

        return count;
    }
};


int main() {

    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution obj;

    int answer = obj.trap(arr);

    cout << answer << endl;

    return 0;
}