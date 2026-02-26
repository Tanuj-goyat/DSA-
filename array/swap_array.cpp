// this program is to swap full array means first will last and last will first
#include <iostream>
using namespace std;

void change(int arr[], int n)
{
    int start = 0, i = 1;
    while (i <= n / 2)
    {
        swap(arr[start], arr[(start + 1)]);
        start = start + 2;
        i++;
    }
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    change(list, 9);
    printarr(list, 9);
    return 0;
}
