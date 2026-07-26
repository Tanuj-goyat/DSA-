#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
========================================================
Problem: Aggregate Time Series
Platform: LeetCode 4001
========================================================

Problem Statement:
You are given two time series:

s1
s2

Each entry contains:

[timestamp, value]

Merge both time series by timestamp.

If a timestamp appears in both series,
add their values together.

Return the merged time series sorted
by timestamp.

========================================================
Approach Used (Two Pointers + Hash Map)

Step 1:
Traverse both sorted time series
simultaneously using two pointers.

Step 2:
If timestamps are equal,
add both values to the hash map.

Step 3:
Otherwise,
process the smaller timestamp and
move its corresponding pointer.

Step 4:
Process any remaining elements from
either series.

Step 5:
Transfer all entries from the hash map
to a vector.

Step 6:
Sort the result by timestamp and
return it.

Time Complexity: O((n + m) log(n + m))
Space Complexity: O(n + m)

========================================================
*/

class Solution
{
public:
    vector<vector<int>> aggregateTimeSeries(
        vector<vector<int>> &s1,
        vector<vector<int>> &s2)
    {

        unordered_map<int, int> m;

        int i = 0;

        int j = 0;

        // ------------------------------
        // Merge both time series
        // ------------------------------
        while (i < s1.size() && j < s2.size())
        {

            if (s1[i][0] == s2[j][0])
            {

                m[s1[i][0]] += (s1[i][1] + s2[j][1]);

                i++;
                j++;
            }

            else if (s1[i][0] < s2[j][0])
            {

                m[s1[i][0]] += (s1[i][1] + s2[j][1]);

                i++;
            }

            else
            {

                m[s2[j][0]] += (s1[i][1] + s2[j][1]);

                j++;
            }
        }

        // ------------------------------
        // Process remaining elements
        // from s1
        // ------------------------------
        while (i < s1.size())
        {

            m[s1[i][0]] += s1[i][1];

            i++;
        }

        // ------------------------------
        // Process remaining elements
        // from s2
        // ------------------------------
        while (j < s2.size())
        {

            m[s2[j][0]] += s2[j][1];

            j++;
        }

        vector<vector<int>> ans;

        // ------------------------------
        // Store result
        // ------------------------------
        for (auto x : m)
        {

            int a = x.first;

            int b = x.second;

            ans.push_back({a, b});
        }

        // ------------------------------
        // Sort by timestamp
        // ------------------------------
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    vector<vector<int>> s1 = {{1, 2}, {3, 4}, {5, 6}};

    vector<vector<int>> s2 = {{1, 5}, {2, 3}, {5, 1}};

    Solution obj;

    vector<vector<int>> answer = obj.aggregateTimeSeries(s1, s2);

    for (auto &row : answer)
    {

        cout << row[0] << " " << row[1] << endl;
    }

    return 0;
}