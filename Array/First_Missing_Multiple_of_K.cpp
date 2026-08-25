/**
 * ============================================================================
 * Problem: First Missing Multiple of K (3718)
 * ============================================================================
 *
 * Problem Statement:
 * Given an integer array `nums` and an integer `k`, find the smallest positive
 * multiple of `k` that is missing from the array.
 *
 * Approach Used: Cyclic Sort (In-Place Array Modification)
 * 1. The goal is to place each valid multiple of 'k' at its corresponding index.
 *    For example, if k=2: 2 goes to index 0, 4 goes to index 1, 6 goes to index 2.
 * 2. We iterate through the array. If the current number is a multiple of 'k',
 *    we calculate its expected index: (nums[i] / k) - 1.
 * 3. We use a while loop to swap the number into its correct expected index as
 *    long as it's within the array bounds and not already in the right place.
 * 4. After sorting, we iterate through the array one more time. The first index
 *    'i' that does NOT contain the expected multiple ((i + 1) * k) represents
 *    our missing multiple.
 * 5. If all multiples from 1*k to n*k are present in their correct spots, the
 *    missing multiple is simply the next one: (n + 1) * k.
 *
 * Complexity:
 * - Time Complexity: O(N) -> Even with the nested while loop, each element is
 *   swapped to its correct position at most once, making it linear time.
 * - Space Complexity: O(1) -> All modifications are done in-place without
 *   allocating extra arrays.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        int n = nums.size();
        int index = 0;

        // Phase 1: Cyclic sort to place multiples of k at their correct indices
        for (int i = 0; i < n; i++)
        {
            // Check if the current number is a multiple of k
            while (nums[i] % k == 0)
            {
                // Check if the multiple belongs within our array bounds
                // and is not already sitting in its correct position
                if (nums[i] / k < n && nums[nums[i] / k - 1] != nums[i])
                {
                    // Swap it to its correct 0-based index
                    swap(nums[nums[i] / k - 1], nums[i]);
                }
                else
                    break;
            }
        }

        // Phase 2: Find the first missing multiple
        for (int i = 0; i < n; i++)
        {
            // If the element is not a multiple of k, or it's not the EXPECTED multiple
            if (nums[i] % k != 0 || nums[i] / k != i + 1)
            {
                return (i + 1) * k;
            }
        }

        // Phase 3: If all elements were exactly the first 'n' multiples, return the (n+1)th
        return (n + 1) * k;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: k = 2. Array has 2 and 4. Missing is 6.
    // Expected index positions: 2 at index 0, 4 at index 1.
    vector<int> nums1 = {4, -1, 2, 7};
    int k1 = 2;
    cout << "Array: [4, -1, 2, 7], k = 2" << endl;
    cout << "First Missing Multiple: " << solution.missingMultiple(nums1, k1) << endl;
    // Expected: 6

    cout << "-----------------------------------" << endl;

    // Test Case 2: k = 3. Array has 3, 6, 9. Missing is 12.
    vector<int> nums2 = {9, 6, 3};
    int k2 = 3;
    cout << "Array: [9, 6, 3], k = 3" << endl;
    cout << "First Missing Multiple: " << solution.missingMultiple(nums2, k2) << endl;
    // Expected: 12

    cout << "-----------------------------------" << endl;

    // Test Case 3: k = 5. Array has no multiples of 5. Missing is 5.
    vector<int> nums3 = {1, 2, 3, 4};
    int k3 = 5;
    cout << "Array: [1, 2, 3, 4], k = 5" << endl;
    cout << "First Missing Multiple: " << solution.missingMultiple(nums3, k3) << endl;
    // Expected: 5

    return 0;
}