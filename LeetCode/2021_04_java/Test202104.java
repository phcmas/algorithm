import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Test202104 {
    public static void SingleElementInASortedArrayTest() {
        SingleElementInASortedArray test0 = new SingleElementInASortedArray();
        SingleElementInASortedArray test1 = new SingleElementInASortedArray();
        SingleElementInASortedArray test2 = new SingleElementInASortedArray();
        SingleElementInASortedArray test3 = new SingleElementInASortedArray();

        int[] nums0 = {1,1,2,3,3,4,4,8,8};
        int[] nums1 = {3,3,7,7,10,11,11};
        int[] nums2 = {1,2,2,3,3};
        List<Integer> temp = new ArrayList<>();

        for (int i = 1; i < 10001; ++i) {
            if (i == 4325) {
                temp.add(i);
            } else {
                temp.add(i);
                temp.add(i);
            }
        }

        int[] nums3 = temp.stream().mapToInt(i->i).toArray();

        int ans0 = test0.singleNonDuplicate(nums0);
        int ans1 = test1.singleNonDuplicate(nums1);
        int ans2 = test2.singleNonDuplicate(nums2);
        int ans3 = test3.singleNonDuplicate(nums3);

        System.out.println(ans0); // 2
        System.out.println(ans1); // 10
        System.out.println(ans2); // 1
        System.out.println(ans3); // 4325
    }

    public static void MaximumSubArrayTest() {
        MaximumSubArray test0 = new MaximumSubArray();
        MaximumSubArray test1 = new MaximumSubArray();
        MaximumSubArray tset2 = new MaximumSubArray();

        int[] nums0 = {-2,1,-3,4,-1,2,1,-5,4};
        int[] nums1 = {1};
        int[] nums2 = {5,4,-1,7,8};

        int ans0 = test0.maxSubArray(nums0);
        int ans1 = test0.maxSubArray(nums1);
        int ans2 = test0.maxSubArray(nums2);

        System.out.println(ans0); // 6
        System.out.println(ans1); // 1
        System.out.println(ans2); // 23
    }

    public static void SingleNumberTest() {
        SingleNumber test0 = new SingleNumber();
        SingleNumber test1 = new SingleNumber();
        SingleNumber test2 = new SingleNumber();

        int[] nums0 = {2,2,1};
        int[] nums1 = {4,1,2,1,2};
        int[] nums2 = {1};

        int ans0 = test0.singleNumber(nums0);
        int ans1 = test1.singleNumber(nums1);
        int ans2 = test2.singleNumber(nums2);

        System.out.println(ans0); // 1
        System.out.println(ans1); // 4
        System.out.println(ans2); // 1

    }

    public static void QueueReconstructionByHeightTest() {
        QueueReconstructionByHeight test0 = new QueueReconstructionByHeight();
        QueueReconstructionByHeight test1 = new QueueReconstructionByHeight();

        int[][] people0 = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
        int[][] people1 = {{6,0}, {5,0}, {4,0}, {3,2}, {2,2}, {1,4}};

        int[][] ans0 = test0.reconstructQueue1(people0);
        int[][] ans1 = test1.reconstructQueue1(people1);

        for (int i = 0; i < ans0.length; ++i) {
            for (int j = 0; j < ans0[0].length; ++j) {
                System.out.print(ans0[i][j] + " ");
            }
            System.out.print("  ");
        } // [5,0],[7,0],[5,2],[6,1],[4,4],[7,1]
        System.out.println();

        for (int i = 0; i < ans1.length; ++i) {
            for (int j = 0; j < ans1[0].length; ++j) {
                System.out.print(ans1[i][j] + " ");
            }
            System.out.print("  ");
        } // [4,0],[5,0],[2,2],[3,2],[1,4],[6,0]
    }

    public static void LastStoneWeightTest() {
        LastStoneWeight test0 = new LastStoneWeight();
        int[] stones0 = {2,7,4,1,8,1};

        int ans0 = test0.lastStoneWeight(stones0);

        System.out.println(ans0);
    }

    public static void LongestWordInDictionaryThroughDeletingTest() {
        LongestWordInDictionaryThroughDeleting test0 = new LongestWordInDictionaryThroughDeleting();
        LongestWordInDictionaryThroughDeleting test1 = new LongestWordInDictionaryThroughDeleting();

        String s0 = "abpcplea";
        List<String> dictionary0 = new ArrayList<>();
        dictionary0.add("ale");
        dictionary0.add("apple");
        dictionary0.add("monkey");
        dictionary0.add("plea");

        String s1 = "abpcplea";
        List<String> dictionary1 = new ArrayList<>();
        dictionary1.add("a");
        dictionary1.add("b");
        dictionary1.add("c");

        String ans0 = test0.findLongestWord(s0, dictionary0);
        String ans1 = test1.findLongestWord(s1, dictionary1);

        System.out.println(ans0); // apple
        System.out.println(ans1); // a
    }

    public static void MostFrequentSubtreeSumTest() {
        MostFrequentSubtreeSum test0 = new MostFrequentSubtreeSum();
        MostFrequentSubtreeSum test1 = new MostFrequentSubtreeSum();

        TreeNode node0_2 = new TreeNode(2);
        TreeNode node0_3 = new TreeNode(-3);
        TreeNode node0_5 = new TreeNode(5, node0_2, node0_3);

        TreeNode node1_2 = new TreeNode(2);
        TreeNode node1_5 = new TreeNode(-5);
        TreeNode node1_5_2 = new TreeNode(5, node1_2, node1_5);

        int[] ans0 = test0.findFrequentTreeSum(node0_5);
        int[] ans1 = test1.findFrequentTreeSum(node1_5_2);

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 2 -3 4

        for (int iter : ans1) {
            System.out.print(iter + " ");
        } System.out.println(); // 2

    }

    public static void MaximumNumberOfVowelsInASubstringOfGivenLengthTest() {
        MaximumNumberOfVowelsInASubstringOfGivenLength test0 = new MaximumNumberOfVowelsInASubstringOfGivenLength();
        MaximumNumberOfVowelsInASubstringOfGivenLength test1 = new MaximumNumberOfVowelsInASubstringOfGivenLength();
        MaximumNumberOfVowelsInASubstringOfGivenLength test2 = new MaximumNumberOfVowelsInASubstringOfGivenLength();
        MaximumNumberOfVowelsInASubstringOfGivenLength test3 = new MaximumNumberOfVowelsInASubstringOfGivenLength();
        MaximumNumberOfVowelsInASubstringOfGivenLength test4 = new MaximumNumberOfVowelsInASubstringOfGivenLength();

        String s0 = "abciiidef";
        int k0 = 3;

        String s1 = "aeiou";
        int k1 = 2;

        String s2 = "leetcode";
        int k2 = 3;

        String s3 = "rhythms";
        int k3 = 4;

        String s4 = "tryhard";
        int k4 = 4;

        int ans0 = test0.maxVowels(s0, k0);
        int ans1 = test1.maxVowels(s1, k1);
        int ans2 = test2.maxVowels(s2, k2);
        int ans3 = test3.maxVowels(s3, k3);
        int ans4 = test4.maxVowels(s4, k4);

        System.out.println(ans0); // 3
        System.out.println(ans1); // 2
        System.out.println(ans2); // 2
        System.out.println(ans3); // 0
        System.out.println(ans4); // 1

    }

    public static void TwoCitySchedulingTest() {
        TwoCityScheduling test0 = new TwoCityScheduling();
        TwoCityScheduling test1 = new TwoCityScheduling();
        TwoCityScheduling test2 = new TwoCityScheduling();

        int[][] costs0 = {{10,20},  {30,200}, {400,50}, {30,20}};
        int[][] costs1 = {{259,770}, {448,54}, {926,667}, {184,139}, {840,118}, {577,469}};
        int[][] costs2 = {{515,563}, {451,713}, {537,709}, {343,819}, {855,779}, {457,60}, {650,359}, {631,42}};

        int ans0 = test0.twoCitySchedCost(costs0);
        int ans1 = test1.twoCitySchedCost(costs1);
        int ans2 = test2.twoCitySchedCost(costs2);

        System.out.println(ans0); // 110
        System.out.println(ans1); // 1859
        System.out.println(ans2); // 3086
    }

    public static void SplitAStringInBalancedStringsTest() {
        SplitAStringInBalancedStrings test0 = new SplitAStringInBalancedStrings();
        SplitAStringInBalancedStrings test1 = new SplitAStringInBalancedStrings();
        SplitAStringInBalancedStrings test2 = new SplitAStringInBalancedStrings();
        SplitAStringInBalancedStrings test3 = new SplitAStringInBalancedStrings();

        String s0 = "RLRRLLRLRL";
        String s1 = "RLLLLRRRLR";
        String s2 = "LLLLRRRR";
        String s3 = "RLRRRLLRLL";

        int ans0 = test0.balancedStringSplit(s0);
        int ans1 = test1.balancedStringSplit(s1);
        int ans2 = test2.balancedStringSplit(s2);
        int ans3 = test3.balancedStringSplit(s3);

        System.out.println(ans0); // 4
        System.out.println(ans1); // 3
        System.out.println(ans2); // 1
        System.out.println(ans3); // 2
    }

    public static void TwoSumIIInputArraryIsSortedTest() {
        TwoSumIIInputArrayIsSorted test0 = new TwoSumIIInputArrayIsSorted();
        TwoSumIIInputArrayIsSorted test1 = new TwoSumIIInputArrayIsSorted();
        TwoSumIIInputArrayIsSorted test2 = new TwoSumIIInputArrayIsSorted();
        TwoSumIIInputArrayIsSorted test3 = new TwoSumIIInputArrayIsSorted();

        int[] numbers0 = {2,7,11,15};
        int[] numbers1 = {2,3,4};
        int[] numbers2 = {-1,0};
        int[] numbers3 = {3,24,50,79,88,150,345};

        int target0 = 9;
        int target1 = 6;
        int target2 = -1;
        int target3 = 200;

        int[] ans0 = test0.twoSum(numbers0, target0);
        int[] ans1 = test1.twoSum(numbers1, target1);
        int[] ans2 = test2.twoSum(numbers2, target2);
        int[] ans3 = test3.twoSum(numbers3, target3);

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 1 2
        
        for (int iter : ans1) {
            System.out.print(iter + " ");
        } System.out.println(); // 1 3

        for (int iter : ans2) {
            System.out.print(iter + " ");
        } System.out.println(); // 1 2

        for (int iter : ans3) {
            System.out.print(iter + " ");
        } System.out.println(); // 3 6
    }

    public static void NextGreaterElementIITest() {
        NextGreaterElementII test0 = new NextGreaterElementII();
        NextGreaterElementII test1 = new NextGreaterElementII();

        int[] nums0 = {1,2,1};
        int[] nums1 = {1,2,3,4,3};

        int[] ans0 = test0.nextGreaterElements(nums0);
        int[] ans1 = test1.nextGreaterElements(nums1);

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 2,-1,2

        for (int iter : ans1) {
            System.out.print(iter + " ");
        } System.out.println(); // 2,3,4,-1,4
        
    }

    public static void LongestArithmeticSubsequenceTest() {
        LongestArithmeticSubsequence test0 = new LongestArithmeticSubsequence();
        LongestArithmeticSubsequence test1 = new LongestArithmeticSubsequence();
        LongestArithmeticSubsequence test2 = new LongestArithmeticSubsequence();

        int[] A0 = {3,6,9,12};
        int[] A1 = {9,4,7,2,10};
        int[] A2 = {20,1,15,3,10,5,8};

        int ans0 = test0.longestArithSeqLength(A0);
        int ans1 = test0.longestArithSeqLength(A1);
        int ans2 = test0.longestArithSeqLength(A2);

        System.out.println(ans0); // 4
        System.out.println(ans1); // 3
        System.out.println(ans2); // 4
    }

    public static void main(String[] args) {
        //SingleElementInASortedArrayTest();
        //MaximumSubArrayTest();
        //SingleNumberTest();
        //QueueReconstructionByHeightTest();
        //LongestWordInDictionaryThroughDeletingTest();
        //LastStoneWeightTest();
        //MostFrequentSubtreeSumTest();
        //MaximumNumberOfVowelsInASubstringOfGivenLengthTest();
        //TwoCitySchedulingTest();
        //SplitAStringInBalancedStringsTest();
        //TwoSumIIInputArraryIsSortedTest();
        //NextGreaterElementIITest();
        LongestArithmeticSubsequenceTest();
    }
}

