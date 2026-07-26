#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

/*
========================================================
Problem: Smallest Subsequence of Distinct Characters
Platform: LeetCode (1081)
========================================================

Problem Statement:
Given a string s,
return the lexicographically smallest
subsequence that contains every
distinct character exactly once.

The relative order of the remaining
characters must be preserved.

Example:
Input:
s = "cbacdcbc"

Output:
"acdb"

========================================================
Approach Used (Monotonic Stack)

Step 1:
Store the last occurrence index of
every character.

Step 2:
Maintain a stack representing the
current subsequence.

Step 3:
If a character is already included in
the stack, skip it.

Step 4:
While the current character is smaller
than the top of the stack and the top
character appears again later,
remove the top character.

Step 5:
Push the current character into the
stack and mark it as taken.

Step 6:
Construct the answer by popping all
characters from the stack and
reversing the obtained string.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    string smallestSubsequence(string s) {

        int n = s.length();

        vector<int> lastSeen(26, 0);

        vector<bool> taken(26, false);

        // ------------------------------
        // Store last occurrence of each
        // character
        // ------------------------------
        for (int i = 0; i < n; i++) {

            int index = s[i] - 'a';

            lastSeen[index] = i;
        }

        stack<char> st;

        // ------------------------------
        // Build monotonic stack
        // ------------------------------
        for (int i = 0; i < n; i++) {

            int index = s[i] - 'a';

            if (st.empty()) {

                st.push(s[i]);

                taken[index] = true;
            }

            else if (st.top() < s[i]) {

                if (!taken[index]) {

                    st.push(s[i]);

                    taken[index] = true;
                }
            }

            else if (st.top() > s[i] && !taken[index]) {

                while (!st.empty() && st.top() > s[i] && lastSeen[st.top() - 'a'] > i) {

                    char ch = st.top();

                    taken[ch - 'a'] = false;

                    st.pop();
                }

                st.push(s[i]);

                taken[index] = true;
            }
        }

        string ans = "";

        // ------------------------------
        // Construct answer
        // ------------------------------
        while (!st.empty()) {

            ans += st.top();

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};


int main() {

    string s = "cbacdcbc";

    Solution obj;

    string answer = obj.smallestSubsequence(s);

    cout << answer << endl;

    return 0;
}