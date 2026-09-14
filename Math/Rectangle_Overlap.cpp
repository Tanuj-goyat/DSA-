/**
 * ============================================================================
 * LeetCode 836: Rectangle Overlap
 * ============================================================================
 *
 * Problem Statement:
 * An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where
 * (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the
 * coordinate of its top-right corner. Its top and bottom edges are parallel
 * to the X-axis, and its left and right edges are parallel to the Y-axis.
 * Two rectangles overlap if the area of their intersection is positive.
 * Return true if they overlap, otherwise return false.
 *
 * Approach Used: 1D Segment Projection
 * 1. Project the 2D rectangles onto the 1D X and Y axes.
 * 2. On the X-axis, the overlap segment starts at the maximum of the two left
 *    edges (`max(rec1[0], rec2[0])`) and ends at the minimum of the two right
 *    edges (`min(rec1[2], rec2[2])`).
 * 3. A valid overlap on the X-axis exists strictly if the start of this
 *    intersection region is less than the end.
 * 4. Apply the exact same logic to the Y-axis (bottom and top edges).
 * 5. The rectangles overlap in 2D space if and only if they overlap on both
 *    the X-axis AND the Y-axis.
 *
 * Complexity:
 * - Time Complexity: O(1) -> Only basic arithmetic comparisons are performed.
 * - Space Complexity: O(1) -> No extra memory is allocated.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for max() and min()

using namespace std;

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {

        // Check if there is an overlap on the X-axis
        bool xOverlap = max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]);

        // Check if there is an overlap on the Y-axis
        bool yOverlap = max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);

        // The rectangles overlap if they overlap on both axes
        return xOverlap && yOverlap;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Overlapping rectangles
    // rec1 = [0,0,2,2], rec2 = [1,1,3,3]
    vector<int> rec1_1 = {0, 0, 2, 2};
    vector<int> rec1_2 = {1, 1, 3, 3};
    cout << "Test Case 1 (Overlapping):" << endl;
    cout << "Do they overlap? " << (solution.isRectangleOverlap(rec1_1, rec1_2) ? "true" : "false") << endl;
    // Expected: true

    cout << "-----------------------------------" << endl;

    // Test Case 2: Non-overlapping rectangles (separated)
    // rec1 = [0,0,1,1], rec2 = [1,0,2,1]
    vector<int> rec2_1 = {0, 0, 1, 1};
    vector<int> rec2_2 = {1, 0, 2, 1};
    cout << "Test Case 2 (Touching boundary, but not overlapping):" << endl;
    cout << "Do they overlap? " << (solution.isRectangleOverlap(rec2_1, rec2_2) ? "true" : "false") << endl;
    // Expected: false

    cout << "-----------------------------------" << endl;

    // Test Case 3: Completely enclosed rectangle
    // rec1 = [0,0,10,10], rec2 = [4,4,6,6]
    vector<int> rec3_1 = {0, 0, 10, 10};
    vector<int> rec3_2 = {4, 4, 6, 6};
    cout << "Test Case 3 (One inside another):" << endl;
    cout << "Do they overlap? " << (solution.isRectangleOverlap(rec3_1, rec3_2) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}