import { minDifference } from "../2025_06/MinimumDifferenceBetweenLargestAndSmallestValueInThreeMoves";
import { maximumGain } from "../2025_06/MaximumScoreFromRemovingSubstrings";

describe("2025_06 test", () => {
  it("Minimum Difference Between Largest and Smallest Value in Three Moves", () => {
    const nums0 = [5, 3, 2, 4];
    const nums1 = [1, 5, 0, 10, 14];
    const nums2 = [3, 100, 20];

    const res0 = minDifference(nums0);
    const res1 = minDifference(nums1);
    const res2 = minDifference(nums2);

    expect(res0).toEqual(0);
    expect(res1).toEqual(1);
    expect(res2).toEqual(0);
  });

  it("Maximum Score From Removing Substrings", () => {
    const s0 = "cdbcbbaaabab";
    const x0 = 4;
    const y0 = 5;

    const s1 = "aabbaaxybbaabb";
    const x1 = 5;
    const y1 = 4;

    const res0 = maximumGain(s0, x0, y0);
    const res1 = maximumGain(s1, x1, y1);

    expect(res0).toEqual(19);
    expect(res1).toEqual(20);
  });
});
