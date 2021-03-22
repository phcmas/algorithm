/* 378. Kth Smallest Element in a Sorted Matrix */
/** Given an n x n matrix where each of the rows and columns are sorted in ascending order, 
 *  return the kth smallest element in the matrix.
 *  
 *  Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * 
 *  Example 1:
 *  Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 *  Output: 13
 *  Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
 * 
 *  Example 2:
 *  Input: matrix = [[-5]], k = 1
 *  Output: -5
 * 
 *  Constraints:
 *  n == matrix.length
 *  n == matrix[i].length
 *  1 <= n <= 300
 *  -10^9 <= matrix[i][j] <= -10^9
 *  All the rows and columns of matrix are guaranteed to be sorted in non-degreasing order.
 *  1 <= k <= n^2 **/

#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

bool seen[300][300];
int dr[4] ={};
int dc[4] ={};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int order = 0;
    queue<int> q;
    priority_queue<int> pq;

    memset(seen, 0, sizeof(seen));
    q.push(matrix[0][0]);
    pq.push(matrix[0][0]);
    while (!q.empty()) {
        int num = q.front();
        q.pop();



    }

}

int main() {
    vector<int> row00 {1,5,9};
    vector<int> row01 {10,11,13};
    vector<int> row02 {12,13,15};
    vector<vector<int>> matrix0 {row00, row01, row02};

    vector<int> row10 {-5};
    vector<vector<int>> matrix1 {row10};

    int ans0 = kthSmallest(matrix0, 8);
    int ans1 = kthSmallest(matrix1, 1);

    cout << ans0 << endl; // 13
    cout << ans1 << endl; // -5

    return 0;
}
