/**
 * ============================================================================
 * Problem: Count Special Integers (Contiguous Occurrences)
 * ============================================================================
 *
 * Problem Statement:
 * Given an array of integers `nums`, an integer is considered "special" if all
 * of its occurrences in the array appear continuously as a single block.
 * Return the total number of such special integers.
 *
 * Approach Used: Hash Map & Two-Pointer Grouping
 * 1. First, we iterate through the array and use an `unordered_map` to count
 *    the total frequency of each distinct integer.
 * 2. We then iterate through the array again using a two-pointer approach
 *    (`i` and `j`) to find contiguous blocks of identical numbers.
 * 3. The `i` pointer marks the start of a block. The `j` pointer moves forward
 *    as long as the elements match `nums[i]`, counting the size of this
 *    contiguous block (`currCount`).
 * 4. If the size of this block (`currCount`) exactly matches the total overall
 *    frequency of that number (`freq`), it means all occurrences of this number
 *    are grouped together right here. We increment our answer.
 * 5. We then jump our starting pointer `i` directly to `j` to process the next
 *    block of numbers.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We traverse the array once to build the frequency
 *   map, and the two-pointer `while` loops traverse the array exactly once more.
 * - Space Complexity: O(N) -> The unordered_map will store up to N distinct
 *   integers in the worst case.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int countSpecialIntegers(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;

        // Step 1: Count the total frequency of each element in the array
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        int i = 0;
        int ans = 0;

        // Step 2: Use two pointers to measure contiguous blocks
        while (i < n)
        {
            int freq = m[nums[i]]; // Total occurrences of the current number in the entire array
            int j = i;
            int currCount = 0;

            // Move 'j' forward as long as it matches the element at 'i'
            while (j < n && nums[j] == nums[i])
            {
                j++;
                currCount++;
            }

            // If the size of this contiguous block matches the total frequency,
            // all instances of this number are grouped together.
            if (currCount == freq)
                ans++;

            // Jump 'i' forward to start processing the next block
            i = j;
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

    // Test Case 1: All occurrences are perfectly grouped
    vector<int> nums1 = {1, 2, 2, 2, 3};
    // '1' appears 1 time (grouped).
    // '2' appears 3 times (grouped).
    // '3' appears 1 time (grouped).
    cout << "Array: [1, 2, 2, 2, 3]" << endl;
    cout << "Special Integers: " << solution.countSpecialIntegers(nums1) << endl;
    // Expected: 3

    cout << "-----------------------------------" << endl;

    // Test Case 2: One element is scattered
    vector<int> nums2 = {1, 2, 2, 3, 2};
    // '1' appears 1 time (grouped).
    // '2' appears 3 times (NOT grouped - split by '3').
    // '3' appears 1 time (grouped).
    cout << "Array: [1, 2, 2, 3, 2]" << endl;
    cout << "Special Integers: " << solution.countSpecialIntegers(nums2) << endl;
    // Expected: 2 (Only 1 and 3 are special)

    cout << "-----------------------------------" << endl;

    // Test Case 3: Completely alternating array
    vector<int> nums3 = {4, 5, 4, 5};
    // Neither '4' nor '5' are perfectly grouped.
    cout << "Array: [4, 5, 4, 5]" << endl;
    cout << "Special Integers: " << solution.countSpecialIntegers(nums3) << endl;
    // Expected: 0

    return 0;
}