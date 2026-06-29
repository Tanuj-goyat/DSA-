#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
========================================================
Problem: Previous Smaller Element
Platform: GeeksforGeeks
========================================================

Problem Statement:
Given an array arr.

For every element, find the nearest
previous element that is strictly
smaller than it.

If no such element exists,
store -1.

Example:
Input:
arr = [4, 5, 2, 10, 8]

Output:
[-1, 4, -1, 2, 2]

========================================================
Approach Used (Monotonic Stack)

Step 1:
Traverse the array from left to right.

Step 2:
Maintain a monotonic increasing stack.

Step 3:
Remove all elements from the stack
that are greater than or equal to the
current element.

Step 4:
If the stack is empty,
answer is -1.

Otherwise,
top of the stack is the previous
smaller element.

Step 5:
Push the current element into the stack.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    vector<int> prevSmaller(vector<int>& arr) {

        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            if (st.empty()) {

                st.push(arr[i]);

                arr[i] = -1;
            }

            else if (st.top() < arr[i]) {

                int num = arr[i];

                arr[i] = st.top();

                st.push(num);
            }

            else if (st.top() >= arr[i]) {

                while (!st.empty() && st.top() >= arr[i]) {

                    st.pop();
                }

                if (!st.empty()) {

                    int num = arr[i];

                    arr[i] = st.top();

                    st.push(num);
                }

                else {

                    st.push(arr[i]);

                    arr[i] = -1;
                }
            }
        }

        return arr;
    }
};


int main() {

    vector<int> arr = {4, 5, 2, 10, 8};

    Solution obj;

    vector<int> answer = obj.prevSmaller(arr);

    for (int x : answer)
        cout << x << " ";

    cout << endl;

    return 0;
}