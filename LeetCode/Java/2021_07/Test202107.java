import java.util.*;

public class Test202107 {

    public static void RelativeRanksTest() {
        RelativeRanks test0 = new RelativeRanks();
        RelativeRanks test1 = new RelativeRanks();

        int[] score0 = {5,4,3,2,1};
        int[] score1 = {10,3,8,9,4};
        String[] ans0 = test0.findRelativeRanks(score0);
        String[] ans1 = test1.findRelativeRanks(score1);

        for (String iter : ans0) {
            System.out.print(iter + " "); // ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
        } System.out.println();

        for (String iter : ans1) {
            System.out.print(iter+ " "); // ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
        }
    }

    public static void SortArrayByIncreasingFrequencyTest() {
        SortArrayByIncreasingFrequency test0 = new SortArrayByIncreasingFrequency();
        SortArrayByIncreasingFrequency test1 = new SortArrayByIncreasingFrequency();
        SortArrayByIncreasingFrequency test2 = new SortArrayByIncreasingFrequency();

        int[] nums0 = {1,1,2,2,2,3};
        int[] nums1 = {2,3,1,3,2};
        int[] nums2 = {-1,1,-6,4,5,-6,1,4,1};

        int[] ans0 = test0.frequencySort(nums0);
        int[] ans1 = test1.frequencySort(nums1);
        int[] ans2 = test2.frequencySort(nums2);

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 3,1,1,2,2,2

        for (int iter : ans1) {
            System.out.print(iter + " ");
        } System.out.println(); // 1,3,3,2,2

        for (int iter : ans2) {
            System.out.print(iter + " ");
        } System.out.println(); // 5,-1,4,4,-6,-6,1,1,1
    }

    public static void LargestNumberTest() {
        LargestNumber test = new LargestNumber();
        LargestNumber2 test2 = new LargestNumber2();

        int[] nums0 = {10,2};
        int[] nums1 = {3,30,34,5,9};
        int[] nums2 = {1};
        int[] nums3 = {10};
        int[] nums4 = {432, 43243};
        int[] nums5 = {8308,8308,830};
        int[] nums6 = {0,0};

        String ans0 = test2.largestNumber(nums0);
        String ans1 = test2.largestNumber(nums1);
        String ans2 = test2.largestNumber(nums2);
        String ans3 = test2.largestNumber(nums3);
        String ans4 = test2.largestNumber(nums4);
        String ans5 = test2.largestNumber(nums5);
        String ans6 = test2.largestNumber(nums6);

        System.out.println(ans0); // "210"
        System.out.println(ans1); // "9534330"
        System.out.println(ans2); // "1"
        System.out.println(ans3); // "10"
        System.out.println(ans4); // "43243432"
        System.out.println(ans5); // "83088308830"
        System.out.println(ans6); // "0"
    }

    public static void main(String[] args) {
        //RelativeRanksTest();
        //SortArrayByIncreasingFrequencyTest();
        LargestNumberTest();
    }
}
