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
    public static void main(String[] args) {
        //UniqueBinarySearchTreesTest();
        //MaximumLengthOfRepeatedSubarray();
        //SubsetsTest();
        //LongestSubstringWithAtLeastKRepeatingCharactersTest();
        LongestSubstringWithoutRepeatingCharactersTest();
    }
}
