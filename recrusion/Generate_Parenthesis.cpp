#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem Name: Generate Parentheses
Platform: LeetCode
Problem Number: 22
========================================================

Problem Statement:
Given n pairs of parentheses, generate all combinations
of well-formed parentheses.

Example:
Input: n = 3

Output:
[
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
]

========================================================
Approach (Backtracking)

At each step we have two choices:

1️⃣ Add '('
   → if count of '(' < n

2️⃣ Add ')'
   → if count of ')' < count of '('

Rules:
✔ Never allow invalid sequence (")(")
✔ Maintain balance

Base Case:
When string size == 2*n and valid → store result

========================================================
Time Complexity: O(2^n)
Space Complexity: O(n)
========================================================
*/

class Solution {
public:

    void f(int k,
           int count1,   // number of '(' used
           int count2,   // number of ')' used
           vector<string>& ans,
           string& s) {

        // Base case 
        if (s.size() >= 2 * k ) {
            ans.push_back(s);
            return;
        }

        // --------------------------------
        // 1️⃣ Add '('
        // --------------------------------
        if (count1 < k) {
            s.push_back('(');
            f(k, count1 + 1, count2, ans, s);
            s.pop_back();   // backtrack
        }

        // --------------------------------
        // 2️⃣ Add ')'
        // --------------------------------
        if (count2 < count1) {
            s.push_back(')');
            f(k, count1, count2 + 1, ans, s);
            s.pop_back();   // backtrack
        }
    }


    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string s;

        f(n, 0, 0, ans, s);

        return ans;
    }
};


int main() {

    int n = 3;

    Solution obj;

    vector<string> result = obj.generateParenthesis(n);

    cout << "Valid Parentheses:\n";

    for (auto &str : result) {
        cout << str << endl;
    }

    return 0;
}