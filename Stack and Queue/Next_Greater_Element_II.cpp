#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
========================================================
Problem: Next Greater Element II
Platform: LeetCode (503)
========================================================

Problem Statement:
Given a circular integer array nums.

For every element, find the first
greater element while traversing
towards the right.

Since the array is circular,
after the last element continue
from the beginning.

If no greater element exists,
return -1.

Example:
Input:
nums = [1,2,1]

Output:
[2,-1,2]

========================================================
Approach Used (Monotonic Stack)

Step 1:
Traverse the array from right to left.

Step 2:
Use a monotonic decreasing stack to
find the next greater element.

Step 3:
Store answers for the normal array.

Step 4:
Traverse again from right to left
to handle the circular property.

Step 5:
Update only those positions whose
answer is still -1.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution
{
public:
    vector<int> nextGreaterElements(
        vector<int> &nums)
    {

        stack<int> st;

        vector<int> ans(nums.size(), 0);

        for (int i = nums.size() - 1;
             i >= 0;
             i--)
        {

            if (st.empty())
            {

                ans[i] = -1;
            }

            else if (st.top() >
                     nums[i])
            {

                ans[i] = st.top();
            }

            else
            {

                while (!st.empty() &&
                       st.top() <= nums[i])
                {

                    st.pop();
                }

                if (!st.empty())
                {

                    ans[i] = st.top();
                }

                else
                {

                    ans[i] = -1;
                }
            }

            st.push(nums[i]);
        }

        for (int i = nums.size() - 1;
             i >= 0;
             i--)
        {

            if (st.empty())
            {

                break;
            }

            else if (st.top() >
                         nums[i] &&
                     ans[i] == -1)
            {

                ans[i] = st.top();
            }

            else
            {

                while (!st.empty() &&
                       st.top() <= nums[i])
                {

                    st.pop();
                }

                if (!st.empty() &&
                    ans[i] == -1)
                {

                    ans[i] = st.top();
                }

                else if (st.empty())
                {

                    break;
                }
            }

            st.push(nums[i]);
        }

        return ans;
    }
};

int main()
{

    vector<int> nums =
        {1, 2, 1};

    Solution obj;

    vector<int> answer =
        obj.nextGreaterElements(nums);

    for (int x : answer)
        cout << x << " ";

    cout << endl;

    return 0;
}