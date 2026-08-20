/**
 * ============================================================================
 * LeetCode 3069: Distribute Elements Into Two Arrays I
 * ============================================================================
 *
 * Problem Statement:
 * You are given an array of distinct integers `nums` of length n.
 * You need to distribute all the elements of `nums` between two arrays `arr1`
 * and `arr2` using n operations.
 * - In the 1st operation, append nums[0] to arr1.
 * - In the 2nd operation, append nums[1] to arr2.
 * - In subsequent operations, append nums[i] to the array whose last element is greater.
 * Return the array obtained by concatenating arr1 and arr2.
 *
 * Approach Used: Array Simulation
 * 1. Create two separate arrays, `arr1` and `arr2`.
 * 2. Iterate through the input array `nums`.
 * 3. Use conditional checks to place the first element in `arr1` and the
 *    second in `arr2`.
 * 4. For all following elements, compare the last element of `arr1` (using
 *    arr1.size() - 1) with the last element of `arr2`. Push the current element
 *    into the array that has the strictly greater last element.
 * 5. Finally, use a two-pointer approach to overwrite the original `nums` array
 *    by placing all elements of `arr1` first, followed by all elements of `arr2`.
 *
 * Complexity:
 * - Time Complexity: O(N) -> We loop through the elements to distribute them,
 *   and then loop through them again to merge. Both steps take linear time.
 * - Space Complexity: O(N) -> We use two additional arrays `arr1` and `arr2`
 *   which together store exactly N elements.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;

        // Step 1 & 2: Distribute elements according to the rules
        for (int i = 0; i < n; i++)
        {
            // The first element always goes to arr1
            if (arr1.empty())
            {
                arr1.push_back(nums[i]);
            }
            // The second element always goes to arr2
            else if (arr2.empty())
            {
                arr2.push_back(nums[i]);
            }
            // For remaining elements, compare the last inserted elements
            else
            {
                if (arr1[arr1.size() - 1] > arr2[arr2.size() - 1])
                {
                    arr1.push_back(nums[i]);
                }
                else
                {
                    arr2.push_back(nums[i]);
                }
            }
        }

        // Step 3: Merge arr1 and arr2 back into nums
        int i = 0;
        int j = 0;
        int index = 0;

        // Iterate until both arrays are completely copied over
        while (i < arr1.size() || j < arr2.size())
        {
            // Copy all elements from arr1 first
            if (i < arr1.size())
            {
                nums[index] = arr1[i];
                i++;
            }
            // Once arr1 is exhausted, copy elements from arr2
            else if (j < arr2.size())
            {
                nums[index] = arr2[j];
                j++;
            }
            else
                break;

            index++; // Move to the next position in nums
        }

        return nums;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {5, 4, 3, 8};
    vector<int> result1 = solution.resultArray(nums1);

    cout << "Original Array: [5, 4, 3, 8]" << endl;
    cout << "Result Array:   [ ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << "]" << endl;
    // Expected output: [5, 3, 4, 8]

    cout << "-----------------------------------" << endl;

    // Test Case 2
    vector<int> nums2 = {2, 1, 3};
    vector<int> result2 = solution.resultArray(nums2);

    cout << "Original Array: [2, 1, 3]" << endl;
    cout << "Result Array:   [ ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << "]" << endl;
    // Expected output: [2, 3, 1]

    return 0;
}