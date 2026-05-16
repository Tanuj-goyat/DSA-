#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Sort an Array
Platform: LeetCode (912)
========================================================

Problem Statement:
Given an integer array nums,
sort the array in ascending order.

Example:
Input:
[5,2,3,1]

Output:
[1,2,3,5]

========================================================
Approach Used (Merge Sort):

Step 1:
Divide array into two halves

Step 2:
Recursively sort both halves

Step 3:
Merge sorted halves

Time Complexity: O(n log n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    // ------------------------------
    // Merge two sorted halves
    // ------------------------------
    void merge(vector<int>& arr,
               int start,
               int mid,
               int end) {

        // Left half pointer
        int i = start;

        // Right half pointer
        int j = mid + 1;

        // Temporary array
        vector<int> v;

        // ------------------------------
        // Compare both halves
        // ------------------------------
        while (i <= mid && j <= end) {

            if (arr[i] <= arr[j]) {

                v.push_back(arr[i]);

                i++;
            }

            else {

                v.push_back(arr[j]);

                j++;
            }
        }

        // ------------------------------
        // Remaining left half
        // ------------------------------
        while (i <= mid) {

            v.push_back(arr[i]);

            i++;
        }

        // ------------------------------
        // Remaining right half
        // ------------------------------
        while (j <= end) {

            v.push_back(arr[j]);

            j++;
        }

        // ------------------------------
        // Copy back to original array
        // ------------------------------
        int k = start;

        for (int x : v) {

            arr[k] = x;

            k++;
        }
    }


    // ------------------------------
    // Merge Sort function
    // ------------------------------
    void merge_sort(vector<int>& arr,
                    int n,
                    int start,
                    int end) {

        // Base case
        if (start >= end)
            return;

        int mid = start + (end - start) / 2;

        // ------------------------------
        // Sort left half
        // ------------------------------
        merge_sort(arr, n, start, mid);

        // ------------------------------
        // Sort right half
        // ------------------------------
        merge_sort(arr, n, mid + 1, end);

        // ------------------------------
        // Merge both halves
        // ------------------------------
        merge(arr, start, mid, end);
    }


    // ------------------------------
    // Main function
    // ------------------------------
    vector<int> sortArray(vector<int>& nums) {

        merge_sort(nums,
                   nums.size(),
                   0,
                   nums.size() - 1);

        return nums;
    }
};


int main() {

    vector<int> nums = {5,2,3,1};

    Solution obj;

    vector<int> result =
        obj.sortArray(nums);

    cout << "Sorted Array:\n";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}