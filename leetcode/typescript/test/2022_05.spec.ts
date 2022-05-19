import { minimumDeleteSum1 } from "../2022_05/MinimumASCIIDeleteSumForTwoStrings-1";
import { minimumDeleteSum2 } from "../2022_05/MinimumASCIIDeleteSumForTwoStrings-2";
import { findMaxLength } from "../2022_05/ContiguousArray";
import { mergeTrees } from "../2022_05/MergeTwoBinaryTrees";
import { TreeNode } from "../common/TreeNode";

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

  it("merge two binary trees", () => {
    const nums00 = [1, 3, 2, 5];
    const nums01 = [2, 1, 3, null, 4, null, 7];
    const ansNum0 = [3, 4, 5, 5, 4, null, 7];

    const nums10 = [1];
    const nums11 = [1, 2];
    const ansNum1 = [2, 2];

    const tree00 = TreeNode.makeTreeNode(nums00);
    const tree01 = TreeNode.makeTreeNode(nums01);
    const ansTree0 = TreeNode.makeTreeNode(ansNum0);
    const retTree0 = mergeTrees(tree00, tree01);
    const ans0 = TreeNode.isSameTree(retTree0, ansTree0);

    const tree10 = TreeNode.makeTreeNode(nums10);
    const tree11 = TreeNode.makeTreeNode(nums11);
    const ansTree1 = TreeNode.makeTreeNode(ansNum1);
    const retTree1 = mergeTrees(tree10, tree11);
    const ans1 = TreeNode.isSameTree(retTree1, ansTree1);

    expect(ans0).toEqual(true);
    expect(ans1).toEqual(true);
  });
});
