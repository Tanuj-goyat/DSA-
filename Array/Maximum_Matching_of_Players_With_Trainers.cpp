/**
 * ============================================================================
 * LeetCode 2410: Maximum Matching of Players With Trainers
 * ============================================================================
 *
 * Problem Statement:
 * You are given a 0-indexed integer array `players`, where `players[i]`
 * represents the ability of the ith player. You are also given a 0-indexed
 * integer array `trainers`, where `trainers[j]` represents the training
 * capacity of the jth trainer.
 *
 * A player can be matched with a trainer if the player's ability is less than
 * or equal to the trainer's capacity. Additionally, each player can be matched
 * with at most one trainer, and each trainer can be matched with at most one
 * player. Return the maximum number of matchings between players and trainers.
 *
 * Approach Used: Sorting + Greedy Two-Pointer
 * 1. Sort both the `players` (nums1) and `trainers` (nums2) arrays in
 *    ascending order.
 * 2. Use two pointers, `i` for players and `j` for trainers.
 * 3. Compare the current player's ability with the current trainer's capacity:
 *    - If `nums1[i] <= nums2[j]`: We found a valid match! Increment both
 *      pointers and the match count.
 *    - If `nums1[i] > nums2[j]`: The current trainer's capacity is too low
 *      for this player. We increment `j` to look for a stronger trainer.
 * 4. Stop when we run out of either players or trainers.
 *
 * Complexity:
 * - Time Complexity: O(N log N + M log M) -> Where N is the number of players
 *   and M is the number of trainers. The bottleneck is the sorting step.
 *   The two-pointer traversal takes only O(N + M) time.
 * - Space Complexity: O(1) auxiliary space -> Sorting might take O(log N)
 *   depending on the underlying implementation, but we use no extra data
 *   structures.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int count = 0;

        // Step 1: Sort both arrays to enable the greedy pairing strategy
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Step 2: Use two pointers to find valid matches
        while (i < n && j < m)
        {

            // If the trainer can handle this player, pair them up
            if (nums1[i] <= nums2[j])
            {
                i++;
                j++;
                count++;
            }
            // Otherwise, this trainer is too weak for the current player.
            // Move to the next trainer.
            else
            {
                j++;
            }
        }

        return count;
    }
};

// ---------------------------------------------------------
// Main function added for VS Code execution and testing
// ---------------------------------------------------------
int main()
{
    Solution solution;

    // Test Case 1: Standard match
    // Players: [4, 7, 9] -> Sorted: [4, 7, 9]
    // Trainers: [8, 2, 5, 8] -> Sorted: [2, 5, 8, 8]
    // Matches:
    // - Player 4 gets Trainer 5
    // - Player 7 gets Trainer 8
    // - Player 9 has no suitable trainer left
    vector<int> players1 = {4, 7, 9};
    vector<int> trainers1 = {8, 2, 5, 8};

    cout << "Test Case 1:" << endl;
    cout << "Players: [4, 7, 9], Trainers: [8, 2, 5, 8]" << endl;
    cout << "Maximum Matches: " << solution.matchPlayersAndTrainers(players1, trainers1) << endl;
    // Expected: 2

    cout << "-----------------------------------" << endl;

    // Test Case 2: All players matched
    // Players: [1, 1, 1]
    // Trainers: [10]
    // Only 1 player can be matched since there is only 1 trainer.
    vector<int> players2 = {1, 1, 1};
    vector<int> trainers2 = {10};

    cout << "Test Case 2:" << endl;
    cout << "Players: [1, 1, 1], Trainers: [10]" << endl;
    cout << "Maximum Matches: " << solution.matchPlayersAndTrainers(players2, trainers2) << endl;
    // Expected: 1

    cout << "-----------------------------------" << endl;

    // Test Case 3: Trainers are too weak
    // Players: [10, 20, 30]
    // Trainers: [5, 9]
    vector<int> players3 = {10, 20, 30};
    vector<int> trainers3 = {5, 9};

    cout << "Test Case 3:" << endl;
    cout << "Players: [10, 20, 30], Trainers: [5, 9]" << endl;
    cout << "Maximum Matches: " << solution.matchPlayersAndTrainers(players3, trainers3) << endl;
    // Expected: 0

    return 0;
}