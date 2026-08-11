/**
 * ============================================================================
 * LeetCode 49: Group Anagrams
 * ============================================================================
 *
 * Problem Statement:
 * Given an array of strings `strs`, group the anagrams together. You can return
 * the answer in any order. An Anagram is a word or phrase formed by rearranging
 * the letters of a different word or phrase, typically using all the original
 * letters exactly once.
 *
 * Approach Used: Hash Map with Sorting
 * 1. Anagrams will always result in the exact same string when their characters
 *    are sorted (e.g., "eat" and "tea" both become "aet").
 * 2. We can use an unordered_map where the 'key' is the sorted version of the
 *    string, and the 'value' is a vector of the original strings that match it.
 * 3. We iterate through the input array once. For each string, we sort a copy
 *    of it to find its key, and then push the original string into the map.
 * 4. Finally, we iterate through the map and push all the grouped vectors
 *    into our final answer array.
 *
 * Complexity:
 * - Time Complexity: O(N * K log K) -> N is the number of strings, and K is the
 *   maximum length of a string. We iterate N times, and sorting each string
 *   takes O(K log K).
 * - Space Complexity: O(N * K) -> The unordered_map will store all N strings
 *   of length K.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // Required for sort()

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Map to group anagrams. Key: sorted string, Value: list of original strings
        unordered_map<string, vector<string>> mp;

        // Step 1: Iterate through each string in the given array
        for (string s : strs)
        {
            string key = s; // Make a copy to sort

            // Sort the copy to create a uniform key for all anagrams
            sort(key.begin(), key.end());

            // Group the original string under this sorted key
            mp[key].push_back(s);
        }

        // Step 2: Prepare the final 2D vector to return
        vector<vector<string>> ans;

        // Step 3: Extract the grouped anagrams from the map
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // Test case setup
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Execute the function
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // Output the result to the console
    cout << "Grouped Anagrams: " << endl;
    cout << "[" << endl;
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < result[i].size(); ++j)
        {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ",";
        cout << endl;
    }
    cout << "]" << endl;

    return 0;
}