import { balanceBST } from "../2022_12/BalanceABinarySearchTree";
import { TreeNode } from "../common/TreeNode";

describe("2022_12 test", () => {
  it("balance a binary search tree", () => {
    const root0 = TreeNode.make([1, null, 2, null, 3, null, 4, null, null]);
    const root1 = TreeNode.make([2, 1, 3]);
    const root2 = TreeNode.make([14, 9, 16, 2, 13]);

    const answer0 = TreeNode.make([2, 1, 3, null, null, null, 4]);
    const answer1 = TreeNode.make([2, 1, 3]);
    const answer2 = TreeNode.make([13, 2, 14, null, 9, null, 16]);

    const result0 = balanceBST(root0);
    const result1 = balanceBST(root1);
    const result2 = balanceBST(root2);

    const compare0 = TreeNode.isSame(result0, answer0);
    const compare1 = TreeNode.isSame(result1, answer1);
    const compare2 = TreeNode.isSame(result2, answer2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
  });
});
