#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem Name: Letter Combinations of a Phone Number
Platform: LeetCode 
Problem Number: 17
========================================================

Problem Statement:
Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number
could represent.

Mapping:
2 → abc
3 → def
4 → ghi
5 → jkl
6 → mno
7 → pqrs
8 → tuv
9 → wxyz

Example:
Input: digits = "23"

Output:
["ad","ae","af","bd","be","bf","cd","ce","cf"]

========================================================
Approach (Backtracking)

1️⃣ For each digit → get corresponding letters

2️⃣ Try all possible letters for current digit

3️⃣ Build string step-by-step

4️⃣ When length == digits length → store answer

========================================================
Time Complexity: O(4^n)
Space Complexity: O(n)
========================================================
*/

class Solution {
public:

    void solve(vector<string>& ans,
               vector<string>& map,
               string& s,
               string& digits,
               int index) {

        // Base case
        if (index == digits.size()) {
            if (!s.empty())   // avoid empty input case
                ans.push_back(s);
            return;
        }

        int num = digits[index] - '0';
        string letters = map[num];

        // Try all letters for current digit
        for (int i = 0; i < letters.size(); i++) {

            s.push_back(letters[i]);

            solve(ans, map, s, digits, index + 1);

            s.pop_back(); // backtrack
        }
    }


    vector<string> letterCombinations(string digits) {

        vector<string> map = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string s = "";

        // Edge case: empty input
        if (digits.empty()) return ans;

        solve(ans, map, s, digits, 0);

        return ans;
    }
};


int main() {

    string digits = "23";

    Solution obj;

    vector<string> result = obj.letterCombinations(digits);

    cout << "Combinations:\n";

    for (auto &str : result) {
        cout << str << " ";
    }

    return 0;
}