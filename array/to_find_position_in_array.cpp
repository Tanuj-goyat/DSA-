/*
  this program is to find index of given number in array if noty print -1

  input: 12
  output: 2

  input: 17
  output: -1
*/

#include <iostream>
using namespace std;

int point(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[n - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start;
}

int index(int arr[], int n, int key, int point)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    if (key > arr[n - 1])
    {
        end = point - 1;
    }
    else
    {
        start = point;
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key == arr[mid])
        {
            ans = mid;
            break;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n = 5, key;
    int arr[n] = {5, 1, 12, 3, 4};
    cout << "Enter the number to find :" << endl;
    cin >> key;
    int x = point(arr, n);
    int final = index(arr, n, key, x);
    cout << "Index of that number is :" << final;

    return 0;
}