import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Test202106 {
    public static void VerifyPreorderSerializationOfABinaryTreeTest() {
        VerifyPreorderSerializationOfABinaryTree test0 = new VerifyPreorderSerializationOfABinaryTree();
        VerifyPreorderSerializationOfABinaryTree test1 = new VerifyPreorderSerializationOfABinaryTree();
        VerifyPreorderSerializationOfABinaryTree test2 = new VerifyPreorderSerializationOfABinaryTree();
        VerifyPreorderSerializationOfABinaryTree test3 = new VerifyPreorderSerializationOfABinaryTree();
        VerifyPreorderSerializationOfABinaryTree test4 = new VerifyPreorderSerializationOfABinaryTree();

        String preorder0 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
        String preorder1 = "1,#";
        String preorder2 = "9,#,#,1";
        String preorder3 = "#";
        String preorder4 = "9,#,92,#,#";

        boolean ans0 = test0.isValidSerialization(preorder0);
        boolean ans1 = test1.isValidSerialization(preorder1);
        boolean ans2 = test2.isValidSerialization(preorder2);
        boolean ans3 = test3.isValidSerialization(preorder3);
        boolean ans4 = test3.isValidSerialization(preorder4);

        System.out.println(ans0); // true 
        System.out.println(ans1); // false
        System.out.println(ans2); // false
        System.out.println(ans3); // true
        System.out.println(ans4); // true
    }

    public static void MinimumSubsequenceInNonIncreasingOrderTest() {
        MinimumSubsequenceInNonIncreasingOrder test0 = new MinimumSubsequenceInNonIncreasingOrder();
        MinimumSubsequenceInNonIncreasingOrder test1 = new MinimumSubsequenceInNonIncreasingOrder();
        MinimumSubsequenceInNonIncreasingOrder test2 = new MinimumSubsequenceInNonIncreasingOrder();

        int[] nums0 = {4,3,10,9,8};
        int[] nums1 = {4,4,7,6,7};
        int[] nums2 = {6};

        List<Integer> ans0 = test0.minSubsequence(nums0);
        List<Integer> ans1 = test1.minSubsequence(nums1);
        List<Integer> ans2 = test2.minSubsequence(nums2);

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 10, 9

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 7, 7, 6

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // 6
    }

    public static void JumpGameIITest() {
        JumpGameII test0 = new JumpGameII();
        JumpGameII test1 = new JumpGameII();

        int[] nums0 = {2,3,1,1,4};
        int[] nums1 = {2,3,0,1,4};

        int ans0 = test0.jump(nums0);
        int ans1 = test1.jump(nums1);

        System.out.println(ans0); // 2
        System.out.println(ans1); // 2
    }

    public static void NextGreaterElementITest() {
        NextGreaterElementI test0 = new NextGreaterElementI();
        NextGreaterElementI test1 = new NextGreaterElementI();

        int[] nums01 = {4,1,2};
        int[] nums02 = {1,3,4,2};

        int[] nums11 = {2,4};
        int[] nums12 = {1,2,3,4};

        int[] ans0 = test0.nextGreaterElement(nums01, nums02);
        int[] ans1 = test1.nextGreaterElement(nums11, nums12);

        for (int iter : ans0) {
            System.out.print(iter + " ");
        } System.out.println(); // -1, 3, -1

        for (int iter : ans1) {
            System.out.print(iter + " ");
        } // 3, -1
    }

    public static void main(String[] args) {
        //VerifyPreorderSerializationOfABinaryTreeTest();
        //MinimumSubsequenceInNonIncreasingOrderTest();
        //JumpGameIITest();
        NextGreaterElementITest();
    }
};
