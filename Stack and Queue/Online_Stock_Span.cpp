#include <bits/stdc++.h>
using namespace std;

/*
========================================================
Problem: Online Stock Span
Platform: LeetCode (901)
========================================================

Problem Statement:
Design a class StockSpanner that
supports the following operation:

next(price)

For each stock price, return the span.

Span =
Number of consecutive days (including
today) for which the stock price is
less than or equal to today's price.

Example:
Input:
100, 80, 60, 70, 60, 75, 85

Output:
1 1 1 2 1 4 6

========================================================
Approach Used (Monotonic Stack)

Step 1:
Store all stock prices in an array.

Step 2:
Maintain a monotonic decreasing stack
containing indices.

Step 3:
Remove all previous prices that are
less than or equal to the current price.

Step 4:
If the stack becomes empty,
the span is index + 1.

Otherwise,
the span is the difference between
the current index and the previous
greater price.

Time Complexity:
next() : O(1) amortized

Space Complexity: O(n)

========================================================
*/

class StockSpanner {
public:

    vector<int> arr;

    stack<int> st;

    int index = -1;

    // ------------------------------
    // Constructor
    // ------------------------------
    StockSpanner() {}

    // ------------------------------
    // Return stock span
    // ------------------------------
    int next(int price) {

        index++;

        arr.push_back(price);

        if (st.empty()) {

            st.push(0);

            return index + 1;
        }

        else if (arr[st.top()] > arr[index]) {

            int ans = index - st.top();

            st.push(index);

            return ans;
        }

        else {

            while (!st.empty() && arr[st.top()] <= arr[index]) {

                st.pop();
            }

            int ans = -1;

            if (st.empty()) {

                ans = index + 1;
            }

            else if (arr[st.top()] == arr[index]) {

                ans = index - st.top() + 1;
            }

            else if (arr[st.top()] > arr[index]) {

                ans = index - st.top();
            }

            st.push(index);

            return ans;
        }
    }
};


int main() {

    StockSpanner obj;

    cout << obj.next(100) << endl;
    cout << obj.next(80) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(70) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(75) << endl;
    cout << obj.next(85) << endl;

    return 0;
}