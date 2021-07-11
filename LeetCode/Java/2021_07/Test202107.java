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

    public static void main(String[] args) {
        RelativeRanksTest();
    }
}
