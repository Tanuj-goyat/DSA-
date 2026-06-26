#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem: Next Greater Element I
Platform: LeetCode (496)
========================================================

Problem Statement:
You are given two arrays:

nums1
nums2

nums1 is a subset of nums2.

For every element in nums1,
find the first greater element
appearing to its right in nums2.

If no such element exists,
return -1.

Example:
Input:
nums1 = [4,1,2]
nums2 = [1,3,4,2]

Output:
[-1,3,-1]

========================================================
Approach Used (Monotonic Stack)

Step 1:
Store the index of every element
of nums1 in a hash map.

Step 2:
Traverse nums2 from right to left.

Step 3:
Maintain a monotonic decreasing stack.

Step 4:
Whenever an element belongs to nums1,
its next greater element is the top
of the stack (if present).

Step 5:
Push the current element into the stack
after removing smaller elements.

Time Complexity: O(n + m)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    vector<int> nextGreaterElement(
        vector<int>& nums1,
        vector<int>& nums2) {

        unordered_map<int, int> m;

        // ------------------------------
        // Store indices of nums1
        // ------------------------------
        for (int i = 0;
             i < nums1.size();
             i++) {

            m[nums1[i]] = i;
        }

        vector<int> st;

        int top = -1;

        // ------------------------------
        // Traverse nums2 from right
        // ------------------------------
        for (int i = nums2.size() - 1;
             i >= 0;
             i--) {

            // Current element belongs
            // to nums1
            if (m.find(nums2[i]) !=
                m.end()) {

                int index =
                    m[nums2[i]];

                if (top == -1) {

                    nums1[index] = -1;
                }

                else {

                    if (nums2[i] <
                        st[top]) {

                        nums1[index] =
                            st[top];
                    }

                    else {

                        while (top >= 0 &&
                               nums2[i] >
                               st[top]) {

                            st.pop_back();

                            top--;
                        }

                        if (top >= 0) {

                            nums1[index] =
                                st[top];
                        }

                        else {

                            nums1[index] = -1;
                        }
                    }
                }
            }

            // --------------------------
            // Maintain monotonic stack
            // --------------------------
            if (top == -1) {

                st.push_back(nums2[i]);

                top++;
            }

            else {

                if (nums2[i] <
                    st[top]) {

                    st.push_back(nums2[i]);

                    top++;
                }

                else {

                    while (top >= 0 &&
                           nums2[i] >
                           st[top]) {

                        st.pop_back();

                        top--;
                    }

                    st.push_back(nums2[i]);

                    top++;
                }
            }
        }

        return nums1;
    }
};


int main() {

    vector<int> nums1 =
        {4, 1, 2};

    vector<int> nums2 =
        {1, 3, 4, 2};

    Solution obj;

    vector<int> answer =
        obj.nextGreaterElement(
            nums1,
            nums2);

    for (int x : answer)
        cout << x << " ";

    cout << endl;

    return 0;
}