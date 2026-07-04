#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Asteroid Collision
Platform: LeetCode (735)
========================================================

Problem Statement:
Given an array nums representing
asteroids.

Positive value  -> Moving right
Negative value  -> Moving left

When two asteroids moving in opposite
directions collide:

- Smaller one explodes.
- If both have equal size,
  both explode.

Return the state of asteroids after
all collisions.

Example:
Input:
nums = [5,10,-5]

Output:
[5,10]

========================================================
Approach Used (Stack Simulation)

Step 1:
Traverse the asteroid array.

Step 2:
Push every asteroid into the stack.

Step 3:
A collision is possible only when:

Current asteroid < 0
Stack top > 0

Step 4:
Remove all smaller positive asteroids.

Step 5:
Handle:
- Equal size (both destroyed)
- Larger positive asteroid survives
- Negative asteroid survives

Step 6:
Extract the remaining asteroids from
the stack.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:

    vector<int> asteroidCollision(vector<int>& nums) {

        int n = nums.size();

        stack<int> st;

        // ------------------------------
        // Process every asteroid
        // ------------------------------
        for (int i = 0; i < n; i++) {

            if (st.empty()) {

                st.push(nums[i]);
            }

            // Collision case
            else if (nums[i] < 0 && st.top() > 0) {

                while (!st.empty() && st.top() > 0 && st.top() < abs(nums[i])) {

                    st.pop();
                }

                if (st.empty()) {

                    st.push(nums[i]);
                }

                else if (st.top() == abs(nums[i])) {

                    st.pop();
                }

                else if (st.top() < 0) {

                    st.push(nums[i]);
                }
            }

            // No collision
            else {

                st.push(nums[i]);
            }
        }

        vector<int> v;

        // ------------------------------
        // Store remaining asteroids
        // ------------------------------
        while (!st.empty()) {

            v.push_back(st.top());

            st.pop();
        }

        reverse(v.begin(), v.end());

        return v;
    }
};


int main() {

    vector<int> nums = {5, 10, -5};

    Solution obj;

    vector<int> answer = obj.asteroidCollision(nums);

    for (int x : answer)
        cout << x << " ";

    cout << endl;

    return 0;
}