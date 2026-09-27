/**
 * ============================================================================
 * LeetCode 1190: Reverse Substrings Between Each Pair of Parentheses
 * ============================================================================
 *
 * Problem Statement:
 * You are given a string s that consists of lower case English letters and
 * brackets. Reverse the strings in each pair of matching parentheses, starting
 * from the innermost one.
 * Your result should not contain any brackets.
 *
 * Approach Used: Stack with Index Mapping (In-Place Reversal)
 * 1. We iterate through the string and build the final answer in `result`.
 * 2. We use a variable `paranthesis` to count how many '(' and ')' we have
 *    encountered so far.
 * 3. When we hit '(':
 *    - The expression `i - paranthesis` calculates exactly how many non-bracket
 *      characters we have processed. This perfectly matches `result.size()`.
 *    - We push this mapped index onto the stack to remember where this
 *      bracket's inner string begins.
 * 4. When we hit ')':
 *    - We pop the start index from the stack.
 *    - We reverse everything in `result` from that start index to the end.
 * 5. Normal characters are simply appended to `result`.
 *
 * Complexity:
 * - Time Complexity: O(N^2) worst case -> If we have deeply nested brackets
 *   like "((((a))))", the reverse function is called multiple times on the
 *   same elements. However, since the string is modified in-place, this is
 *   highly efficient in practice and easily passes constraints.
 * - Space Complexity: O(N) -> To store the `result` string and the stack.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // Required for reverse()

using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> st;
        string result = "";
        int paranthesis = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                // (i - paranthesis) perfectly mimics result.size()
                st.push(i - paranthesis);
                paranthesis++;
            }
            else if (ch == ')')
            {
                // Reverse the segment of 'result' that corresponds to these brackets
                reverse(result.begin() + st.top(), result.end());
                st.pop();
                paranthesis++;
            }
            else
            {
                // Append standard characters to our growing result string
                result += ch;
            }
        }

        return result;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Single reversal
    // Reverse "abcd" -> "dcba"
    string s1 = "(abcd)";
    cout << "Test Case 1:" << endl;
    cout << "Input:  " << s1 << endl;
    cout << "Output: " << solution.reverseParentheses(s1) << endl;
    // Expected: "dcba"

    cout << "-----------------------------------" << endl;

    // Test Case 2: Nested reversal
    // 1st reverse: "love" -> "evol"
    // String state conceptually: (u evol i)
    // 2nd reverse: "u evol i" -> "i love u"
    string s2 = "(u(love)i)";
    cout << "Test Case 2:" << endl;
    cout << "Input:  " << s2 << endl;
    cout << "Output: " << solution.reverseParentheses(s2) << endl;
    // Expected: "iloveu"

    cout << "-----------------------------------" << endl;

    // Test Case 3: Deeply nested reversal
    string s3 = "(ed(et(oc))el)";
    cout << "Test Case 3:" << endl;
    cout << "Input:  " << s3 << endl;
    cout << "Output: " << solution.reverseParentheses(s3) << endl;
    // Expected: "leetcode"

    return 0;
}