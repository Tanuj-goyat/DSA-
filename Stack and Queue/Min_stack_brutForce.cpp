#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Min Stack
Platform: LeetCode (155)
========================================================

Problem Statement:
Design a stack that supports the
following operations:

1. push(value)
2. pop()
3. top()
4. getMin()

All operations must work in O(1) time.

========================================================
Approach Used (Store Value + Current Minimum)

Step 1:
For every pushed element, store:

- Current value
- Minimum value till this position

Step 2:
While pushing:

minimum =
min(current value,
previous minimum)

Step 3:
Top element is stored at:

st[last][0]

Step 4:
Current minimum is stored at:

st[last][1]

Thus every operation works in O(1).

Time Complexity:
Push   : O(1)
Pop    : O(1)
Top    : O(1)
GetMin : O(1)

Space Complexity: O(n)

========================================================
*/

class MinStack
{
public:
    int currSize = 0;

    int last = -1;

    vector<vector<int>> st;

    MinStack()
    {
    }

    void push(int value)
    {

        if (currSize == 0)
        {

            st.push_back({value, value});
        }

        else
        {

            st.push_back({value, min(value, st[last][1])});
        }

        last++;

        currSize++;
    }

    void pop()
    {

        st.pop_back();

        last--;

        currSize--;
    }

    int top()
    {

        return st[last][0];
    }

    int getMin()
    {

        return st[last][1];
    }
};

int main()
{

    MinStack obj;

    obj.push(5);

    obj.push(3);

    obj.push(7);

    cout << "Top : " << obj.top() << endl;

    cout << "Min : " << obj.getMin() << endl;

    obj.pop();

    cout << "Top : " << obj.top() << endl;

    cout << "Min : " << obj.getMin() << endl;

    return 0;
}