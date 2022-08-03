import { minPairSum } from "../2022_08/MinimizeMaximumPairSumInArray";

describe("2022_08 test", () => {
  it("minimize maximum pair sum in array", () => {
    const nums0 = [3, 5, 2, 3];
    const nums1 = [3, 5, 4, 2, 4, 6];

    const ans0 = 7;
    const ans1 = 8;

    const ret0 = minPairSum(nums0);
    const ret1 = minPairSum(nums1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });
});
