#include <iostream>
#include <vector>
#include <climits>
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
Approach Used (Encoded Minimum)

Step 1:
Maintain the current minimum element.

Step 2:
If a new value is greater than or equal
to the current minimum,
store it normally.

Step 3:
If the new value is smaller,
store an encoded value:

2 * value - minum

and update the minimum.

Step 4:
While popping:

- Normal value:
  simply remove it.

- Encoded value:
  restore the previous minimum using:

minum = 2 * minum - encodedValue

Step 5:
For top():

If stored value is encoded,
actual top element is minum.

Otherwise,
top is the stored value.

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

    int i = -1;

    vector<long long> st;

    long long minum = INT_MAX;

    MinStack() {}

    void push(int value)
    {

        if (currSize == 0)
        {

            st.push_back(value);

            minum = value;
        }

        else if (value >= minum)
        {

            st.push_back(value);
        }

        else
        {

            st.push_back((long long)2 * value - minum);

            minum = value;
        }

        currSize++;

        i++;
    }

    void pop()
    {

        if (currSize == 1)
        {

            st.pop_back();

            minum = INT_MAX;
        }

        else if (st[i] >= minum)
        {

            st.pop_back();
        }

        else
        {

            minum = 2 * minum - st[i];

            st.pop_back();
        }

        i--;

        currSize--;
    }

    int top()
    {

        return max(st[i], minum);
    }

    int getMin()
    {

        return minum;
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