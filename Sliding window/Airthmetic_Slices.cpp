#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem Name: Arithmetic Slices
Platform: LeetCode
Problem Number: 413
========================================================

Problem Statement:
An arithmetic array is an array where the difference
between consecutive elements is the same.

Return the number of arithmetic subarrays (length ≥ 3).

Example:
Input: [1,2,3,4]
Output: 3

Subarrays:
[1,2,3], [2,3,4], [1,2,3,4]

========================================================
Approach (Sliding Window Idea)

1️⃣ Maintain a window with same difference

2️⃣ If current diff matches previous:
   → Extend window
   → Add (window size - 2) to count

3️⃣ Else:
   → Reset window

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();

        if (n < 3) return 0;

        int i = 0;   // start of window
        int j = 2;   // current index
        int count = 0;

        while (j < n) {

            int diff1 = nums[j] - nums[j - 1];
            int diff2 = nums[j - 1] - nums[j - 2];

            if (diff1 == diff2) {

                // Number of new slices formed
                count += (j - i - 1);

                j++;
            }
            else {
                // Reset window
                i = j - 1;
                j = i + 2;
            }
        }

        return count;
    }
};


int main() {

    vector<int> nums = {1, 2, 3, 4};

    Solution obj;

    cout << "Arithmetic Slices: "
         << obj.numberOfArithmeticSlices(nums);

    return 0;
}