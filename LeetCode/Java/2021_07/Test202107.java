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

    public static void main(String[] args) {
        //RelativeRanksTest();
        SortArrayByIncreasingFrequencyTest();
    }
}
