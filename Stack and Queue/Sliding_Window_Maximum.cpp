#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
========================================================
Problem: Sliding Window Maximum
Platform: LeetCode (239)
========================================================

Problem Statement:
Given an integer array nums and an
integer k.

For every sliding window of size k,
return the maximum element in that
window.

Example:
Input:
nums = [1,3,-1,-3,5,3,6,7]
k = 3

Output:
[3,3,5,5,6,7]

========================================================
Approach Used (Monotonic Deque)

Step 1:
Maintain a deque storing indices of
elements.

Step 2:
Remove indices that are outside the
current window.

Step 3:
Remove all smaller elements from the
back of the deque.

Step 4:
Insert the current index.

Step 5:
The front of the deque always contains
the index of the maximum element for
the current window.

Time Complexity: O(n)
Space Complexity: O(k)

========================================================
*/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        vector<int> ans;

        deque<int> dq;

        // ------------------------------
        // Traverse the array
        // ------------------------------
        for (int i = 0; i < nums.size(); i++)
        {

            // Remove indices outside
            // the current window
            if (!dq.empty() && dq.front() == i - k)
            {

                dq.pop_front();
            }

            // Remove smaller elements
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {

                dq.pop_back();
            }

            // Insert current index
            dq.push_back(i);

            // Store window maximum
            if (i >= k - 1)
            {

                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

int main()
{

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    int k = 3;

    Solution obj;

    vector<int> answer = obj.maxSlidingWindow(nums, k);

    for (int x : answer)
        cout << x << " ";

    cout << endl;

    return 0;
}