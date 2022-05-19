export class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;

  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }

  // array를 tree로 만드는 함수. LeetCode TreeVisualizer가 array를 Tree로 만드는 방식과 동일.
  static makeTreeNode(numbers: (number | null)[]) {
    if (numbers.length === 0 || numbers[0] === null) return null;

    const root = new TreeNode(numbers[0]);
    const queue: TreeNode[] = [root];
    const length = numbers.length;
    let index = 0;

    while (queue.length > 0) {
      const node = queue.shift() as TreeNode;
      const leftNumber = index < length - 1 ? numbers[++index] : null;
      const rightNumber = index < length - 1 ? numbers[++index] : null;
      const left = leftNumber !== null ? new TreeNode(leftNumber) : null;
      const right = rightNumber !== null ? new TreeNode(rightNumber) : null;

      node.left = left;
      node.right = right;

      if (left) queue.push(left);
      if (right) queue.push(right);
    }

    return root;
  }

  static compareNodes(node0: TreeNode | null, node1: TreeNode | null) {
    if (!node0 && !node1) return true;
    if ((node0 && !node1) || (!node0 && node1)) return false;

    return node0?.val === node1?.val;
  }

  static isSameTree(tree0: TreeNode, tree1: TreeNode) {
    if (tree0.val !== tree1.val) return false;

    const queue0: TreeNode[] = [tree0];
    const queue1: TreeNode[] = [tree1];

    while (queue0.length > 0) {
      const node0 = queue0.shift() as TreeNode;
      const node1 = queue1.shift() as TreeNode;
      const compareLeft = this.compareNodes(node0.left, node1.left);
      const compareRight = this.compareNodes(node0.right, node1.right);

      if (!compareLeft || !compareRight) return false;

      if (node0.left && node1.left) {
        queue0.push(node0.left);
        queue1.push(node1.left);
      }

      if (node0.right && node1.right) {
        queue0.push(node0.right);
        queue1.push(node1.right);
      }
    }

    return true;
  }
}
