/**
 * ============================================================================
 * Problem: Maximum Fruits in a Circular Array (Max Subarray of Size M)
 * ============================================================================
 *
 * Problem Statement:
 * Given an array of integers representing fruits on trees arranged in a circle,
 * find the maximum amount of fruits you can collect by picking from at most
 * 'm' consecutive trees. Since the array is circular, the end of the array
 * wraps around to the beginning.
 *
 * Approach Used: Circular Sliding Window
 * 1. Base Case: If the allowed window size 'm' is greater than or equal to the
 *    array size, we can simply pick all the fruits. We return the total sum.
 * 2. Sliding Window: We use two pointers, `index1` (start of window) and
 *    `index2` (end of window).
 * 3. Circular Wrapping: As `index2` grows beyond the array boundaries, we map
 *    it to a valid array index `j`. If `j >= n`, we subtract `n` to wrap it
 *    around to the start of the array.
 * 4. Window Maintenance: We continuously add `arr[j]` to our current `sum`.
 *    If our window size (`index2 - index1 + 1`) exceeds the allowed size `m`,
 *    we shrink the window from the left by subtracting `arr[index1]` and
 *    incrementing `index1`.
 * 5. We track the maximum sum encountered during this entire traversal. The loop
 *    terminates when our left pointer `index1` completes one full rotation (`< n`).
 *
 * Complexity:
 * - Time Complexity: O(N) -> Both `index1` and `index2` advance linearly. The
 *   array is traversed essentially twice (once by the front pointer, once by the
 *   back), making it strictly O(N).
 * - Space Complexity: O(1) -> Only a few integer variables are used for tracking.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for max()

using namespace std;

class Solution
{
public:
    int maxFruits(vector<int> &arr, int m)
    {
        int n = arr.size();

        // Base case: If allowed size >= array size, take everything
        if (m >= n)
        {
            int result = 0;
            for (int x : arr)
                result += x;
            return result;
        }

        int index1 = 0;
        int index2 = 0;
        int sum = 0;
        int ans = 0;

        // Slide the window until the starting pointer completes a full cycle
        while (index1 < n)
        {
            int i = index1;
            int j = index2;

            // Wrap the right pointer around if it goes out of bounds
            if (j >= n)
                j -= n;

            // Expand window by adding the new element
            sum += arr[j];

            // If window exceeds size 'm', shrink it from the left
            if (index2 - index1 + 1 > m)
            {
                sum -= arr[i]; // i is strictly < n, so no wrapping needed here
                index1++;
            }

            index2++;

            // Update the global maximum with the current valid window's sum
            ans = max(ans, sum);
        }

        return ans;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard circular wrapping
    // Array: [2, 1, 3, 5, 4] | m = 2
    // Windows of size 2: (2,1)=3, (1,3)=4, (3,5)=8, (5,4)=9, (4,2)=6
    // Max is 9 (from elements 5 and 4)
    vector<int> arr1 = {2, 1, 3, 5, 4};
    int m1 = 2;
    cout << "Array: [2, 1, 3, 5, 4], m = 2" << endl;
    cout << "Max Fruits: " << solution.maxFruits(arr1, m1) << endl;
    // Expected: 9

    cout << "-----------------------------------" << endl;

    // Test Case 2: Maximum sum wraps around the array boundary
    // Array: [8, 2, -1, 3, 6] | m = 3
    // The sequence [6, 8, 2] wraps around the end and yields 16.
    vector<int> arr2 = {8, 2, -1, 3, 6};
    int m2 = 3;
    cout << "Array: [8, 2, -1, 3, 6], m = 3" << endl;
    cout << "Max Fruits: " << solution.maxFruits(arr2, m2) << endl;
    // Expected: 16

    cout << "-----------------------------------" << endl;

    // Test Case 3: m is larger than the array size
    // Array: [1, 2, 3] | m = 5
    // Just takes the sum of the entire array.
    vector<int> arr3 = {1, 2, 3};
    int m3 = 5;
    cout << "Array: [1, 2, 3], m = 5" << endl;
    cout << "Max Fruits: " << solution.maxFruits(arr3, m3) << endl;
    // Expected: 6

    return 0;
}