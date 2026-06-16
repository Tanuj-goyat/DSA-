#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
========================================================
Problem: Registration System
Platform: Codeforces (4C)
========================================================

Problem Statement:
A registration system stores usernames.

For each new username:

1. If the username has not appeared before,
   print "OK".

2. Otherwise append the current count of
   that username and print the new name.

Example:
Input:
4

abacaba
acaba
abacaba
acab

Output:
OK
OK
abacaba1
OK

========================================================
Approach Used (Hash Map)

Step 1:
Use a hash map to store frequency
of each username.

Step 2:
If username is not present:
- Print "OK"
- Insert into map

Step 3:
Otherwise:
- Print username + frequency
- Increase frequency

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

int main() {

    // ------------------------------
    // Stores username frequencies
    // ------------------------------
    unordered_map<string, int> db;

    int n;

    cin >> n;

    // ------------------------------
    // Process all usernames
    // ------------------------------
    for (int x = 0; x < n; x++) {

        string s;

        cin >> s;

        // New username
        if (db.find(s) == db.end()) {

            cout << "OK" << endl;

            db[s]++;
        }

        // Username already exists
        else {

            cout << s
                 << db[s]
                 << endl;

            db[s]++;
        }
    }

    return 0;
}