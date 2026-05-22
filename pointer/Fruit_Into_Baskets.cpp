#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Fruit Into Baskets
Platform: LeetCode (904)
========================================================

Problem Statement:
You are given an array fruits where:
fruits[i] represents the type of fruit.

You have only 2 baskets,
and each basket can store only one type.

Return the maximum number of fruits
you can collect continuously.

Example:
Input:
[1,2,1]

Output:
3

Example:
Input:
[0,1,2,2]

Output:
3

========================================================
Approach Used (Sliding Window with 2 Types):

Step 1:
Maintain two fruit types:
- a
- b

Step 2:
Track last occurrence:
- aLast
- bLast

Step 3:
If third fruit appears:
remove older fruit type
by moving left pointer

Step 4:
Track maximum window size

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int totalFruit(vector<int>& nums) {

        // Two fruit types
        int a = -1;
        int b = -1;

        // Sliding window
        int i = 0;
        int j = 0;

        // Maximum answer
        int sum = 0;

        // Last occurrence positions
        int aLast = -1;
        int bLast = -1;

        // ------------------------------
        // Sliding window traversal
        // ------------------------------
        while (j < nums.size()) {

            // Current fruit belongs to type a
            if (nums[j] == a) {

                aLast = j;
            }

            // Current fruit belongs to type b
            else if (nums[j] == b) {

                bLast = j;
            }

            // Third fruit type appears
            else {

                // Basket a empty
                if (a == -1) {

                    a = nums[j];

                    aLast = i;
                }

                // Basket b empty
                else if (b == -1) {

                    b = nums[j];

                    bLast = j;
                }

                // Replace older fruit type
                else {

                    int extra =
                        min(aLast, bLast);

                    // Shrink window
                    i = extra + 1;

                    // Replace fruit type
                    if (extra == aLast) {

                        a = nums[j];

                        aLast = j;
                    }

                    else {

                        b = nums[j];

                        bLast = j;
                    }
                }
            }

            // Maximum valid window
            sum = max(sum,
                      j - i + 1);

            j++;
        }

        return sum;
    }
};


int main() {

    vector<int> nums =
        {1,2,1,2,3,2,2};

    Solution obj;

    int result =
        obj.totalFruit(nums);

    cout << "Maximum Fruits Collected: "
         << result << endl;

    return 0;
}