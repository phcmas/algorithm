import { maxSubarraySumCircular } from "../2023_01/MaximumSumCircularSubarray";
import { countKDifference } from "../2023_01/CountNumberOfPairsWithAbsoluteDifferenceK";

describe("2022_12 test", () => {
  it("maximum sum circular subarray", () => {
    const nums0 = [1, -2, 3, -2];
    const nums1 = [5, -3, 5];
    const nums2 = [-3, -2, -3];
    const nums3 = [1, 3, -1, -4, 6];
    const nums4 = [-2, -3, -1];

    const ans0 = 3;
    const ans1 = 10;
    const ans2 = -2;
    const ans3 = 10;
    const ans4 = -1;

    const ret0 = maxSubarraySumCircular(nums0);
    const ret1 = maxSubarraySumCircular(nums1);
    const ret2 = maxSubarraySumCircular(nums2);
    const ret3 = maxSubarraySumCircular(nums3);
    const ret4 = maxSubarraySumCircular(nums4);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
    expect(ret4).toEqual(ans4);
  });

  it("count number of pairs with absolute difference K", () => {
    const nums0 = [1, 2, 2, 1];
    const nums1 = [1, 3];
    const nums2 = [3, 2, 1, 5, 4];

    const k0 = 1;
    const k1 = 3;
    const k2 = 2;

    const ret0 = countKDifference(nums0, k0);
    const ret1 = countKDifference(nums1, k1);
    const ret2 = countKDifference(nums2, k2);

    const ans0 = 4;
    const ans1 = 0;
    const ans2 = 3;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });
});
