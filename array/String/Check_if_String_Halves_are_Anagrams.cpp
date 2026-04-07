#include <bits/stdc++.h>
using namespace std;

/*
========================================================
Problem: Check if String Halves are Anagrams
Platform: Custom / Interview Problem
========================================================

Problem Statement:
Given a string, check whether the first half and second
half of the string are anagrams of each other.

Rules:
- If length is odd → ignore the middle character
- Return "YES" if both halves match
- Else return "NO"

========================================================
Approach (Frequency Count)

1️⃣ Count frequency of characters in first half

2️⃣ Subtract frequency using second half

3️⃣ If all values become 0 → valid anagram

========================================================
Time Complexity: O(n)
Space Complexity: O(1)
========================================================
*/

int main() {

    int T;
    cin >> T;

    while (T--) {

        string str;
        cin >> str;

        // Frequency array for 26 letters
        vector<int> v(26, 0);

        int n = str.size();

        // First half end index
        int first = n / 2 - 1;

        // Count first half
        for (int i = 0; i <= first; i++) {
            v[str[i] - 'a']++;
        }

        // Second half start index
        int second = n / 2;

        // If odd length → skip middle character
        if (n % 2 != 0)
            second++;

        // Subtract second half
        for (int i = second; i < n; i++) {
            v[str[i] - 'a']--;
        }

        // Check if all frequencies are zero
        bool flag = true;

        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}