#include <bits/stdc++.h>
using namespace std;

/*
========================================================
Problem: Remove K Digits
Platform: LeetCode (402)
========================================================

Problem Statement:
Given a non-negative integer represented
as a string nums and an integer k.

Remove exactly k digits so that the
remaining number is the smallest
possible.

Return the resulting number as a string.

Example:
Input:
nums = "1432219"
k = 3

Output:
"1219"

========================================================
Approach Used (Monotonic Stack)

Step 1:
Traverse each digit.

Step 2:
Maintain a monotonic increasing stack.

Step 3:
While the current digit is smaller
than the stack top and removals are
still allowed, remove the larger digit.

Step 4:
Push the current digit into the stack.

Step 5:
If removals are still left,
remove digits from the end.

Step 6:
Construct the answer from the stack,
remove leading zeros, and return
the result.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    string removeKdigits(string nums, int k) {

        stack<int> st;

        int i = 0;

        // ------------------------------
        // Build monotonic increasing stack
        // ------------------------------
        while (i < nums.size()) {

            if (st.empty()) {

                st.push(nums[i]);
            }

            else if (k > 0 && st.top() > nums[i]) {

                while (!st.empty() && k > 0 && st.top() > nums[i]) {

                    st.pop();

                    k--;
                }

                st.push(nums[i]);
            }

            else {

                st.push(nums[i]);
            }

            i++;
        }

        // ------------------------------
        // Remove remaining digits
        // ------------------------------
        while (!st.empty() && k > 0) {

            st.pop();

            k--;
        }

        string s = "";

        // ------------------------------
        // Build answer string
        // ------------------------------
        while (!st.empty()) {

            s += st.top();

            st.pop();
        }

        // ------------------------------
        // Remove leading zeros
        // (currently at the end because
        // string is reversed)
        // ------------------------------
        while (s.size() > 0 && s[s.size() - 1] == '0') {

            s.pop_back();
        }

        reverse(s.begin(), s.end());

        if (s == "")
            return "0";

        return s;
    }
};


int main() {

    string nums = "1432219";

    int k = 3;

    Solution obj;

    string answer = obj.removeKdigits(nums, k);

    cout << answer << endl;

    return 0;
}