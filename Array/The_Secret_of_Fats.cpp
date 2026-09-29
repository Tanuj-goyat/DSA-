/**
 * ============================================================================
 * Problem: The Secret of Fats
 * ============================================================================
 * 
 * Problem Statement:
 * Given the total number of carbon (c), hydrogen (h), and oxygen (o) atoms 
 * in a triglyceride molecule, determine if it is a Saturated or Unsaturated fat.
 * A saturated fat strictly satisfies the linear relationship: h = 2c - 4.
 * If h < 2c - 4, the molecule contains carbon-carbon double bonds and is 
 * therefore an unsaturated fat. (Oxygen is always 6 and valid data is guaranteed).
 * 
 * Approach Used: O(1) Mathematical Check
 * 1. Read the number of Carbon (c), Hydrogen (h), and Oxygen (o) atoms.
 * 2. Evaluate the given chemical degree of unsaturation formula.
 * 3. If `h < (2 * c) - 4`, output "Unsaturated".
 * 4. Otherwise, output "Saturated".
 * 
 * Complexity:
 * - Time Complexity: O(1) per test case -> A single arithmetic condition check.
 * - Space Complexity: O(1) -> Only primitive integer variables are allocated.
 * ============================================================================
 */

#include <iostream>

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    
    // Check if input exists to avoid hanging when running locally
    if (cin >> t) {
        for (; t > 0; t--)
        {
            int c, h, o;
            cin >> c >> h >> o;
            
            // If hydrogen count is less than the saturated standard, 
            // it contains double bonds (Unsaturated)
            if(h < (2 * c) - 4) {
                cout << "Unsaturated\n";
            } 
            // Otherwise, it fully satisfies the h = 2c - 4 rule (Saturated)
            else {
                cout << "Saturated\n";
            }
        }
    }
    
    return 0;
}