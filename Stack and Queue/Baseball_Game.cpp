#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*
========================================================
Problem: Baseball Game
Platform: LeetCode (682)
========================================================

Problem Statement:
You are given a list of operations
representing scores in a baseball game.

Operations are:

- Integer : Record a new score.
- "+"     : Record the sum of the
            previous two scores.
- "D"     : Record double the previous
            score.
- "C"     : Remove the previous score.

Return the total score after
processing all operations.

Example:
Input:
["5","2","C","D","+"]

Output:
30

========================================================
Approach Used (Stack Simulation)

Step 1:
Use a stack to store all valid scores.

Step 2:
Process each operation:

- Integer:
  Push the score.

- "C":
  Remove the last valid score.

- "D":
  Push twice the previous score.

- "+":
  Push the sum of the previous
  two scores.

Step 3:
Maintain the running total while
processing the operations.

Step 4:
Return the final score.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution
{
public:
    int calPoints(vector<string> &s)
    {

        int n = s.size();

        stack<int> st;

        int score = 0;

        // ------------------------------
        // Process all operations
        // ------------------------------
        for (int i = 0; i < n; i++)
        {

            if (s[i] == "C")
            {

                score -= st.top();

                st.pop();
            }

            else if (s[i] == "D")
            {

                st.push(2 * st.top());

                score += st.top();
            }

            else if (s[i] == "+")
            {

                int a = st.top();

                st.pop();

                int b = st.top() + a;

                st.push(a);

                st.push(b);

                score += b;
            }

            else
            {

                int num = stoi(s[i]);

                st.push(num);

                score += num;
            }
        }

        return score;
    }
};

int main()
{

    vector<string> s = {"5", "2", "C", "D", "+"};

    Solution obj;

    int answer = obj.calPoints(s);

    cout << answer << endl;

    return 0;
}