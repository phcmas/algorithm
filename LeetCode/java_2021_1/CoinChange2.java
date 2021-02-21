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

package leet_code.java_2021_1;
import java.util.Arrays;

public class CoinChange2 {
    public int coinChange(int[] coins, int amount) {
        int answer, remain;
        int[] minCoins = new int[amount+1];
        Arrays.fill(minCoins, amount+1);
        minCoins[0] = 0;

        for (int i = 0; i < amount+1; ++i) {
            for (int j = 0; j < coins.length; ++j) {
                if (i >= coins[j]) {
                   remain = i - coins[j];
                   minCoins[i] = Math.min(minCoins[remain]+1, minCoins[i]);
                }
            }
        }

        answer = minCoins[amount] == amount+1 ? -1 : minCoins[amount];
        return answer;
    }
}
