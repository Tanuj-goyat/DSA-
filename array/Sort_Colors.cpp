/*
Given an array with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]


APPROACH

count all 0's, 1's and 2's
then arrange them
*/

#include <iostream>
using namespace std;

int main()
{

    int nums[6] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);
    int count0 = 0; // count no. of 0's
    int count1 = 0;
    int count2 = 0;
    for (int i : nums)
    {
        switch (i)
        {
        case 0:
            count0++;
            break;
        case 1:
            count1++;
            break;
        case 3:
            count2++;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i <= count0 - 1)
        {
            nums[i] = 0;
        }
        else if (i >= count0 && i < (count0 + count1))
        {
            nums[i] = 1;
        }
        else
            nums[i] = 2;
    }

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}