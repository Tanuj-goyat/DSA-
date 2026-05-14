#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Maximum Points You Can Obtain from Cards
Platform: LeetCode (1423)
========================================================

Problem Statement:
You have several cards arranged in a row.

Each card has points.

You can take exactly k cards from:
- beginning
OR
- end

Return the maximum score possible.

Example:
Input:
cardPoints = [1,2,3,4,5,6,1]
k = 3

Output:
12

Explanation:
Take cards:
1 + 6 + 5 = 12

========================================================
Approach Used (Sliding Window):

Key Idea:
Instead of selecting k cards,
remove (n-k) consecutive cards
with minimum sum.

Answer:
totalSum - minimumWindowSum

Step 1:
Find sum of first (n-k) elements

Step 2:
Slide window and track minimum sum

Step 3:
Return total - minWindow

Time Complexity: O(n)
Space Complexity: O(1)

========================================================
*/

class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int sum = 0;
        int minSum = 0;
        int total = 0;

        // ------------------------------
        // First window of size (n-k)
        // ------------------------------
        for (int i = 0; i < n - k; i++) {

            sum += cardPoints[i];
        }

        minSum = sum;
        total = sum;

        int j = 0;

        // ------------------------------
        // Slide window
        // ------------------------------
        for (int i = n - k; i < n; i++) {

            // Remove left element
            sum -= cardPoints[j];

            // Add new element
            sum += cardPoints[i];

            // Total array sum
            total += cardPoints[i];

            j++;

            // Track minimum window sum
            minSum = min(sum, minSum);
        }

        // Maximum score
        return total - minSum;
    }
};


int main() {

    vector<int> cardPoints =
        {1,2,3,4,5,6,1};

    int k = 3;

    Solution obj;

    int result =
        obj.maxScore(cardPoints, k);

    cout << "Maximum Score: "
         << result << endl;

    return 0;
}