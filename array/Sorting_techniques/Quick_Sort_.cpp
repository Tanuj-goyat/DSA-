#include <iostream>
using namespace std;

/*
========================================================
Algorithm: Quick Sort
========================================================

Problem:
Sort an array using Quick Sort algorithm.

Example:
Input:
[4, 6, 2, 5, 7, 9, 1, 3]

Output:
[1, 2, 3, 4, 5, 6, 7, 9]

========================================================
Approach (Divide and Conquer)

Quick Sort works in three steps:

1️⃣ Choose a pivot element
   In this code → first element is pivot.

2️⃣ Partition the array
   Elements smaller than pivot go to the left,
   elements greater go to the right.

3️⃣ Recursively apply quick sort on
   left and right partitions.

========================================================
Time Complexity

Best Case:    O(n log n)
Average Case: O(n log n)
Worst Case:   O(n²)

Worst case occurs when array is already sorted
and pivot choice is poor.

========================================================
Space Complexity

O(log n) recursion stack (average)

========================================================
*/


// Quick Sort function
void qs(int arr[], int l, int h)
{
    // Base case: if subarray has 0 or 1 element
    if (h <= l)
    {
        return;
    }

    int pivot = arr[l];   // Choose first element as pivot

    int i = l;            // Left pointer
    int j = h;            // Right pointer

    // Partition process
    while (i < j)
    {
        // Move i until element greater than pivot
        while (arr[i] <= pivot && i < j)
            i++;

        // Move j until element smaller than or equal to pivot
        while (arr[j] > pivot && i < j)
            j--;

        // Swap misplaced elements
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in correct position
    swap(arr[l], arr[i - 1]);

    // Recursively sort left part
    qs(arr, l, i - 2);

    // Recursively sort right part
    qs(arr, i, h);
}


int main()
{
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Call quick sort
    qs(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}