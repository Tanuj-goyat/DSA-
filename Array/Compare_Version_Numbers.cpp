#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Compare Version Numbers
Platform: LeetCode (165)
========================================================

Problem Statement:
Given two version strings:

version1
version2

Compare them revision by revision.

Rules:

- Revisions are separated by '.'
- Leading zeros should be ignored
- Return:

  1  -> version1 > version2
 -1  -> version1 < version2
  0  -> version1 == version2

Example:
Input:
version1 = "1.01"
version2 = "1.001"

Output:
0

Example:
Input:
version1 = "1.0"
version2 = "1.0.0"

Output:
0

========================================================
Approach Used (Two Pointers + String Parsing)

Step 1:
Traverse both version strings
simultaneously.

Step 2:
Extract one revision from each
version string.

Step 3:
Convert revisions into integers.

Step 4:
Compare current revisions.

Step 5:
If unequal, return answer.

Step 6:
If all revisions are equal,
return 0.

Time Complexity: O(n + m)
Space Complexity: O(n + m)

========================================================
*/

class Solution {
public:

    int compareVersion(string version1,
                       string version2) {

        int i1 = 0;

        int i2 = 0;

        string s1 = "";

        string s2 = "";

        // ------------------------------
        // Traverse both version strings
        // ------------------------------
        while (i1 < version1.size() ||
               i2 < version2.size()) {

            if (i1 < version1.size() &&
                version1[i1] != '.') {

                s1.push_back(version1[i1]);

                i1++;
            }

            if (i2 < version2.size() &&
                version2[i2] != '.') {

                s2.push_back(version2[i2]);

                i2++;
            }

            bool end1 =
                (i1 >= version1.size() ||
                 version1[i1] == '.');

            bool end2 =
                (i2 >= version2.size() ||
                 version2[i2] == '.');

            // --------------------------
            // Compare current revisions
            // --------------------------
            if (end1 && end2) {

                int num1 = 0;

                int num2 = 0;

                if (s1 != "")
                    num1 = stoi(s1);

                if (s2 != "")
                    num2 = stoi(s2);

                if (num1 < num2)
                    return -1;

                else if (num1 > num2)
                    return 1;

                s1 = "";

                s2 = "";

                i1++;

                i2++;
            }
        }

        // ------------------------------
        // Compare any remaining revision
        // ------------------------------
        int num1 = 0;

        int num2 = 0;

        if (s1 != "")
            num1 = stoi(s1);

        if (s2 != "")
            num2 = stoi(s2);

        if (num1 < num2)
            return -1;

        else if (num1 > num2)
            return 1;

        return 0;
    }
};


int main() {

    string version1 = "1.01";

    string version2 = "1.001";

    Solution obj;

    int answer =
        obj.compareVersion(version1,
                           version2);

    cout << answer << endl;

    return 0;
}