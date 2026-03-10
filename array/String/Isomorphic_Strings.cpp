#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
========================================================
Problem Name: Isomorphic Strings
Platform: LeetCode
Problem Number: 205
========================================================

Problem Statement:
Two strings s and t are isomorphic if the characters in s
can be replaced to get t.

Rules:
1️⃣ Every character in s must map to exactly one character in t.
2️⃣ No two characters in s can map to the same character in t.
3️⃣ The order must be preserved.

Example:

Input:
s = "egg"
t = "add"

Output:
true

Explanation:
e → a
g → d

Mapping is consistent.

--------------------------------------------------------

Input:
s = "foo"
t = "bar"

Output:
false

Because:
o → r and o → a (inconsistent mapping)

========================================================
Approach (Two Hash Maps)

We maintain two maps:

1️⃣ map1 : s → t
2️⃣ map2 : t → s

Why two maps?

Because mapping must be one-to-one.

Example of invalid case:
s = "ab"
t = "aa"

If we only check s → t:
a → a
b → a (looks valid)

But this breaks the rule because
two characters map to the same character.

So we also check t → s.

========================================================
Time Complexity: O(n)
Space Complexity: O(1) (since alphabet size is limited)
========================================================
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> m1; // mapping s → t
        unordered_map<char, char> m2; // mapping t → s

        for(int i = 0; i < s.size(); i++) {

            // Check mapping from s → t
            if(m1.find(s[i]) == m1.end()) {
                m1[s[i]] = t[i];
            }
            else if(m1[s[i]] != t[i]) {
                return false;
            }

            // Check mapping from t → s
            if(m2.find(t[i]) == m2.end()) {
                m2[t[i]] = s[i];
            }
            else if(m2[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "egg";
    string t = "add";

    if(obj.isIsomorphic(s, t))
        cout << "Strings are Isomorphic";
    else
        cout << "Strings are NOT Isomorphic";

    return 0;
}