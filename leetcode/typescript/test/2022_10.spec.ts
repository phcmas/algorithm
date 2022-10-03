import { TreeNode } from "../common/TreeNode";
import { generateTrees } from "../2022_10/UniqueBinarySearchTreesII";

describe("2022_10 test", () => {
  it("unique binary search tree II", () => {
    const tree00 = TreeNode.make([1, null, 2, null, 3]);
    const tree01 = TreeNode.make([1, null, 3, 2]);
    const tree02 = TreeNode.make([2, 1, 3]);
    const tree03 = TreeNode.make([3, 1, null, null, 2]);
    const tree04 = TreeNode.make([3, 2, null, 1]);
    const tree10 = TreeNode.make([1]);

    const n0 = 3;
    const n1 = 1;

    const ans0 = [tree00, tree01, tree02, tree03, tree04];
    const ans1 = [tree10];

    const ret0 = generateTrees(n0);
    const ret1 = generateTrees(n1);

    const compare0 = TreeNode.isSameListIgnoringOrder(ans0, ret0);
    const compare1 = TreeNode.isSameListIgnoringOrder(ans1, ret1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });
});
