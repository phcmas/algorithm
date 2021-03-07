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
    public static void main(String[] args) {
        //UniqueBinarySearchTreesTest();
        MaximumLengthOfRepeatedSubarray();
    }
}
