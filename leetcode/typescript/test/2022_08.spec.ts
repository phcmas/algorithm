import { Z_ASCII } from "zlib";
import { minPairSum } from "../2022_08/MinimizeMaximumPairSumInArray";
import { pushDominoes } from "../2022_08/PushDominoes";

describe("2022_08 test", () => {
  it("push dominoes", () => {
    const dominoes0 = "RR.L";
    const dominoes1 = ".L.R...LR..L..";

    const ans0 = "RR.L";
    const ans1 = "LL.RR.LLRRLL..";

    const ret0 = pushDominoes(dominoes0);
    const ret1 = pushDominoes(dominoes1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

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
