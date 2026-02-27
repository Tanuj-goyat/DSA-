// INSERTION SORT

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

    for (int i = 1; i < n; i++)
    {
        int temp = v[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j] <= temp)
            {
                v[j + 1] = temp;
                break;
            }
            else
            {
                v[j + 1] = v[j];
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