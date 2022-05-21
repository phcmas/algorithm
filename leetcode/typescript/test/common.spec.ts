import { TreeNode } from "../common/TreeNode";

const treeExample0 = () => {
  const node5 = new TreeNode(5);
  const node2 = new TreeNode(2);
  const node3 = new TreeNode(3, node5);
  const node1 = new TreeNode(1, node3, node2); // root

  return node1;
};

const treeExample1 = () => {
  const node4 = new TreeNode(4);
  const node7 = new TreeNode(7);
  const node1 = new TreeNode(1, null, node4);
  const node3 = new TreeNode(3, null, node7);
  const node2 = new TreeNode(2, node1, node3);

  return node2;
};

describe("common utility test", () => {
  it("check if two trees are same", () => {
    const tree0 = treeExample0();
    const tree1 = treeExample1();

    const ans0 = TreeNode.isSameTree(tree0, tree0);
    const ans1 = TreeNode.isSameTree(tree1, tree1);
    const ans2 = TreeNode.isSameTree(tree0, tree1);

    expect(ans0).toEqual(true);
    expect(ans1).toEqual(true);
    expect(ans2).toEqual(false);
  });

  it("make tree from array", () => {
    const arr0 = [1, 3, 2, 5];
    const arr1 = [2, 1, 3, null, 4, null, 7];

    const ret0 = TreeNode.makeTreeNode(arr0);
    const ret1 = TreeNode.makeTreeNode(arr1);

    const ans0 = treeExample0();
    const ans1 = treeExample1();

    const compare0 = TreeNode.isSameTree(ret0, ans0);
    const compare1 = TreeNode.isSameTree(ret1, ans1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });
});
