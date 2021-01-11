package leet_code.java_2021_1;

import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void sortColorTest() {
        sortColor tester = new sortColor();
        int[] nums0 = {2,0,2,1,1,0};
        tester.sortColor(nums0);

        int[] nums1 = {2,0,1};
        tester.sortColor(nums1);

        int[] nums2 = {0};
        tester.sortColor(nums2);

        int [] nums3 = {1};
        tester.sortColor(nums3);

        int [] nums4 = {1,2,0};
        tester.sortColor(nums4);

        for (int i = 0; i < nums0.length; ++i) {
            System.out.print(nums0[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < nums1.length; ++i) {
            System.out.print(nums1[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < nums2.length; ++i) {
            System.out.print(nums2[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < nums3.length; ++i) {
            System.out.print(nums3[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < nums4.length; ++i) {
            System.out.print(nums4[i] + " ");
        }
        System.out.println();
    }

    public static void allPathsSourceTargetTest() {
        allPathsSourceTarget test = new allPathsSourceTarget();
        int[][] graph0 = new int[4][];
        graph0[0] = new int[2];

        graph0[1] = new int[1];
        graph0[2] = new int[1];
        graph0[3] = new int[0];
        graph0[0][0] = 1;
        graph0[0][1] = 2;
        graph0[1][0] = 3;
        graph0[2][0] = 3;

        List<List<Integer>> ans0 = test.allPathsSourceTarget(graph0);

        int[][] graph1 = new int[2][];
        graph1[0] = new int[1];
        graph1[1] = new int[0];
        graph1[0][0] = 1;

        List<List<Integer>> ans1 = test.allPathsSourceTarget(graph1);

        int[][] graph2 = new int[5][];
        graph2[0] = new int[3];
        graph2[1] = new int[3];
        graph2[2] = new int[1];
        graph2[3] = new int[1];
        graph2[4] = new int[0];

        graph2[0][0] = 4;
        graph2[0][1] = 3;
        graph2[0][2] = 1;
        graph2[1][0] = 3;
        graph2[1][1] = 2;
        graph2[1][2] = 4;
        graph2[2][0] = 3;
        graph2[3][0] = 4;
        
        List<List<Integer>> ans2 = test.allPathsSourceTarget(graph2);

        for (List<Integer> iter0 : ans0) {
            for (Integer iter1 : iter0) {
                System.out.print(iter1 + " ");
            }
            System.out.println();
        } // [0 1 3], [0 2 3]
        System.out.println();
        
        for (List<Integer> iter0 : ans1) {
            for (Integer iter1 : iter0) {
                System.out.print(iter1 + " ");
            }
            System.out.println();
        } // 0 1
        System.out.println();

        for (List<Integer> iter0 : ans2) {
            for (Integer iter1 : iter0) {
                System.out.print(iter1 + " ");
            }
            System.out.println();
        } // [0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]
        System.out.println();

    }

    public static void allPathsSourceTargetTest2() {
        allPathsSourceTarget2 test0 = new allPathsSourceTarget2();
        allPathsSourceTarget2 test1 = new allPathsSourceTarget2();
        allPathsSourceTarget2 test2 = new allPathsSourceTarget2();
        int[][] graph0 = new int[4][];
        graph0[0] = new int[2];

        graph0[1] = new int[1];
        graph0[2] = new int[1];
        graph0[3] = new int[0];
        graph0[0][0] = 1;
        graph0[0][1] = 2;
        graph0[1][0] = 3;
        graph0[2][0] = 3;

        List<List<Integer>> ans0 = test0.allPathsSourceTarget(graph0);

        int[][] graph1 = new int[2][];
        graph1[0] = new int[1];
        graph1[1] = new int[0];
        graph1[0][0] = 1;

        List<List<Integer>> ans1 = test1.allPathsSourceTarget(graph1);

        int[][] graph2 = new int[5][];
        graph2[0] = new int[3];
        graph2[1] = new int[3];
        graph2[2] = new int[1];
        graph2[3] = new int[1];
        graph2[4] = new int[0];

        graph2[0][0] = 4;
        graph2[0][1] = 3;
        graph2[0][2] = 1;
        graph2[1][0] = 3;
        graph2[1][1] = 2;
        graph2[1][2] = 4;
        graph2[2][0] = 3;
        graph2[3][0] = 4;
        
        List<List<Integer>> ans2 = test2.allPathsSourceTarget(graph2);

        for (List<Integer> iter0 : ans0) {
            for (Integer iter1 : iter0) {
                System.out.print(iter1 + " ");
            }
            System.out.print("    ");
        } // [0 1 3], [0 2 3]
        System.out.println();
        
        for (List<Integer> iter0 : ans1) {
            for (Integer iter1 : iter0) {
                System.out.print(iter1 + " ");
            }
            System.out.print("    ");
        } // 0 1
        System.out.println();

        for (List<Integer> iter0 : ans2) {
            for (Integer iter1 : iter0) {
                System.out.print(iter1 + " ");
            }
            System.out.print("    ");
        } // [0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]
        System.out.println();
    }

    public static void main(String[] args) {
        //sortColorTest();       
        //allPathsSourceTargetTest(); 
        allPathsSourceTargetTest2(); 
    }
}
