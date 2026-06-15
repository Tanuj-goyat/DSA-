#include <bits/stdc++.h>
using namespace std;

int main()
{
    string given;
    cin >> given;
    string word = "hello";
    int j = 0;
    for (int i = 0; i < given.size(); i++)
    {
        if (given[i] == word[j])
            j++;
        if (j > 4)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}