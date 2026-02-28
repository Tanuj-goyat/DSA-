#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Problem Name: Defanging an IP Address
Platform: LeetCode
Problem Number: 1108
========================================================

Problem Statement:
Given a valid IPv4 address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

Example:
Input:  "1.1.1.1"
Output: "1[.]1[.]1[.]1"

========================================================
Approach Used:

We traverse each character of the string:
- If the character is not '.', simply append it.
- If the character is '.', append "[.]" instead.

Time Complexity: O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:
    string defangIPaddr(string address) {
        
        string result;   // Stores the final defanged IP address
        
        // Traverse each character of the input string
        for(int i = 0; i < address.size(); i++) {
            
            // If character is not '.'
            if(address[i] != '.') {
                result.push_back(address[i]);   // Add character as it is
            }
            else {
                // Replace '.' with "[.]"
                result += "[.]";
            }
        }
        
        return result;   // Return modified string
    }
};


int main() {
    
    string address = "192.168.0.1";
    
    Solution obj;
    string result = obj.defangIPaddr(address);
    
    cout << "Defanged IP Address: " << result << endl;
    
    return 0;
}