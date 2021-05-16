public class Test202105 {
    public static void MagneticForceBetweenTwoBallsTest() {
        MagneticForceBetweenTwoBalls test0 = new MagneticForceBetweenTwoBalls();
        MagneticForceBetweenTwoBalls test1 = new MagneticForceBetweenTwoBalls();

        int[] position0 = {1,2,3,4,7};
        int[] position1 = {5,4,3,2,1,1000000000};

        int ans0 = test0.maxDistance(position0, 3);
        int ans1 = test1.maxDistance(position1, 2);

        System.out.println(ans0); // 3
        System.out.println(ans1); // 999999999
    }
    
    public static void MaximizeSumOfArrayAfterKNegationsTest() {
        MaximizeSumOfArrayAfterKNegations test0 = new MaximizeSumOfArrayAfterKNegations();
        MaximizeSumOfArrayAfterKNegations test1 = new MaximizeSumOfArrayAfterKNegations();
        MaximizeSumOfArrayAfterKNegations test2 = new MaximizeSumOfArrayAfterKNegations();

        int[] A0 = {4,2,3};
        int[] A1 = {3,-1,0,2};
        int[] A2 = {2,-3,-1,5,-4};

        int ans0 = test0.largestSumAfterKNegations(A0, 1);
        int ans1 = test1.largestSumAfterKNegations(A1, 3);
        int ans2 = test2.largestSumAfterKNegations(A2, 2);

        System.out.println(ans0); // 5
        System.out.println(ans1); // 6
        System.out.println(ans2); // 13
    }

    public static void FindBottomLeftTreeValueTest() {
        // 테스트 만드는거 귀찮아서 생략.
    }
 
    public static void DeleteAndEarnTest() {
        DeleteAndEarn test0 = new DeleteAndEarn();
        DeleteAndEarn test1 = new DeleteAndEarn();

        int[] nums0 = {3,4,2};
        int[] nums1 = {2,2,3,3,3,4};
        int[] nums2 = {3,1};

        int ans0 = test0.deleteAndEarn(nums0);
        int ans1 = test0.deleteAndEarn(nums1);
        int ans2 = test0.deleteAndEarn(nums2);
        
        System.out.println(ans0); // 6
        System.out.println(ans1); // 9
        System.out.println(ans2); // 4
    }
    
    public static void MaximumAscendingSubarraySumTest() {
        MaximumAscendingSubarraySum test0 = new MaximumAscendingSubarraySum();
        MaximumAscendingSubarraySum test1 = new MaximumAscendingSubarraySum();
        MaximumAscendingSubarraySum test2 = new MaximumAscendingSubarraySum();
        MaximumAscendingSubarraySum test3 = new MaximumAscendingSubarraySum();

        int[] nums0 = {10,20,30,5,10,50};
        int[] nums1 = {10,20,30,40,50};
        int[] nums2 = {12,17,15,13,10,11,12};
        int[] nums3 = {100,10,1};

        int ans0 = test0.maxAscendingSum(nums0);
        int ans1 = test1.maxAscendingSum(nums1);
        int ans2 = test2.maxAscendingSum(nums2);
        int ans3 = test3.maxAscendingSum(nums3);

        System.out.println(ans0); // 65
        System.out.println(ans1); // 150
        System.out.println(ans2); // 33
        System.out.println(ans3); // 100
    }

    public static void MinimumOperationsToMakeTheArrayIncreasingTest() {
        MinimumOperationsToMakeTheArrayIncreasing test0 = new MinimumOperationsToMakeTheArrayIncreasing();
        MinimumOperationsToMakeTheArrayIncreasing test1 = new MinimumOperationsToMakeTheArrayIncreasing();
        MinimumOperationsToMakeTheArrayIncreasing test2 = new MinimumOperationsToMakeTheArrayIncreasing();

        int[] nums0 = {1,1,1};
        int[] nums1 = {1,5,2,4,1};
        int[] nums2 = {8};

        int ans0 = test0.minOperations(nums0);
        int ans1 = test0.minOperations(nums1);
        int ans2 = test0.minOperations(nums2);

        System.out.println(ans0); // 3
        System.out.println(ans1); // 14
        System.out.println(ans2); // 0
    }

    public static void main(String[] args) {
        //MagneticForceBetweenTwoBallsTest();
        //MaximizeSumOfArrayAfterKNegationsTest();
        //FindBottomLeftTreeValueTest();
        //DeleteAndEarnTest();
        //MaximumAscendingSubarraySumTest();\
        MinimumOperationsToMakeTheArrayIncreasingTest();
    }
}
