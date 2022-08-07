import { TreeNode } from "../common/TreeNode";
import { minPairSum } from "../2022_08/MinimizeMaximumPairSumInArray";
import { pushDominoes } from "../2022_08/PushDominoes";
import { deepestLeavesSum } from "../2022_08/DeepestLeavesSum";
import { longestCommonSubsequence } from "../2022_08/LongestCommonSubsequence";

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

  it("deepest leaves sum", () => {
    const arr0 = [1, 2, 3, 4, 5, null, 6, 7, null, null, null, null, 8];
    const arr1 = [6, 7, 8, 2, 7, 1, 3, 9, null, 1, 4, null, null, null, 5];

    const root0 = TreeNode.makeTreeNode(arr0);
    const root1 = TreeNode.makeTreeNode(arr1);

    const ans0 = 15;
    const ans1 = 19;

    const ret0 = deepestLeavesSum(root0);
    const ret1 = deepestLeavesSum(root1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("longest common subsequence", () => {
    const text01 = "abcde";
    const text02 = "ace";

    const text11 = "abc";
    const text12 = "abc";

    const text21 = "abc";
    const text22 = "def";

    const text31 = "ezupkr";
    const text32 = "ubmrapg";

    const text41 = "pmjghexybyrgzczy";
    const text42 = "hafcdqbgncrcbihkd";

    const ans0 = 3;
    const ans1 = 3;
    const ans2 = 0;
    const ans3 = 2;
    const ans4 = 4;

    const ret0 = longestCommonSubsequence(text01, text02);
    const ret1 = longestCommonSubsequence(text11, text12);
    const ret2 = longestCommonSubsequence(text21, text22);
    const ret3 = longestCommonSubsequence(text31, text32);
    const ret4 = longestCommonSubsequence(text41, text42);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
    expect(ret4).toEqual(ans4);
  });
});
