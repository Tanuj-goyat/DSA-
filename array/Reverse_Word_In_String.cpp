/*
This program is to reverse string and remove extra space
Level: medium
Qestion no. 151

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

#include <iostream>
#include <algorithm>
using namespace std;

 void f(string s)
{
    // step 1: to reverse whole string
    // step 2: to reverse words
    // step 3: to remove extra space from starting and ending
    // step 4: to remove extra space from between

    // step 1
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }

    // step 2

    int a = 0; // mark starting of word
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ' || i == s.size() - 1)
        {
            int start = a;
            int end = i - 1;
            if (i == s.size() - 1)
            {
                end = i;
            }
            while (start < end)
            {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            a = i + 1;
        }
    }

    // step 3

    int sp = 0; // Here sp denotes space
    while (s[sp] == ' ')
    {
        s.erase(s.begin() + sp);
    }
    for (int i = s.size() - 1;;)
    {
        if (s[i] == ' ')
        {
            s.erase(s.begin() + i);
            i = s.size() - 1;
        }
        else
            break;
    }

    // step 4

    int esp = 0; // Here esp denotes extra space
    while (esp < s.size() - 1)
    {
        if (s[esp] == ' ' && s[esp + 1] == ' ')
        {
            s.erase(s.begin() + esp);
        }
        else
            esp++;
    }
}

int main()
{
    string s = "  hello world  ";
    f(s);
    return 0;
}

// Time and space complexicity are O(n) and O(1)