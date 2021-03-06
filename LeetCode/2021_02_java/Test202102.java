import java.util.ArrayList;
import java.util.List;

public class Test202102 {
    public static void MaxConsecutiveOnesIIITest() {
        MaxConsecutiveOnesIII test0 = new MaxConsecutiveOnesIII();
        MaxConsecutiveOnesIII test1 = new MaxConsecutiveOnesIII();

        int[] A0 = {1,1,1,0,0,0,1,1,1,1,0};
        int K0 = 2;

        int[] A1 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int K1 = 3;

        int ans0 = test0.longestOnes(A0, K0);
        int ans1 = test1.longestOnes(A1, K1);
        int ans2 = test0.longestOnes2(A0, K0);
        int ans3 = test1.longestOnes2(A1, K1);

        System.out.println(ans0); // 6
        System.out.println(ans1); // 10
        System.out.println(ans2); // 6
        System.out.println(ans3); // 10
    }

    public static void LongestIncreasingSubsequenceTest() {
        LongestIncreasingSubsequence test0 = new LongestIncreasingSubsequence();
        LongestIncreasingSubsequence test1 = new LongestIncreasingSubsequence();
        LongestIncreasingSubsequence test2 = new LongestIncreasingSubsequence();
        LongestIncreasingSubsequence test3 = new LongestIncreasingSubsequence();

        int[] nums0 = {10,9,2,5,3,7,101,18};
        int[] nums1 = {0,1,0,3,2,3};
        int[] nums2 = {7,7,7,7,7,7,7};
        int[] nums3 = {1,3,6,7,9,4,10,5,6};

        int ans0 = test0.lengthOfLIS(nums0);
        int ans1 = test1.lengthOfLIS(nums1);
        int ans2 = test2.lengthOfLIS(nums2);
        int ans3 = test3.lengthOfLIS(nums3);

        System.out.println(ans0); // 4
        System.out.println(ans1); // 4
        System.out.println(ans2); // 1
        System.out.println(ans3); // 6
    }
    public static void CombinationSumIIITest() {
        CombinationSumIII test0 = new CombinationSumIII();
        List<List<Integer>> ans0 = test0.combinationSum3(3, 7);

        CombinationSumIII test1 = new CombinationSumIII();
        List<List<Integer>> ans1 = test1.combinationSum3(3, 9);

        CombinationSumIII test2 = new CombinationSumIII();
        List<List<Integer>> ans2 = test2.combinationSum3(4, 1);

        CombinationSumIII test3 = new CombinationSumIII();
        List<List<Integer>> ans3 = test3.combinationSum3(3, 2);

        CombinationSumIII test4 = new CombinationSumIII();
        List<List<Integer>> ans4 = test4.combinationSum3(9, 45);

        for (List<Integer> list : ans0) {
            System.out.print("[");
            for (int ele : list) {
                System.out.print(ele + " ");
            }
            System.out.print("], ");
        }
        System.out.println(); // [1,2,4]

        for (List<Integer> list : ans1) {
            System.out.print("[");
            for (int ele : list) {
                System.out.print(ele + " ");
            }
            System.out.print("], ");
        }
        System.out.println(); // [[1,2,6],[1,3,5],[2,3,4]]

        for (List<Integer> list : ans2) {
            System.out.print("[");
            for (int ele : list) {
                System.out.print(ele + " ");
            }
            System.out.print("], ");
        }
        System.out.println(); // []

        for (List<Integer> list : ans3) {
            System.out.print("[");
            for (int ele : list) {
                System.out.print(ele + " ");
            }
            System.out.print("], ");
        }
        System.out.println(); // []

        for (List<Integer> list : ans4) {
            System.out.print("[");
            for (int ele : list) {
                System.out.print(ele + " ");
            }
            System.out.print("], ");
        }
        System.out.println(); // [[1,2,3,4,5,6,7,8,9]]
    }
    public static void KthLargestElementInAnArrayTest() {
        KthLargestElementInAnArray test0 = new KthLargestElementInAnArray();
        KthLargestElementInAnArray test1 = new KthLargestElementInAnArray();

        int[] nums0 = {3,2,1,5,6,4};
        int ans0 = test0.findKthLargest2(nums0, 2);

        int[] nums1 = {3,2,3,1,2,4,5,5,6};
        int ans1 = test1.findKthLargest2(nums1, 4);

        System.out.println(ans0);
        System.out.println(ans1);
    }

    public static void SplitArrayIntoConsecutiveSubsequencesTest() {
        SplitArrayIntoConsecutiveSubsequences test0 = new SplitArrayIntoConsecutiveSubsequences();
        SplitArrayIntoConsecutiveSubsequences test1 = new SplitArrayIntoConsecutiveSubsequences();
        SplitArrayIntoConsecutiveSubsequences test2 = new SplitArrayIntoConsecutiveSubsequences();

        int[] nums0 = {1,2,3,3,4,5};
        int[] nums1 = {1,2,3,3,4,4,5,5};
        int[] nums2 = {1,2,3,4,4,5};

        boolean ans0 = test0.isPossible(nums0);
        boolean ans1 = test1.isPossible(nums1);
        boolean ans2 = test2.isPossible(nums2);

        System.out.println(ans0); // true
        System.out.println(ans1); // true
        System.out.println(ans2); // false

    }

    public static void KClosestPointsToOriginTest() {
        KClosestPointsToOrigin test0 = new KClosestPointsToOrigin();
        KClosestPointsToOrigin test1 = new KClosestPointsToOrigin();

        int[][] points0 = {{1,3}, {-2,2}};
        int[][] points1 = {{3,3}, {5,-1}, {-2,4}};

        int[][] ans0 = test0.kClosest(points0, 1);
        int[][] ans1 = test1.kClosest(points1, 2);

        for (int i = 0; i < ans0.length; ++i) {
            for (int j = 0; j < ans0[0].length; ++j) {
                System.out.print(ans0[i][j] + " ");
            }
            System.out.print(", ");
        } // [[-2,2]]

        System.out.println();

        for (int i = 0; i < ans1.length; ++i) {
            for (int j = 0; j < ans1[0].length; ++j) {
                System.out.print(ans1[i][j] + " ");
            }
            System.out.print(", ");
        } // [[3,3], [-2,4]]
    }

    public static void FurthestBuildingYouCanReachTest() {
        FurthestBuildingYouCanReach test0 = new FurthestBuildingYouCanReach();
        FurthestBuildingYouCanReach test1 = new FurthestBuildingYouCanReach();
        FurthestBuildingYouCanReach test2 = new FurthestBuildingYouCanReach();
        FurthestBuildingYouCanReach test3 = new FurthestBuildingYouCanReach();

        int[] heights0 = {4,2,7,6,9,14,12};
        int ans0 = test0.furthestBuilding(heights0, 5, 1);

        int[] heights1 = {4,12,2,7,3,18,20,3,19};
        int ans1 = test1.furthestBuilding(heights1, 10, 2);

        int[] heights2 = {14,3,19,3};
        int ans2 = test2.furthestBuilding(heights2, 17, 0);

        int[] heights3 = {1,5,1,2,3,4,10000};
        int ans3 = test3.furthestBuilding(heights3, 4, 1);
        
        System.out.println(ans0); // 4
        System.out.println(ans1); // 7
        System.out.println(ans2); // 3
        System.out.println(ans3); // 5
    }

    public static void MaxAreaOfIslandTest() {
        MaxAreaOfIsland test0 = new MaxAreaOfIsland();

        int[] row00 = {1,1,0,0,0};
        int[] row01 = {1,1,0,0,0};
        int[] row02 = {0,0,0,1,1};
        int[] row03 = {0,0,0,1,1};
        int[][] grid0 = {row00, row01, row02, row03};

        int ans0 = test0.maxAreaOfIsland(grid0);
        System.out.println(ans0);

    }
    public static void CopyListWithRandomPointer() {
        Node iter;
        CopyListWithRandomPointer test0 = new CopyListWithRandomPointer();

        Node node00 = new Node(3);
        Node node01 = new Node(3);
        Node node02 = new Node(3);

        node00.next = node01;
        node01.next = node02;
        node02.next = null;
        node00.random = null;
        node01.random = node00;
        node02.random = null;

        Node ans0 = test0.copyRandomList(node00);

        iter = ans0;
        while (iter != null) {
            System.out.print("val : " + iter.val + ", random : " + iter.random +" ");
            System.out.println();
            iter = iter.next;
        }
    }

    public static void ArithmeticSlicesTest() {
        ArithmeticSlices test0 = new ArithmeticSlices();
        int[] A0 = {1, 2, 3, 4};
        int ans0 = test0.numberOfArithmeticSlices(A0);

        System.out.println(ans0); // 3
    }

    public static void ShortestBridgeTest() {
        ShortestBridge test0 = new ShortestBridge();
        ShortestBridge test1 = new ShortestBridge();
        ShortestBridge test2 = new ShortestBridge();

        int[][] A0 = {{0,1}, {1,0}};
        int[][] A1 = {{0,1,0}, {0,0,0}, {0,0,1}};
        int[][] A2 = {{1,1,1,1,1}, {1,0,0,0,1}, {1,0,1,0,1}, {1,0,0,0,1}, {1,1,1,1,1}};

        int ans0 = test0.shortestBridge(A0);
        int ans1 = test1.shortestBridge(A1);
        int ans2 = test2.shortestBridge(A2);

        System.out.println(ans0); // 1
        System.out.println(ans1); // 2
        System.out.println(ans2); // 1
    }

    public static void IsSubsequenceTest() {
         IsSubsequence test0 = new IsSubsequence();
         IsSubsequence test1 = new IsSubsequence();

         String s0 = "abc";
         String s1 = "axc";
         String t0 = "ahbgdc";
         String t1 = "ahbgdc";

         boolean ans0 = test0.isSubsequence(s0, t0);
         boolean ans1 = test1.isSubsequence(s1, t1);

         System.out.println(ans0); // true
         System.out.println(ans1); // false
    }

    public static void LongestPalindromicSubsequenceTest() {
        LongestPalindromicSubsequence test0 = new LongestPalindromicSubsequence();
        LongestPalindromicSubsequence test1 = new LongestPalindromicSubsequence();
        LongestPalindromicSubsequence test2 = new LongestPalindromicSubsequence();

        String s0 = "bbbab";
        String s1 = "cbbd";
        String s2 = "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew";
        
        int ans0 = test0.longestPalindromeSubseq(s0);
        int ans1 = test1.longestPalindromeSubseq(s1);
        int ans2 = test2.longestPalindromeSubseq(s2);

        System.out.println(ans0); // 4
        System.out.println(ans1); // 2
        System.out.println(ans2); // 159
    }

    public static void SwapNodesInPairsTest() {
        SwapNodesInPairs test0 = new SwapNodesInPairs();
        SwapNodesInPairs test1 = new SwapNodesInPairs();
        SwapNodesInPairs test2 = new SwapNodesInPairs();

        ListNode node00 = new ListNode(4);
        ListNode node01 = new ListNode(3, node00);
        ListNode node02 = new ListNode(2, node01);
        ListNode node03 = new ListNode(1, node02);
        ListNode ans0 = test0.swapPairs(node03);

        ListNode node10 = new ListNode(1);
        ListNode ans1 = test1.swapPairs(node10);

        ListNode ans2 = test2.swapPairs(null);

        while (ans0 != null) {
            System.out.print(ans0.val + " ");
            ans0 = ans0.next;
        } System.out.println(); // [2,1,4,3]

        while (ans1 != null) {
            System.out.print(ans1.val + " ");
            ans1 = ans1.next;
        } System.out.println(); // [1]

        while (ans2 != null) {
            System.out.print(ans2.val + " ");
            ans2 = ans2.next;
        } System.out.println(); // []
    }

    public static void printTree(TreeNode root) {
        // print pre order
        if (root == null) return;
        System.out.print(root.val);
        printTree(root.left);
        printTree(root.right);
    }

    public static void SmallestSubtreeWithAllTheDeepestNodesTest() {
        SmallestSubtreeWithAllTheDeepestNodes test0 = new SmallestSubtreeWithAllTheDeepestNodes();
        SmallestSubtreeWithAllTheDeepestNodes test1 = new SmallestSubtreeWithAllTheDeepestNodes();
        SmallestSubtreeWithAllTheDeepestNodes test2 = new SmallestSubtreeWithAllTheDeepestNodes();

        TreeNode node04 = new TreeNode(4);
        TreeNode node07 = new TreeNode(7);
        TreeNode node06 = new TreeNode(6);
        TreeNode node02 = new TreeNode(2, node07, node04);
        TreeNode node00 = new TreeNode(0);
        TreeNode node08 = new TreeNode(8);
        TreeNode node05 = new TreeNode(5, node06, node02);
        TreeNode node01 = new TreeNode(1, node00, node08);
        TreeNode node03 = new TreeNode(3, node05, node01);

        TreeNode node11 = new TreeNode(1);

        TreeNode node22 = new TreeNode(2);
        TreeNode node21 = new TreeNode(1, null, node22);
        TreeNode node23 = new TreeNode(3);
        TreeNode node20 = new TreeNode(0, node21, node23);

        TreeNode ans0 = test0.subtreeWithAllDeepest(node03);
        TreeNode ans1 = test1.subtreeWithAllDeepest(node11);
        TreeNode ans2 = test2.subtreeWithAllDeepest(node20);

        printTree(ans0); // 2 7 4
        System.out.println();
        
        printTree(ans1); // 1
        System.out.println();

        printTree(ans2); // 2
        System.out.println();
    }
    public static void main(String[] args) {
        //MaxConsecutiveOnesIIITest();
        //LongestIncreasingSubsequenceTest();
        //CombinationSumIIITest();
        //KthLargestElementInAnArrayTest();
        //SplitArrayIntoConsecutiveSubsequencesTest();
        //KClosestPointsToOriginTest();
        //FurthestBuildingYouCanReachTest();
        //MaxAreaOfIslandTest();
        //CopyListWithRandomPointer();
        //ArithmeticSlicesTest();
        //ShortestBridgeTest();
        //IsSubsequenceTest();
        //LongestPalindromicSubsequenceTest();
        //SwapNodesInPairsTest();
        SmallestSubtreeWithAllTheDeepestNodesTest();
    }
}


