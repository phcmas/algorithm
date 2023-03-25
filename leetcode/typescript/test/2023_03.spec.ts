import { minimumCardPickup } from "../2023_03/MinimumConsecutiveCardsToPickUp";
import { lowestCommonAncestor } from "../2023_03/LowestCommonAncestorOfABinaryTree";
import { TreeNode } from "../common/TreeNode";

describe("2023_03 test", () => {
  it("minimum consecutive cards to pick up", () => {
    const cards0 = [3, 4, 2, 3, 4, 7];
    const cards1 = [1, 0, 5, 3];
    const cards2 = [0, 0];

    const answer0 = 4;
    const answer1 = -1;
    const answer2 = 2;

    const result0 = minimumCardPickup(cards0);
    const result1 = minimumCardPickup(cards1);
    const result2 = minimumCardPickup(cards2);

    expect(result0).toEqual(answer0);
    expect(result1).toEqual(answer1);
    expect(result2).toEqual(answer2);
  });

  it("lowest common ancestor of a binary tree", () => {
    const root0 = TreeNode.make([3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]);
    const p0 = TreeNode.make([5, 6, 2, null, null, 7, 4]);
    const q0 = TreeNode.make([1, 0, 8]);

    const root1 = TreeNode.make([3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]);
    const p1 = TreeNode.make([5, 6, 2, null, null, 7, 4]);
    const q1 = TreeNode.make([4]);

    const root2 = TreeNode.make([1, 2]);
    const p2 = TreeNode.make([1, 2]);
    const q2 = TreeNode.make([2]);

    const answer0 = TreeNode.make([3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]);
    const answer1 = TreeNode.make([5, 6, 2, null, null, 7, 4]);
    const answer2 = TreeNode.make([1, 2]);

    const result0 = lowestCommonAncestor(root0, p0, q0);
    const result1 = lowestCommonAncestor(root1, p1, q1);
    const result2 = lowestCommonAncestor(root2, p2, q2);

    const compare0 = TreeNode.isSame(result0, answer0);
    const compare1 = TreeNode.isSame(result1, answer1);
    const compare2 = TreeNode.isSame(result2, answer2);

    expect(compare0).toEqual(answer0);
    expect(compare1).toEqual(answer1);
    expect(compare2).toEqual(answer2);
  });
});
