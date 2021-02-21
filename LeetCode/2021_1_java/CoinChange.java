/* 322. Coin Change */
/** You are given coins of different denominations and a total amount of money amount. 
 *  Write a function to compute the fewest number of coins that you need to make up that amount. 
 *  If that amount of money cannot be made up by any combination of the coins, return -1.
 *  You may assume that you have an infinite number of each kind of coin.
 * 
 *  Example 1:
 *  Input: coins = [1,2,5], amount = 11
 *  Output: 3
 *  Explanation: 11 = 5 + 5 + 1
 * 
 *  Example 2:
 *  Input: coins = [2], amount = 3
 *  Output: -1
 * 
 *  Example 3:
 *  Input: coins = [1], amount = 0
 *  Output: 0
 * 
 *  Example 4:
 *  Input: coins = [1], amount = 1
 *  Output: 1
 * 
 *  Example 5:
 *  Input: coins = [1], amount = 2
 *  Output: 2
 * 
 *  Constraints:
 *  1 <= coins.length <= 12
 *  1 <= coins[i] <= 2^31 - 1
 *  0 <= amount <= 10^4 */

 /** 처음에 풀었을 때는 시간초과함. 원인은 Arrays.fill(minCoins, -1)로 minCoins를 초기화하였기 때문에.. 
  *  이게 c++의 memset과는 다르게 생각보다 overhead가 큰 것 같다 */

package leet_code.java_2021_1;

public class CoinChange {
    private int fewestCombination(int[] coins, int[] minCoins, int amount) {
        int ret = Integer.MAX_VALUE;
        int cand;

        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (minCoins[amount] != 0) return minCoins[amount];

        for (int coin : coins) {
            cand = fewestCombination(coins, minCoins, amount-coin);
            if (cand != -1) ret = Math.min(ret, cand);
        }

        minCoins[amount] = ret == Integer.MAX_VALUE ? -1 : ret + 1;
        return minCoins[amount];
    }

    public int coinChange(int[] coins, int amount) {
        int[] minCoins = new int[amount+1];
        return fewestCombination(coins, minCoins, amount);
    }
}


