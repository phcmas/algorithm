import java.util.List;

public class Test202103 {
    public static void UniqueBinarySearchTreesTest() {
        UniqueBinarySearchTrees test0 = new UniqueBinarySearchTrees();
        UniqueBinarySearchTrees test1 = new UniqueBinarySearchTrees();

        int ans0 = test0.numTrees(3);
        int ans1 = test1.numTrees(1);

        System.out.println(ans0); // 5
        System.out.println(ans1); // 1

    }

    public static void MaximumLengthOfRepeatedSubarray() {
        MaximumLengthOfRepeatedSubarray test0 = new MaximumLengthOfRepeatedSubarray();
        MaximumLengthOfRepeatedSubarray test1 = new MaximumLengthOfRepeatedSubarray();

        int[] A0 = {1,2,3,2,1};
        int[] B0 = {3,2,1,4,7};

        int[] A1 = {0,0,0,0,1};
        int[] B1 = {1,0,0,0,0};

        int ans0 = test0.findLength(A0,B0);
        int ans1 = test1.findLength(A1,B1);

        System.out.println(ans0); // 3
        System.out.println(ans1); // 4
    }

    public static void SubsetsTest() {
        Subsets test0 = new Subsets();
        Subsets test1 = new Subsets();

        int nums0[] = {1,2,3};
        int nums1[] = {0};

        List<List<Integer>> ans0 = test0.subsets(nums0);
        List<List<Integer>> ans1 = test1.subsets(nums1);

        for (List<Integer> iter1 : ans0) {
            System.out.print("[");
            for (Integer iter2 : iter1) {
                System.out.print(iter2 + " ");
            }
            System.out.print("], ");
        } // [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

        System.out.println();
        for (List<Integer> iter1 : ans1) {
            System.out.print("[");
            for (Integer iter2 : iter1) {
                System.out.print(iter2 + " ");
            }
            System.out.print("], ");
        } // [[],[0]]

    }

    public static void LongestSubstringWithAtLeastKRepeatingCharactersTest() {
        LongestSubstringWithAtLeastKRepeatingCharacters test0 = new LongestSubstringWithAtLeastKRepeatingCharacters();
        LongestSubstringWithAtLeastKRepeatingCharacters test1 = new LongestSubstringWithAtLeastKRepeatingCharacters();

        String s0 = "aaabb";
        String s1 = "ababbc";

        int k0 = 3;
        int k1 = 2;

        int ans0 = test0.longestSubstring(s0, k0);
        int ans1 = test1.longestSubstring(s1, k1);

        System.out.println(ans0); // 3
        System.out.println(ans1); // 5
    }

    public static void LongestSubstringWithoutRepeatingCharactersTest() {
        LongestSubstringWithoutRepeatingCharacters test0 = new LongestSubstringWithoutRepeatingCharacters();
        LongestSubstringWithoutRepeatingCharacters test1 = new LongestSubstringWithoutRepeatingCharacters();
        LongestSubstringWithoutRepeatingCharacters test2 = new LongestSubstringWithoutRepeatingCharacters();
        LongestSubstringWithoutRepeatingCharacters test3 = new LongestSubstringWithoutRepeatingCharacters();

        String s0 = "abcabcbb";
        String s1 = "bbbbb";
        String s2 = "pwwkew";
        String s3 = "";
        String s4 = " ";

        int ans0 = test0.lengthOfLongestSubstring(s0);
        int ans1 = test1.lengthOfLongestSubstring(s1);
        int ans2 = test2.lengthOfLongestSubstring(s2);
        int ans3 = test3.lengthOfLongestSubstring(s3);
        int ans4 = test3.lengthOfLongestSubstring(s4);

        System.out.println(ans0); // 3
        System.out.println(ans1); // 1
        System.out.println(ans2); // 3
        System.out.println(ans3); // 0
        System.out.println(ans4); // 1
    }
    
    public static void IntervalListIntersectionsTest() {
        IntervalListIntersections test0 = new IntervalListIntersections();
        IntervalListIntersections test1 = new IntervalListIntersections();
        IntervalListIntersections test2 = new IntervalListIntersections();
        IntervalListIntersections test3 = new IntervalListIntersections();


        int[][] firstList0 = {{0,2},{5,10},{13,23},{24,25}};
        int[][] secondList0 = {{1,5},{8,12},{15,24},{25,26}};

        int[][] firstList1 = {{1,3},{5,9}};
        int[][] secondList1 = {};

        int[][] firstList2 = {};
        int[][] secondList2 = {{4,8},{10,12}};

        int[][] firstList3 = {{1,7}};
        int[][] secondList3 = {{3,10}};

        int[][] ans0 = test0.intervalIntersection(firstList0, secondList0);
        int[][] ans1 = test1.intervalIntersection(firstList1, secondList1);
        int[][] ans2 = test2.intervalIntersection(firstList2, secondList2);
        int[][] ans3 = test3.intervalIntersection(firstList3, secondList3);

        for (int i = 0; i < ans0.length; ++i) {
            System.out.print("[");
            for (int j = 0; j < ans0[0].length; ++j) {
                System.out.print(ans0[i][j] + " ");
            }
            System.out.print("] ");
        } // [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

        System.out.println();
        for (int i = 0; i < ans1.length; ++i) {
            System.out.print("[");
            for (int j = 0; j < ans1[0].length; ++j) {
                System.out.print(ans1[i][j] + " ");
            }
            System.out.print("] ");
        } // []

        System.out.println();
        for (int i = 0; i < ans2.length; ++i) {
            System.out.print("[");
            for (int j = 0; j < ans2[0].length; ++j) {
                System.out.print(ans2[i][j] + " ");
            }
            System.out.print("] ");
        } // []

        System.out.println();
        for (int i = 0; i < ans3.length; ++i) {
            System.out.print("[");
            for (int j = 0; j < ans3[0].length; ++j) {
                System.out.print(ans3[i][j] + " ");
            }
            System.out.print("] ");
        } // [[3,7]]

    }

    public static void PalindromeSubstringsTest() {
        PalindromicSubstrings test0 = new PalindromicSubstrings();
        PalindromicSubstrings test1 = new PalindromicSubstrings();

        String s0 = "abc";
        String s1 = "aaa";

        int ans0 = test0.countSubstrings(s0);
        int ans1 = test1.countSubstrings(s1);

        System.out.println(ans0); // 3
        System.out.println(ans1); // 6
    }
    
    public static void MinimumCostTreeFromLeafValuesTest() {
        MinimumCostTreeFromLeafValues test0 = new MinimumCostTreeFromLeafValues();
        int[] arr0 = {6,2,4};

        int ans0 = test0.mctFromLeafValues(arr0);

        System.out.println(ans0); // 32
    }
    public static void main(String[] args) {
        //UniqueBinarySearchTreesTest();
        //MaximumLengthOfRepeatedSubarray();
        //SubsetsTest();
        //LongestSubstringWithAtLeastKRepeatingCharactersTest();
        //LongestSubstringWithoutRepeatingCharactersTest();
        //IntervalListIntersectionsTest();
        //PalindromeSubstringsTest();
        MinimumCostTreeFromLeafValuesTest();
    }
}
