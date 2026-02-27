/*
This program is to sort array (selection sort)

step 2: first find smallest number in arrar and then swap it with first element similarly then
find 2nd smallest number and thrn swap it with next element

step 1: time complexity of this in every case is n square so to reduce it first check whether
it is allready sorted or not this will reduce time complexity to 'n' in best case
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

    // step 1

    bool c = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            c = false;
            break;
        }
    }

    // step 2

    if (c == false)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int t = i;
            for (int j = i; j < n; j++)
            {
                if (v[j] < v[t]) 
                    t = j;
            }
            swap(v[i], v[t]);
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