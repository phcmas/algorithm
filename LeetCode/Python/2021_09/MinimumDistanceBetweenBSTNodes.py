'''
783. Minimum Distance Between BST Nodes
Given the root of a Binary Search Tree (BST), 
return the minimum difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:
The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 10^5 '''

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderTraversal(self, nodes: list[TreeNode], root: Optional[TreeNode]):
        if root == None: return

        self.inorderTraversal(nodes, root.left)
        nodes.append(root)
        self.inorderTraversal(nodes, root.right)
        

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        nodes = []
        answer = 100000

        self.inorderTraversal(nodes, root)

        for i in range(0, len(nodes)-1):
           answer = min(answer, nodes[i+1].val - nodes[i].val)

        return answer


def main():
    solution = Solution()
    node0_1 = TreeNode(1)
    node0_3 = TreeNode(3)
    node0_2 = TreeNode(2, node0_1, node0_3)
    node0_6 = TreeNode(6)
    node0_4 = TreeNode(4, node0_2, node0_6)

    ans0 = solution.minDiffInBST(node0_4)

    node1_0 = TreeNode(0)
    node1_12 = TreeNode(12)
    node1_49 = TreeNode(49)
    node1_48 = TreeNode(48, node1_12, node1_49)
    node1_1 = TreeNode(1, node1_0, node1_48)

    ans1 = solution.minDiffInBST(node1_1)

    print(ans0)
    print(ans1)

main()








