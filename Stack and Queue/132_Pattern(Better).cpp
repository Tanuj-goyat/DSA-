/**
 * ============================================================================
 * LeetCode 456: 132 Pattern
 * ============================================================================
 *
 * Problem Statement:
 * Given an array of n integers nums, a 132 pattern is a subsequence of three
 * integers nums[i], nums[j] and nums[k] such that i < j < k and
 * nums[i] < nums[k] < nums[j].
 * Return true if there is a 132 pattern in nums, otherwise, return false.
 *
 * Approach Used: Prefix Minimums + Previous Greater Element (Monotonic Stack)
 * 1. Step 1 (Prefix Minimums): We build an array `premin` where `premin[i]`
 *    stores the index of the smallest element seen from index 0 up to i.
 *    This acts as our candidate for "1" (the smallest number).
 * 2. Step 2 (Previous Greater Element): We use a monotonic decreasing stack
 *    to build an array `preGreater`. `preGreater[i]` stores the index of the
 *    closest previous element that is strictly greater than `nums[i]`.
 *    This acts as our candidate for "3" (the peak).
 * 3. Step 3 (Verification): We iterate backwards. We treat the current index
 *    `c` as the "2" in our pattern.
 *    - `b` = preGreater[c] (the "3" before "2")
 *    - `a` = premin[b] (the "1" before "3")
 *    - If `nums[a] < nums[c]` and all indices are distinct, we have
 *      successfully found `nums[a] < nums[c] < nums[b]` which is our 132 pattern!
 *
 * Complexity:
 * - Time Complexity: O(N) -> We make three separate O(N) passes over the array.
 *   The stack operations process each element at most twice.
 * - Space Complexity: O(N) -> We use three O(N) data structures: `st`,
 *   `preGreater`, and `premin`.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;
        vector<int> preGreater(n, 0);
        vector<int> premin;
        int mini = 0;

        // Step 1: Track the index of the minimum element seen so far
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < nums[mini])
            {
                mini = i;
            }
            premin.push_back(mini);
        }

        // Step 2: Use a monotonic stack to find the previous greater element
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(i);
                preGreater[i] = i; // Points to itself if no greater element exists
            }
            else if (nums[st.top()] > nums[i])
            {
                preGreater[i] = st.top();
                st.push(i);
            }
            else
            {
                // Pop elements smaller than or equal to current element
                while (!st.empty() && nums[i] >= nums[st.top()])
                {
                    st.pop();
                }

                if (st.empty())
                {
                    preGreater[i] = i;
                }
                else
                {
                    preGreater[i] = st.top();
                }
                st.push(i);
            }
        }

        // Step 3: Validate the 132 pattern
        for (int i = n - 1; i >= 0; i--)
        {
            int c = i;             // Represents index 'k' (the "2")
            int b = preGreater[c]; // Represents index 'j' (the "3")
            int a = premin[b];     // Represents index 'i' (the "1")

            // Check if the pattern holds and all indices are distinct
            if (nums[a] < nums[c] && a != b && b != c)
            {
                return true;
            }
        }
        return false;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: No 132 pattern
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Array: [1, 2, 3, 4]" << endl;
    cout << "Contains 132 Pattern: "
         << (solution.find132pattern(nums1) ? "true" : "false") << endl;
    // Expected: false

    cout << "-----------------------------------" << endl;

    // Test Case 2: Contains 132 pattern (1, 4, 2)
    vector<int> nums2 = {3, 1, 4, 2};
    cout << "Array: [3, 1, 4, 2]" << endl;
    cout << "Contains 132 Pattern: "
         << (solution.find132pattern(nums2) ? "true" : "false") << endl;
    // Expected: true

    cout << "-----------------------------------" << endl;

    // Test Case 3: Contains multiple patterns, e.g., (-1, 3, 2) or (-1, 3, 0)
    vector<int> nums3 = {-1, 3, 2, 0};
    cout << "Array: [-1, 3, 2, 0]" << endl;
    cout << "Contains 132 Pattern: "
         << (solution.find132pattern(nums3) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}