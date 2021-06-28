/** 518. Coin Change 2 */
/** You are given an integer array coins representing coins of different denominations and an 
 *  integer amount representing a total amount of money.
 * 
 *  Return the number of combinations that make up that amount. If that amount of money cannot be 
 *  made up by any combination of the coins, return 0.
 * 
 *  You may assume that you have an infinite number of each kind of coin.
 *  The answer is guaranteed to fit into a signed 32-bit integer.
 * 
 *  Example 1:
 *  Input: amount = 5, coins = [1,2,5]
 *  Output: 4
 *  Explanation: there are four ways to make up the amount:
 *  5=5
 *  5=2+2+1
 *  5=2+1+1+1
 *  5=1+1+1+1+1
 * 
 *  Example 2:
 *  Input: amount = 3, coins = [2]
 *  Output: 0
 *  Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 *  Example 3:
 *  Input: amount = 10, coins = [10]
 *  Output: 1
 * 
 *  Constraints:
 *  1 <= coins.length <= 300
 *  1 <= coins[i] <= 5000
 *  All the values of coins are unique.
 *  0 <= amount <= 5000 */

function init(amount, coins, cache) {
    for (var i = 0; i < coins.length; ++i) {
        for (var j = 0; j <= amount; ++j) {
            cache[i][j] = 0;
        }
    }
}

var change = function(amount, coins) {
    let cache = Array.from(Array(coins.length), ()=> new Array(amount+1));
    let answer = 0;
    
    if (amount == 0) return 1;

    init(amount, coins, cache);
    coins.sort();

    for (let i = 0; i < coins.length; ++i) {
        if (coins[i] <= amount) cache[i][coins[i]] = 1;
    }

    for (let i = 1; i <= amount; ++i) {
        for (let m = 0; m < coins.length; ++m) {
            if (i < coins[m]) continue;
            for (let j = 0; j <= m; ++j) {
                cache[m][i] += cache[j][i-coins[m]];
            }

            if (i == amount) answer += cache[m][i];
        }
    }

    return answer;
};

var amount0 = 5;
var coins0 = [1,2,5];
var ans0 = change(amount0, coins0);

var amount1 = 3;
var coins1 = [2];
var ans1 = change(amount1, coins1);

var amount2 = 10;
var coins2 = [10];
var ans2 = change(amount2, coins2);

var amount3 = 0;
var coins3 = [7];
var ans3 = change(amount3, coins3);

var amount4 = 0;
var coins4 = [1,2];
var ans4 = change(amount4, coins4);

console.log(ans0); // 4
console.log(ans1); // 0
console.log(ans2); // 1
console.log(ans3); // 1

