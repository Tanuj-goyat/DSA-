#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
Problem: Implement Stack using Array
Platform: LeetCode (225)
========================================================

Problem Statement:
Design a stack supporting the
following operations:

1. push(x)
2. pop()
3. top()
4. empty()

Implement the stack using the given
approach.

========================================================
Approach Used (Dynamic Array)

Step 1:
Use a vector to store stack elements.

Step 2:
Maintain:
- i   -> index of top element
- len -> current size of stack

Step 3:
For push():
Insert element at the end.

Step 4:
For pop():
Return and remove the last element.

Step 5:
For top():
Return the last inserted element.

Step 6:
For empty():
Return true if stack size is zero.

Time Complexity:
Push  : O(1)
Pop   : O(1)
Top   : O(1)
Empty : O(1)

Space Complexity: O(n)

========================================================
*/

class MyStack {
public:

    vector<int> v;

    int i = -1;

    int len = 0;

    MyStack() {

    }

    void push(int x) {

        v.push_back(x);

        i++;

        len++;
    }

    int pop() {

        int num = v[i];

        v.pop_back();

        i--;

        len--;

        return num;
    }


    int top() {

        return v[i];
    }


    bool empty() {

        if (len == 0)
            return true;

        return false;
    }
};


int main() {

    MyStack obj;

    obj.push(10);

    obj.push(20);

    obj.push(30);

    cout << "Top : " << obj.top() << endl;

    cout << "Pop : " << obj.pop() << endl;

    cout << "Top : " << obj.top() << endl;

    cout << "Empty : " << obj.empty() << endl;

    return 0;
}