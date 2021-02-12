package leet_code.java_2021_2;

import java.util.ArrayList;
import java.util.List;

public class Test {
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

    public static void main(String[] args) {
        //MaxConsecutiveOnesIIITest();
        //LongestIncreasingSubsequenceTest();
        //CombinationSumIIITest();
        KthLargestElementInAnArrayTest();
    }
}


