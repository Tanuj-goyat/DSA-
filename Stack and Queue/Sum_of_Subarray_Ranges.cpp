#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
========================================================
Problem: Sum of Subarray Ranges
Platform: LeetCode (2104)
========================================================

Problem Statement:
Given an integer array nums.

The range of a subarray is:

maximum element - minimum element

Return the sum of ranges of all
subarrays.

Example:
Input:
nums = [1,2,3]

Output:
4

Explanation:
Subarrays:

[1] -> 0
[2] -> 0
[3] -> 0
[1,2] -> 1
[2,3] -> 1
[1,2,3] -> 2

Total = 4

========================================================
Approach Used (Monotonic Stack)

Step 1:
Calculate the total contribution of every
element as the maximum element.

Step 2:
Calculate the total contribution of every
element as the minimum element.

Step 3:
Answer =

(sum of maximums) -
(sum of minimums)

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution
{
public:
    // ------------------------------
    // Calculate contribution of every
    // element as maximum
    // ------------------------------
    long long maxSum(vector<int> &v)
    {

        int n = v.size();

        stack<int> st1;

        vector<int> left;

        // Previous Greater Element
        for (int i = 0; i < n; i++)
        {

            if (st1.empty())
            {

                left.push_back(-1);

                st1.push(i);
            }

            else if (v[st1.top()] >= v[i])
            {

                left.push_back(st1.top());

                st1.push(i);
            }

            else
            {

                while (!st1.empty() && v[st1.top()] < v[i])
                {

                    st1.pop();
                }

                if (st1.empty())
                {

                    left.push_back(-1);
                }

                else
                {

                    left.push_back(st1.top());
                }

                st1.push(i);
            }
        }

        stack<int> st2;

        vector<int> right(n, 0);

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--)
        {

            if (st2.empty())
            {

                right[i] = n;

                st2.push(i);
            }

            else if (v[st2.top()] > v[i])
            {

                right[i] = st2.top();

                st2.push(i);
            }

            else
            {

                while (!st2.empty() && v[st2.top()] <= v[i])
                {

                    st2.pop();
                }

                if (st2.empty())
                {

                    right[i] = n;
                }

                else
                {

                    right[i] = st2.top();
                }

                st2.push(i);
            }
        }

        long long ans = 0;

        // Contribution as maximum
        for (int i = 0; i < n; i++)
        {

            ans += (long long)(i - left[i]) * (right[i] - i) * v[i];
        }

        return ans;
    }

    // ------------------------------
    // Calculate contribution of every
    // element as minimum
    // ------------------------------
    long long minSum(vector<int> &v)
    {

        int n = v.size();

        stack<int> st1;

        vector<int> left;

        // Previous Smaller Element
        for (int i = 0; i < n; i++)
        {

            if (st1.empty())
            {

                left.push_back(-1);

                st1.push(i);
            }

            else if (v[st1.top()] <= v[i])
            {

                left.push_back(st1.top());

                st1.push(i);
            }

            else
            {

                while (!st1.empty() && v[st1.top()] > v[i])
                {

                    st1.pop();
                }

                if (st1.empty())
                {

                    left.push_back(-1);
                }

                else
                {

                    left.push_back(st1.top());
                }

                st1.push(i);
            }
        }

        stack<int> st2;

        vector<int> right(n, 0);

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--)
        {

            if (st2.empty())
            {

                right[i] = n;

                st2.push(i);
            }

            else if (v[st2.top()] < v[i])
            {

                right[i] = st2.top();

                st2.push(i);
            }

            else
            {

                while (!st2.empty() && v[st2.top()] >= v[i])
                {

                    st2.pop();
                }

                if (st2.empty())
                {

                    right[i] = n;
                }

                else
                {

                    right[i] = st2.top();
                }

                st2.push(i);
            }
        }

        long long ans = 0;

        // Contribution as minimum
        for (int i = 0; i < n; i++)
        {

            ans += (long long)(i - left[i]) * (right[i] - i) * v[i];
        }

        return ans;
    }

    // ------------------------------
    // Calculate sum of subarray ranges
    // ------------------------------
    long long subArrayRanges(vector<int> &nums)
    {

        long long ans = maxSum(nums) - minSum(nums);

        return ans;
    }
};

int main()
{

    vector<int> nums = {1, 2, 3};

    Solution obj;

    long long answer = obj.subArrayRanges(nums);

    cout << answer << endl;

    return 0;
}