import { minDifference } from "../2025_06/MinimumDifferenceBetweenLargestAndSmallestValueInThreeMoves";

describe("2025_06 test", () => {
  it("Minimum Difference Between Largest and Smallest Value in Three Moves", () => {
    const nums0 = [5, 3, 2, 4];
    const nums1 = [1, 5, 0, 10, 14];
    const nums2 = [3, 100, 20];

    const ans0 = minDifference(nums0);
    const ans1 = minDifference(nums1);
    const ans2 = minDifference(nums2);

    expect(ans0).toEqual(0);
    expect(ans1).toEqual(1);
    expect(ans2).toEqual(0);
  });
});
