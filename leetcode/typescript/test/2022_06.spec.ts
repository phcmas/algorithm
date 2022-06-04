import { minimumSwap } from "../2022_06/MinimumSwapsToMakeStringsEqual";
import { numOfSubarrays } from "../2022_06/NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold";
import { kWeakestRows } from "../2022_06/TheKWeakestRowsInAMatrix";
import { isArraySame } from "../common/Util";

describe("2022_06 test", () => {
  it("minimum swaps to make strings equal", () => {
    const s00 = "xx";
    const s01 = "yy";

    const s10 = "xy";
    const s11 = "yx";

    const s20 = "xx";
    const s21 = "xy";

    const s30 = "xxyy";
    const s31 = "xyxy";

    const s40 = "xxyyxyxyxx";
    const s41 = "xyyxyxxxyx";

    const s50 = "xyyyyx";
    const s51 = "xxxxyy";

    const s60 = "xxxxyyyy";
    const s61 = "yyyyxyyx";

    const ret0 = minimumSwap(s00, s01);
    const ret1 = minimumSwap(s10, s11);
    const ret2 = minimumSwap(s20, s21);
    const ret3 = minimumSwap(s30, s31);
    const ret4 = minimumSwap(s40, s41);
    const ret5 = minimumSwap(s50, s51);
    const ret6 = minimumSwap(s60, s61);

    expect(ret0).toEqual(1);
    expect(ret1).toEqual(2);
    expect(ret2).toEqual(-1);
    expect(ret3).toEqual(2);
    expect(ret4).toEqual(4);
    expect(ret5).toEqual(3);
    expect(ret6).toEqual(3);
  });

  it("number of sub array of size k and average greater than or equal to threshold", () => {
    const arr0 = [2, 2, 2, 2, 5, 5, 5, 8];
    const k0 = 3;
    const threshold0 = 4;

    const arr1 = [11, 13, 17, 23, 29, 31, 7, 5, 2, 3];
    const k1 = 3;
    const threshold1 = 5;

    const ret0 = numOfSubarrays(arr0, k0, threshold0);
    const ret1 = numOfSubarrays(arr1, k1, threshold1);

    expect(ret0).toEqual(3);
    expect(ret1).toEqual(6);
  });

  it("k weakest rows", () => {
    const mat0 = [
      [1, 1, 0, 0, 0],
      [1, 1, 1, 1, 0],
      [1, 0, 0, 0, 0],
      [1, 1, 0, 0, 0],
      [1, 1, 1, 1, 1],
    ];
    const k0 = 3;

    const mat1 = [
      [1, 0, 0, 0],
      [1, 1, 1, 1],
      [1, 0, 0, 0],
      [1, 0, 0, 0],
    ];
    const k1 = 2;

    const mat2 = [
      [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0],
      [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ];
    const k2 = 1;

    const ret0 = kWeakestRows(mat0, k0);
    const ret1 = kWeakestRows(mat1, k1);
    const ret2 = kWeakestRows(mat2, k2);

    const ans0 = [2, 0, 3];
    const ans1 = [0, 2];
    const ans2 = [4];

    const compare0 = isArraySame(ret0, ans0);
    const compare1 = isArraySame(ret1, ans1);
    const compare2 = isArraySame(ret2, ans2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
  });
});
