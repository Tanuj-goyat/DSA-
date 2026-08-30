/**
 * ============================================================================
 * LeetCode 2091: Removing Minimum and Maximum From Array
 * ============================================================================
 *
 * Problem Statement:
 * You are given a 0-indexed array of distinct integers `nums`.
 * There is an array where you can remove elements from either the front or
 * the back. Return the minimum number of deletions it would take to remove
 * BOTH the minimum and maximum elements from the array.
 *
 * Approach Used: Greedy Index Math
 * 1. Traverse the array once to find the indices of the minimum and maximum
 *    elements.
 * 2. Assign `index1` to be the smaller of the two indices, and `index2` to
 *    be the larger of the two indices (so index1 always comes before index2).
 * 3. Calculate the minimum deletions by evaluating the three possible removal
 *    strategies:
 *    - Remove both elements from the front.
 *    - Remove both elements from the back.
 *    - Remove the first element from the front and the second from the back.
 * 4. The conditional logic optimally picks the cheapest combination by
 *    checking if it's better to continue removing from the front after
 *    hitting `index1`, or to switch and remove `index2` from the back.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We traverse the array exactly once to find the
 *   min and max indices.
 * - Space Complexity: O(1) -> Only a few integer variables are used.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for min() and max()

using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        int minimum = 0;
        int maximum = 0;

        // Step 1: Find the indices of the minimum and maximum elements
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[maximum])
            {
                maximum = i;
            }
            if (nums[i] < nums[minimum])
            {
                minimum = i;
            }
        }

        // Step 2: Order the indices so index1 is the leftmost and index2 is the rightmost
        int index1 = min(maximum, minimum);
        int index2 = max(maximum, minimum);

        int ans = 0;

        // Step 3: Calculate the optimal deletions
        // If the first target is in the left half of the array
        if (index1 <= n / 2)
        {
            ans += index1 + 1; // Cost to remove everything up to index1 from the front

            // Check what is cheaper for index2:
            // removing from the remaining front vs removing from the back
            if (index2 - index1 <= n - index2)
            {
                ans += index2 - index1; // Continue from the front
            }
            else
            {
                ans += n - index2; // Remove from the back
            }
        }
        else
        {
            // If even the first target is in the right half, just remove both from the back
            ans += n - index1;
        }

        // Step 4: Final safety check against removing everything purely from the back
        ans = min(ans, n - index1);

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Elements are near opposite ends
    vector<int> nums1 = {2, 10, 7, 5, 4, 1, 8, 6};
    // min is 1 at index 5. max is 10 at index 1.
    // Removing 10 from front (2 deletions) and 1 from back (3 deletions) = 5.
    cout << "Array: [2, 10, 7, 5, 4, 1, 8, 6]" << endl;
    cout << "Minimum Deletions: " << solution.minimumDeletions(nums1) << endl;
    // Expected: 5

    cout << "-----------------------------------" << endl;

    // Test Case 2: Elements are both near the front
    vector<int> nums2 = {0, -4, 19, 1, 8, -2, -3, 5};
    // min is -4 at index 1. max is 19 at index 2.
    // Removing both from the front takes 3 deletions.
    cout << "Array: [0, -4, 19, 1, 8, -2, -3, 5]" << endl;
    cout << "Minimum Deletions: " << solution.minimumDeletions(nums2) << endl;
    // Expected: 3

    cout << "-----------------------------------" << endl;

    // Test Case 3: Single element array
    vector<int> nums3 = {101};
    // min and max are the same element at index 0.
    // Takes 1 deletion.
    cout << "Array: [101]" << endl;
    cout << "Minimum Deletions: " << solution.minimumDeletions(nums3) << endl;
    // Expected: 1

    return 0;
}