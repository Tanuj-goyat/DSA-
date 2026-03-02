#include <iostream>
using namespace std;

/*
========================================================
Problem: Book Allocation Problem
========================================================

Problem Statement:
Given an array where each element represents
number of pages in a book, and m students,

Allocate books such that:
- Each student gets at least one book
- Books are allocated in continuous order
- Minimize the maximum pages assigned to a student

Example:
Books = {10, 20, 30, 40}
Students = 2

Output: 60

Explanation:
Possible allocations:
[10,20,30] | [40] → max = 60  ✅ (minimum possible)

========================================================
Approach Used (Binary Search on Answer):

We apply binary search on the answer space:

Range:
start = 0
end = sum of all pages

For each mid:
Check if it is possible to allocate books
so that no student gets more than mid pages.

If possible:
    Try smaller value (end = mid - 1)
Else:
    Increase limit (start = mid + 1)

Time Complexity: O(n log(sum))
Space Complexity: O(1)

========================================================
*/


// Function to check if allocation is possible
bool ifpossible(int arr[], int m, int n, int mid)
{
    int pagesum = 0;   // Pages allocated to current student
    int student = 1;   // Start with first student

    for (int i = 0; i < n; i++)
    {
        // If adding this book does not exceed limit
        if (pagesum + arr[i] <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            // Assign new student
            student++;

            // If students exceed m OR
            // single book has more pages than mid
            if (student > m || arr[i] > mid)
            {
                return false;
            }

            pagesum = arr[i];  // Assign current book to new student
        }
    }

    return true;  // Allocation possible
}


int main()
{
    int m = 2;  // Number of students
    int n = 4;  // Number of books

    int arr[n] = {10, 20, 30, 40};

    int final = -1;

    // Calculate total pages
    int arrsum = 0;
    for (int i = 0; i < n; i++)
    {
        arrsum += arr[i];
    }

    int start = 0;
    int end = arrsum;

    // Binary search
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (ifpossible(arr, m, n, mid))
        {
            final = mid;      // Store possible answer
            end = mid - 1;    // Try to minimize further
        }
        else
        {
            start = mid + 1;  // Increase limit
        }
    }

    cout << "Minimum maximum pages: " << final << endl;

    return 0;
}