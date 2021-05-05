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

    public static void main(String[] args) {
        MagneticForceBetweenTwoBallsTest();
    }
}
