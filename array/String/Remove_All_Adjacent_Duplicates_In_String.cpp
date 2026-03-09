#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem Name: Remove All Adjacent Duplicates In String
Platform: LeetCode
Problem Number: 1047
========================================================

Problem Statement: 
Given a string s, repeatedly remove adjacent duplicate 
characters until no more duplicates remain.

Return the final string.

Example:
Input:  "abbaca"
Output: "ca"

Explanation:
"abbaca"
 → remove "bb" → "aaca"
 → remove "aa" → "ca"

========================================================
Approach Used (In-place Removal):

We iterate through the string using index i:

1. If s[i] == s[i+1], remove both characters using erase().
2. After removal:
   - If i is not 0, move one step back (i--)
     because new adjacent duplicates might form.
3. Otherwise, move forward (i++).

We continue until no adjacent duplicates exist.

Time Complexity:
Worst case O(n²) because erase() shifts characters.

Space Complexity:
O(1) extra space (modifying string in-place).

========================================================
*/

class Solution {
public:
    string removeDuplicates(string s) {
        
        int i = 0;
        
        // Traverse while next character exists
        while (i + 1 < s.size()) {
            
            // If two adjacent characters are equal
            if (s[i] == s[i + 1]) {
                
                // Remove both characters
                s.erase(i, 2);
                
                // Step back to re-check for new duplicates
                if (i != 0) {
                    i--;
                }
            }
            else {
                // Move forward if no duplicate
                i++;
            }
        }
        
        return s;
    }
};


int main() {
    
    string s = "abbaca";
    
    Solution obj;
    string result = obj.removeDuplicates(s);
    
    cout << "Final string: " << result << endl;
    
    return 0;
}