#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Factorial of Large Numbers
========================================================

Problem Statement:
Calculate factorial of a number n.

For large values of n (like 100 or 500),
the factorial becomes too large to store
in standard data types like int or long long.

Example:
100! has 158 digits.

So we store the number digit by digit
using a vector.

========================================================
Approach Used (Digit-by-Digit Multiplication):

1️⃣ Store digits of the number in reverse order
   inside a vector.

2️⃣ Start with factorial = 1.

3️⃣ Multiply the current factorial by numbers
   from 2 to n.

4️⃣ While multiplying:
   - Handle carry just like manual multiplication.

5️⃣ Store result digits back in the vector.

6️⃣ Finally print digits in reverse order.

Time Complexity: O(n × digits)
Space Complexity: O(digits)

========================================================
*/

int main()
{
    int n;

    cout << "Enter the value to find factorial: ";
    cin >> n;

    vector<int> v;

    // Initially factorial = 1
    v.push_back(1);

    // Multiply numbers from 2 to n
    for (int a = 2; a <= n; a++)
    {
        int carry = 0;

        // Multiply current number with each digit
        for (int i = 0; i < v.size(); i++)
        {
            int mul = (a * v[i]) + carry;

            v[i] = mul % 10;     // Store last digit
            carry = mul / 10;    // Remaining carry
        }

        // If carry remains, store extra digits
        while (carry != 0)
        {
            v.push_back(carry % 10);
            carry = carry / 10;
        }
    }

    cout << endl;
    cout << "Factorial = ";

    // Print digits in reverse (since stored reversed)
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
    }

    return 0;
}