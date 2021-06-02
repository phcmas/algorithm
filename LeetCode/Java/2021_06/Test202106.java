

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
    public static void main(String[] args) {
        VerifyPreorderSerializationOfABinaryTreeTest();
    }
};
