/**
 * ============================================================================
 * LeetCode 2958: Length of Longest Subarray With at Most K Frequency
 * ============================================================================
 *
 * Problem Statement:
 * You are given an integer array `nums` and an integer `k`. The frequency of an
 * element is the number of times it occurs in an array.
 * Return the length of the longest good subarray. A subarray is good if the
 * frequency of each element in this subarray is less than or equal to `k`.
 *
 * Approach Used: Sliding Window (Two Pointers)
 * 1. We use two pointers, `i` (left) and `j` (right), to define our window,
 *    and an unordered_map `m` to track the frequencies of elements inside it.
 * 2. We expand our window by moving `j` to the right and adding `nums[j]`
 *    to our map.
 * 3. If adding `nums[j]` causes its frequency to exceed `k`, our window 
 *    becomes invalid.
 * 4. To fix this, we shrink the window from the left by moving `i` forward.
 *    We decrement the frequency of `nums[i]` until `nums[i] == nums[j]`,
 *    effectively removing the extra occurrence of `nums[j]`.
 * 5. At each valid step, we update our maximum length (`ans`) using the
 *    formula `j - i + 1`.
 *
 * Complexity:
 * - Time Complexity: O(N) -> Both pointers `i` and `j` traverse the array at
 *   most once, making it a linear time solution.
 * - Space Complexity: O(N) -> The unordered_map can store up to N distinct
 *   elements in the worst case.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // Required for max()

using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;   // Left pointer of the window
        int j = 0;   // Right pointer of the window
        int ans = 0; // Variable to store the maximum subarray length

        unordered_map<int, int> m; // Map to track element frequencies

        // Expand the window by moving the right pointer
        while (j < n)
        {
            // Include the current element in our frequency map
            m[nums[j]]++;

            // If the current element's frequency exceeds k, the window is invalid
            if (m[nums[j]] > k)
            {
                // Shrink from the left until we find the duplicate of nums[j]
                while (nums[i] != nums[j])
                {
                    m[nums[i]]--; // Decrease frequency of elements leaving the window
                    i++;          // Shrink the window
                }
                // We found the duplicate (nums[i] == nums[j]), so we remove it
                // to make the frequency of nums[j] valid again.
                m[nums[i]]--;
                i++; // Move left pointer past the duplicate
            }

            // Update the maximum length found so far
            ans = max(ans, j - i + 1);

            // Move right pointer to process the next element
            j++;
        }

        return ans;
    }
};


int main()
{
    Solution solution;

    // Test case setup
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    // Execute the function
    int result = solution.maxSubarrayLength(nums, k);

    // Output the result to the console
    cout << "Array: [1, 2, 3, 1, 2, 3, 1, 2], k = 2" << endl;
    cout << "Length of longest valid subarray: " << result << endl;

    return 0;
}