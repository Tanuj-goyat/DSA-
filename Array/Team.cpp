#include <iostream>
using namespace std;

/*
========================================================
Problem: Team
Platform: Codeforces (231A)
========================================================

Problem Statement:
There are n problems.

For each problem, three friends decide
whether they are confident enough to
solve it.

Each friend gives:

1 -> Confident
0 -> Not Confident

If at least two friends are confident,
they will solve that problem.

Determine how many problems they will
solve.

Example:
Input:
3
1 1 0
1 0 0
1 1 1

Output:
2

========================================================
Approach Used (Counting)

Step 1:
Read the number of problems.

Step 2:
For every problem,
count how many friends answered 1.

Step 3:
If the count is at least 2,
increase the final answer.

Step 4:
Print the total number of problems
that the team will solve.

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

int main() {

    int n;

    cin >> n;

    int count = 0;

    // ------------------------------
    // Process all problems
    // ------------------------------
    for (int i = 0; i < n; i++) {

        int correct = 0;

        // ------------------------------
        // Count confident friends
        // ------------------------------
        for (int i = 0; i < 3; i++) {

            int num;

            cin >> num;

            if (num == 1) {

                correct++;
            }
        }

        // ------------------------------
        // Check if problem will be solved
        // ------------------------------
        if (correct >= 2) {

            count++;
        }
    }

    // ------------------------------
    // Print final answer
    // ------------------------------
    cout << count << endl;

    return 0;
}