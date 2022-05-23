import { minimumDeleteSum1 } from "../2022_05/MinimumASCIIDeleteSumForTwoStrings-1";
import { minimumDeleteSum2 } from "../2022_05/MinimumASCIIDeleteSumForTwoStrings-2";
import { findMaxLength } from "../2022_05/ContiguousArray";
import { mergeTrees } from "../2022_05/MergeTwoBinaryTrees";
import { lexicalOrder } from "../2022_05/LexicographicalNumbers";
import { distanceK } from "../2022_05/AllNodesDistanceKInBinaryTree";
import { TreeNode } from "../common/TreeNode";
import { isArraySame, isArraySameIgnoringOrder } from "../common/Util";

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

  it("lexicographical numbers", () => {
    const n0 = 13;
    const n1 = 2;

    const ret0 = lexicalOrder(n0);
    const ret1 = lexicalOrder(n1);

    const ans0 = [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9];
    const ans1 = [1, 2];

    const compare0 = isArraySame(ans0, ret0);
    const compare1 = isArraySame(ans1, ret1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("all nodes distance K in binary tree", () => {
    const arr0 = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4];
    const root0 = TreeNode.makeTreeNode(arr0);
    const target0 = TreeNode.makeTreeNode([5]);
    const k0 = 2;

    const arr1 = [1];
    const root1 = TreeNode.makeTreeNode(arr1);
    const target1 = TreeNode.makeTreeNode([1]);
    const k1 = 3;

    const arr2 = [0, 2, 1, null, null, 3];
    const root2 = TreeNode.makeTreeNode(arr2);
    const target2 = TreeNode.makeTreeNode([3]);
    const k2 = 3;

    const arr3 = [0, 1, 3, 2, null, null, null, 4];
    const root3 = TreeNode.makeTreeNode(arr3);
    const target3 = TreeNode.makeTreeNode([1]);
    const k3 = 0;

    const ret0 = distanceK(root0, target0, k0);
    const ans0 = [7, 4, 1];
    const compare0 = isArraySameIgnoringOrder(ret0, ans0);

    const ret1 = distanceK(root1, target1, k1);
    const ans1: number[] = [];
    const compare1 = isArraySameIgnoringOrder(ret1, ans1);

    const ret2 = distanceK(root2, target2, k2);
    const ans2: number[] = [2];
    const compare2 = isArraySameIgnoringOrder(ret2, ans2);

    const ret3 = distanceK(root3, target3, k3);
    const ans3: number[] = [1];
    const compare3 = isArraySameIgnoringOrder(ret3, ans3);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
    expect(compare3).toEqual(true);
  });
});
