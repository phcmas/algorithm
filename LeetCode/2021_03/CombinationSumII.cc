/* 40. Combination Sum II */
/** Given a collection of candidate numbers (candidates) and a target number (target), 
 *  find all unique combinations in candidates where the candidate numbers sum to target.
 *  Each number in candidates may only be used once in the combination.
 * 
 *  Note: The solution set must not contain duplicate combinations.
 * 
 *  Example 1:
 *  Input: candidates = [10,1,2,7,6,1,5], target = 8
 *  Output: 
 *  [
 *  [1,1,6],
 *  [1,2,5],
 *  [1,7],
 *  [2,6]
 *  ]
 * 
 *  Example 2:
 *  Input: candidates = [2,5,2,1,2], target = 5
 *  Output: 
 *  [
 *  [1,2,2],
 *  [5]
 *  ]
 * 
 *  Constraints:
 *  1 <= candidates.length <= 100
 *  1 <= candidates[i] <= 50
 *  1 <= target <= 30 **/

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
}

int main() {
    vector<int> candidate0 {10,1,2,7,6,1,5};
    vector<int> candidate1 {2,5,2,1,2};

    vector<vector<int>> ans0 = combinationSum2(candidate0, 8);
    vector<vector<int>> ans1 = combinationSum2(candidate1, 5);

    for (vector<int> iter0 : ans0) {
        cout << "[ ";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        }
        cout << "], ";
    } // [[1,1,6], [1,2,5], [1,7], [2,6]]

    for (vector<int> iter0 : ans1) {
        cout << "[ ";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        }
        cout << "], ";
    } // [[1,2,2], [5]]

    return 0;
}