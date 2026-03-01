#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Rotate Array
Platform: LeetCode
Problem Number: 189
========================================================

Problem Statement:
Given an integer array nums, rotate the array to the right
by k steps.

Example:
Input:  nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Explanation:
Rotate right by 1 → [7,1,2,3,4,5,6]
Rotate right by 2 → [6,7,1,2,3,4,5]
Rotate right by 3 → [5,6,7,1,2,3,4]

========================================================
Approach Used (Extra Array Method):

1️⃣ Handle large k:
   If k > size, take k % size.

2️⃣ Store last k elements in temporary array.

3️⃣ Shift remaining elements to the right.

4️⃣ Copy stored elements to the beginning.

Time Complexity: O(n)
Space Complexity: O(k)

========================================================
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        // Only proceed if k > 0 and array has more than 1 element
        if (k > 0 && nums.size() > 1)
        {
            int n = nums.size() - 1;   // Last index
            int x = k;

            // If k is greater than array size,
            // reduce it using modulo
            if (k > n)
            {
                x = k % (n + 1);
            }

            // Store last x elements in temporary array
            vector<int> arr(x);
            for (int i = 0; i < x; i++)
            {
                arr[i] = nums[n - x + i + 1];
            }

            // Shift remaining elements to the right
            int i = 0;
            while (n - (x + i) >= 0)
            {
                nums[n - i] = nums[n - (x + i)];
                i++;
            }

            // Place stored elements at beginning
            for (int i = 0; i < x; i++)
            {
                nums[i] = arr[i];
            }
        }
    }
};


int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    Solution obj;
    obj.rotate(nums, k);

    cout << "Rotated Array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}