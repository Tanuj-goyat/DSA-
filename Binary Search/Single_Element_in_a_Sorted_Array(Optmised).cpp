/**
 * ============================================================================
 * LeetCode 540: Single Element in a Sorted Array
 * ============================================================================
 * 
 * Problem Statement:
 * You are given a sorted array consisting of only integers where every element 
 * appears exactly twice, except for one element which appears exactly once. 
 * Find this single element that appears only once.
 * 
 * Approach Used: Binary Search
 * Since the array is sorted and an O(log n) solution is required, we use Binary Search.
 * 1. Pointers: Initialize 'start' and 'end' pointers.
 * 2. Boundary Checks: If 'mid' is at the extreme ends (index 0 or n-1) and distinct, return it.
 * 3. Core Condition: If nums[mid] is different from both its left and right neighbors, 
 *    it is the unique element, and we return it.
 * 4. Shrinking the Search Space:
 *    - If nums[mid] == nums[mid - 1]: Check the remaining elements on the right. 
 *      If even, the target is in the left half. Otherwise, it is in the right half.
 *    - If nums[mid] == nums[mid + 1]: Check the elements on the left. 
 *      If even, the target is in the right half. Otherwise, it is in the left half.
 * 
 * Complexity:
 * - Time Complexity: O(log n) -> By using Binary Search, the search space is halved every iteration.
 * - Space Complexity: O(1) -> We only use a few extra variables, taking constant space.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        // Base case: If the array has only one element, it is the answer.
        if (n == 1) return nums[0];

        // Binary search to find the single element in O(log n) time
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Boundary Check 1: If mid is at the start and distinct from the next element
            if (mid == 0 && nums[mid] != nums[mid + 1]) 
                return nums[0];
            
            // Boundary Check 2: If mid is at the end and distinct from the previous element
            else if (mid == (n - 1) && nums[mid - 1] != nums[mid]) 
                return nums[mid];
            
            // Core Logic: If mid is distinct from both its left and right neighbors, we found it
            else if (nums[mid] != nums[mid - 1] && nums[mid + 1] != nums[mid]) {
                return nums[mid];
            }
            
            // Condition 1: The duplicate of mid is on the left
            else if (nums[mid - 1] == nums[mid]) {
                // If the number of remaining elements on the right is even,
                // the single element must be hiding in the left half.
                if ((n - 1 - mid) % 2 == 0) {
                    end = mid - 1;
                } 
                // Otherwise, the single element is in the right half.
                else {
                    start = mid + 1;
                }
            }
            
            // Condition 2: The duplicate of mid is on the right
            else if (nums[mid + 1] == nums[mid]) {
                // If the number of elements on the left of mid is even,
                // the single element must be hiding in the right half.
                if (mid % 2 == 0) {
                    start = mid + 1;
                } 
                // Otherwise, it is in the left half.
                else {
                    end = mid - 1;
                }
            }
        }
        
        // Fallback return (should not be reached if the input is valid)
        return -1; 
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main() {
    Solution solution;

    // Test case setup
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    // Execute the function
    int result = solution.singleNonDuplicate(nums);

    // Output the result to the console
    cout << "Array: [1, 1, 2, 3, 3, 4, 4, 8, 8]" << endl;
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}