#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================================================
Problem: Third Maximum Number
Platform: LeetCode (414)
========================================================

Problem Statement:
Given an integer array nums,
return the third distinct maximum number.

If the third distinct maximum does not exist,
return the maximum number.

Example:
Input:
[3,2,1]

Output:
1

Example:
Input:
[1,2]

Output:
2

========================================================
Approach Used (Three Maximum Variables):

Step 1:
Maintain:
- a = largest
- b = second largest
- c = third largest

Step 2:
Update values carefully while avoiding duplicates

Step 3:
If third maximum does not exist,
return maximum element

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int thirdMax(vector<int>& nums) {

        // First maximum
        long a = LONG_MIN;

        // Second maximum
        long b = LONG_MIN;

        // Third maximum
        long c = LONG_MIN;

        // ------------------------------
        // Traverse array
        // ------------------------------
        for (int i = 0; i < nums.size(); i++) {

            // New largest element
            if (nums[i] > a) {

                c = b;

                b = a;

                a = nums[i];
            }

            // New second largest
            else if (nums[i] > b &&
                     nums[i] != a) {

                c = b;

                b = nums[i];
            }

            // New third largest
            else if (nums[i] > c &&
                     nums[i] != a &&
                     nums[i] != b) {

                c = nums[i];
            }
        }

        // Third maximum does not exist
        if (c == LONG_MIN)
            return (int)a;

        return (int)c;
    }
};


int main() {

    vector<int> nums = {2,2,3,1};

    Solution obj;

    int result =
        obj.thirdMax(nums);

    cout << "Third Maximum: "
         << result << endl;

    return 0;
}