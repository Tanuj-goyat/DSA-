#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
========================================================
Problem: Mirror Frequency Difference
Platform: LeetCode
Problem Number: 3889
========================================================

Problem Statement:
Given a string containing lowercase letters and digits,
calculate the total difference between frequencies of
mirror characters.

Mirror pairs:
Digits:
0 ↔ 9
1 ↔ 8
2 ↔ 7
3 ↔ 6
4 ↔ 5

Letters:
a ↔ z
b ↔ y
c ↔ x
...
m ↔ n

For each pair:
add |freq[left] - freq[right]|

========================================================
Approach (Frequency Counting)

1️⃣ Count frequency of:
   - digits (0–9)
   - letters (a–z)

2️⃣ For digits:
   compare i with (9 - i)

3️⃣ For letters:
   compare i with (25 - i)

4️⃣ Add absolute differences

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

class Solution {
public:
    int mirrorFrequency(string s) {

        // Edge case
        if (s.size() == 1)
            return 1;

        int ans = 0;

        vector<int> digit(10, 0);   // frequency of digits
        vector<int> letter(26, 0);  // frequency of letters

        // Step 1: Count frequency
        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= '0' && s[i] <= '9') {
                digit[s[i] - '0']++;
            }
            else {
                letter[s[i] - 'a']++;
            }
        }

        // Step 2: Compare digit mirrors
        for (int i = 0; i < 5; i++) {
            ans += abs(digit[i] - digit[9 - i]);
        }

        // Step 3: Compare letter mirrors
        for (int i = 0; i < 13; i++) {
            ans += abs(letter[i] - letter[25 - i]);
        }

        return ans;
    }
};


int main() {

    string s = "a1b2c3z9y8";

    Solution obj;

    cout << "Mirror Frequency Difference: "
         << obj.mirrorFrequency(s);

    return 0;
}