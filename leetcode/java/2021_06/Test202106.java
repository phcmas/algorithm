import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Test202106 {
    public static void VerifyPreorderSerializationOfABinaryTreeTest() {
        VerifyPreorderSerializationOfABinaryTree test0 = new VerifyPreorderSerializationOfABinaryTree();
        VerifyPreorderSerializationOfABinaryTree test1 = new VerifyPreorderSerializationOfABinaryTree();
        VerifyPreorderSerializationOfABinaryTree test2 = new VerifyPreorderSerializationOfABinaryTree();
        VerifyPreorderSerializationOfABinaryTree test3 = new VerifyPreorderSerializationOfABinaryTree();
        VerifyPreorderSerializationOfABinaryTree test4 = new VerifyPreorderSerializationOfABinaryTree();

        String preorder0 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
        String preorder1 = "1,#";
        String preorder2 = "9,#,#,1";
        String preorder3 = "#";
        String preorder4 = "9,#,92,#,#";

        boolean ans0 = test0.isValidSerialization(preorder0);
        boolean ans1 = test1.isValidSerialization(preorder1);
        boolean ans2 = test2.isValidSerialization(preorder2);
        boolean ans3 = test3.isValidSerialization(preorder3);
        boolean ans4 = test3.isValidSerialization(preorder4);

        System.out.println(ans0); // true 
        System.out.println(ans1); // false
        System.out.println(ans2); // false
        System.out.println(ans3); // true
        System.out.println(ans4); // true
    }

    public static void MinimumSubsequenceInNonIncreasingOrderTest() {
        MinimumSubsequenceInNonIncreasingOrder test0 = new MinimumSubsequenceInNonIncreasingOrder();
        MinimumSubsequenceInNonIncreasingOrder test1 = new MinimumSubsequenceInNonIncreasingOrder();
        MinimumSubsequenceInNonIncreasingOrder test2 = new MinimumSubsequenceInNonIncreasingOrder();

        int[] nums0 = {4,3,10,9,8};
        int[] nums1 = {4,4,7,6,7};
        int[] nums2 = {6};

        List<Integer> ans0 = test0.minSubsequence(nums0);
        List<Integer> ans1 = test1.minSubsequence(nums1);
        List<Integer> ans2 = test2.minSubsequence(nums2);

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 10, 9

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 7, 7, 6

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 6
    }

    public static void JumpGameIITest() {
        JumpGameII test0 = new JumpGameII();
        JumpGameII test1 = new JumpGameII();

        int[] nums0 = {2,3,1,1,4};
        int[] nums1 = {2,3,0,1,4};

        int ans0 = test0.jump(nums0);
        int ans1 = test1.jump(nums1);

        System.out.println(ans0); // 2
        System.out.println(ans1); // 2
    }

    public static void NextGreaterElementITest() {
        NextGreaterElementI test0 = new NextGreaterElementI();
        NextGreaterElementI test1 = new NextGreaterElementI();

        int[] nums01 = {4,1,2};
        int[] nums02 = {1,3,4,2};

        int[] nums11 = {2,4};
        int[] nums12 = {1,2,3,4};

        int[] ans0 = test0.nextGreaterElement(nums01, nums02);
        int[] ans1 = test1.nextGreaterElement(nums11, nums12);

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // -1, 3, -1

        for (int iter : ans1) {
            System.out.print(iter + " ");
        } // 3, -1
    }

    public static void BestTimeToBuyAndSellStockWithCooldownTest() {
        BestTimeToBuyAndSellStockWithCooldown test0 = new BestTimeToBuyAndSellStockWithCooldown();
        BestTimeToBuyAndSellStockWithCooldown test1 = new BestTimeToBuyAndSellStockWithCooldown();
        BestTimeToBuyAndSellStockWithCooldown test2 = new BestTimeToBuyAndSellStockWithCooldown();

        int[] prices0 = {1,2,3,0,2};
        int[] prices1 = {1};
        int[] prices2 = {6,1,6,4,3,0,2};

        int ans0 = test0.maxProfit(prices0);
        int ans1 = test1.maxProfit(prices1);
        int ans2 = test2.maxProfit(prices2);

        System.out.println(ans0); // 3
        System.out.println(ans1); // 0
        System.out.println(ans2); // 7
    }
    
    public static void FindValidMatrixGivenRowAndColumnSumsTest() {
        FindValidMatrixGivenRowAndColumnSums test0 = new FindValidMatrixGivenRowAndColumnSums();
        FindValidMatrixGivenRowAndColumnSums test1 = new FindValidMatrixGivenRowAndColumnSums();
        FindValidMatrixGivenRowAndColumnSums test2 = new FindValidMatrixGivenRowAndColumnSums();
        FindValidMatrixGivenRowAndColumnSums test3 = new FindValidMatrixGivenRowAndColumnSums();
        FindValidMatrixGivenRowAndColumnSums test4 = new FindValidMatrixGivenRowAndColumnSums();

        int[] rowSum0 = {3,8};
        int[] colSum0 = {4,7};
        int[][] answer0 = test0.restoreMatrix(rowSum0, colSum0);

        int[] rowSum1 = {5,7,10};
        int[] colSum1 = {8,6,8};
        int[][] answer1 = test1.restoreMatrix(rowSum1, colSum1);

        int[] rowSum2 = {14,9};
        int[] colSum2 = {6,9,8};
        int[][] answer2 = test2.restoreMatrix(rowSum2, colSum2);

        int[] rowSum3 = {1,0};
        int[] colSum3 = {1};
        int[][] answer3 = test3.restoreMatrix(rowSum3, colSum3);

        int[] rowSum4 = {0};
        int[] colSum4 = {0};
        int[][] answer4 = test4.restoreMatrix(rowSum4, colSum4);

        for (int i = 0; i < answer0.length; ++i) {
            for (int j = 0; j < answer0[0].length; ++j) {
                System.out.print(answer0[i][j]);
            }
            System.out.println();
        } System.out.println();

        for (int i = 0; i < answer1.length; ++i) {
            for (int j = 0; j < answer1[0].length; ++j) {
                System.out.print(answer1[i][j]);
            }
            System.out.println();
        } System.out.println();

        for (int i = 0; i < answer2.length; ++i) {
            for (int j = 0; j < answer2[0].length; ++j) {
                System.out.print(answer2[i][j]);
            }
            System.out.println();
        } System.out.println();

        for (int i = 0; i < answer3.length; ++i) {
            for (int j = 0; j < answer3[0].length; ++j) {
                System.out.print(answer3[i][j]);
            }
            System.out.println();
        } System.out.println();
    }

    public static void main(String[] args) {
        //VerifyPreorderSerializationOfABinaryTreeTest();
        //MinimumSubsequenceInNonIncreasingOrderTest();
        //JumpGameIITest();
        //NextGreaterElementITest();
        //BestTimeToBuyAndSellStockWithCooldownTest();
        FindValidMatrixGivenRowAndColumnSumsTest();
    }
};
