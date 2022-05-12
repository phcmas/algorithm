import minimumDeleteSum from "../2022_05/MinimumASCIIDeleteSumForTwoStrings";

describe("2022_05 test", () => {
  it("Minimum ASCII Delete Sum for Two Strings", async () => {
    const s01 = "sea";
    const s02 = "eat";

    const s11 = "delete";
    const s12 = "leet";

    const ans0 = minimumDeleteSum(s01, s02);
    const ans1 = minimumDeleteSum(s11, s12);

    expect(ans0).toEqual(231);
    expect(ans1).toEqual(403);
  });
});
