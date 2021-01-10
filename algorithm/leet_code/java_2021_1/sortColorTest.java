package leet_code.java_2021_1;

public class sortColorTest {
    public static void main(String[] args) {
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
}
