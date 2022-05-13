import minimumDeleteSum1 from "../2022_05/MinimumASCIIDeleteSumForTwoStrings-1";
import minimumDeleteSum2 from "../2022_05/MinimumASCIIDeleteSumForTwoStrings-2";

describe("2022_05 test", () => {
  it("Minimum ASCII Delete Sum for Two Strings - 1", async () => {
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

  it("Minimum ASCII Delete Sum for Two Strings - 2", async () => {
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
});
