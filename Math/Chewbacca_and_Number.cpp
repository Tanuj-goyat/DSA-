#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem: Chewbacca and Number
Platform: Codeforces (514A)
========================================================

Problem Statement:
Given a positive integer n.

Replace every digit d with:

9 - d

only if it makes the number smaller.

Rules:

- The first digit should never become 0.
- Therefore, if the first digit is 9,
  it must remain unchanged.

Print the smallest possible number.

Example:
Input:
4545

Output:
4444

========================================================
Approach Used (Greedy Digit Replacement)

Step 1:
Convert the number into a string.

Step 2:
Traverse every digit.

Step 3:
If the digit is greater than 4,
replace it with:

9 - digit

Step 4:
Do not change the first digit if it is 9,
otherwise the number would start with 0.

Step 5:
Convert the string back into an integer
and print it.

Time Complexity: O(d)
where d is the number of digits.

Space Complexity: O(d)

========================================================
*/

int main()
{
    long long n;

    cin >> n;

    string s = to_string(n);

    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - '0';

        if (i == 0 && num == 9)
            continue;


        if (num > 4 && num <= 9)
        {
            num = 9 - num;
        }

        s[i] = num + '0';
    }

    long long ans = stoll(s);

    cout << ans << endl;

    return 0;
}