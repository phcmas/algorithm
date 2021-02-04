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

    public static void main(String[] args) {
        //MaxConsecutiveOnesIIITest();
        LongestIncreasingSubsequenceTest();
    }
}


