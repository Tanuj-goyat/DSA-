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
 * Approach Used: Monotonic Stack (Right-to-Left Traversal)
 * 1. We want to find a pattern where: 1st number < 3rd number < 2nd number.
 * 2. We traverse the array backwards (from right to left).
 * 3. We maintain a stack to keep track of potential candidates for the "3"
 *    (the largest number, nums[j]).
 * 4. We maintain a variable `last` which represents the highest valid "2"
 *    (the middle-valued number, nums[k]) we have found so far. We initialize
 *    it to INT_MIN.
 * 5. As we traverse backwards:
 *    - If the current number `nums[i]` is less than `last`, we have found
 *      our "1", and since we already secured a valid "3" and "2" previously,
 *      we return true!
 *    - If `nums[i]` is greater than the top of the stack, it's a great
 *      candidate for "3". We pop all elements smaller than it from the stack,
 *      and the largest popped element becomes our new `last` ("2").
 *    - We push the current number onto the stack.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We traverse the array once, and each element is
 *   pushed and popped from the stack at most once.
 * - Space Complexity: O(N) -> The stack can hold up to N elements in the worst
 *   case (a strictly decreasing array).
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
#include <climits> // Required for INT_MIN

using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();

        // 'last' represents nums[k] (the "2" in the 132 pattern)
        int last = INT_MIN;

        // Stack stores candidates for nums[j] (the "3" in the 132 pattern)
        stack<int> st;

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // If we find a number smaller than our highest recorded "2",
            // it acts as the "1", completing the 132 pattern!
            if (nums[i] < last)
                return true;

            // If current number is greater than stack top, it's a new "3" candidate.
            // Pop smaller elements. The highest popped element safely becomes our new "2".
            while (!st.empty() && nums[i] > st.top())
            {
                last = st.top();
                st.pop();
            }

            // Push current number onto the stack as a potential future "3"
            st.push(nums[i]);
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