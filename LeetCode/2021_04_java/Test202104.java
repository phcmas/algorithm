import java.util.ArrayList;
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

    public static void main(String[] args) {
        SingleElementInASortedArrayTest();
    }
}
