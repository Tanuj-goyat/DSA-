#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================================================
Problem Name: construct uniform parity array 2
Platform: LeetCode
Problem Number: 3876
========================================================

Problem Understanding (based on your code):

You are checking whether the array satisfies a condition
based on parity (odd/even nature of elements).

Logic observed:
1️⃣ Find the smallest element in the array.
2️⃣ Check parity of elements:
   - If smallest is even → all elements must be even
   - If smallest is odd → all elements must be odd

If mixture exists → return false

========================================================
Approach Used:

- Traverse array
- Track:
    small → smallest element
    ev → true if all even
    od → true if all odd

- If any odd found → ev = false
- If smallest is odd → od remains valid
- Else → od = false

Finally:
If both ev and od are false → invalid

========================================================
Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int small = INT_MAX;   // smallest element
        bool od = true;        // assume all odd
        bool ev = true;        // assume all even

        // Step 1: Traverse array
        for(int i = 0; i < nums1.size(); i++) {

            // If number is odd → not all even
            if(nums1[i] & 1)
                ev = false;

            // Track smallest element
            if(nums1[i] < small)
                small = nums1[i];
        }
        
        // Step 2: Check smallest element parity

        // If smallest is odd → array must be odd-only
        if(small & 1) {
            ev = false;
        }
        else {
            // If smallest is even → array must be even-only
            od = false;
        }

        // Step 3: Final check
        if(ev == false && od == false)
            return false;

        return true;
    }
};


int main() {

    vector<int> nums = {2, 4, 6, 8};

    Solution obj;

    if(obj.uniformArray(nums))
        cout << "Uniform Array";
    else
        cout << "Not Uniform";

    return 0;
}