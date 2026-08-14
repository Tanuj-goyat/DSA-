/**
 * ============================================================================
 * LeetCode 4: Median of Two Sorted Arrays
 * ============================================================================
 *
 * Problem Statement:
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 *
 * Approach Used: Two Pointers / Merging (Merge Sort logic)
 * 1. We create a new vector `v` to store the merged elements of both arrays.
 * 2. We use two pointers, `i` for nums1 and `j` for nums2.
 * 3. We compare elements at both pointers and push the smaller one into `v`,
 *    incrementing the respective pointer.
 * 4. Once one array is exhausted, we push the remaining elements of the other
 *    array into `v`.
 * 5. Finally, we calculate the median using the combined size of the array.
 *    - If the size is odd, the median is the middle element.
 *    - If the size is even, the median is the average of the two middle elements.
 *
 * Complexity:
 * - Time Complexity: O(m + n) -> We iterate through both arrays exactly once.
 * - Space Complexity: O(m + n) -> We create a new vector `v` that stores all
 *   elements from both arrays.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> v; // Vector to store the merged sorted arrays
        int i = 0;     // Pointer for nums1
        int j = 0;     // Pointer for nums2

        // Step 1: Merge elements from both arrays in sorted order
        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }

        // Step 2: If nums1 has remaining elements, append them
        while (i < n)
        {
            v.push_back(nums1[i]);
            i++;
        }

        // Step 3: If nums2 has remaining elements, append them
        while (j < m)
        {
            v.push_back(nums2[j]);
            j++;
        }

        // Step 4: Calculate the median
        int size = m + n;

        // Assume the array size is odd initially
        double ans = v[size / 2];

        // If the combined size is even, average the two middle elements
        if (size % 2 == 0)
        {
            ans = (ans + v[(size / 2) - 1]) / 2.0;
        }

        return ans;
    }
};


int main()
{
    Solution solution;

    // Test case setup
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    // Execute the function
    double result = solution.findMedianSortedArrays(nums1, nums2);

    // Output the result to the console
    cout << "Array 1: [1, 3]" << endl;
    cout << "Array 2: [2]" << endl;
    cout << "The median is: " << result << endl;

    // Another test case with an even total number of elements
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "\nArray 1: [1, 2]" << endl;
    cout << "Array 2: [3, 4]" << endl;
    cout << "The median is: " << solution.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}