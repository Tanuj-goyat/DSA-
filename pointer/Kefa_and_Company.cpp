#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Kefa and Company
Platform: Codeforces (580B)
========================================================

Problem Statement:
There are n friends.

Each friend has:
- money m
- friendship factor s

Choose a group of friends such that:

(maximum money - minimum money) < d

Find the maximum possible sum of
friendship factors.

Example:
Input:
4 5

75 5
0 100
150 20
75 1

Output:
106

========================================================
Approach Used (Sorting + Sliding Window)

Step 1:
Store:
[money, friendship factor]

Step 2:
Sort friends according to money.

Step 3:
Use a sliding window where:

money[right] - money[left] < d

Step 4:
Maintain sum of friendship factors
inside the current window.

Step 5:
Track maximum friendship factor sum.

Time Complexity: O(n log n)
Space Complexity: O(n)

========================================================
*/

int main()
{
    int numberOfFriends;
    int moneyDifference;

    cin >> numberOfFriends >> moneyDifference;

    vector<vector<int>> friendsData(
        numberOfFriends,
        vector<int>(2, 0));

    int totalFriendship = 0;

    // ------------------------------
    // Input money and friendship
    // ------------------------------
    for (int index = 0;
         index < numberOfFriends;
         index++)
    {
        int money;
        int friendshipFactor;

        cin >> money >> friendshipFactor;

        totalFriendship += friendshipFactor;

        friendsData[index][0] = money;
        friendsData[index][1] = friendshipFactor;
    }

    // ------------------------------
    // Sort by money
    // ------------------------------
    sort(friendsData.begin(),
         friendsData.end());

    int leftPointer = 0;

    int rightPointer = 0;

    long long currentFactor = 0;

    long long maximumFactor = 0;

    // ------------------------------
    // Sliding Window
    // ------------------------------
    while (rightPointer < numberOfFriends)
    {
        // Window is valid
        if (friendsData[rightPointer][0] -
                friendsData[leftPointer][0] <
            moneyDifference)
        {
            currentFactor +=
                friendsData[rightPointer][1];

            rightPointer++;
        }

        // Window becomes invalid
        else
        {
            currentFactor -=
                friendsData[leftPointer][1];

            if (leftPointer < rightPointer)
            {
                leftPointer++;
            }
            else
            {
                leftPointer++;
                rightPointer++;
            }
        }

        maximumFactor =
            max(maximumFactor,
                currentFactor);
    }

    cout << maximumFactor << endl;

    return 0;
}