#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem: Valid Parentheses
Platform: LeetCode (20)
========================================================

Problem Statement:
Given a string containing only:

'(' , ')' , '{' , '}' , '[' , ']'

Determine whether the input string
contains valid parentheses.

A string is valid if:

1. Every opening bracket has a
   corresponding closing bracket.

2. Brackets are closed in the
   correct order.

Example:
Input:
"()[]{}"

Output:
true

Example:
Input:
"([)]"

Output:
false

========================================================
Approach Used (Stack)

Step 1:
Traverse the string.

Step 2:
Push every opening bracket
into the stack.

Step 3:
For every closing bracket,
check the top element of stack.

Step 4:
If brackets match,
remove the opening bracket.

Step 5:
At the end,
stack must be empty.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    bool isValid(string s) {

        // Stack to store opening brackets
        vector<int> stack;

        int top = -1;

        // ------------------------------
        // Traverse string
        // ------------------------------
        for (int i = 0; i < s.size(); i++) {

            // Opening bracket
            if (s[i] == '(' ||
                s[i] == '{' ||
                s[i] == '[') {

                stack.push_back(s[i]);

                top++;
            }

            // Closing bracket
            else {

                // No matching opening bracket
                if (top == -1)
                    return false;

                // Match ()
                if (s[i] == ')' &&
                    stack[top] == '(') {

                    stack.pop_back();

                    top--;
                }

                // Match []
                else if (s[i] == ']' &&
                         stack[top] == '[') {

                    stack.pop_back();

                    top--;
                }

                // Match {}
                else if (s[i] == '}' &&
                         stack[top] == '{') {

                    stack.pop_back();

                    top--;
                }

                // Invalid match
                else
                    return false;
            }
        }

        // Stack should be empty
        if (top == -1)
            return true;

        return false;
    }
};


int main() {

    string s = "()[]{}";

    Solution obj;

    bool result = obj.isValid(s);

    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}