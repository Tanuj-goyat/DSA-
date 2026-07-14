#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Simplify Path
Platform: LeetCode (71)
========================================================

Problem Statement:
Given an absolute Unix-style file path.

Simplify the path according to the
following rules:

1. "." represents the current directory.
2. ".." moves to the parent directory.
3. Multiple '/' are treated as a single
   '/'.
4. The returned path should be in its
   canonical form.

Example:
Input:
"/home//foo/"

Output:
"/home/foo"

========================================================
Approach Used (Stack)

Step 1:
Split the path into directory names.

Step 2:
Ignore empty directory names caused
by multiple '/'.

Step 3:
Traverse each directory:

- ".." : Remove the previous directory.
- "."  : Ignore.
- Otherwise push the directory into
  the stack.

Step 4:
Store the remaining directories.

Step 5:
Construct the canonical path.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    string simplifyPath(string path) {

        int n = path.size();

        vector<string> vs;

        string s = "";

        // ------------------------------
        // Split path into directories
        // ------------------------------
        for (int i = 0; i < n; i++) {

            if (path[i] == '/') {

                if (s.size() > 0)
                    vs.push_back(s);

                s = "";
            }

            else {

                s += path[i];
            }
        }

        if (s.size() > 0)
            vs.push_back(s);

        stack<string> st;

        // ------------------------------
        // Process each directory
        // ------------------------------
        for (int i = 0; i < vs.size(); i++) {

            if (vs[i] == "..") {

                if (!st.empty()) {

                    st.pop();
                }
            }

            else if (vs[i] != ".") {

                st.push(vs[i]);
            }
        }

        int len = 0;

        // ------------------------------
        // Store stack contents
        // ------------------------------
        while (!st.empty()) {

            vs[len] = st.top();

            st.pop();

            len++;
        }

        reverse(vs.begin(), vs.begin() + len);

        string ans = "/";

        // ------------------------------
        // Build simplified path
        // ------------------------------
        for (int i = 0; i < len; i++) {

            ans += vs[i];

            ans += "/";
        }

        if (ans.size() > 1)
            ans.pop_back();

        return ans;
    }
};


int main() {

    string path = "/home//foo/../bar/./";

    Solution obj;

    string answer = obj.simplifyPath(path);

    cout << answer << endl;

    return 0;
}