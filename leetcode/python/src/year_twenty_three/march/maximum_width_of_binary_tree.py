"""
662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
where the null nodes between the end-nodes that would be present in a complete
binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

Constraints:
The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
"""


from queue import Queue
from typing import Optional

from common.tree_node import TreeNode


class Solution:
    def width_of_binary_tree(self, root: Optional[TreeNode]) -> int:
        level_leftmost, index_leftmost, width = 1, 1, 0

        queue = Queue()
        queue.put([level_leftmost, index_leftmost, root])

        while not queue.empty():
            [level, index, node] = queue.get()

            if level_leftmost < level:
                level_leftmost, index_leftmost = level, index

            if node.left:
                queue.put([level + 1, 2 * index, node.left])

            if node.right:
                queue.put([level + 1, 2 * index + 1, node.right])

            width = max(width, index - index_leftmost + 1)

        return width
