import minimumDeleteSum1 from "../2022_05/MinimumASCIIDeleteSumForTwoStrings-1";
import minimumDeleteSum2 from "../2022_05/MinimumASCIIDeleteSumForTwoStrings-2";
import findMaxLength from "../2022_05/ContiguousArray";

describe("2022_05 test", () => {
  it("Minimum ASCII Delete Sum for Two Strings - 1", () => {
    const s01 = "sea";
    const s02 = "eat";

    const s11 = "ete";
    const s12 = "leet";

    const s21 = "delete";
    const s22 = "leet";

    const ans0 = minimumDeleteSum1(s01, s02);
    const ans1 = minimumDeleteSum1(s11, s12);
    const ans2 = minimumDeleteSum1(s21, s22);

    expect(ans0).toEqual(231);
    expect(ans1).toEqual(310);
    expect(ans2).toEqual(403);
  });

  it("Minimum ASCII Delete Sum for Two Strings - 2", () => {
    const s01 = "sea";
    const s02 = "eat";

    const s11 = "ete";
    const s12 = "leet";

    const s21 = "delete";
    const s22 = "leet";

    const ans0 = minimumDeleteSum2(s01, s02);
    const ans1 = minimumDeleteSum2(s11, s12);
    const ans2 = minimumDeleteSum2(s21, s22);

    expect(ans0).toEqual(231);
    expect(ans1).toEqual(310);
    expect(ans2).toEqual(403);
  });

  it("contiguous array", () => {
    const nums0 = [0, 1];
    const nums1 = [0, 1, 0];
    const nums2 = [0, 0, 0, 1, 1, 1, 0];
    const nums3 = [0, 0, 0, 1, 1, 1, 1];
    const nums4 = [0, 0, 1, 0, 0, 0, 1, 1];
    const nums5 = [0, 0, 1];

    const ans0 = findMaxLength(nums0);
    const ans1 = findMaxLength(nums1);
    const ans2 = findMaxLength(nums2);
    const ans3 = findMaxLength(nums3);
    const ans4 = findMaxLength(nums4);
    const ans5 = findMaxLength(nums5);

    expect(ans0).toEqual(2);
    expect(ans1).toEqual(2);
    expect(ans2).toEqual(6);
    expect(ans3).toEqual(6);
    expect(ans4).toEqual(6);
    expect(ans5).toEqual(2);
  });
});
