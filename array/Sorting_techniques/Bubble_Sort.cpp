/*
This is bubble short methord

In this first we compare first 2 elements of array then compare them if second element is
smaller then swap them and do this throught the full array now largest element is placed at its
correct position so, repeat this process n times such that all elements are placed at their
position


if u want to reduce time complexicity then u can also check it in starting if it is already
sorted or not
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // step 0: Take input from user of array

    vector<int> v;
    int n = 0;
    cout << "Enter the length of array" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th value of array ";
        int a = 0;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }

    // now print that vector

    cout << endl
         << "Sorted vector is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}