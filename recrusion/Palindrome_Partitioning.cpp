#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem Name: Palindrome Partitioning
Platform: LeetCode
Problem Number: 131
========================================================

Problem Statement:
Given a string s, partition s such that every substring
of the partition is a palindrome.

Return all possible palindrome partitionings.

Example:
Input: s = "aab"

Output:
[
 ["a","a","b"],
 ["aa","b"]
]

========================================================
Approach (Backtracking)

At each index:
1️⃣ Try all possible substrings starting from that index
2️⃣ Check if substring is a palindrome
3️⃣ If yes:
   - Add it to current partition
   - Recurse for remaining string
4️⃣ Backtrack after recursion

Base Case:
If index reaches end → valid partition

========================================================
Time Complexity: O(n * 2^n)
Space Complexity: O(n)
========================================================
*/

class Solution {
public:

    // Check if substring s[start...end] is palindrome
    bool ispalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    // Backtracking function
    void f(vector<string> &v,
           vector<vector<string>> &ans,
           int index,
           string s) {

        // Base case: full string processed
        if(index >= s.size()) {
            ans.push_back(v);
            return;
        }

        // Try all partitions starting from index
        for(int i = index; i < s.size(); i++) {

            // Check if substring is palindrome
            if(ispalindrome(s, index, i)) {

                // Choose
                v.push_back(s.substr(index, i - index + 1));

                // Explore
                f(v, ans, i + 1, s);

                // Backtrack
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> v;
        vector<vector<string>> ans;

        f(v, ans, 0, s);

        return ans;
    }
};


int main() {

    string s = "aab";

    Solution obj;

    vector<vector<string>> result = obj.partition(s);

    cout << "Palindrome Partitions:\n";

    for(auto &vec : result) {
        cout << "[ ";
        for(auto &str : vec) {
            cout << str << " ";
        }
        cout << "]\n";
    }

    return 0;
}