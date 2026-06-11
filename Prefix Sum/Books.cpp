#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Books
Platform: Codeforces (279B)
========================================================

Problem Statement:
There are n books.

The i-th book takes time[i] minutes
to read.

You have only t minutes available.

Find the maximum number of consecutive
books that can be read completely.

Example:
Input:
4 5

3 1 2 1

Output:
3

Explanation:
Books:
1 + 2 + 1 = 4

So maximum consecutive books = 3

========================================================
Approach Used (Sliding Window)

Step 1:
Maintain a window using two pointers.

Step 2:
Keep track of total reading time
inside the current window.

Step 3:
If current book can be included
within available time, expand window.

Step 4:
Otherwise remove books from left side.

Step 5:
Track maximum valid window size.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

int main() {

    int numberOfBooks;
    int availableTime;

    cin >> numberOfBooks >> availableTime;

    vector<int> readingTime;

    // ------------------------------
    // Input reading times
    // ------------------------------
    for (int index = 0; index < numberOfBooks; index++) {

        int currentTime;

        cin >> currentTime;

        readingTime.push_back(currentTime);
    }

    int leftPointer = 0;

    int rightPointer = 0;

    int currentSum = 0;

    int maximumBooks = 0;

    // ------------------------------
    // Sliding Window
    // ------------------------------
    while (rightPointer < numberOfBooks) {

        int remainingTime =
            availableTime - currentSum;

        // Current book can be included
        if (readingTime[rightPointer] <= remainingTime) {

            currentSum += readingTime[rightPointer];

            maximumBooks =
                max(maximumBooks,
                    rightPointer - leftPointer + 1);

            rightPointer++;
        }

        // Window exceeds limit
        else {

            currentSum -= readingTime[leftPointer];

            leftPointer++;
        }
    }

    cout << endl
         << maximumBooks
         << endl;

    return 0;
}