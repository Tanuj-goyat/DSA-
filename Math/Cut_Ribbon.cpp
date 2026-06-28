#include <bits/stdc++.h>
using namespace std;

/*
========================================================
Problem: Cut Ribbon 
Platform: Codeforces (189A)
========================================================

Problem Statement:
A ribbon of length n is given.

You can cut the ribbon into pieces of
length:

a, b, or c

Find the maximum number of pieces that
can be obtained such that the entire
ribbon is used.

Example:
Input:
5 5 3 2

Output:
2

Explanation:
5 = 3 + 2

Total pieces = 2
*/

//  ax + by + cz = n

int varify(int n, int a, int b, int c, int y, int z)
{
    int x = (n - c * z - b * y) / a;
    if (a * x + b * y + c * z == n)
        return x;
    return -1;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (b > a)
        swap(a, b);
    if (c > a)
        swap(a, c);
    if (c > b)
        swap(b, c);
    int ans = 0;
    for (int z = n / c; z >= 0; z--)
    {
        for (int y = (n - c * z) / b; y >= 0; y--)
        {
            int x = varify(n, a, b, c, y, z);
            if (x != -1)
            {
                ans = max(ans, x + y + z);
            }
        }
    }
    cout << ans << endl;
    return 0;
}