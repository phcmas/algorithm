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

    public static void evaluateDivisionTest() {
        evaluateDivision test0 = new evaluateDivision();
        evaluateDivision test1 = new evaluateDivision();

        List<String> eq00 = new ArrayList<>();
        eq00.add("a");
        eq00.add("b");
        List<String> eq01 = new ArrayList<>();
        eq01.add("b");
        eq01.add("c");
        List<List<String>> equations0 = new ArrayList<>();
        equations0.add(eq00);
        equations0.add(eq01);

        double[] values0 = new double[2];
        values0[0] = 2.0;
        values0[1] = 3.0;

        List<String> q00 = new ArrayList<>();
        q00.add("a");
        q00.add("c");
        List<String> q01 = new ArrayList<>();
        q01.add("b");
        q01.add("a");
        List<String> q02 = new ArrayList<>();
        q02.add("a");
        q02.add("e");
        List<String> q03 = new ArrayList<>();
        q03.add("a");
        q03.add("a");
        List<String> q04 = new ArrayList<>();
        q04.add("x");
        q04.add("x");

        List<List<String>> queries0 = new ArrayList<>();
        queries0.add(q00);
        queries0.add(q01);
        queries0.add(q02);
        queries0.add(q03);
        queries0.add(q04);

        double[] answer0 = test0.calcEquation(equations0, values0, queries0);

        List<String> eq10 = new ArrayList<>();
        eq10.add("a");
        eq10.add("b");
        List<String> eq11 = new ArrayList<>();
        eq11.add("b");
        eq11.add("c");
        List<String> eq12 = new ArrayList<>();
        eq12.add("bc");
        eq12.add("cd");

        List<List<String>> equations1 = new ArrayList<>();
        equations1.add(eq10);
        equations1.add(eq11);
        equations1.add(eq12);

        double[] values1 = new double[3];
        values1[0] = 1.5;
        values1[1] = 2.5;
        values1[2] = 5.0;

        List<String> q10 = new ArrayList<>();
        q10.add("a");
        q10.add("c");
        List<String> q11 = new ArrayList<>();
        q11.add("c");
        q11.add("b");
        List<String> q12 = new ArrayList<>();
        q12.add("bc");
        q12.add("cd");
        List<String> q13 = new ArrayList<>();
        q13.add("cd");
        q13.add("bc");

        List<List<String>> queries1 = new ArrayList<>();
        queries1.add(q10);
        queries1.add(q11);
        queries1.add(q12);
        queries1.add(q13);

        double[] answer1 = test1.calcEquation(equations1, values1, queries1);

        for (int i = 0; i < answer0.length; ++i) {
            System.out.println(answer0[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < answer1.length; ++i) {
            System.out.println(answer1[i] + " ");
        }
        System.out.println();

    }

    public static void findSmallestSetOfVerticesTest() {
        findSmallestSetOfVertices test0 = new findSmallestSetOfVertices();
        findSmallestSetOfVertices test1 = new findSmallestSetOfVertices();
        ArrayList<Integer> test = new ArrayList<>();
        test.add(-1);
        test.add(-1);

        List<Integer> edge00 = new ArrayList<>(test);
        edge00.set(0,0);
        edge00.set(1,1);

        List<Integer> edge01 = new ArrayList<>(test);
        edge01.set(0,0);
        edge01.set(1,2);

        List<Integer> edge02 = new ArrayList<>(test);
        edge02.set(0,2);
        edge02.set(1,5);

        List<Integer> edge03 = new ArrayList<>(test);
        edge03.set(0,3);
        edge03.set(1,4);

        List<Integer> edge04 = new ArrayList<>(test);
        edge04.set(0,4);
        edge04.set(1,2);

        List<List<Integer>> edges0 = new ArrayList<>(5);
        edges0.add(edge00);
        edges0.add(edge01);
        edges0.add(edge02);
        edges0.add(edge03);
        edges0.add(edge04);

        List<Integer> answer0 = test0.findSmallestSetOfVertices(6, edges0);


        List<Integer> edge10 = new ArrayList<>(test);
        edge10.set(0,0);
        edge10.set(1,1);

        List<Integer> edge11 = new ArrayList<>(test);
        edge11.set(0,2);
        edge11.set(1,1);

        List<Integer> edge12 = new ArrayList<>(test);
        edge12.set(0,3);
        edge12.set(1,1);

        List<Integer> edge13 = new ArrayList<>(test);
        edge13.set(0,1);
        edge13.set(1,4);

        List<Integer> edge14 = new ArrayList<>(test);
        edge14.set(0,2);
        edge14.set(1,4);

        List<List<Integer>> edges1 = new ArrayList<>(5);
        edges1.add(edge10);
        edges1.add(edge11);
        edges1.add(edge12);
        edges1.add(edge13);
        edges1.add(edge14);

        List<Integer> answer1 = test1.findSmallestSetOfVertices(5, edges1);

        for (int iter : answer0) {
            System.out.print(iter + " ");
        }
        System.out.println(); // 0 3

        for (int iter : answer1) {
            System.out.print(iter + " ");
        }
        System.out.println(); // 0 2 3
    }
    
    public static void findSmallestSetOfVertices2Test() {
        findSmallestSetOfVertices2 test0 = new findSmallestSetOfVertices2();
        findSmallestSetOfVertices2 test1 = new findSmallestSetOfVertices2();
        ArrayList<Integer> test = new ArrayList<>();
        test.add(-1);
        test.add(-1);

        List<Integer> edge00 = new ArrayList<>(test);
        edge00.set(0,0);
        edge00.set(1,1);

        List<Integer> edge01 = new ArrayList<>(test);
        edge01.set(0,0);
        edge01.set(1,2);

        List<Integer> edge02 = new ArrayList<>(test);
        edge02.set(0,2);
        edge02.set(1,5);

        List<Integer> edge03 = new ArrayList<>(test);
        edge03.set(0,3);
        edge03.set(1,4);

        List<Integer> edge04 = new ArrayList<>(test);
        edge04.set(0,4);
        edge04.set(1,2);

        List<List<Integer>> edges0 = new ArrayList<>(5);
        edges0.add(edge00);
        edges0.add(edge01);
        edges0.add(edge02);
        edges0.add(edge03);
        edges0.add(edge04);

        List<Integer> answer0 = test0.findSmallestSetOfVertices2(6, edges0);


        List<Integer> edge10 = new ArrayList<>(test);
        edge10.set(0,0);
        edge10.set(1,1);

        List<Integer> edge11 = new ArrayList<>(test);
        edge11.set(0,2);
        edge11.set(1,1);

        List<Integer> edge12 = new ArrayList<>(test);
        edge12.set(0,3);
        edge12.set(1,1);

        List<Integer> edge13 = new ArrayList<>(test);
        edge13.set(0,1);
        edge13.set(1,4);

        List<Integer> edge14 = new ArrayList<>(test);
        edge14.set(0,2);
        edge14.set(1,4);

        List<List<Integer>> edges1 = new ArrayList<>(5);
        edges1.add(edge10);
        edges1.add(edge11);
        edges1.add(edge12);
        edges1.add(edge13);
        edges1.add(edge14);

        List<Integer> answer1 = test1.findSmallestSetOfVertices2(5, edges1);

        for (int iter : answer0) {
            System.out.print(iter + " ");
        }
        System.out.println(); // 0 3

        for (int iter : answer1) {
            System.out.print(iter + " ");
        }
        System.out.println(); // 0 2 3
    }
    
    public static void pacificAtlanticTest() {
        pacificAtlantic test0 = new pacificAtlantic();

        int[][] matrix0 = new int[5][5];

        matrix0[0][0] = 1;
        matrix0[0][1] = 2;
        matrix0[0][2] = 2;
        matrix0[0][3] = 3;
        matrix0[0][4] = 5;

        matrix0[1][0] = 3;
        matrix0[1][1] = 2;
        matrix0[1][2] = 3;
        matrix0[1][3] = 4;
        matrix0[1][4] = 4;

        matrix0[2][0] = 2;
        matrix0[2][1] = 4;
        matrix0[2][2] = 5;
        matrix0[2][3] = 3;
        matrix0[2][4] = 1;

        matrix0[3][0] = 6;
        matrix0[3][1] = 7;
        matrix0[3][2] = 1;
        matrix0[3][3] = 4;
        matrix0[3][4] = 5;

        matrix0[4][0] = 5;
        matrix0[4][1] = 1;
        matrix0[4][2] = 1;
        matrix0[4][3] = 2;
        matrix0[4][4] = 4;

        List<List<Integer>> answer0 = test0.pacificAtlantic(matrix0);

        for (List<Integer> iter0 : answer0) {
            for (int iter1 : iter0) {
                System.out.print(iter1 + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        //sortColorTest();       
        //allPathsSourceTargetTest(); 
        //allPathsSourceTargetTest2(); 
        //evaluateDivisionTest();
        //findSmallestSetOfVerticesTest();
        //findSmallestSetOfVertices2Test();
        pacificAtlanticTest();
    }
}
