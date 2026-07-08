#include<bits/stdc++.h>
using namespace std;

/*
========================================================
Problem: Way Too Long Words
Platform: Codeforces (71A)
========================================================

Problem Statement:
Given n words.

If a word has more than 10 characters,
replace it with:

first letter +
(number of characters between first
and last letter) +
last letter

Otherwise, print the word as it is.

Example:
Input:
4

word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis

Output:
word
l10n
i18n
p43s
*/

int main() {
    int n;
    cin >> n;
    for( ; n > 0; n--) {
        string s;
        cin >> s;
        if(s.size() <= 10) {
            cout << s << endl;
        }
        else {
            string num = to_string(s.size() - 2);
            cout << s[0] << num << s[s.size() - 1] << endl;
        }
    }
    return 0;
}