#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Algorithm: Merge Sort
========================================================

Problem Statement:
Sort an array using Merge Sort algorithm.

Example:
Input:
[564, 44, 8, 464, 684, 684, 874, 1, 5, 87, 5641, 87, 4, 87, 56]

Output:
[1, 4, 5, 8, 44, 56, 87, 87, 87, 464, 564, 684, 684, 874, 5641]

========================================================
Approach Used (Divide and Conquer)

Merge Sort works in three steps:

1️⃣ Divide
Split the array into two halves recursively
until each subarray contains only one element.

2️⃣ Conquer
Sort the smaller subarrays recursively.

3️⃣ Merge
Merge two sorted subarrays into one sorted array.

========================================================
Time Complexity:
Best Case:   O(n log n)
Average Case: O(n log n)
Worst Case:  O(n log n)

Space Complexity:
O(n) extra space for temporary array.

========================================================
*/


// Function to merge two sorted halves of the array
void merge(int arr[], int start, int mid, int end)
{
    int i = start;     // pointer for left subarray
    int j = mid + 1;   // pointer for right subarray

    vector<int> v;     // temporary array to store merged elements

    // Compare elements from both halves
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            v.push_back(arr[i]);
            i++;
        }
        else
        {
            v.push_back(arr[j]);
            j++;
        }
    }

    // Add remaining elements from left half
    while (i <= mid)
    {
        v.push_back(arr[i]);
        i++;
    }

    // Add remaining elements from right half
    while (j <= end)
    {
        v.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    int k = start;
    for (int x : v)
    {
        arr[k] = x;
        k++;
    }
}


// Recursive merge sort function
void merge_sort(int arr[], int n, int start, int end)
{
    // Base case: single element
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    // Sort left half
    merge_sort(arr, n, start, mid);

    // Sort right half
    merge_sort(arr, n, mid + 1, end);

    // Merge sorted halves
    merge(arr, start, mid, end);
}


int main()
{
    int arr[] = {564, 44, 8, 464, 684, 684, 874, 1, 5, 87, 5641, 87, 4, 87, 56};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Call merge sort
    merge_sort(arr, n, 0, n - 1);

    cout << "Sorted Array: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}